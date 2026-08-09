#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n], rst[n];
    int gantt[100], g=0;

    cout << "Enter tq : ";
    cin >>tq;

    for(int i=0; i<n; i++)
    {
        p[i] = i+1;
      cout<<"enter at and bt of process "<<p[i]<<": ";
        cin>>at[i]>>bt[i];
        rt[i] = bt[i];
        rst[i]=-1;
    }

    queue<int> q;
    int time =0, completed =0;
    int next =0;

    q.push(0);
    next =1;

    while(!q.empty())
    {
        int i= q.front();
        q.pop();
        gantt[g++]=p[i];
        if(rst[i]==-1)
            rst[i]=time-at[i];

        if(rt[i] >tq)
        {
            time +=tq;
            rt[i] -=tq;
        }
        else
        {
            time +=rt[i];
            rt[i] =0;
            ct[i] =time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            completed++;
        }

        while(next <n && at[next] <=time)
        {
            q.push(next);
            next++;
        }

        if(rt[i] >0)
            q.push(i);

        if(q.empty() && next <n)
        {
            time =at[next];
            q.push(next);
            next++;
        }
    }

    cout <<"P\tat\tbt\tct\ttat\twt\trt\n";
    for(int i = 0; i < n; i++)
        cout << "P" << p[i] << "\t" << at[i]<< "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i]<<"\t"<<rst[i]<<endl;
        cout<<"Gantt chart:\n|";
        for(int i=0; i<g; i++)
            cout<<"P"<<gantt[i]<<" |";
    return 0;
}
