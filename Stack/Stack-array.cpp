#include <iostream>
using namespace std;

void push(int stack[],int size,int *top){
    if(*top==size-1){
        cout<<"Stack Overflow!\n";
    }else{
        cout<<"Enter The Value To Push:";
        int value;
        cin>> value;
        *top=*top+1;
        stack[*top]=value;
    }
}
int pop(int stack[],int size,int *top){
	if(*top==-1){
		cout<<"Stack Is Empty!\n";
        return 0;
	}else{
        int temp= stack[*top];
        (*top) --;
        return temp;
	}
}
void print(int stack[],int size,int *top){
  if (*top ==-1){
    cout << "Stack is Empty!\n" << endl;
    return;
  }else{
    while(*top!=-1){
    cout<<stack[*top]<<"\n";
    (*top)--;
    }
  }

}
main(){
  cout<<"Enter Stack Size:";
  int size,top;
  cin>> size;
  top=-1;
  int stack[size];
  while(true){
    cout <<"Press\n[1] Push a Value \n[2] Pop a Value\n[3] Print Stack\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:   
	push(stack,size,&top);
    break;
    case 2:
	cout<<pop(stack,size,&top)<<"\n";
    break;
    case 3:
    print(stack,size,&top);
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