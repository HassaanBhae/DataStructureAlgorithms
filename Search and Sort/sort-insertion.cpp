#include <iostream>
using namespace std;
void printArr(int arr[],int arrayLength){
    cout <<"Sorted Array:";
    for(int i=0;i<arrayLength;i++){
    cout << arr[i]<<",";
		}
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
//int arrayLength;
  int numToSearch,arrayLength,numToAdd;
  //cout <<"Enter The Length Of Array:";
  //cin >> arrayLength;
  arrayLength=5;
  //int arr[arrayLength];
  ////cout <<"Enter The Numbers To Add In Array:";
  //for(int i=0;i<arrayLength;i++){
    //cin >>arr[i];
  //}
//Choose Sort Algorithm//
  int arr[]={5,2,4,1,7};
  cout <<"Start:";

  insertionSort(arr,arrayLength);
  
}



   
/*Program Exit Code (pogram will exit instantly without showing final output without this code)//
 cout<<"Proccess Finished,Press Any Key To Exit!";
 int ex;
  cin>>ex;    
}*/