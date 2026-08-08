#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "enter no of process: ";
    cin >>n;
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    for(int i=0; i<n; i++) {
        pid[i] = i + 1;
        cout<< "enter at and bt of process " <<pid[i]<< ": ";
        cin>> at[i] >>bt[i];
    }
    for(int i=0; i< n-1; i++) {
        for(int j=0; j< n-i-1; j++) {
            if(at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }
    ct[0]= at[0] + bt[0];
    for(int i=1; i<n; i++) {
        if(ct[i- 1] < at[i]) {
            ct[i]= at[i] + bt[i];
        }
        else {
            ct[i]=ct[i-1] + bt[i];
        }
    }
    for(int i= 0; i<n;i++) {
        tat[i]= ct[i] - at[i];
        wt[i]= tat[i] - bt[i];
        rt[i]= wt[i];
    }
    cout<< "process\tat\tbt\tct\ttat\twt\trt\n";
    for(int i=0; i<n;i++) {
        cout << "p" << pid[i] << "\t";
        cout << at[i]<< "\t";
        cout<< bt[i] <<"\t";
        cout << ct[i]<< "\t";
        cout << tat[i] << "\t";
        cout<< wt[i]<< "\t";
        cout << rt[i] << "\t" << endl;
    }
    cout<< "Gantt chart:" <<endl;
    for(int i=0; i<n;i++) {
        cout << "| p" <<pid[i];
    }
    cout<< " |";
    return 0;
}
