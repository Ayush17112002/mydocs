#include<iostream>
using namespace std;

class list{
    public:
    virtual void store(int value)=0;
    virtual int retreive()=0;
};

class stack:public list{
    int values[50];
    int top;
    public:
    stack(){
        top=-1;
    } 
    void store(int value){
        if(top++>=50){
            cout<<"Overflow!!";
            --top;
            return;
        }
        values[top]=value;
    }
    int retreive(){
        if(top==-1){
            cout<<"Underflow";
            return -1;
        }
        return values[top--];
    }
    void display();
};
void stack::display(){
    int i=0;
    while(i<=top){
        cout<<values[i]<<" ";
        ++i;
    }
}

class queue:public list{
     int values[50];
     int front,rear;
     public:
     queue(){
         front=0;
         rear=0;
     }
     void store(int value){
         if((rear+1)==front){
             cout<<"Overflow!!";
             return;
         }
         values[rear]=value;
         rear++;
         rear=rear%50;
     }
     int retreive(){
         if(rear==front){
             cout<<"Underflow!!";
             return -1;
         }
         if (front==49){
             front=0;
             return values[49];
         }
         return values[front++];
     }
     void display();
};
void queue::display(){
    int i=front;
    while(i<rear){
        cout<<values[i]<<" ";
        i++;
        i%=50;
    }
    cout<<endl;
}
int main(){
    stack s;
    queue q;
    cout<<"Menu\n1.Add to stack\n2.Add to queue\n3.Delete from stack\n4.Delete from queue\n5.Display from stack and queue\n6.Exit"<<endl;
    while(1){
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            int value;
            cout<<"Enter value: ";
            cin>>value;
            s.store(value);
            cout<<" "<<value<<" added to stack\n";
            break;
            case 2:
            cout<<"Enter value: ";
            cin>>value;
            q.store(value);
            cout<<" "<<value<<" added to queue\n";
            break;     
            case 3:
            cout<<" "<<s.retreive()<<" deleted from stack\n";
            break;
            case 4:
            cout<<" "<<q.retreive()<<" deleted from queue\n";
            break;
            case 5:
            cout<<"\nStack: ";
            s.display();
            cout<<"\nQueue: ";
            q.display();
            break;
            case 6:
            exit(1);
            default:
            cout<<"Invalid choice!! Try again";
        }
    }
return 0;
}