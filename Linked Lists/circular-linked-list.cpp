#include <iostream>
using namespace std;

struct record
{
  int data;
  int index;
  record *next;
};

void insertRecordSorted(int value, record **head){
  record *ptr = (record *)malloc(sizeof(record));
  ptr->data = value;
  ptr->index = 0;
  ptr->next = NULL;
  if (*head == NULL){
    *head = ptr;
    (*head)->next = *head;
    return;
  }
  if (ptr->data < (*head)->data){
    record *last = *head;
    do
    {
      last = last->next;
    } while (last->next != *head);

    ptr->next = *head;
    *head = ptr;
    last->next = *head;
    record *curr = (*head)->next;
    while (curr != *head)
    {
      curr->index++;
      curr = curr->next;
    }
    return;
  }
  record *prev = NULL;
  record *curr = *head;
  while (curr->next != *head)
  {
    ptr->index++;
    prev = curr;
    curr = curr->next;
    if (ptr->data < curr->data)
    {
      prev->next = ptr;
      ptr->next = curr;
      while (curr != *head)
      {
        curr->index++;
        curr = curr->next;
      }
      return;
    }
  }
  // if current == null
  ptr->index++;
  curr->next = ptr;
  ptr->next = *head;
}

void insert(int value, record **head)
{
  record *ptr = (record *)malloc(sizeof(record));
  ptr->data = value;
  ptr->index = 0;
  ptr->next = *head;
  if (*head == NULL)
  {
    *head = ptr;
    (*head)->next = *head;
    return;
  }
  record *curr = *head;
  while (curr->next != *head)
  {
    ptr->index++;
    curr = curr->next;
  }
  ptr->index++;
  curr->next = ptr;
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
		do{
			if(toSearch==curr->data){
				cout<<"Value:"<<curr->data<< endl;
				cout<<"Index:"<<curr->index<< endl;
				return;
			}
			else{
				curr=curr->next;
			}
			}while (curr!=head);
		
		cout<<"Number Not Found In List!\n";
	}
}

void printrecord(record *head)
{
  if (head == NULL)
  {
    cout << "List is Empty" << endl;
    return;
  }
  record *curr = head;
  do
  {
    cout << curr->data << " and index is " << curr->index << " ";
    curr = curr->next;
  } while (curr != head);
  cout << endl;
}

void deleterecord(int toDelete, record **head)
{
  if (*head == NULL)
  {
    cout << "List is Empty!" << endl;
    return;
  }
  if ((*head)->data == toDelete && (*head)->next == *head)
  {
    record *curr = *head;
    free(curr);
    *head = NULL;
    cout << "Deleted Successfully " << endl;
    return;
  }
  if ((*head)->data == toDelete)
  {
    record *last = *head;
    do
    {
      last = last->next;
    } while (last->next != *head);
    record *curr = *head;
    *head = (*head)->next;
    free(curr);
    last->next = *head;
    curr = *head;
    do
    {
      curr->index--;
      curr = curr->next;
    } while (curr != *head);

    cout << "Deleted Successfully " << endl;
    return;
  }
  record *prev = *head;
  record *curr = (*head)->next;
  while (curr != *head)
  {
    if (curr->data == toDelete)
    {
      prev->next = curr->next;
      free(curr);
      curr = prev->next;
      while (curr != *head)
      {
        curr->index--;
        curr = curr->next;
      }

      cout << "Deleted Successfully" << endl;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  cout << "Value not Found" << endl;
}

void deleteallrecord(record **head)
{
  if (*head == NULL)
  {
    cout << "list is already empty" << endl;
    return;
  }
  record *last = *head;
  do
  {
    last = last->next;
  } while (last->next != *head);

  record *curr = *head;
  while (curr != last)
  {
    *head = (*head)->next;
    free(curr);
    curr = *head;
  }
  free(*head);
  *head = NULL;
  cout << "Delete whole List Successfully" << endl;
}

int countrecord(record *head)
{
  if (head == NULL)
  {
    return -1;
  }
  int count = 0;
  record *curr = head;
  do
  {
    count++;
    curr = curr->next;
  } while (curr != head);
  return count;
}

main(){
  	record* head=NULL;
    int value;
  while(true){
    cout <<"Press\n[1] Add to the Insert Sorted\n[2] Add to Count the Record\n[3] Search the Record\n[4] Print the Record\n[5] Delete A Record\n[6] Delete Whole Record\n[7] End the Program\n> ";
    cin >> value;
    if(value==1){ 
        cout<<"Enter Value to Insert:";
        cin>>value;
    insertRecordSorted(value,&head);
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
        cout<<"Enter Value to Delete:";
        cin>>value;
    deleterecord(value,&head);
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
