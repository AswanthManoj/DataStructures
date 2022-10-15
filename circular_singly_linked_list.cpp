// Circular single linked list code written by 20/4001 ASWANTH C M

#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int value, node *n = 0){
        data = value;
        next = n;
    }
};

struct circularSLList{
    node *head = NULL;
    node *tail = NULL;
};

// Function to check whether the list is empty
bool isEmpty(circularSLList list){
    return (list.head == NULL);
}

// Function to display elements
void display(circularSLList list){
    if(list.head == NULL){
        cout<<"\nThe list is empty\n";
    }else{
        cout<<'\n';
        node *temp = list.head;
        while(temp->next != list.head){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<list.tail->data;
    }
    cout<<'\n';
}

// Function to insert an element at head position
void addToHead(circularSLList &list, int val){
    if(list.head == NULL){
        node *temp = new node(val, list.tail);
        list.head = temp;
        list.tail = list.head;
    }else{
        node *temp = new node(val, list.head);
        list.head = temp;
    }
    list.tail->next = list.head;
}

// Function to insert an element at tail position
void addToTail(circularSLList &list, int val){    
    if(list.tail == NULL){
        node *temp = new node(val, list.head);
        list.tail = temp;
        list.head = list.tail;
        list.tail->next = list.head;
    }else{
        node *temp = new node(val, list.head);
        list.tail->next = temp;
        list.tail = temp;
    }
}

// Function to check wheather an element is in the list
bool isDataInList(circularSLList list, int val){
    if(!isEmpty(list)){
        node *temp = list.head;
        while(temp->next != list.head){
            if(temp->data == val){
                return true;
            }
            temp = temp->next;
        }
        if(temp->data == val){
            return true;
        }else{
            return false;
        }
        
    }else{
        cout<<"The list is empty";
        return false;
    }
}

// Function to delete an element from head
string deleteFromHead(circularSLList &list){
    string info;
    if(!isEmpty(list)){
        info = to_string(list.head->data);
        if(list.head == list.tail){
            delete list.head;
            list.head = NULL;
            list.tail = NULL;
        }else{
            node *temp = list.head->next;
            delete list.head;
            list.head = temp;
            list.tail->next = list.head;
        }
    }else{
        info = "empty";
    }
    return info;
}

// Function to delete an element from tail
string deleteFromTail(circularSLList &list){
    string info;
    if(!isEmpty(list)){
        info = to_string(list.tail->data);
        if(list.head == list.tail){
            delete list.tail;
            list.head = NULL;
            list.tail = NULL;
        }else{
            node *temp = list.head;
            while(temp->next != list.tail){
                temp = temp->next;
            }
            delete list.tail;
            list.tail = temp;
            list.tail->next=list.head;
        }
    }else{
        info = "empty";
    }
    return info;
}

// Function to delete an element in node by value
bool deleteData(circularSLList &list, int val){
    bool isdeleted = false;
    
    if(list.head->data == val){
        deleteFromHead(list);
        isdeleted = true;
    }
    if(list.tail->data == val){
        deleteFromTail(list);
        isdeleted = true;
    }
    if(!isEmpty(list)){
        node *temp = list.head;
        node *prev = list.tail;
        while(temp != list.tail){
            if(temp->data == val){
                prev->next = temp->next;
                isdeleted = true;
            }
            temp = temp->next;
            prev = prev->next;
        }
    }
    return isdeleted;
}


int main(){
    circularSLList List;
    display(List);
    addToHead(List, 5);
    addToTail(List, 3);
    addToHead(List, 10);
    addToTail(List, 7);
    addToTail(List, 13);
    display(List);
  
    if(isDataInList(List, 13)){
        cout<<"The data "<<13<<" is in the list\n";
    }else{
        cout<<"The data "<<13<<" is not in the list\n";
    }
    
    addToTail(List, 17);
    addToHead(List, 19);
    display(List);
    
    if(isDataInList(List, 8)){
        cout<<"The data "<<8<<" is in the list\n";
    }else{
        cout<<"The data "<<8<<" is not in the list\n";
    }
    
    string info = deleteFromHead(List);
    if(info == "empty"){
        cout<<"\nThe list is empty, unable to delete!";
    }else{
        cout<<"\nThe deleted element is "+info;
    }
    display(List);

    info = deleteFromTail(List);
    if(info == "empty"){
        cout<<"\nThe list is empty, unable to delete!";
    }else{
        cout<<"\nThe deleted element is "+info;
    }
    display(List);

    if(deleteData(List, 43)){
        cout<<"\nThe data "<<43<<" has been deleted";
    }else{
        cout<<"\nThe data "<<43<<" not found";
    }
    display(List);
  
    if(deleteData(List, 3)){
        cout<<"\nThe data "<<3<<" has been deleted";
    }else{
        cout<<"\nThe data "<<3<<" not found";
    }
    display(List);
    return 0;
}