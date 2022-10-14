//Stack as linked list code written by 20/4001 Aswanth C M
#include <iostream>
using namespace std;

struct node{
    int data;
    node *link;
};
node *top;

//Function to check if stack is empty or not
bool isempty(){
    return (top == NULL);
}

//Function to push an element in stack
void push (int value){
    node *ptr = new node();
    ptr->data = value;
    ptr->link = top;
    top = ptr;
}

//Function to pop an element from the stack
void pop (){
    if ( isempty() )
        cout<<"Stack is Empty\n";
    else{
        node *ptr = top;
        top = top -> link;
        delete(ptr);
    }
}

// Function to show the element at the top of the stack
void peek(){
  if ( isempty() )
      cout<<"Stack is Empty\n";
  else
      cout<<"Element at top is : "<< top->data<<'\n';
}

// Function to Display the stack
void display(){
    if ( isempty() )
        cout<<"Stack is Empty\n";
    else{
        node *temp=top;
        while(temp!=NULL){   
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    cout<<"\n";
    }
}

void isEmpty(){
    if (isempty())
        cout<<"The stack is empty\n";
    else
        cout<<"The stack is not empty\n";
}

int main() {

    cout<<"\nSTACK AS ARRAY\n";
    cout<<"==============\n\n\n";
    cout<<"+--------Options---------+\n";
    cout<<"|                        |\n";
    cout<<"| a.\t\tpush         |\n";
    cout<<"| b.\t\tpop          |\n";
    cout<<"| c.\t\tpeek         |\n";
    cout<<"| d.\t\tisEmpty      |\n";
    cout<<"| e.\t\tdisplay      |\n";
    cout<<"|                        |\n";
    cout<<"+------------------------+\n\n";
  
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
              push(data);
              break;
            case 'b':
              pop();
              break;
            case 'c':
              peek();
              break;
            case 'd':
              isEmpty();
              break;
            case 'e':
              display();
              break;
            default:
              cout<<"\nInvalid option!!!";
              tryAgain = false;
        }
    }
    return 0;
}