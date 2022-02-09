import numpy as np
from statistics import mean
import pandas as pd

lst_of_delays = []
lst_of_data = []

lst_of_f_data = []


def time_to_microseconds(str_of_time):
    t_0 = int(str_of_time[9:]) + (1000 * int(str_of_time[6:8])) + \
        (60000000 * int(str_of_time[3:5])) + \
        (3600000000 * int(str_of_time[0:2]))
    return t_0


def fetch_the_line_data(dataset, y):
    return str(dataset[y, :][0])[16:]


def fetch_the_line_time(dataset, y):
    t_str = str(dataset[y, :][0])[:12]
    t_1 = time_to_microseconds(t_str)
    return t_1


def match_the_lines(dataset, y):
    lst_of_micros = []
    lst_of_micros.append(fetch_the_line_time(dataset, y))
    c_line = fetch_the_line_data(dataset, y)
    v = i + 2
    while(True):
        if v < len(dataset):
            if c_line == fetch_the_line_data(dataset, v):
                lst_of_micros.append(int(fetch_the_line_time(dataset, v)))
                v = v + 2

            else:
                break
        else:
            break

    r = [mean(lst_of_micros), v]

    return r


if __name__ == "__main__":
    datasheet = pd.read_csv(
        "C:/Users/henis/Downloads/bank/Traccia/Data of Reading No. 1/Rx_2m.txt", header=None)
    x = datasheet.iloc[:, :].values
    i = 0
    while(True):
        if i < len(x):
            if i % 2 == 0:
                lst_of_data.append(fetch_the_line_data(x, i))
                data = match_the_lines(x, i)
                lst_of_delays.append(data[0])
                i = data[1]
            else:
                i = i + 1
        else:
            break

    print(lst_of_data)
    print(lst_of_delays)
    print(len(lst_of_data))
    print(len(lst_of_delays))

    for i in range(len(lst_of_data)):
        lst_of_f_data.append([lst_of_data[i], lst_of_delays[i]])

    print(lst_of_f_data)
