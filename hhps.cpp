#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Enter number of process: ";
    cin >> n;
    int pid[n], at[n], bt[n], pr[n], rt[n], ct[n], tat[n], wt[n], rst[n];
    int gantt[100];
    int g =0;
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout<< "enter at and bt of process " <<pid[i]<< ": ";
        cin>> at[i] >>bt[i];
        cout << "P" << pid[i] << " Priority: ";
        cin >> pr[i];
        rt[i] = bt[i];
        rst[i] =-1;
    }

    int time =0;
    int complete= 0;
    while(complete!= n) {
        int highest= -1;
        for(int i=0; i<n; i++) {
            if(at[i]<=time && rt[i]>0) {
                if(highest==-1 || pr[i]>pr[highest]) {
                    highest=i;
                }
            }
        }
        if(highest==-1) {
            gantt[g++]=0;
            time++;
        }
        else {
            if(rst[highest] == -1)
                rst[highest] = time - at[highest];
            gantt[g++] = pid[highest];
            rt[highest]--;
            time++;
            if(rt[highest]==0) {
                complete++;
                ct[highest]= time;
                tat[highest] =ct[highest]-at[highest];
                wt[highest] =tat[highest]-bt[highest];
            }
        }
    }
    cout <<"\nGantt Chart:\n|";

    for(int i=0; i<g; i++) {
        if(gantt[i]== 0)
            cout<<" Idle |";
        else
            cout<<" P" << gantt[i] << " |";
    }
    cout << "\n\nProcess\tat\tbt\tct\ttat\twt\trst\n";
    float awt = 0, atat = 0, art = 0;
    for(int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << rst[i] << endl;
        awt += wt[i];
        atat += tat[i];
        art += rst[i];
    }
    cout << "\nAverage Waiting Time = " << awt/n<< "\nAverage Turnaround Time = " << atat/n<< "\nAverage Response Time = " << art/n;
    return 0;
}
