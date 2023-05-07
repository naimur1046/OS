#include<bits\stdc++.h>
using namespace std;
int main()
{
    int p;
    cout << "Enter The Number of Process" << endl;
    cin >> p;
    int r;
    cin >> "Enter The Number of Resourse" << endl;
    
    // Allocation Matrix
    vector<vector<int>> allocation(p);
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            int a;
            cin >> a;
            allocation[i].push_back(a);
        }
    }

    // Need or request Matrix
    vector<vector<int>> need(p);
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            int a;
            cin >> a;
            need[i].push_back(a);
        }
    }

    // Available Matrix
    vector<int> available(r);
    for(int i=0;i<r;i++)
    {
        int a;
        cin >> a;
        available.push_back(a);
    }

    // Resours Allocation Graph Algorithm
    
    vector<int> finish(p),sequence;
    int flag=0;
    for(int i=0;i<p;i++) finish[i]=0;
    for(int i=0;i<p;i++)
    {
        if(!finish[i])
        {
            for(int j=0;<r;j++)
            {
                if(need[i][j]>available[j])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                finish[i]=1;
                for(int j=0;j<r;j++) available[j]+=allocation[i][j];
                flag=0;
                sequence.push_back(i);
                i=-1;
            }
        }
    }
    flag=0;
    for(int i=0;i<p;i++)
    {
        if(!finish[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout << "There is a deadlock" << endl;
    }
    else
    {
        cout << "Safe Sequence are " << endl;
        for(auto x:sequence) cout << x << " "; 
    }
}
