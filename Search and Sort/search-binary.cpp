#include <iostream>
using namespace std;
main() {
//Input//
  int numToSearch,arrayLength,numToAdd;
  cout <<"Enter The Length Of Array:";
  cin >> arrayLength;
  int arr[arrayLength];
  cout <<"Enter The Numbers To Add In Array:";
  for(int i=0;i<arrayLength;i++){
    cin >>arr[i];
  }
  cout <<"Enter The Number To Search In Array:";
  cin >> numToSearch;
//Binary Search Algorithm//
  int Left=0;
  int Right=arrayLength-1;
  int middle=(Left+Right)/2;
  while(true){
    if(Left>Right){
      cout<<"Value Not Found!\n";
      break;
    }
    if(numToSearch==arr[middle]){
      cout <<"Value Found At Index: "<< middle<<endl;
      break;
    }
    else if(numToSearch<arr[middle]){
        Right=middle-1;
        middle=(Left+Right)/2;
    }
    else{
        Left=middle+1;
        middle=(Left+Right)/2;
    }
  }
//Program Exit Code (pogram will exit instantly without showing final output without this code)//
  cout<<"Proccess Finished,Press Any Key To Exit!";
  int exit;
  cin>>exit;    
}