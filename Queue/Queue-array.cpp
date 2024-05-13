#include <iostream>
#include <stdlib.h>
using namespace std;
void enQueue(int queue[],int size,int *front,int *rear){
    if((*rear==size-1 && *front==0)|| (*rear + 1 ==* front)){
        cout<<"Queue Is Full!\n";
    }else{
        cout<<"Enter The Value To enQueue:";
        int value;
        cin>> value;
        if (*front == -1){
            *front = 0;
            *rear = 0;
            queue[*rear] = value;
        return;
        }else{
            if(*rear==size-1 && front !=0){
            rear=0;
            }
            else{
                (*rear)++;
            }
            queue[*rear]=value;
            }
        }
        }

int deQueue(int queue[],int size,int *front,int *rear){
	if(*front==-1 || (*front)>(*rear)){
		cout<<"Queue Is Empty!\n";
        return 0;
	}else{
        int a= queue[*front];
        if((*front)==(*rear) && (*front)!=-1){
            *front=-1;
            *rear=-1;
        }
        if ((*front)==size-1){
            *front=0;
        }else{
        (*front)++;
        }
        return a;
	}
}
void print(int queue[],int size,int *front,int *rear){
  if (*front==-1 || *front>*rear){
    cout << "Queue is Empty!\n" << endl;
    return;
  }else{
  cout << "Queue values are ";
  for (int i = 0; i < size; i++)
  {
    cout << queue[i] << " ";
  }
  cout << endl;
}
}
main(){
  cout<<"Enter Queue Size:";
  int size,front,rear;
  cin>> size;
  front=-1;
  rear=-1;
  int queue[size];
  while(true){
    cout <<"Press\n[1] Push a Value \n[2] Pop a Value\n[3] Print Queue\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:   
	enQueue(queue,size,&front,&rear);
    break;
    case 2:
	cout<<deQueue(queue,size,&front,&rear)<<"\n";
    break;
    case 3:
    print(queue,size,&front,&rear);
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