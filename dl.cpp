#include <iostream>
using namespace std;
int main(){
    int p,r;
    cout<<  "Enter number of process: ";
    cin>>p;
    cout<< "Enter number of resource: ";
    cin>> r;
    int maximum [p][r];
    int allocated [p][r];
    int need [p][r];
    int available [r];
    int finish[p] = {0};
    int safe[p];
    cout<< "enter all the maximum need:" <<endl;
    for(int i=0; i<p ; i++){
        for(int j=0 ;j<r ; j++){
         cin>> maximum[i][j];
        }
    }
    cout<< "enter all the allocation:"<<endl;
    for(int i=0 ; i<p ; i++){
        for(int j=0 ; j<r ; j++){
         cin>> allocated[i][j];
        }
    }
    cout<< "enter all the available:"<<endl;
    for(int i=0 ; i<r ; i++){
        cin>>available[i];
    }
    cout <<"need:"<<endl;
    for(int i=0 ; i<p; i++){
        for(int j=0 ; j<r; j++){
           need[i][j]= maximum[i][j] - allocated[i][j];
          cout<< need[i][j]<<" ";
        }
        cout<<endl;
    }


    int count=0;
    while(count<p){
        bool found =false;
        for(int i=0; i<p; i++){
            if(finish[i] ==0){
                bool possible =true;
                for(int j=0 ; j<r; j++){
                    if(need[i][j] > available[j]){
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    for(int j=0 ; j<r; j++){
                        available[j] += allocated[i][j];
                    }
                    finish[i] =1;
                    found =true;
                    safe[count] =i;
                    count++;
                }
            }
        }
        if(found ==false){
            cout<<"its unsafe";
            return 0;
        }
    }

    cout<< "its safe"<<endl;
    cout<<"safe sequence:" <<endl;
    for(int i=0 ; i<p; i++){
           cout<<"P"<<safe[i]+1;
           if(i!=p-1){
               cout<<" -> ";
        }
    }
}
