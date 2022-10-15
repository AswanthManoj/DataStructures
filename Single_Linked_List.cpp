// Single linked list code written by 20/4001 ASWANTH C M

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to check whether a list is empty
bool isEmpty(node* head){
    return head == 0;
}

// Function to insert an element at head position
void addToHead(node*& head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Function to insert an element at tail position
void addToTail(node*& head, int val){    
    node* n = new node(val);
    if(head->next == NULL){
      head->next = n;
    }else{
      node* temp = head->next;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next=n;
    }
  
}

// Function to find position of an element
int findInfo(node* head, int val){
    int pos = 0;
  
    if(head->next == NULL){
        if(head->data == val){
            return(1);
        }
    }else{
        node* temp = head->next;
        pos=2;
        while(temp->next != NULL && temp->data != val){
          temp = temp->next;
          pos=pos+1;
        }
        if(temp->data == val){
          return(pos);
        }else{
          return(-1);
        }   
    }
}

// Function to delete an element from head
int deleteFromHead(node*& head){
    if (isEmpty(head))
        throw("is empty");

    int info = head->data;
    if(head->next==NULL){
        delete head;
        head = 0;
    }else{
        node *temp;
        temp = head->next;
        delete head;
        head = temp;
    }
    return info;
}

// Function to delete an element from tail
int deleteFromTail(node*& head){
    if (isEmpty(head))
        throw("is empty");
    int info = head->data;
    if(head->next==NULL){
        delete head;
        head = 0;
    }else{
        node *temp, *prev;
        temp = head->next;
        prev = head;
        while(temp->next != NULL){
            temp = temp->next;
            prev = prev->next;
          }
        info = temp->data;
        delete temp;
        prev->next = NULL;
    }
    return info;
}

// Function to delete an element in node by value
int deleteData(node*& head, int val){
    int info;
    if(head != 0){
        if(head->next==NULL && val == head->data){
            info = head->data;
            delete head;
            head=0;
        }else if(val == head->data){
            info = head->data;
            head = head->next;
        }else{
            node *prev, *temp;
            temp = head->next; prev = head;
            while(temp->data != val && temp != 0){
                prev=prev->next;
                temp=temp->next;
            }
            info = temp->data;
            if(temp != 0){
                prev->next = temp->next;
                if (temp->next == NULL)
                    prev->next->next= NULL;
                delete temp;
            }
        }      
    }
    return info;
}

// Function to display elements
void display(node* head){
    node* temp = head;
    cout<<head->data<<" -> ";
    while(temp->next != NULL){
        temp = temp->next;
        cout << temp->data;
        if(temp->next != NULL)
            cout<<" -> ";
    }
    cout<<'\n';
}

int main(){
  
  node* head = NULL;
  addToHead(head,10);
  addToTail(head,20);
  addToTail(head,15);
  addToTail(head,25);
  addToTail(head,35);
  addToTail(head,55);
  addToHead(head,5);
  display(head);
  
  deleteFromHead(head);
  cout<<"\nAfter deleting from head : ";
  display(head);
  
  deleteFromTail(head);
  cout<<"\nAfter deleting from Tail : ";
  display(head);
  
  deleteData(head,20);
  cout<<"\nAfter deleting the element 20 : ";
  display(head);
  
  int pos = findInfo(head,35);
  if(pos==-1){
      cout<<"\nThe element is not found!\n";
  }else{
      cout<<"\nThe element is found at position "<<pos<<'\n';
  }
  return 0;
  
}