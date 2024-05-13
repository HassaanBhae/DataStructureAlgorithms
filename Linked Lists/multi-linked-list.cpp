#include <iostream>
using namespace std;
struct student{
	int studentId;
	student *nextStudent;
};
struct course{
	int courseId;
	student *studentHead;
	course *nextCourse;
};
void addCourse(course** courseHead){
	course* ptr=(course*)malloc(sizeof(course));
	cout<<"Enter Course ID:";
	cin>>ptr->courseId;
	ptr->nextCourse=NULL;
	ptr->studentHead=NULL;
	if(*courseHead==NULL){
		*courseHead=ptr;
		cout<<"Course Has Been Added!\n";
		return;
	}else{
		course* curr=*courseHead;
		while(curr->nextCourse!=NULL){
			curr=curr->nextCourse;
		}
		curr->nextCourse=ptr;
		cout<<"Course Has Been Added!\n";
		return;
	}
}
void searchCourse(course * courseHead){
	if (courseHead==NULL){
    cout << "List is Empty!\n" << endl;
    return;
	}
	else{
		int toSearch;
		cout <<"Enter Course Id To Search:";
		cin>>toSearch;
		course *curr=courseHead;
		while(curr!=NULL){
			if(curr->courseId==toSearch){
				cout<<"Course Found In list!\n";
				return;
			}else{
				curr=curr->nextCourse;
			}
		}
		cout<<"Course Not Found In Course List!\n";
	}
}
void deleteCourse(course ** courseHead){
	if (courseHead==NULL){
		cout <<"Course List Is Empty!";
	}
	else{
		int toDelete;
		cout <<"Enter Course Id To Delete:";
		cin>>toDelete;
		course *curr=*courseHead;
		if((*courseHead)->courseId==toDelete){
			*courseHead=(*courseHead)->nextCourse;
			free(curr);
			cout<<"Course Deleted Successfully!\n";
			return;
		}else{
		course *prev=*courseHead;
		curr=curr->nextCourse;
		while(curr!=NULL){
		if(curr->courseId==toDelete){
			prev->nextCourse=curr->nextCourse;
			free(curr);
			cout<<"Course Deleted Successfully!\n";
			return;
		}else{
			prev=prev->nextCourse;
			curr=curr->nextCourse;
		}
		}
		cout<<"Course Not Found In Course List";
		}
	}
}
void deleteAllCourse(course **courseHead){
	if (courseHead==NULL){
		cout <<"Course List Is Empty!";
	}else{
		course * curr=*courseHead;
		while((*courseHead)!=NULL){
			(*courseHead)=(*courseHead)->nextCourse;
			free(curr);
			curr=*courseHead;
		}
		cout<<"All Courses Deleted!\n";
	}
}
void addStudentToCourse(course *courseHead){
	if (courseHead==NULL){
    cout << "List is Empty!\n" << endl;
    return;
	}
	else{
	student* ptr=(student*)malloc(sizeof(student));
	cout<<"Enter Course Id to Add Student In:";
	int toAdd;
	cin>>toAdd;
	cout<<"Enter Student Id:";
	cin>>ptr->studentId;
	ptr->nextStudent=NULL;
	//FInd COurse
	course *curr=courseHead;
	while(curr!=NULL){
		//IF Course Found
		if(toAdd==curr->courseId){
			//IF NO STUDENT
			if(curr->studentHead==NULL){
			curr->studentHead=ptr;
			cout<<"Student Added SuccessFully!\n";
			return;
			//IF STUDENTS PRESENT THEN TRAVERSE THROGH STUDNTS
			}else{
				student *currStudent=curr->studentHead;
				while(currStudent->nextStudent!=NULL){
					currStudent=currStudent->nextStudent;
				}
				currStudent->nextStudent=ptr;
			    cout<<"Student Added SuccessFully!\n";
				return;
			}
		//ELse KEEP SEARCHIN COURSES
		}else{
			curr=curr->nextCourse;
		}
	}
	cout<<"Course Not Found In Course List!\n";
	}
}
void searchStudentInCourse(course *courseHead){
	if(courseHead==NULL){
		cout<<"Course List IS Empty!\n";
		return;
	}else{
	int toSearch,counter;
	counter=0;
	course *curr=courseHead;
	while(curr!=NULL){
	cout<<"Enter Student ID to Search:";
	cin>>toSearch;
	student *currStudent=curr->studentHead;
	while(currStudent!=NULL){
		if(currStudent->studentId==toSearch){
		cout<<"Student Found in Course No:"<<curr->courseId<<"\n";
		counter++;
		}
		currStudent=currStudent->nextStudent;
		}
	curr=curr->nextCourse;
	}
	if(counter==0){
	cout<<"Student Not Found In Any Course!\n";
	}
	}
}
void deleteStudentInCourse(course *courseHead){
	if(courseHead==NULL){
		cout<<"Course List IS Empty!\n";
		return;
	}else{
	int toSearch,courseId;
	cout<<"Enter Student ID to Delete:";
	cin>>toSearch;
	cout<<"Enter Course ID to Delete Student From:";
	cin>>courseId;
	course *curr=courseHead;
	while(curr!=NULL){
		//IF Course Found
		if(courseId==curr->courseId){
			if(curr->studentHead->studentId==toSearch){
				student *currStudent=curr->studentHead;
				curr->studentHead=curr->studentHead->nextStudent;
				free(currStudent);
				cout<<"Student Deleted SuccessFully!\n";
				return;
			}else{
				student *currStudent=curr->studentHead;
				student *prevStudent=curr->studentHead;
				currStudent=currStudent->nextStudent;
				while(currStudent!=NULL){
					if(currStudent->studentId==toSearch){
						prevStudent->nextStudent=currStudent->nextStudent;
						free(currStudent);
						cout<<"Student Deleted SuccessFully!\n";
						return;
					}
					currStudent=currStudent->nextStudent;
					prevStudent=prevStudent->nextStudent;
				}
			}
		//ELse KEEP SEARCHIN COURSES
		}else{
			curr=curr->nextCourse;
		}
	}
	cout<<"Student Not Found In Course List!\n";
	}
}
void deleteStudent(course *courseHead){
	if(courseHead==NULL){
		cout<<"Course List IS Empty!\n";
		return;
	}else{
	int toSearch,counter;
	counter=0;
	cout<<"Enter Student ID to Delete:";
	cin>>toSearch;
	course *curr=courseHead;
	while(curr!=NULL){
			if(curr->studentHead->studentId==toSearch){
				student *currStudent=curr->studentHead;
				curr->studentHead=curr->studentHead->nextStudent;
				free(currStudent);
				counter++;
			}else{
				student *currStudent=curr->studentHead;
				student *prevStudent=curr->studentHead;
				currStudent=currStudent->nextStudent;
				while(currStudent!=NULL){
					if(currStudent->studentId==toSearch){
						prevStudent->nextStudent=currStudent->nextStudent;
						free(currStudent);
						counter++;
					}
					currStudent=currStudent->nextStudent;
					prevStudent=prevStudent->nextStudent;
				}
			}
			curr=curr->nextCourse;
		}
		if(counter==0){
		cout<<"Student Not Found In Any Course!\n";
		}else{
			cout<<"Student Deleted SuccessFully!\n";
		}
	}
}


main(){
  	course* courseHead=NULL;
    int value;
  	while(true){
    cout <<"Press\n[1] Insert A course\n[2] Search A Course\n[3] Delete A Course\n[4] Add Student To Course\n[5] Search Student In A Course\n[6] Delete All Courses\n[7] Delete Student In A Course\n[8] Delete Student\n[9] End the Program\n> ";
    cin >> value;
    if(value==1){ 
    addCourse(&courseHead);
	}
    if(value==2){
    searchCourse(courseHead);
	}
    if(value==3){
    deleteCourse(&courseHead);
	}
	if(value==4){
    addStudentToCourse(courseHead);
	}
	if(value==5){
    searchStudentInCourse(courseHead);
	}
	if(value==6){
    deleteAllCourse(&courseHead);
	}
	if(value==7){
    deleteStudentInCourse(courseHead);
	}
	if(value==8){
    deleteStudent(courseHead);
	}
    if(value==9){
      cout <<"Program Ended!";
      break;
    }
  }
}
