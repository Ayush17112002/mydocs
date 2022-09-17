#include<bits/stdc++.h>
using namespace std;

class emp{
    public:
    virtual void raiseSalary(){
        cout<<"emp";
    }
    void promote(){
        cout<<"promoteEmp";
    }
};
class Engg:public emp{
    public:
    void raiseSalary(){
        cout<<"empEngg";
    }
};

int main(){
    emp *abc = new Engg;
    abc->raiseSalary();
    delete abc;
    return 0;
}