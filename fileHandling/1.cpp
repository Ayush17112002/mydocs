#include<iostream>
#include<fstream>
using namespace std;
class student{
    public:
    int a,b;
    student(){
        a=0,b=0;
    }
    student(int a,int b){
        this->a = a;
        this->b = b;
    }
};
int main(){
    ifstream fin;
    ofstream fout;
    fout.open("output.txt",ios::trunc);
    for(int i = 0; i < 3; i++){
        student s(i,i+1);
        fout.write((char*)&s, sizeof(student));
    }
    fout.close();
    fin.open("output.txt");
    fout.open("input.txt",ios::trunc|ios::out);
    while(!fin.eof()){
        student s;
        fin.read((char*)&s, sizeof(student));
        fout.write((char*)&s, sizeof(student));
    }
    fin.close(); fout.close();
    remove("output.txt");
    fin.open("input.txt",ios::in);
    while(!fin.eof()){
        student s; 
        fin.read((char*)&s, sizeof(student));
        cout<<s.a<<" "<<s.b<<endl;
    }
    return 0;
}