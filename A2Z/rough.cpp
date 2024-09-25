
void InsertionSort(int A[], int n) {
    // Outer loop: Start from the second element and iterate through the array
    for (int i = 1; i < n; i++) {
        int key = A[i];  // Store the current element to be inserted into the sorted sub-array
        int j = i - 1;   // Set j to the last index of the sorted sub-array

        // Inner loop: Shift elements of the sorted sub-array that are greater than the key
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];  // Shift the element one position to the right
            j--;  // Move to the previous element
        }

        // Insert the key at its correct position in the sorted sub-array
        A[j + 1] = key;
    }
}




#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum crossing sum using max() function
int maxCrossingSum(vector<int>& arr, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    
    // Find the maximum sum on the left half from mid to low
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum); // using max function
    }

    int right_sum = INT_MIN;
    sum = 0;

    // Find the maximum sum on the right half from mid+1 to high
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum); // using max function
    }

    // Return the maximum possible sum crossing the mid
    return left_sum + right_sum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubarraySum(vector<int>& arr, int low, int high) {
    if (low == high) {
        // Base case: only one element
        return arr[low];
    }

    int mid = (low + high) / 2;

    // Find maximum subarray sum in left half, right half, and crossing the middle
    int left_max = maxSubarraySum(arr, low, mid);
    int right_max = maxSubarraySum(arr, mid + 1, high);
    int cross_max = maxCrossingSum(arr, low, mid, high);

    // Return the maximum of the three
    return max(left_max, max(right_max, cross_max));
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = arr.size();
    int max_sum = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum Subarray Sum is: " << max_sum << endl;

    return 0;
}
