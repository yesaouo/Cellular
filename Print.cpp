#include<iostream>
#include<iomanip>
#include"Print.h"
using namespace std;
print::print(bool **value,int m,int n,bool show){
    if(show){
        cout<<"   ";
        for(int i=0;i<m;i++){
            cout<<setw(3)<<i;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(show)cout<<setw(3)<<i;
        for(int j=0;j<m;j++){ 
            cout<<((value[i][j]!=0)?"▒▒▒":"░░░");
        }
        cout<<endl;
    }
}
print::print(int **value,int m,int n,char a,char b){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){ 
            if(value[i][j]==1)cout<<" "<<a<<" ";
            else if(value[i][j]==2)cout<<"▒▒▒";
            else if(value[i][j]==3)cout<<" "<<b<<" ";
            else if(value[i][j]==4)cout<<"░░░";
            else cout<<"   ";
        }
        cout<<endl;
    }
}