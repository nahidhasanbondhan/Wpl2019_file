#include <iostream>
#include <stdio.h>
#include<string>
#include<string.h>
using namespace std;

int main() {
    string name;
    int n,i,j,c=0,t=0;
    cin>>n;
    for(j=0;j<n;j++) {
        cin >> name;
        if(name.length()==5){
            cout<<"3"<<endl;
            break;
        }
        else if((name[0]=='o'&&name[1]=='n')||(name[0]=='o'&&name[2]=='e')
                ||(name[1]=='n'&&name[2]=='e')||(name[0]=='o'&&name[1]=='n'&&name[2]=='e')){
            cout<<"1"<<endl;
            break;

        }
        else
            cout<<"2"<<endl;


    }
    return 0;
}