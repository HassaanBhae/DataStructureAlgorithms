#include <iostream>
#include <stdlib.h>
using namespace std;
struct QNode{
  int value;
  QNode *next;
};
QNode *front = NULL;
QNode *rear = NULL;
void enQueue(){
  QNode *ptr = (QNode *)malloc(sizeof(QNode));
  cout<<"Enter Value to Add to Queue:";
  int value;
  cin>>value;
  ptr->value = value;
  ptr->next = NULL;
  if (front == NULL){
    front = ptr;
    rear = ptr;
    return;
  }
  rear->next = ptr;
  rear = ptr;
}
int deQueue(){
  if (front == NULL){
    cout << "Queue is Empty!\n" << endl;
    return 0;
  }
  int value = front->value;
  QNode *curr = front;
  front = front->next;
  free(curr);
  return value;
}

void print(){
  if (front == NULL)
  {
    cout << "Queue is Empty!\n" << endl;
    return;
  }
  QNode *curr = front;
  while (curr != NULL)
  {
    cout << "Value is " << curr->value << endl;
    curr = curr->next;
  }
}

main(){
  while(true){
    cout <<"Press\n[1] enQueue a Value \n[2] deQueue a Value\n[3] Print Stack\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:   
	  enQueue();
    break;
    case 2:
	  cout<<deQueue()<<"\n";
    break;
    case 3:
    print();
    break;
    default:
    break;
    }
    if(press>=4){
      cout <<"Program Ended!";
      break;
    }
  }
}