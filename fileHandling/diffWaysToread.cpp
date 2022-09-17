#include<fstream>
#include<iostream>
using namespace std;
int main(){
    ifstream fin;
    fin.open("myfile.txt",ios::in);
    // char buff[100];
    // fin.getline(buff,'.');
    // int i = 0;
    // while(buff[i]!='\0'){
    //     cout<<buff[i];
    //     i++;
    // }
    // cout<<i;

    string s[2];
    int i = 0;
    while(!fin.eof()){
        fin>>s[i];
        i++;
    }
    cout<<s[0];

    return 0;
}