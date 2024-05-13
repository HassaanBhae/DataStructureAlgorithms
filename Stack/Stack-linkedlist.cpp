#include <iostream>
using namespace std;
struct stack{
	int value;
	stack* next;
};
void push(stack* *top){
	stack* ptr=(stack*)malloc(sizeof(stack));
	cout<<"Enter Value to Push:";
  	cin>>ptr->value;
	if(*top==NULL){
		*top=ptr;
		ptr->next=NULL;

	}else{
		ptr->next=*top;
		*top=ptr;
	}
}
int pop(stack** top){
	if(*top==NULL){
		cout<<"Stack Is Empty!\n";
        return 0;
	}else{
		stack* curr=*top;
		int a= (*top)->value;
		*top=(*top)->next;
		free(curr);
		return a;
	}
}
void print(stack *top){
  if (top == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }
  stack *curr = top;
  while (curr != NULL)
  {
    cout << curr->value << "\n";
    curr = curr->next;
  }
}

main(){
	stack* top=NULL;
  while(true){
    cout <<"Press\n[1] Push a Value \n[2] Pop a Value\n[3] Print Stack\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:   
	push(&top);
    break;
    case 2:
	cout<<pop(&top)<<"\n";
    break;
    case 3:
    print(top);
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