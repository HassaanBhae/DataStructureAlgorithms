#include <iostream>
#include <stdlib.h>
using namespace std;
void upHeapify(int arr[], int ci){
  int pi = (ci - 1) / 2;
  while (arr[ci] < arr[pi]){
    int tmp = arr[ci];
    arr[ci] = arr[pi];
    arr[pi] = tmp;
    ci = pi;
    if (ci == 0)
      break;
    pi = (ci - 1) / 2;
  }
}
void insert(int arr[], int value, int size){
  for (int i = 0; i < size+1; i++){
    if (arr[i] == -1){
      arr[i] = value;
      if (i != 0){
        upHeapify(arr, i);
      }

      break;
    }
    if(i==size){
  cout<<"Heap Is Full!\n";
    }
  }
}
void downHeapify(int arr[], int pi, int size)
{
  int lc = 2 * pi + 1;
  int rc = 2 * pi + 2;
  if (lc >= size)
  {
    return;
  }
  if (rc >= size)
  {
    if (arr[pi] < arr[lc])
    {
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
    }
    return;
  }
  while (arr[pi] < arr[lc] || arr[pi] < arr[rc])
  {
    if (arr[lc] > arr[rc])
    {
      int tmp = arr[lc];
      arr[lc] = arr[pi];
      arr[pi] = tmp;
      pi = lc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (lc >= size)
      {
        break;
      }
      if (rc >= size)
      {
        if (arr[pi] < arr[lc])
        {
          int tmp = arr[lc];
          arr[lc] = arr[pi];
          arr[pi] = tmp;
        }
        break;
      }
    }
    else
    {
      int tmp = arr[rc];
      arr[rc] = arr[pi];
      arr[pi] = tmp;
      pi = rc;
      lc = 2 * pi + 1;
      rc = 2 * pi + 2;
      if (lc >= size)
      {
        break;
      }
      if (rc >= size)
      {
        if (arr[pi] < arr[lc])
        {
          int tmp = arr[lc];
          arr[lc] = arr[pi];
          arr[pi] = tmp;
          break;
        }
      }
    }
  }
}
void deleteData(int arr[], int &size){
    if (size == 0){
        cout << "Heap is Empty!\n";
        return;
    }
    arr[0] = arr[size - 1]; 
    arr[size - 1] = -1;      
    size--;                  
    if (size > 0){
        downHeapify(arr, 0, size); 
    }
    cout << "Value deleted successfully!\n";
}
void heapSort(int arr[], int size){
  for (int i = 1; i < size; i++){
    for (int j = size - i; j >= 0; j--){
      if (arr[j] != -1){
        int tmp = arr[j];
        arr[j] = arr[0];
        arr[0] = tmp;
        downHeapify(arr, 0, j);
        break;
      }
    }
  }
}
main(){
  cout<<"Enter Array Size:";
  int size,top;
  cin>> size;
  top=-1;
  int maxHeap[size];
  for (int i = 0; i < size; i++){
    maxHeap[i] = -1;
  }
  while(true){
    cout <<"Press\n[1] Insert a Value \n[2] Delete a Value\n[3] Print Array\n[4] Apply HeapSort\n[5] End the Program\n> ";
    int press;
    cin>>press;
    switch (press) {
    case 1:
      int value;
      cout << "Enter Value To Insert:";
      cin >> value;   
      insert(maxHeap, value, size);
    break;
    case 2:
      deleteData(maxHeap, size);
    break;
    case 3:
      for (int i = 0; i < size; i++){
        cout << maxHeap[i] << " ";
      }
      cout << endl;
    break;
    case 4:
        heapSort(maxHeap,size);
    break;
    default:
    break;
    }
    if(press>=5){
      cout <<"Program Ended!";
      break;
    }
  }
}
