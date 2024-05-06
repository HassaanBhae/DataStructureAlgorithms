#include <iostream>
using namespace std;
main() {
  int flag=0;
  int numToSearch,arrayLength,numberToAdd;
  cout <<"Enter The Length Of Array:";
  cin >> arrayLength;
  int arr[arrayLength];
  //Adding Numbers To Array
  cout <<"Enter The Numbers To Add In Array:";
  for(int i=0;i<arrayLength;i++){
    cin >>arr[i];
  }
  //Search In Array
  cout <<"Enter The Number To Search In Array:";
  cin >> numToSearch;
  for(int a=0;a<arrayLength;a++){
    if(numToSearch==arr[a]){
      cout<< "value Found at index:"<< a;
      flag=1;
      break;
    }
  }
  if(flag==0){
    cout <<"Value not found.";
  } 
}