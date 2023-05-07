#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Process" << endl;
    cin >> n;
    cout << "Enter The Default Time Quantum" << endl;
    int dtq;
    cin >> dtq;
    vector<vector<int>> process(n);
    cout << "Enter Arival Time, Execution Time, Remaining Time, Quantum" << endl;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        process.push_back(a);
        process.push_back(b);
        process.push_back(c);
        process.push_back(d);
    }
    queue<vector<int>> qprocess;
    qprocess=process;
    int time_increase=dtq/10;
    int time=0;
    while (!qprocess.empty())
    {
        auto p=qprocess.front();
        qprocess.pop();
        int remaining_time=p[2];
        int qntm=p[3];
        while(remaining_time>0)
        {
            if(qntm>remaining_time)
            {
                qntm=remaining_time;
            }

            // Execute The Process One Time
            for(int i=0;i<qntm;i++)
            {
                time++;
                remaining_time--;

                // Check The Process has finished
                if(remaining_time==0)
                {
                    cout << "Process " << i << " has finished " << endl;
                    break;
                }
                if(i==qntm-1&&remaining_time>0)
                {
                    if(qntm==p[3])
                    {
                        qntm+=time_increase;
                    }
                    else
                    {
                        qntm=p[3];
                    }
                }
            }
        }

        // If time quantum should increase or decresed

        if(remaining_time>0)
        {
            if(qntm==p[3])
            {
                qntm+=time_increase;
            }
            else
            {
                qntm=p[3];
            }
        }

    }
    
    return 0;
}
