#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process " << endl;
    cin >> n;
    cout << "Enter the time quantam " << endl;
    int timequantam;
    cin >> timequantam;
    vector<pair<int, int>> values;
    vector<int> gc;
    cout << "Enter the brust time & arival time " << endl;
    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        values.push_back({c, d});
        gc.push_back(c);
    }
    int completiontime[n], wt[n], tt[n], i = 0, loopistrue = 1;
    int current_time = values[0].second;
    while (true)
    {
        if (gc[i] <= timequantam && gc[i] != -1)
        {
            completiontime[i] = current_time + gc[i];
            tt[i] = completiontime[i] - values[i].second;
            wt[i] = tt[i] - values[i].first;
            current_time += gc[i];
            gc[i] = -1;
        }
        else
        {
            if (gc[i] != -1)
            {
                gc[i] -= timequantam;
                current_time += timequantam;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (gc[j] != -1)
                break;
            else
            {
                if (j == n - 1)
                {
                    loopistrue = 0;
                }
            }
        }
        if (loopistrue == 0)
        {
            break;
        }
        i++;
        if (i >= n)
        {
            i = 0;
        }
    }
    float totaltt = 0, totalwt = 0;
    for (int i = 0; i < n; i++)
    {
        totaltt += tt[i];
        totalwt += wt[i];
    }
    cout << "Average Weatig time is " << (totalwt / n) << endl;
    cout << "Average Turnaround time is " << (totaltt / n) << endl;
    return 0;
}
