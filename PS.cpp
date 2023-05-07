#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter Total Number of Process"<<endl;
    cin >> n;
    vector<vector<int>> values(n);
    cout << "Enter The Value of Brust Time, Value of Arival Time" << endl;
    for(int i=0;i<n;i++)
    {
        int c,d,e;
        cin >> c >> d >> e;
        values[i].push_back(c);
        values[i].push_back(d);
        values[i].push_back(e);
    }
    sort(values.begin(),values.end());
    int wt[n],tt[n],previous=0;
    wt[0]=values[0][2];
    tt[0]=values[0][1];
    previous=wt[0]+values[0][1];
    for(int i=1;i<n;i++)
    {
        wt[i]=previous-values[i][2];
        previous+=values[i][1];
        tt[i]=wt[i]+values[i][1];
    }
    float totaltt=0,totalwt=0;
    for(int i=0;i<n;i++)
    {
        totaltt+=tt[i];
        totalwt+=wt[i];
    }
    cout << "Average Wating time is " << totalwt/n << endl;
    cout << "Average Turned Around Time is " << totaltt/n << endl;
    return 0;
}
