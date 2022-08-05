#include<iostream>
#include<algorithm>
using namespace std;

string keyexp(string text,string keystr){
    int x = text.size();
    for(int j=0;;j++){
        if(x==j){
            j=0;
        }
        if(text.size()==keystr.size()){
            break;
        }
        keystr.push_back(keystr[j]);
    }
    return keystr;
}

string encrypt(string text,string key){
    string cipher = "";
    for(int j=0;j<text.size();j++){
        char x = (text[j]+key[j])%26;
        x+='A';
        cipher+=x;
    }
    return cipher;
}

string decrypt(string text,string key){
    string cipher = "";
    for(int j=0;j<text.size();j++){
        char x = (text[j]-key[j]+26)%26;
        x+='A';
        cipher+=x;
    }
    return cipher;
}

string removeSpaces(string str){
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    return str;
}

int main()
{
	string str ;
	string keyword ;
    int choice;
    
    cout<<"Message:\n";
    getline(cin,str);
    cout<<"Key\n";
    getline(cin,keyword);
    // cout<<"1.encryption\n2.decryption\n Enter your choice"<<endl;
    // cin>>choice;
    str=removeSpaces(str);
    keyword=removeSpaces(keyword);
	string key = keyexp(str, keyword);
	string cipher_text = encrypt(str, key);

	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< decrypt(cipher_text, key);
	return 0;
}
