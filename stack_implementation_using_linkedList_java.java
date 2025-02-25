
#include <iostream>
using namespace std;
class stack{
    public: 
    int top;
    int arr[100];
    stack()
    {
        top=-1;
    }
    
    int push(int num)
    {
        top++;
        arr[top]=num;
        cout<<"Number is Successfully pushed into stack"<<endl;
        return top;
    }
    int pop(int top)
    {
        int item;
        item=arr[top];
        top--;
        cout<<"Your Deleted item is: "<<item<<endl;
        
        return top;
    }
    void display()
    {
        while(top>=0)
        {
            cout<<arr[top]<<" ";
            top--;
        }
        cout<<endl;
    }
};
int main() {
    stack s1;
    int num;
    int top;
    int choice;
    
    do{
        cout<<"-------------------MENU------------------"<<endl;
        cout<<"1.Insert Element \n2.Display Element \n3.pop \n4.Exit"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cin>>choice;
    switch(choice)
    {
        case 1: cout<<"Enter a number: "<<endl;
                cin>>num;
                top=s1.push(num);
                break;
        case 2:cout<<"Here's Your Stack"<<endl;
                s1.display();
                break;
        case 3:top=s1.pop(top);
                break;
        case 4:break;
        default:cout<<"Invalid Choice!"<<endl;
    }
    }while(choice!=4);
    return 0;
}
