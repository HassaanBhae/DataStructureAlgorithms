#include <iostream>
#include <stdlib.h>
using namespace std;
void cHeapify(int arr[], int ci){
  int pi = (ci - 1) / 2;
  while (arr[ci] < arr[pi]){
    int tmp = arr[ci];
    arr[ci] = arr[pi];
    arr[pi] = tmp;
    ci = pi;
    if (ci == 0){
      break;
    }
    pi = (ci - 1) / 2;
  }
}
int max(int a, int b){
  return a > b ? a : b;
}

void insert(int arr[], int value, int size){
  for (int i = 0; i < size+1; i++){
    if (arr[i] == -1){
      arr[i] = value;
      if (i != 0){
        cHeapify(arr, i);
      }

      break;
    }
    if(i==size){
  cout<<"Heap Is Full!\n";
    }
  }
}
void dHeapify(int arr[], int pi, int size){
  int lc = 2 * pi + 1;
  int rc = 2 * pi + 2;
  while (arr[pi] > arr[lc] || arr[pi] > arr[rc]){
    if (arr[lc] < arr[rc]){
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
      pi = lc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (rc >= size || lc >= size){
        break;
      }
    }else{
      int tmp = arr[rc];
      arr[rc] = arr[pi];
      arr[pi] = tmp;
      pi = rc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (rc >= size || lc >= size){
        break;
      }
    }
  }
}
void deleteData(int arr[], int size){
    if (arr[0] == -1) {
        cout << "Heap is Empty!\n";
        return;
    }
    arr[0] = arr[size - 1];
    arr[size - 1] = -1;
    dHeapify(arr, 0, size - 1);
    cout << "Value deleted successfully!\n";
}
main(){
  cout<<"Enter Array Size:";
  int size,top;
  cin>> size;
  top=-1;
  int minHeap[size];
  for (int i = 0; i < size; i++){
    minHeap[i] = -1;
  }
  while(true){
    cout <<"Press\n[1] Insert a Value \n[2] Delete a Value\n[3] Print Array\n[4] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:
      int value;
      cout << "Enter Value To Insert:";
      cin >> value;   
      insert(minHeap, value, size);
    break;
    case 2:
      deleteData(minHeap, size);
    break;
    case 3:
      for (int i = 0; i < size; i++){
        cout << minHeap[i] << " ";
      }
      cout << endl;
    break;
    default:
    break;
    }
    if(press>=4){
      cout <<"Program Ended!";
      break;
    }
  }
}
