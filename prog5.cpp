#include<bits/stdc++.h>
using namespace std;

void encrypt(string text,int n){
    int j,k,flag=0;
    vector<vector<char>> a(n,vector<char>(text.size(),' '));
    for(j=0;j<text.size();j++){
        a[k][j] = text[j];
        if(k==n-1){
            flag=1;
        }
        else if(k==0){
            flag=0;
        }
        if(flag==1){
            k--;
        }
        else{
            k++;
        }
    }
    for(int i=0;i<n;i++){
        for(j=0;j<text.size();j++){
            if(a[i][j]!=' ')
                cout<<a[i][j];
        }
    }
    cout<<'\n';   
}

void decrypt(string text,int n){
    int j,k,flag=0;
    vector<vector<char>> a(n,vector<char>(text.size(),' '));
    for(j=0;j<text.size();j++){
        a[k][j] = '0';
        if(k==n-1){
            flag=1;
        }
        else if(k==0){
            flag=0;
        }
        if(flag==1){
            k--;
        }
        else{
            k++;
        }
    }
    int temp = 0;
    for(int i=0;i<n;i++){
        for(j=0;j<text.size();j++){
            if(a[i][j]=='0')
                a[i][j]=text[temp++];
        }
    }
    k=0;
    for(j=0;j<text.size();j++){
        cout<<a[k][j];
        if(k==n-1){
            flag=1;
        }
        else if(k==0){
            flag=0;
        }
        if(flag==1){
            k--;
        }
        else{
            k++;
        }
    }
    cout<<'\n';  
}


int main(){
    string text;
    int key,choice;
    cout<<"Enter the text\n";
    getline(cin,text);
    cout<<"Enter the key\n";
    cin>>key;
    cout<<"Enter the choice\n";
    cin>>choice;
    if(choice==1){
        encrypt(text,key);
    }
    else{
        decrypt(text,key);
    }
}