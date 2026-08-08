#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n], rst[n];
    int gantt[100], g = 0;
    for (int i=0; i<n; i++) {
        pid[i] = i+1;
        cout<< "enter at and bt of process " <<pid[i]<< ": ";
        cin>> at[i] >>bt[i];
        rt[i] = bt[i];
        rst[i] =-1;
    }
    int time= 0;
    int complete= 0;
    while (complete!= n) {
        int shortest = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {

                if (rt[i] < min) {
                    min = rt[i];
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            gantt[g++] = 0;
            time++;
        }

        else {
            if (rst[shortest] == -1)
                rst[shortest] = time - at[shortest];
            gantt[g++] = pid[shortest];
            rt[shortest]--;
            time++;
            if (rt[shortest] == 0) {
                complete++;
                ct[shortest] = time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
            }
        }
    }
    cout << "\nGantt Chart:\n|";
    for (int i = 0; i < g; i++) {

        if (gantt[i] == 0)
            cout << " Idle |";
        else
            cout << " P" << gantt[i] << " |";
    }
    cout << "\n\nProcess\tat\tbt\tct\ttat\twt\trst\n";
    float awt = 0, atat = 0, art = 0;
    for (int i = 0; i < n; i++) {
  cout << "p" << pid[i] << "\t"<< at[i]<< "\t" << bt[i] <<"\t" << ct[i]<< "\t" << tat[i] << "\t"<< wt[i]<< "\t" << rst[i] << "\t" << endl;
        awt += wt[i];
        atat += tat[i];
        art += rst[i];
    }
    cout << "\nAverage Waiting Time = " << awt/n<< "\nAverage Turnaround Time = " << atat/n<< "\nAverage Response Time = " << art/n;
    return 0;
}
