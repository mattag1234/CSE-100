#include <iostream>
#include <climits>

#define MAX_INT 2147483647

using namespace std;

int maxCrossingSubarray( int arr[], int low, int mid, int high){
    int max_left, max_right;
    int left_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low ; i--){                              // decrements from midpoint to low, then checks the sum values
        sum = sum + arr[i];                                         // replaces left sum if the sum us greater than, and maximum left too.
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    
    int right_sum = INT_MIN; 
    sum = 0;

    for (int j = mid+1; j <= high; j++){                           // increments from mid + 1 to high, checking sum and replacing value
        sum = sum + arr [j];
        if (sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }

    return (max_left, max_right, left_sum + right_sum);
}

int maximumSubarray(int arr[], int low, int high){
    int mid, left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;

    if (high == low) {
        return (low, high, arr[low]);
    }                                                                                   // base case where there is only one element
    else {                                                  
        mid = (low + high) / 2;                                                 
        (left_low, left_high, left_sum) = maximumSubarray(arr ,low , mid);              // finding max subarry on left
        (right_low, right_high, right_sum) = maximumSubarray(arr , mid+1, high);        // finding max subarry on right 
        (cross_low, cross_high, cross_sum) = maxCrossingSubarray(arr, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum)                             // compares left side vs right and must also be less than cross_sum
            return (left_low, left_high, left_sum);                                     
        else if (right_sum >= left_sum && right_sum >= cross_sum){                      // compares with right, left, and corss
            return (right_low, right_high, right_sum);                                  
        }
        else return (cross_low, cross_high, cross_sum);                                 // returns cross values if its max
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

    int max_sum = maximumSubarray(arr, 0, n - 1);
    cout << max_sum;
    return 0;


}


