#include <iostream>
#include <vector>
#include <climits>

#define MAX_INT 2147483647

using namespace std;

void merge(int arr[], int p, int q, int r){
    int n_one = q - p + 1;
    int n_two = r - q;
    int leftArr[n_one+1];
    int rightArr[n_two+1];
    for (int i = 0; i < n_one; i++){
        leftArr[i] = arr[p+i];
    }
    for (int k = 0; k < n_two; k++){
        rightArr[k] = arr[(q+1)+k];
    }

    leftArr[n_one]= INT_MAX;
    rightArr[n_two] = INT_MAX;

    int i=0;
    int k=0;

    for (int z = p; z <= r; z++){
        if (leftArr[i] <= rightArr[k]){
            arr[z] = leftArr[i];
            i++;
        }
        else {(arr[z] = rightArr[k]);k++;}
    }
}

void mergesort(int arr[] ,int p ,int r ){                  // first iteration of merge sort
    if (p < r){                                         // checks if p < r
    int q = (p+r)/2;                                     // gets mid of array
    mergesort(arr, p, q);                                // left side
    mergesort(arr,(q+1),r);                              // right side
    merge(arr,p,q,r);                                    // merges both left and right
    }
}
 


int main() {
    int n; // size of array

    int input; //input in array

    cin >> n; //grab len of array then declare array 
    int arr[n]; //empty array

    for (int j=0;j < n; j++){
        cin >> input;
        arr[j] = input; // creates array
        
    }

    int r = n - 1;

    mergesort(arr,0,r);

    for (int i = 0; i < n; i++){
    cout << arr[i]<< ";";}
}

