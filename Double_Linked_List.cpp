// Doubly linked list code written by 20/4001 Aswanth C M

#include <iostream>
#include <string>
using namespace std;

// Doubly linked list node class
class node{
    public:
        int data;
        node *next, *prev;
    public:
        node(){
            next=prev=0;
        }
            node(int info, node *n = 0, node *p = 0){
            data = info; next = n; prev = p;
        }
};


// Doubly linked list struct with data members head and tail
struct dLList{
    node *head;
    node *tail;
};


// Function to check wheather a list is empty or not;
string isEmpty(dLList &List){
    string info;
    if(List.head == 0){
        info = "empty";
    }else{
        info = "not empty";
    }
    return info;
}


// Function header for adding data to head of the list
void addToHead(dLList &List, int info){
    if(List.head != 0){
        List.head = new node(info, List.head, 0);
        List.head->next->prev = List.head;
    }else{
        List.head = List.tail = new node(info);
    }
}


// Function to add data to tail of the list
void addToTail(dLList &List, int info){
    if(List.tail != 0){
        List.tail = new node(info, 0, List.tail);
        List.tail->prev->next = List.tail;
    }else{
        List.head = List.tail = new node(info);
    }
}


// Function to delete from head of the List
bool deleteFromHead(dLList &List){
  
      if(List.head != 0){
          node *temp = List.head->next;
          temp->prev = 0;
          delete List.head;
          List.head = temp;
          return true;
      }else{
          return false;
      }

}


// Function to delete from tail of the List
bool deleteFromTail(dLList &List){
  
      if(List.tail != 0){
          node *temp = List.tail->prev;
          temp->next = 0;
          delete List.tail;
          List.tail = temp;
          return true;
      }else{
          return false;
      }
}


// Function to delete a data from the list
bool deleteFromList(dLList &List, int info){
    if(List.head != 0){
        if(List.head->data == info){
            deleteFromHead(List);
            return true;
        }
        if(List.tail->data == info){
            deleteFromTail(List);
            return true;
        }
        if(List.head->next != List.tail){
            node *temp = List.head->next;
            while(temp != List.tail){
                if(temp->data == info){
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }else{
          return false;
        } 
    }else{
        return false;
    }
}


// Function to display the list
void display(dLList List){
    if(List.head != 0){
        node *temp;
        temp = List.head;
        cout<<'\n';
        while(temp->next != 0){
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<<temp->data<<'\n';
    }else{
        cout<<"\nThe list is empty!\n";
    }
}


// Function to search for a data in list
int searchFor(dLList List, int info){
      if(List.head != 0){
          if(List.head == List.tail){
              if(List.head->data == info){
                  return 1;
              }else{
                  return -1;
              }
          }else{
              node *nextTemp = List.head;
              node *prevTemp = List.tail;
              while(nextTemp->next != prevTemp){
                  if(nextTemp->data == info || prevTemp->data == info){
                      return 1;
                  }
                  nextTemp = nextTemp->next;
                  prevTemp = prevTemp->prev;
              }
              if(prevTemp->data == info){
                  return 1;
              }else{
                  return -1;
              }
          }
      }else{
          return -1;
      }
}


int main() {
    dLList list;
    cout<<'\n'<<isEmpty(list)<<'\n';
    addToHead(list, 5);
    addToTail(list, 10);
    addToHead(list, 19);
    addToHead(list, 13);
    cout<<'\n'<<isEmpty(list)<<'\n';
    addToTail(list,23);
    addToHead(list, 17);
    if(searchFor(list, 13)){
        cout<<"\nThe data is in the list\n";
    }else{
        cout<<"\nThe data is not in the list\n";
    }
    display(list);
    deleteFromHead(list);
    display(list);
    deleteFromTail(list);
    //deleteFromTail(list);
    //deleteFromTail(list);
    if(searchFor(list, 23)){
        cout<<"\nThe data is in the list\n";
    }else{
        cout<<"\nThe data is not in the list\n";
    }
    display(list);
    cout<<'\n'<<isEmpty(list)<<'\n';
    deleteFromList(list,19);
    display(list);
    return 0;
}