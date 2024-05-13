#include <iostream>
using namespace std;
void quadraticProbInsert(int hashTable[],int value,int hashSize,int *counter){
  int hashIndex=value % hashSize;
  int startingIndex=hashIndex;
  int i=1;
  while(true){
  if(*counter==hashSize){
    cout<<"Array is Full!";
    break;
  }
  else if(hashTable[hashIndex]==-1){
  hashTable[hashIndex]=value;
  (*counter)++;
  break;
  }else{
    hashIndex=startingIndex+(i*i);
    hashIndex=hashIndex % hashSize;
    i++;
    }
  }
}

void quadraticProbSearch(int hashTable[],int value,int hashSize){
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
  

void quadraticProbPrint(int hashTable[],int hashSize){
  for (int z=0;z<hashSize;z++){
    cout<<hashTable[z]<<"\n";
  }
}
main(){
  int x;
  int counter=0;
  int scounter=0;
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
    quadraticProbInsert(hashTable,value,hashSize,&counter);
    break;
    case 2:
    cout <<"Enter The Number To Search In Hashtable:";
    cin >>value;
    quadraticProbSearch(hashTable,value,hashSize);
    break;
    case 3:
    quadraticProbPrint(hashTable,hashSize);
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
