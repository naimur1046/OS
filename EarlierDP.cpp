#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Number of Process" << endl;
    cin >> n;
    
    // Input of Arival Time (AT), Brust Time(t), deadline(d)
    vector<vector<int>> process;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        process[i].push_back(a);
        process[i].push_back(b);
        process[i].push_back(c);
    }
    int time=0;
    for(int i=0;i<n;i++)
    {
        int flag=-1;
        for(int j=0;j<n;j++)
        {
            if(process[j][0]<=time&&process[j][1]>0)
            {
                if(flag==-1||process[j][2]<process[flag][2])
                {
                    flag=j;
                }
            }
        }
        if(flag==-1)
        {
            time=process[i][0];
            flag=i;
        }
        process[flag][1]--;
        time++;
        if(time>process[flag][2])
        {
            cout << "Porcess " << i << " Missed its Deadline" << endl; 
        }
        if(process[flag][1]==0)
        {
            cout << "Process " << i << " Has Completed" << endl;
        }
    }
}
