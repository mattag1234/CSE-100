#include <iostream>
#include <vector>
#include <array>
using namespace std;

const int WIDTH = 10; // bad thing i did

void InsertionSort (int arr[], int pos, int n ){
    for (int j = 1; j < n; j++){
        int key[WIDTH];
        for (int k = 0; k < WIDTH; k++)
            key[k] = arr[j * WIDTH + k];
        int i = j -1;

        while(i >= 0 && arr[i * WIDTH + pos]> key[pos]){
            for (int k =0 ; k < WIDTH ; k++)
                arr[(i+1) * WIDTH + k] = arr[i * WIDTH + k];
                i--;
            }
        for (int k = 0; k < WIDTH; k++)
            arr[(i+1) * WIDTH + k] = key[k];
    }
}
 void RadixSort(int arr [], int d, int n) { // where arr is array, d = digits, n - amount of arrays
    for (int pos = (d-1) ; pos >= 0; pos--){ //iterating from all digits i = pos at digit
       InsertionSort(arr, pos, n ); // have insertion sort sort each one
    }
}





int main(){
    int n; // amount of arr
    int d = 10; // digit len
    int input; //input in array

    cin >> n; //grab len of array then declare array 

    int *arr = new int[n * d];
    for (int i = 0; i < n * d; i++)
        cin >> arr[i];

    RadixSort(arr, d, n );
    
    for(int k = 0; k < n ; k++){
        for (int c = 0; c < d; c++)
            cout << arr[k * d + c] << ";";
        cout << "\n";
    }
    
    return 0;

}

   

    