#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
char key[5][5];
int choice;
void pf(char ch1,char ch2){
    int w,x,y,z,j,k;
    for(j=0;j<5;j++){
        for(k=0;k<5;k++){
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
            x = ((x-1) % 5+5)%5;
            z = ((z-1) % 5+5)%5;
        }
        printf("%c%c",key[w][x],key[y][z]);
    }
    else if(x==z){
        if(choice==1){
            w = (w+1)%5;
            y = (y+1)%5;
        }
        else{
            w = ((w-1) % 5+5)%5;
            y = ((y-1) % 5+5)%5;
        }
        printf("%c%c",key[w][x],key[y][z]);
    }
    else{
        printf("%c%c",key[w][z],key[y][x]);
    }
}

void removeDup(char str[]){
    int hash[256]={0};
    int cur=0,last=0;
    while (*(str+cur))
    {
        char temp = *(str+cur); 
        if(0==hash[temp]){
            hash[temp] = 1;
            *(str+last) = temp;
            last = last+1;
        }
        cur  = cur+1;
    }
    *(str+last)='\0';
}


int main(){
    char str[25],keystr[10],keyminus[25];
    char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i, j, k, m, n;
    cout<<"Enter the text:\n";
    gets(str);
    cout<<"Enter the keystring\n";
    gets(keystr);
    cout<<"Enter your choice\n";
    cin>>choice;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'j')
            str[i] = 'i';
        if (str[i] == 'J')
            str[i] = 'I';
        str[i] = toupper(str[i]);
    }
    for (i = 0; i < strlen(keystr); i++)
    {
        if (keystr[i] == 'j')
            keystr[i] = 'i';
        if (keystr[i] == 'J')
            keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);
    }
    removeDup(keystr);
    cout<<str<<endl;
    cout<<keystr<<endl;
    n = strlen(keystr);
    m=0;
    for(j=0;j<26;j++){
        for(k=0;k<n;k++){
            if(keystr[k]==alpa[j])
            break;
            if(keystr[k]=='J')
            break;
        }
        if(k==n && alpa[j]!='J'){
            keyminus[m]=alpa[j];
            m++;
        }
    }
    k=0;
    m=0;
    for(j=0;j<5;j++){
        for(int l=0;l<5;l++){
            if(k<n){
                key[j][l] = keystr[k];
                k++;
            }
            else{
                key[j][l]=keyminus[m];
                m++;
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
