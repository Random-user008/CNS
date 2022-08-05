#include<bits/stdc++.h>
using namespace std;

long int calmod(long int a,long int b){
    return a>=0 ? (a%b): b-(abs(a)%b);
}

long int cal_d(long int e,long int ph){
    for(int j=1;j<=ph;j++){
        if(calmod(e*j,ph)==1){
            return j;
        }
    }
    return 0;
}

int main(){
    long int m,p,q,phi,e;
    cout<<"Enter two prime numbers\n";
    cin>>p>>q;
    long int n = p*q;
    phi = (p-1)*(q-1);
    cout<<"Enter value of e\n";
    cin>>e;
    long int d = cal_d(e,phi);
    cout<<"Enter the message\n";
    cin>>m;
    cout<<"e:"<<e<<"\td:"<<d<<endl;
    long int cipher = calmod(pow(m,e),n);
    long int normal = calmod(pow(cipher,d),n);
    cout<<"Cipher:"<<cipher<<endl;
    cout<<"Decipher:"<<normal<<endl;
}