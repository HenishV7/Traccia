from ast import Pass
import numpy as np
import pandas as pd

lst_of_micros = []
lst_of_delays = []

isfirstline = True


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


if __name__ == "__main__":
    datasheet = pd.read_csv(
        "C:/Users/henis/Downloads/bank/Traccia/Data of Reading No. 1/Rx_1m.txt", header=None)
    x = datasheet.iloc[:, :].values

    for i in range(len(x)):
        if isfirstline == True:
            t = str(x[i, :][0])
            q = i + 2
            while(True):
                if(q < len(x)):
                    if t[16:] == fetch_the_line_data(x, q):
                        lst_of_micros.append(fetch_the_line_time)
                        q = q + 2
                    else:
                        i = q
                        break
            isfirstline = False
        else:
            i = i + 1
            isfirstline = True

    print(lst_of_micros)
