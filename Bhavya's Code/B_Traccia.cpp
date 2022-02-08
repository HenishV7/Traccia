#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the time difference
    long long int getTimeInSeconds(string str)
    {

        vector<int> curr_time;
        istringstream ss(str);
        string token;

        while (getline(ss, token, ':'))
        {

            curr_time.push_back(stoi(token));
        }

        long long int t = curr_time[0] * 60 * 60 + curr_time[1] * 60 + curr_time[2];

        return t;
    }

    // Function to convert seconds back to hh::mm:ss
    // format
    string convertSecToTime(long long int t)
    {
        int hours = t / 3600;
        string hh = hours < 10 ? "0" + to_string(hours)
                               : to_string(hours);
        int min = (t % 3600) / 60;
        string mm = min < 10 ? "0" + to_string(min)
                             : to_string(min);
        int sec = ((t % 3600) % 60);
        string ss = sec < 10 ? "0" + to_string(sec)
                             : to_string(sec);
        string ans = hh + ":" + mm + ":" + ss;
        return ans;
    }

    // Function to find the time gap
    string timeGap(string st, string et)
    {

        long long int t1 = getTimeInSeconds(st);
        long long int t2 = getTimeInSeconds(et);

        long long int time_diff = (t1 - t2 < 0) ? t2 - t1 : t1 - t2;

        return convertSecToTime(time_diff);
    }
};

// Driver Code
int main()
{

    string st, et;
    for (int i = 0; i <= 1; i++)
    {
        string hour, minute, second;
        if (i == 0)
        {
            cout << "Enter first Time:(hour minute second separated by space)" << endl;
            cin >> hour >> minute >> second;
            st = hour + ":" + minute + ":" + second;
        }
        else
        {
            cout << "Enter second Time:(hour minute second separated by space)" << endl;
            cin >> hour >> minute >> second;
            et = hour + ":" + minute + ":" + second;
        }
    }

    Solution ob;
    cout << ob.timeGap(st, et) << "\n";

    return 0;
}