#include<iostream>
using namespace std;
int key[3][3];
int mod26(int x){
    return x>=0 ? (x%26):26-(abs(x)%26);
}

int det(int m[3][3]){
    int det;
    det = m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2])-m[0][1]*(m[1][0]*m[2][2]-m[2][0]*m[1][2])+m[0][2]*(m[1][0]*m[2][1]-m[2][0]*m[1][1]);
    return mod26(det);
}

int detInv(int r){
    for(int j=1;j<=25;j++){
        if(mod26(r*j)==1){
            return j;
        }
    }
    return 0;
}

void mulmat(int a[100][3],int r1,int c1,int b[100][3],int r2,int c2,int re[100][3]){
    for(int j=0;j<r1;j++){
        for(int p=0;p<c2;p++){
            for(int k=0;k<r2;k++){
                re[j][p] += a[j][k]*b[k][p]; 
            }
            re[j][p]=mod26(re[j][p]);
        }
    }
}

void Inv(int m[3][3],int n,int rev[3][3]){
    int det1 = det(m);
    int det2 = detInv(det1);
    int temp[5][5] = {0};
    int adj[3][3];
    for(int j=0;j<5;j++){
        for(int k=0;k<5;k++){
            temp[j][k] = m[j%3][k%3];
        }
    }
    for(int j=1;j<=3;j++){
        for(int k=1;k<=3;k++){
            adj[k-1][j-1] = temp[j][k]*temp[j+1][k+1] - temp[j][k+1]*temp[j+1][k];
        }
    }
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            rev[j][k] = mod26(adj[j][k]*det2);
        }
    }
}

string encrypt(string text,int n){
    string cipher = "";
    int p[100][3] = {0};
    int c[100][3] = {0};
    int l = text.length()/3;
    int pter=0;
    for(int j=0;j<l;j++){
        for(int k=0;k<3;k++){
            p[j][k] = text[pter++]-'a';
        }
    }
    mulmat(p,l,3,key,3,3,c);
    for(int j=0;j<l;j++){
        for(int k=0;k<3;k++){
            cipher+= c[j][k]+'a';
        }
    }
    return cipher;
}

string decrypt(string text,int n){
    string cipher = "";
    int p[100][3] = {0};
    int c[100][3] = {0};
    int l = text.length()/3;
    int pter=0;
    int inv[3][3]={0};
    for(int j=0;j<l;j++){
        for(int k=0;k<3;k++){
            p[j][k] = text[pter++]-'a';
        }
    }
    Inv(key,3,inv);
    mulmat(p,l,3,inv,3,3,c);
    for(int j=0;j<l;j++){
        for(int k=0;k<3;k++){
            cipher+= c[j][k]+'a';
        }
    }
    return cipher;
}

int main(){
    string pt,et,dt;
    cout<<"Enter text\n";
    cin>>pt;
    cout<<"Enter the key matrix\n";
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            cin>>key[j][k];
        }
    }
    et = encrypt(pt,3);
    cout<<et<<endl;
    dt = decrypt(et,3);
    cout<<dt<<endl;

}