#include <iostream>
using namespace std;
struct record{
	int rollNo;
  	double GPA;
  	record* next;
  	record* prev;
	int index;
};
int countrecord(record *head){
	if (head==NULL){
    cout << "Record is Empty!\n" << endl;
  }else{
	record *curr=head;
	int count=0;
	while(curr!=NULL){	
	count++;
	curr=curr->next;
	}
    return count;
}
}
void insertRecordsorted(record* *head){
  record *ptr = (record *)malloc(sizeof(record));
  cout << "Enter Roll no of the Student : ";
  cin >> ptr->rollNo;
  cout << "Enter CGPA of Student : ";
  cin >> ptr->GPA;
  if (*head == NULL)
  {
    ptr->next = NULL;
    ptr->index = 0;
    *head = ptr;
    return;
  }
  record *curr = *head;
  if (ptr->rollNo < (*head)->rollNo)
  {
    ptr->next = *head;
    ptr->index = 0;
    *head = ptr;
    while (curr != NULL)
    {
      curr->index++;
      curr = curr->next;
    }
    return;
  }
  record *prev = *head;
  curr = prev->next;
  while (curr != NULL)
  {
    if (ptr->rollNo < curr->rollNo)
    {
      ptr->next = curr;
      ptr->index = (prev->index) + 1;
      prev->next = ptr;
      while (curr != NULL)
      {
        curr->index++;
        curr = curr->next;
      }
      return;
    }
    prev = prev->next;
    curr = curr->next;
  }
  if (curr == NULL)
  {
    ptr->next = NULL;
    ptr->index = (prev->index) + 1;
    prev->next = ptr;
  }
}
void insertRecordFirst(record* *head){
	record* ptr=(record*)malloc(sizeof(record));
	cout<<"Enter RollNO:";
  	cin>>ptr->rollNo;
	cout<<"Enter GPA:";
  	cin>>ptr->GPA;
	ptr->prev=NULL;
	if(*head ==NULL){
		*head=ptr;
		ptr->index=0;
		ptr->next=NULL;
		cout<<"Number Has Been Added!\n";		
		return;
	}else{
  	ptr->next=*head;
	*head=ptr;
	int i=0;
	while(ptr!=NULL){
		ptr->index=i;
		i++;
		ptr=ptr->next;
	}
	cout<<"Number Has Been Added!\n";		
	}
}
void insertRecordLast(record* *head){
  	record* ptr=(record*)malloc(sizeof(record));
	cout<<"Enter RollNO:";
  	cin>>ptr->rollNo;
	cout<<"Enter GPA:";
  	cin>>ptr->GPA;
  	ptr->next=NULL;
  	ptr->prev=NULL;
	if (*head==NULL){
		*head=ptr;
		ptr->index=0;
		cout<<"Number Has Been Added!\n";
		return;
	}else{
		record *curr=*head;
		ptr->index=1;
		while(curr->next!=NULL){
			curr=curr->next;
			ptr->index++;	
		}
		curr->next=ptr;
		ptr->prev=curr;
		cout<<"Number Has Been Added!\n";
	}

}
void printrecord(record *head){
	if (head==NULL){
    cout << "List is Empty!\n" << endl;
    return;
  }else{
	record *curr=head;
	while(curr!=NULL){
		cout<<"RollNO:"<<curr->rollNo<< endl;
		cout<<"GPA:"<<curr->GPA<< endl;
		cout<<"Index:"<<curr->index<< endl;
		curr=curr->next;
	}
  }
}
void searchrecord(record *head){
	if (head==NULL){
	cout << "List is Empty!\n" << endl;
    return;
	}else{
		int toSearch;
		cout<<"Enter the Number to Search:";
		cin>>toSearch;
		record *curr=head;
		while (curr!=NULL){
			if(toSearch==curr->rollNo){
				cout<<"RollNO:"<<curr->rollNo<< endl;
				cout<<"GPA:"<<curr->GPA<< endl;
				cout<<"Index:"<<curr->index<< endl;
				break;
			}
			curr=curr->next;

		}
		if(curr==NULL){
			cout<<"Number Not Found In List!\n";
		}
	}
}
void deleterecord(record **head){
	if (*head==NULL){
	cout << "List is Empty!\n" << endl;
    return;
	}else{
		int toDelete;
		cout<<"Enter the Number to Delete:";
		cin>>toDelete;
		record *curr=*head;
		//Incase ToDelete Is the First Node:
		if(toDelete==(*head)->rollNo){
			//Delete Record Algo
			*head=(*head)->next;
			free(curr);
			curr=*head;
			curr->prev=NULL;
			while(curr!=NULL){
				curr->index--;
				curr=curr->next;
			}
			cout<<"Deleted Succesfully!\n";
			return;
		}else{
		record *temp=*head;
		curr=curr->next;
		while(curr!=NULL){
		if(toDelete==curr->rollNo){
			temp->next=curr->next;
			free(curr);
			curr=temp->next;
			curr->prev=temp;

			while(temp->next!=NULL){
				temp=temp->next;
				temp->index--;
			}
			cout<<"Deleted Succesfully!\n";
			return;
		}else{
			temp=temp->next;
			curr=curr->next;
		}
		}
		}
		if(curr==NULL){
			cout<<"Number Not Found In List!\n";
		}
	
	}
}
void deleteallrecord(record **head){
	if (*head==NULL){
	cout << "List is Empty!\n" << endl;
    return;
	}else{
		record *curr=*head;
		while((*head)!=NULL){
			(*head)=(*head)->next;
			free(curr);
			curr=*head;
			}
		cout<<"Whole Record Deleted!";
		}
	
}
void insertRecordSorted(record **head){

}
main(){
  	record* head=NULL;
    int value;
  while(true){
    cout <<"Press\n[1] Add to the Insert Sorted\n[2] Add to Count the Record\n[3] Search the Record\n[4] Print the Record\n[5] Delete A Record\n[6] Delete Whole Record\n[7] End the Program\n> ";
    cin >> value;
    if(value==1){ 
    insertRecordsorted(&head);
	}
    if(value==2){
    cout<<countrecord(head);
	}
    if(value==3){
    searchrecord(head);
	}
	if(value==4){
    printrecord(head);
	}
	if(value==5){
    deleterecord(&head);
	}
	if(value==6){
    deleteallrecord(&head);
	}
    if(value==7){
      cout <<"Program Ended!";
      break;
    }
  }
}
