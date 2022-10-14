// Stack as array menu driven program written by 20/4001 Aswanth C M
#include <iostream>
using namespace std;

struct stack{
    int n=100;
    int top=-1;
    int stack[100];
};

void push(stack &st, int val){
    if(st.top>=st.n-1)
        cout<<"Stack Overflow"<<endl;
    else{
        st.top++;
        st.stack[st.top]=val;
    }
}

void pop(stack &st){
    if(st.top<=-1)
        cout<<"Stack Underflow"<<endl;
    else{
        cout<<"The popped element is "<< st.stack[st.top] <<endl;
        st.top--;
   }
}

void display(stack st){
    if(st.top>=0){
        cout<<"Stack elements are : ";
        for(int i=st.top; i>=0; i--)
        cout<<st.stack[i]<<" ";
        cout<<endl;
    }else
        cout<<"Stack is empty";
}

void peek(stack st){
    if(st.top<=-1)
        cout<<"Stack Underflow"<<endl;
    else{
        cout<<"The top of the stack element is "<< st.stack[st.top] <<endl;
   }
}

void isFull(stack &st){
    if(st.top>=st.n-1)
        cout<<"Stack is full"<<endl;
    else
        cout<<"Stack is not full"<<endl;
}

void isEmpty(stack &st){
    if(st.top<0)
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;
}

int main() {

    cout<<"\nSTACK AS ARRAY\n";
    cout<<"==============\n\n\n";
    cout<<"+--------Options---------+\n";
    cout<<"|                        |\n";
    cout<<"| a.\t\tpush         |\n";
    cout<<"| b.\t\tpop          |\n";
    cout<<"| c.\t\tpeek         |\n";
    cout<<"| d.\t\tisFull       |\n";
    cout<<"| e.\t\tisEmpty      |\n";
    cout<<"| f.\t\tdisplay      |\n";
    cout<<"|                        |\n";
    cout<<"+------------------------+\n\n";
  
    stack Stack;
    bool tryAgain = true;
    while(tryAgain){
        char option;
        cout<<"Enter an option : ";
        cin>>option;
        switch(option) {
            case 'a':
              int data;
              cout<<"Enter data to push into the stack : ";
              cin>>data;
              push(Stack, data);
              break;
            case 'b':
              pop(Stack);
              break;
            case 'c':
              peek(Stack);
              break;
            case 'd':
              isFull(Stack);
              break;
            case 'e':
              isEmpty(Stack);
              break;
            case 'f':
              display(Stack);
              break;
            default:
              cout<<"\nInvalid option!!!";
              tryAgain = false;
        }
    }
    return 0;
}