#include<bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter The Number of Processes" << endl;
    cin >> n;
    cout << "Enter The Number of Resources" << endl;
    int r;
    cin >> r;

    // Read Allocation
    vector<vector<int>> allocation(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            int a;
            cin >> a;
            allocation[i].push_back(a);
        }
    }

    // Read Maximum Requirement
    vector<vector<int>> maxirequrment(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            int a;
            cin >>a;
            maxirequrment[i].push_back(a);
        }
    }

    //The Available Resourse
    vector<vector<int>> availresourse(1);
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<r;j++)
        {
            int a;
            cin >>a;
            availresourse[i].push_back(a);
        }
    }

    //Need Calculation
    vector<vector<int>> need(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i].push_back(maxirequrment[i][j]-allocation[i][j]);
        }
    }

    //Printing The Need
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    // Bankers Algorithm
    
    vector<int> safesequence,finish(n);
    for(int i=0;i<n;i++) finish[i]=0;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(!finish[i])
        {
            for(int j=0;j<r;j++)
            {
                if(need[i][j]>availresourse[0][j])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                finish[i]=1;
                safesequence.push_back(i);
                for(int j=0;j<r;j++) availresourse[0][j]+=allocation[i][j];
                i=-1;
                
            }
            flag=0;
        }
    }
    flag=0;
    for(int i=0;i<n;i++) 
    {
        if(!finish[i])
        {
            flag=1;
            cout << "The System is in Deadlock" << endl;
            break;
        }
    }
    if(flag==0)
    {
        cout << "The process is in safe sequence " << endl;
        cout << "The Sequence are" << endl;
        for(auto x:safesequence) cout << x << endl;
    }
    return 0;
}
