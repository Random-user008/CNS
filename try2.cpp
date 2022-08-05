#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
int key[5][5];
int choice;
void pf(char ch1,char ch2){
    int w,x,y,z;
    for(int j=0;j<5;j++){
        for(int k=0;k<5;k++){
            if(ch1==key[j][k]){
                w=j;
                x=k;
            }
            else if(ch2==key[j][k]){
                y=j;
                z=k;
            }
        }
    }
    if(w==y){
        if(choice==1){
            x = (x+1)%5;
            z = (z+1)%5;
        }
        else{
            x = ((x-1)% 5+5)%5;
            z = ((z-1)%5+5)%5;
        }
        printf("%c%c",key[w][x],key[y][z]);
    }
    else if(x==z){
        if(choice==1){
            w = (w+1)%5;
            y = (y+1)%5;
        }
        else{
            w = ((w-1)% 5+5)%5;
            y = ((y-1)%5+5)%5;
        }
        printf("%c%c",key[w][x],key[y][z]);
    }
    else{
        printf("%c%c",key[w][z],key[y][x]);
    }
}

void removeDup(char str[]){
    char temp;
    int hash[256]={0};
    int cur=0,last=0;
    while(*(str+cur)){
        temp = *(str+cur);
        if(0==hash[temp]){
            hash[temp] = 1;
            *(str+last) = temp;
            last = last+1;
        }
        cur = cur+1;
    }
    *(str+last) = '\0';
}

int main(){
    char str[25],keystr[10],keyminus[20];
    char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i, j, k, m=0, n;
    cout<<"Enter the text\n";
    gets(str);
    cout<<"Enter the key\n";
    gets(keystr);
    cout<<"Enter your choice\n";
    cin>>choice;
    removeDup(keystr);
    for(int j=0;j<strlen(str);j++){
        if(str[j]=='j')
            str[j]='i';
        if(str[j]=='J')
            str[j]='I';
        str[j] = toupper(str[j]);
    }
     for(int j=0;j<strlen(keystr);j++){
        if(keystr[j]=='j')
            keystr[j]='i';
        if(keystr[j]=='J')
            keystr[j]='I';
        keystr[j] = toupper(keystr[j]);
    }
    n = strlen(keystr);
    // int m=0;
    for(j=0;j<25;j++){
        for(k=0;k<n;k++){
            if(keystr[k]==alpa[j]){
                break;
            }
            if(keystr[k]=='J'){
                break;
            }
        }
         if(k==n && alpa[j]!='J'){
                keyminus[m++] = alpa[j];
            }
    }
    m=0;
    k=0;
    for(j=0;j<5;j++){
        for(int l=0;l<5;l++){
            if(m<n){
                key[j][l] = keystr[m++];
            }
            else{
                key[j][l] = keyminus[k++];
            }
            printf("%c ",key[j][l]);
        }
         printf("\n");
    }

    for(j=0;j<strlen(str);j++){
        if(str[j]>='A' && str[j]<='Z'){
            if (str[j] == 'J')
                str[j] = 'I';
            if(str[j+1]=='\0'){
                pf(str[j],'X');
            }
            else{
                if (str[j+1] == 'J')
                    str[j+1] = 'I';
                if(str[j]==str[j+1]){
                    pf(str[j],'X');
                }
                else{
                    pf(str[j],str[j+1]);
                    j++;
                }
            }
        }
    }

}