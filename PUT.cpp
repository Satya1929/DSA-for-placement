#include <bits/stdc++.h>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//0-1 knapsack
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int maxWeight, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `maxWeight`
    if (ind == 0) 
    {
        // If the weight_arr of the first item is less than or equal to `maxWeight`, take it
        if (wt_arr[0] <= maxWeight) return val_arr[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][maxWeight] != -1) return dp_matrix[ind][maxWeight];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `maxWeight`
    int notTake = 0 + knapsack_helper(ind -1, maxWeight, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `maxWeight`)
    if (wt_arr[ind] <= maxWeight)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind-1, maxWeight - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][maxWeight] = max(take, notTake); // store the result first
    return dp_matrix[ind][maxWeight];
}

// Main function to start the knapsack calculation
int knapsack_striver_memorization(vector<int> weight_arr, vector<int> value_arr, int n, int maxWeight) 
//0-1 knapsack // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization
    vector<vector<int>> dp_matrix(n, vector<int>(maxWeight + 1, -1));

    // We start the recursion from the last item (index `n - 1`) with the full weight_arr limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight_arr, value_arr, dp_matrix);
    // Write your code here
}








//tabulation did
int 01_knapsack_tabulation(vector<int> &wt_arr, vector<int> &val_arr, int n, int maxWeight) {
    // Create a DP table with dimensions (n x (maxWeight + 1))
    vector<vector<int>> dp_matrix(n, vector<int>(maxWeight + 1, 0));

    // Base case: Fill the first row of the table
    // If the weight of the first item is less than or equal to `maxWeight`,
    // then we can take it and the value is the value of the first item
    for (int w = wt_arr[0]; w <= maxWeight; w++) {
        dp_matrix[0][w] = val_arr[0];
    }

    // Fill the DP table in a bottom-up manner
    for (int ind = 1; ind < n; ind++) {
        for (int w = 0; w <= maxWeight; w++) {
            // Case 1: Do not take the current item
            int notTake = dp_matrix[ind - 1][w];

            // Case 2: Take the current item (if possible)
            int take = INT_MIN;
            if (wt_arr[ind] <= w) {
                take = val_arr[ind] + dp_matrix[ind - 1][w - wt_arr[ind]];
            }

            // Store the maximum of the two cases
            dp_matrix[ind][w] = max(take, notTake);
        }
    }

    // The answer is in the bottom-right corner of the DP table
    return dp_matrix[n - 1][maxWeight];
}





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Unbounded knapsack
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int maxWeight, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `maxWeight`
    if (ind == 0) 
    {
        // just checking how many 
        return ((int)(maxWeight/wt_arr[0]))*val_arr[0];
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][maxWeight] != -1) return dp_matrix[ind][maxWeight];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `maxWeight`
    int notTake = 0 + knapsack_helper(ind -1, maxWeight, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `maxWeight`)
    if (wt_arr[ind] <= maxWeight)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind, maxWeight - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][maxWeight] = max(take, notTake); // store the result first
    return dp_matrix[ind][maxWeight];
}

// Main function to start the knapsack calculation
int knapsack_striver_memorization(vector<int> weight_arr, vector<int> value_arr, int n, int maxWeight) 
//0-1 knapsack // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization
    vector<vector<int>> dp_matrix(n, vector<int>(maxWeight + 1, -1));

    // We start the recursion from the last item (index `n - 1`) with the full weight_arr limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight_arr, value_arr, dp_matrix);
    // Write your code here
}







int unboundedKnapsack(int n, int maxWeight, vector<int>& val_arr, vector<int>& wt_arr) { //tabulation
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt_arr[0]; i <= maxWeight; i++) {
        dp[0][i] = (i / wt_arr[0]) * val_arr[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= maxWeight; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt_arr[ind] <= cap)
                taken = val_arr[ind] + dp[ind][cap - wt_arr[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][maxWeight]; // Return the maximum value considering all items and the knapsack capacity
}









//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Unbounded knapsack - ROD CUT
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int maxWeight, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `maxWeight`
    if (ind == 0) 
    {
        // just checking how many 
        return ((int)(maxWeight/wt_arr[0]))*val_arr[0];
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][maxWeight] != -1) return dp_matrix[ind][maxWeight];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `maxWeight`
    int notTake = 0 + knapsack_helper(ind -1, maxWeight, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `maxWeight`)
    if (wt_arr[ind] <= maxWeight)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind, maxWeight - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][maxWeight] = max(take, notTake); // store the result first
    return dp_matrix[ind][maxWeight];
}

// Main function to start the knapsack calculation
int knapsack_striver_memorization(vector<int> weight_arr, vector<int> value_arr, int n, int maxWeight) //0-1 knapsack // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization
    vector<vector<int>> dp_matrix(n, vector<int>(maxWeight + 1, -1));

    // We start the recursion from the last item (index `n - 1`) with the full weight_arr limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight_arr, value_arr, dp_matrix);
    // Write your code here
}

int cutRod(vector<int> &value_arr, int n) //n=rod lenght 
{
    // Rod lengths will be 1 to n, so create an array of lengths
    vector<int> length_arr(n); // = weight_arr
    for (int i = 0; i <= n-1; i++)
    {
        length_arr[i] = i + 1; // Lengths are 1, 2, 3, ..., n
    }

	// weight_arr and value_arr = both n size
	// maxWeight = max lenght = n


    return knapsack_striver_memorization(length_arr, value_arr, n, n);
}









// Function to solve the unbounded knapsack problem
int unboundedKnapsack(int n, int maxWeight, vector<int>& val_arr, vector<int>& wt_arr) { //tabulation for Rod cutting function
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt_arr[0]; i <= maxWeight; i++) {
        dp[0][i] = (i / wt_arr[0]) * val_arr[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= maxWeight; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt_arr[ind] <= cap)
                taken = val_arr[ind] + dp[ind][cap - wt_arr[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][maxWeight]; // Return the maximum value considering all items and the knapsack capacity
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Matrix chain multiplication
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cost(vector<int> &v, int i, int j, vector<vector<int>> &mem_matrix)
{

    // base case
    if (i >= j)
    {
        return 0;
    }

    // FOR MEMORISATION
    // donot calculate cost if it is already stored in matrix
    if (mem_matrix[i][j] != -1) // i.e stored hai value
    {
        return mem_matrix[i][j];
    }

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // most important. two way possible according to video
        //  k = i to j-1 , then break (i to k) (k+1 to j)
        //  k = i+1 to j , then break (i to k-1) (k to j)
        //  always check the edge cases (A)(BCD) and (ABC)(D) should be formed
        int temp = cost(v, i, k, mem_matrix) + cost(v, k + 1, j, mem_matrix) + v[i - 1] * v[k] * v[j];

        // min of all temp costs of all partition
        mini = min(temp, mini);
    }

    mem_matrix[i][j] = mini;
    return mini;
}


int matrixMultiplication(vector<int> &v, int n)
{
    int i = 1;
    int j = n - 1;

    // FOR MEMORISATION
    // intialize 2D vector called mem_matrix with dimensions n by n.
    // Each element in the vector is initialized to -1.
    // Essentially, it creates a square matrix of size n where all elements are set to -1
    vector<vector<int>> mem_matrix(n, vector<int>(n, -1));
    // now pass this matrix to cost function to let the function acces it. otherwise declare this matrix globallly

    return cost(v, i, j, mem_matrix);
}





//tabulation
int matrixMultiplicationTabulation(vector<int> &v, int n) {
    // Create a DP table with dimensions (n x n)
    vector<vector<int>> dp_matrix(n, vector<int>(n, 0));

    // Base case: No cost for multiplying one matrix
    // So, when i == j, dp_matrix[i][i] = 0 (diagonal is 0)

    // Fill the DP table in a bottom-up manner
    for (int length = 2; length < n; length++) {  // length of the chain (starting from 2 matrices)
        for (int i = 1; i < n - length + 1; i++) {  // `i` is the starting index
            int j = i + length - 1;  // `j` is the ending index for the current subproblem
            dp_matrix[i][j] = INT_MAX;

            // Try all possible splits of the chain
            for (int k = i; k < j; k++) {
                // Calculate the cost of multiplying the matrices between i to j
                int cost = dp_matrix[i][k] + dp_matrix[k + 1][j] + v[i - 1] * v[k] * v[j];

                // Update the dp_matrix with the minimum cost
                dp_matrix[i][j] = min(dp_matrix[i][j], cost);
            }
        }
    }

    // The final answer (minimum cost) is stored in dp_matrix[1][n-1]
    return dp_matrix[1][n - 1];
}








//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sorting
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    ///one of left/right willexeed it's limit i.e array finished of that side
    //so now justb copy paste other array (already sorted)

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}



void insertionSort(int arr[], int n)  //striver easy logic
{
    for (int i = 1; i < n; i++) 
    {   // Start from the second element
        for (int j = i; j > 0; j--) 
        {  // Iterate backwards from the current position
            if (arr[j] < arr[j - 1]) 
            { // Compare with the previous element
                swap(arr[j - 1], arr[j]);  // Swap if the previous element is greater
            } 
            else 
            {
                break;  // Stop if the current element is in the right position , iskliye hi while better tha here
            }
        }
    }
}


void bubbleSort(int arr[], int n) {
    
    int did_swap_in_this_pass = 0 ; 
    
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j <= i-1 ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);  
                did_swap_in_this_pass ++ ;
            }
            
        }
        
        if (did_swap_in_this_pass == 0 )
        {
            break ; 
        }
    }
    
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insertion_sort(arr, n);

    cout << "After sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}