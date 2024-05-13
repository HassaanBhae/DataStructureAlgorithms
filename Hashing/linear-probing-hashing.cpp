#include <iostream>
using namespace std;
void linearProbInsert(int hashTable[],int value,int hashSize){
  int hashIndex=value % hashSize;
  int startingIndex=hashIndex;
  while(true){
  if(hashTable[hashIndex]==-1){
  hashTable[hashIndex]=value;
  break;
  }else{
    hashIndex++;
    if(hashIndex==hashSize){
      hashIndex=0;
    }
    if(hashIndex==startingIndex){
      cout<<"HashTable is Full!\n";
      break;
    }
  }
  }
}
void linearProbSearch(int hashTable[],int value,int hashSize){
  int hashIndex=value % hashSize;
  int startingIndex=hashIndex;
  while(true){
  if(hashTable[hashIndex]==-1){
  cout<<"Value Not Found in HashTable!"<<hashIndex<<"\n";
  break;
  }
  else if(hashTable[hashIndex]==value){
  cout<<"Value Found at Index:"<<hashIndex<<"\n";
  break;
  }else{
    hashIndex++;
    if(hashIndex==hashSize){
      hashIndex=0;
    }
    if(hashIndex==startingIndex){
      cout<<"Value Not Found in HashTable!";
      break;
    }
  }
  }
}
void linearProbPrint(int hashTable[],int hashSize){
  for (int z=0;z<hashSize;z++){
    cout<<hashTable[z]<<"\n";
  }
}
main(){
  int x;
  int hashSize,value;
  cout <<"Enter The Length Of Hashtable:";
  cin >> hashSize;
  int hashTable[hashSize];
  for(int i=0;i<hashSize;i++){
    hashTable[i]=-1;
  }
  while(true){
    cout <<"Press\n[1] Add a number to the HashTable\n[2] Search in the HashTable\n[3] Print the Hashtable\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:   
    cout <<"Enter The Number To Add In Hashtable:";
    cin >>value;
    linearProbInsert(hashTable,value,hashSize);
    break;
    case 2:
    cout <<"Enter The Number To Search In Hashtable:";
    cin >>value;
    linearProbSearch(hashTable,value,hashSize);
    break;
    case 3:
    linearProbPrint(hashTable,hashSize);
    break;
    default:
    break;
    }
    if(press==4){
      cout <<"Program Ended!";
      break;
    }
  }
}
