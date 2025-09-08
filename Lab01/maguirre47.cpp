#include <iostream>
#include <vector>

#define MAX_INT 2147483647

using namespace std;

int main() {
    int n; // size of array
    int i; // j-1 pos
    int key;

    int input; //input in array

    cin >> n; //grab len of array then declare array 
    int arr[n]; //empty array

    for (int j=0;j < n; j++){
        cin >> input;
        arr[j] = input;
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
        if (j >=1){
            for(int t=0; t <= j; t++){
                cout << arr[t] << ";" ;
            }
            cout << endl;
        }

    
        

    }

    return 0;
}