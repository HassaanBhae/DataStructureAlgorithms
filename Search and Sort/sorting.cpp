#include <iostream>
using namespace std;
//Array Print Function//
void printArr(int arr[],int arrayLength){
  for(int i=0;i<arrayLength;i++){
		cout<< arr[i]<<" ";
		}
  cout<< "\n";
}
void selectionSort(int arr[],int arrayLength){
	int mi,i;
  	for(int j=0;j<arrayLength-1;j++){
		mi=j;
		for(i=j+1;i<arrayLength;i++){
			if (arr[i] < arr[mi]){
			mi=i;
			}		
		}
		int t=arr[j];
		arr[j]=arr[mi];
		arr[mi]=t;
		}
  printArr(arr,arrayLength);
}
void bubbleSort(int arr[],int arrayLength){
  int i;
  for(i=0;i<arrayLength;i++){
    for(int j=0;j<arrayLength-1;j++){
        if(arr[j]>arr[j+1]){
        //Swap Algo
        int s1=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=s1;
        }
    }
  }
    for(int i=0;i<arrayLength;i++){
    cout << arr[i]<<",";
    }
  printArr(arr,arrayLength);
}
void insertionSort(int arr[],int arrayLength){
  int hold;
  for (int mainValueIndex=1;mainValueIndex<arrayLength;mainValueIndex++){
    hold=arr[mainValueIndex];
    int leftValueIndex=mainValueIndex-1;
    while(arr[leftValueIndex] > hold && leftValueIndex>=0){
        arr[leftValueIndex+1]=arr[leftValueIndex];
        leftValueIndex--;
    }
        arr[leftValueIndex+1]=hold;

  }
  printArr(arr,arrayLength);
  }
main() {
//Input//
  int x;
  int numToSearch,arrayLength,numToAdd;
  cout <<"Enter The Length Of Array:";
  cin >> arrayLength;
  int arr[arrayLength];
  cout <<"Enter The Numbers To Add In Array:";
  for(int i=0;i<arrayLength;i++){
    cin >>arr[i];
  }
//Choose Sort Algorithm//
  cout <<"Press 1 for Selection Sort:2 for Bubble Sort:3 for Insertion Sort:";
  int n;
  cin >> n;
  if(n==1){
  	selectionSort(arr,arrayLength);
  }
  else if(n==2){
  	bubbleSort(arr,arrayLength);
  }
  else if (n==3){
  	insertionSort(arr,arrayLength);
  }
  else{
    cout<<"Error:Invalid Number!\n";
  }  
//Program Exit Code (pogram will exit instantly without showing final output without this code)//
 cout<<"Proccess Finished, Press Any Key To Exit!";
 int ex;
 cin>> ex;    
//Main Method Bracked Closing//
}
