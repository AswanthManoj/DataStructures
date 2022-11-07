// Queue as linked list menu driven program written by 20/4001 Aswanth C M
#include <iostream>
using namespace std;

struct node {
   int data;
   struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;

//Function add element at end of queue
void enqueue() {
   int val;
    cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}

//Function remove element from the front of the queue
void dequeue() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}

//Function to display elements of queue
void display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

//Function to check if queue is empty or not
void isEmpty(){
    if (front == NULL)
        cout<<"The queue is empty"<<endl;
    else
        cout<<"The queue is not empty"<<endl;
}

//Function to see the first element of queue
void peek(){
    if (front == NULL)
        cout<<"The queue is empty"<<endl;
    else{
        cout<<"The element at front of the queue is "<<front->data<<endl;
   }
}

int main() {

    cout<<"\nQUEUE AS LINKED LIST\n";
    cout<<"==============\n\n\n";
    cout<<"+--------Options---------+\n";
    cout<<"|                        |\n";
    cout<<"|a.\t\tEnqueue          |\n";
    cout<<"|b.\t\tDequeue          |\n";
    cout<<"|c.\t\tPeek             |\n";
    cout<<"|d.\t\tIs Empty         |\n";
    cout<<"|e.\t\tDisplay          |\n";
    cout<<"+------------------------+\n\n";
  
    bool tryAgain = true;
    while(tryAgain){
        char option;
        cout<<"Enter an option : ";
        cin>>option;
        switch(option) {
            case 'a':
              enqueue();
              break;
            case 'b':
              dequeue();
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