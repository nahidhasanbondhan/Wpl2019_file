#include <iostream>
#include <cstdio>

using namespace std;

int main()

{
    int m[5][5],i,j,p,q,c=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>m[i][j];
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(m[i][j]==1){
                p=i;
                q=j;
            }

        }
    }
    if(p<=2){
        c=c+(2-p);
    }
    if(p>2){
        c=c+(p-2);
    }
    if(q<=2){
        c=c+(2-q);
    }
    if(q>2){
        c=c+(q-2);
    }
    cout<<c;
}
