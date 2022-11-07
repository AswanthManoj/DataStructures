 Queue as array menu driven program written by 204001 Aswanth C M
#include iostream
using namespace std;

struct queue{
    int n=100;
    int rear=-1;
    int queue[100];
};

void display(queue q){
    if(q.rear=0){
        coutQueue elements are  ;
        for(int i=q.rear; i=0; i--)
        coutq.queue[i] ;
        coutendl;
    }else
        coutQueue is emptyn;
}

void isFull(queue &q){
    if(q.rear=q.n-1)
        coutQueue is fullendl;
    else
        coutQueue is not fullendl;
}

void isEmpty(queue &q){
    if(q.rear0)
        coutQueue is emptyendl;
    else
        coutQueue is not emptyendl;
}

void enqueue(queue &q, int val){
    if(q.rear=q.n-1)
        coutQueue Overflowendl;
    else{
        q.rear++;
        q.queue[q.rear]=val;
    }
}

void dequeue(queue &q){
    if(q.rear=-1)
        coutQueue Underflowendl;
    else{
        coutThe removed element is  q.queue[0] endl;
        for(int i=0; iq.rear; i++){
            q.queue[i]=q.queue[i+1];
        }
        q.rear--;
   }
}

void peek(queue q){
    if(q.rear=-1)
        coutQueue is emptyendl;
    else{
        coutThe element at front of the queue is  q.queue[0] endl;
   }
}

int main() {

    coutnQUEUE AS ARRAYn;
    cout==============nnn;
    cout+--------Options---------+n;
    cout                        n;
    cout a.tEnqueue          n;
    cout b.tDequeue          n;
    cout c.tPeek             n;
    cout d.tIs Full          n;
    cout e.tIs Empty         n;
    cout f.tDisplay          n;
    cout                        n;
    cout+------------------------+nn;
  
    queue QUEUE;
    bool tryAgain = true;
    while(tryAgain){
        char option;
        coutEnter an option  ;
        cinoption;
        switch(option) {
            case 'a'
              int data;
              coutEnter data to push into the stack  ;
              cindata;
              enqueue(QUEUE, data);
              break;
            case 'b'
              dequeue(QUEUE);
              break;
            case 'c'
              peek(QUEUE);
              break;
            case 'd'
              isFull(QUEUE);
              break;
            case 'e'
              isEmpty(QUEUE);
              break;
            case 'f'
              display(QUEUE);
              break;
            default
              coutnInvalid option!!!;
              tryAgain = false;
        }
    }
    return 0;
}