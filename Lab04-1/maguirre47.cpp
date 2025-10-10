#include <iostream>
#include <climits>

#define MAX_INT 2147483647

using namespace std;

int left(int i) { return 2 * i + 1;}
int right(int i) { return 2 * i + 2;}

void maxHeapify( int arr[], int i, int heapSize ){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && arr[l] > arr[i]){
        largest = l;
    }
    else largest = i;
    if (r < heapSize && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, heapSize);
    
        }
    }

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; --i)
        maxHeapify(arr, i, n);
}
   
void heapSort( int arr[], int heapSize){
    buildMaxHeap(arr, heapSize);
    for(int i = heapSize-1; i > 0; i--){ // after sorted, root is sent to end and finds the next largest by calling maxHeap again.
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, 0, i);
    }
}




int main() {
    int n; // size of array

    int input; //input in array

    cin >> n; //grab len of array then declare array 
    int arr[n]; //empty array

    for (int k=0;k < n; k++){
        cin >> input;
        arr[k] = input; // creates array
    }

    heapSort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << ";";
    }
    return 0;
    


}


