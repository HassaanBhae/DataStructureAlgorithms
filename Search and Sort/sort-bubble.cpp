#include <iostream>
using namespace std;
void printArr(int arr[],int arrayLength){
    cout <<"Sorted Array:";
    for(int i=0;i<arrayLength;i++){
    cout << arr[i]<<",";
		}
}
void bubbleSort(int arr[],int arrayLength){
  int i;
  //checks n times
  for(i=0;i<arrayLength;i++){
    //checks all numbs 
    for(int j=0;j<arrayLength-1;j++){
        if(arr[j]>arr[j+1]){
        //Swap Algo
        int s1=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=s1;
        }
    }
  }
  printArr(arr,arrayLength);
  }

main() {
//Input//
  int x;
//int arrayLength;
  int numToSearch,arrayLength,numToAdd;
  cout <<"Enter The Length Of Array:";
  cin >> arrayLength;
  //arrayLength=5;
  int arr[arrayLength];
  cout <<"Enter The Numbers To Add In Array:";
  for(int i=0;i<arrayLength;i++){
    cin >>arr[i];
  }
//Choose Sort Algorithm//
  //int arr[]={5,2,4,1,7};

  bubbleSort(arr,arrayLength);
  
}



   
/*Program Exit Code (pogram will exit instantly without showing final output without this code)//
 cout<<"Proccess Finished,Press Any Key To Exit!";
 int ex;
  cin>>ex;    
}*/