#include<bits/stdc++.h>
using namespace std;
 long long int df(int a,int b,int m){
    if(b==1)
        return a;
    long long int t = df(a,b/2,m);
    if(b%2==0){
        return (t*t)%m;
    }
    else{
        return (((t*t)%m)*a)%m;
    }
 }

int main()
{
long long int q, alpha, x, a, y, b, ka, kb;
cout<<"Enter the values of q and alpha upon which Alice And Bob both will aggree : "<<endl;
       cin>>q>>alpha;
     
       cout<<"Enter the Secret Integer for Alice : ";
       cin>>x;
       cout<<"Enter the Secret Integer for Bob : ";
       cin>>y;
       cout<<endl;
     a=df(alpha,x,q);
                     b=df(alpha,y,q);
       cout<<"Alice's private key, known only to Alice : "<<a<<endl;
       cout<<"Bob's private key known only to Bob : "<<b<<endl;
       cout<<endl;
       ka = df(b,x,q);
                     kb = df(a,y,q);
       cout<<"Alice's public key, known to Alice and Bob : "<<ka<<endl;
       cout<<"Bob's public key, known to Alice and Bob : "<<kb<<endl;
       return 0;
      }
