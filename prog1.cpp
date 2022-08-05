#include<iostream>
using namespace std;
int main(){
    string text,cipher="";
    int key,choice;
    cout<<"Enter the text:\n";
    getline(cin,text);
    cout<<"Enter the key\n";
    cin>>key;
    cout<<"Enter the choice\n";
    cin>>choice;
    if(choice==1){

        for(int j=0;j<text.size();j++){
            char ch = text[j];
            if(ch>='a' && ch<='z'){
                ch = ch +key;
                if(ch>'z'){
                    ch += 'a'-'z'-1;
                }
            }
            else if(ch>='A' && ch<='Z'){
                ch = ch +key;
                if(ch>'Z'){
                    ch += 'A'-'Z'-1;
                }
            }
            cipher+=ch;
        }
    }else{
         for(int j=0;j<text.size();j++){
            char ch = text[j];
            if(ch>='a' && ch<='z'){
                ch = ch-key;
                if(ch<'a'){
                    ch += 'z'-'a'+1;
                }
            }
            else if(ch>='A' && ch<='Z'){
                ch = ch-key;
                if(ch<'A'){
                    ch += 'Z'-'A'+1;
                }
            }
            cipher+=ch;
        }

    }
    cout<<cipher<<endl;
}