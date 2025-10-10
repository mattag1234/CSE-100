#include <iostream>
using namespace std;

int partition(int arr[], int p, int r){ // this is the pivot function that will rearrange the subarray in place
    int x = arr[r]; 
    int i = p - 1; 
    for(int j = p; j <= r-1; j++){
        if(arr[j] <= x){ // if the current element is smaller than the pivot we increment the index of smaller element
            i++;
            int temp = arr[i]; // swap smaller element with current element
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1]; // swap right of smaller element index and the right of it
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quickSort(int arr[], int p, int r){ 
    if(p < r){ 
        int q = partition(arr, p, r); 
        quickSort(arr, p, q-1); // recursivly sorts bottom half
        quickSort(arr, q+1, r); // recursivly sorts upper half
    }
}

int main(){
    int n; // size of array

    int input; //input in array

    cin >> n; //grab len of array then declare array 
    int arr[n]; //empty array

    for (int k=0;k < n; k++){
        cin >> input;
        arr[k] = input; // creates array
    }


    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << ";";
    }
    return 0;
    
}

   

    