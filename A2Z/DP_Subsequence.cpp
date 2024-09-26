#include <bits/stdc++.h>
using namespace std;


// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt_arr, vector<int> &val_arr) 
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    // we r gong from last index to first index bcz the value_arr is sorted and max value_arr is at the end , hence greedy algo
    if (ind == 0) 
    {
        // If the weight_arr of the first item is less than or equal to `W`, take it
        if (wt_arr[0] <= W) return val_arr[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack_helper(ind-1, W, wt_arr, val_arr);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (wt_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind-1, W - wt_arr[ind], wt_arr, val_arr);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    return max(take, notTake);
}

// Main function to start the knapsack calculation
int knapsack_striver_recursion(vector<int> weight_arr, vector<int> value_arr, int n, int maxWeight)//0-1 knapsack  // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization

    // We start the recursion from the last item (index `n - 1`) with the full weight_arr limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight_arr, value_arr);
    // Write your code here
}














// Function to calculate the maximum value_arr that can be obtained
// with a given weight_arr limit using the first `n` items
int knapsack(vector<int> &weight_arr, vector<int> &value_arr, int ind, int W)//0-1 knapsack  //striver recursion in 1 function (only ideal if not modify to DP (which involves modification of recursion to memorisation and tabulation)
{
    
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    if (ind == 0) 
    {
        // If the weight_arr of the first item is less than or equal to `W`, take it
        if (weight_arr[0] <= W) return value_arr[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack(weight_arr, value_arr, ind - 1, W);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (weight_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = value_arr[ind] + knapsack(weight_arr, value_arr, ind - 1, W - weight_arr[ind]);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    return max(take, notTake);
}

















// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    if (ind == 0) 
    {
        // If the weight_arr of the first item is less than or equal to `W`, take it
        if (wt_arr[0] <= W) return val_arr[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][W] != -1) return dp_matrix[ind][W];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack_helper(ind -1, W, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (wt_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind-1, W - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][W] = max(take, notTake); // store the result first
    return dp_matrix[ind][W];
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








// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt_arr, vector<int> &val_arr) 
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    // we r gong from last index to first index bcz the value_arr is sorted and max value_arr is at the end , hence greedy algo
    if (ind == 0) 
    {
        // just checking how many 
        return ((int)(W/wt_arr[0]))*val_arr[0];
    }

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack_helper(ind-1, W, wt_arr, val_arr);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (wt_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind, W - wt_arr[ind], wt_arr, val_arr);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    return max(take, notTake);
}

// Main function to start the knapsack calculation
int knapsack_striver_recursion(vector<int> weight_arr, vector<int> value_arr, int n, int maxWeight)//Unbounded knapsack  // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization

    // We start the recursion from the last item (index `n - 1`) with the full weight_arr limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight_arr, value_arr);
    // Write your code here
}








// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    if (ind == 0) 
    {
        // just checking how many 
        return ((int)(W/wt_arr[0]))*val_arr[0];
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][W] != -1) return dp_matrix[ind][W];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack_helper(ind -1, W, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (wt_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind, W - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][W] = max(take, notTake); // store the result first
    return dp_matrix[ind][W];
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



















// Function to calculate the maximum value_arr that can be obtained 
// with a given weight_arr limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt_arr, vector<int> &val_arr,vector<vector<int>> &dp_matrix) //striver memo
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight_arr is within the allowed weight_arr `W`
    if (ind == 0) 
    {
        // just checking how many 
        return ((int)(W/wt_arr[0]))*val_arr[0];
    }

    // Check if the value_arr is already computed
    if (dp_matrix[ind][W] != -1) return dp_matrix[ind][W];

    // Recursive case 1: Do not take the current item `ind`
    // The value_arr remains as the result of the previous items (ind - 1) with the same weight_arr limit `W`
    int notTake = 0 + knapsack_helper(ind -1, W, wt_arr, val_arr,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight_arr is less than or equal to the current weight_arr limit `W`)
    if (wt_arr[ind] <= W)
    {
        // If we take the item, add its value_arr to the result of the remaining items with the reduced weight_arr limit
        take = val_arr[ind] + knapsack_helper(ind, W - wt_arr[ind], wt_arr, val_arr, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][W] = max(take, notTake); // store the result first
    return dp_matrix[ind][W];
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