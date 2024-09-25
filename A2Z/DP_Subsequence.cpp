#include <bits/stdc++.h>
using namespace std;


// Function to calculate the maximum value that can be obtained 
// with a given weight limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt, vector<int> &val) 
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight is within the allowed weight `W`
    // we r gong from last index to first index bcz the value is sorted and max value is at the end , hence greedy algo
    if (ind == 0) 
    {
        // If the weight of the first item is less than or equal to `W`, take it
        if (wt[0] <= W) return val[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Recursive case 1: Do not take the current item `ind`
    // The value remains as the result of the previous items (ind - 1) with the same weight limit `W`
    int notTake = 0 + knapsack_helper(ind-1, W, wt, val);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight is less than or equal to the current weight limit `W`)
    if (wt[ind] <= W)
    {
        // If we take the item, add its value to the result of the remaining items with the reduced weight limit
        take = val[ind] + knapsack_helper(ind-1, W - wt[ind], wt, val);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    return max(take, notTake);
}

// Main function to start the knapsack calculation
int knapsack_striver_recursion(vector<int> weight, vector<int> value, int n, int maxWeight) // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization

    // We start the recursion from the last item (index `n - 1`) with the full weight limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight, value);
    // Write your code here
}














// Function to calculate the maximum value that can be obtained
// with a given weight limit using the first `n` items
int knapsack(vector<int> &weight, vector<int> &value, int ind, int W)  //striver recursion in 1 function (only ideal if not modify to DP (which involves modification of recursion to memorisation and tabulation)
{
    
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight is within the allowed weight `W`
    if (ind == 0) 
    {
        // If the weight of the first item is less than or equal to `W`, take it
        if (weight[0] <= W) return value[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Recursive case 1: Do not take the current item `ind`
    // The value remains as the result of the previous items (ind - 1) with the same weight limit `W`
    int notTake = 0 + knapsack(weight, value, ind - 1, W);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight is less than or equal to the current weight limit `W`)
    if (weight[ind] <= W)
    {
        // If we take the item, add its value to the result of the remaining items with the reduced weight limit
        take = value[ind] + knapsack(weight, value, ind - 1, W - weight[ind]);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    return max(take, notTake);
}

















// Function to calculate the maximum value that can be obtained 
// with a given weight limit using the first `ind + 1` items
int knapsack_helper(int ind, int W, vector<int> &wt, vector<int> &val,vector<vector<int>> &dp_matrix) 
{
    // Base case: If we are at the first item (index 0)
    // We can only take this item if its weight is within the allowed weight `W`
    if (ind == 0) 
    {
        // If the weight of the first item is less than or equal to `W`, take it
        if (wt[0] <= W) return val[0];
        // Otherwise, we can't take it, so return 0
        return 0;
    }

    // Check if the value is already computed
    if (dp_matrix[ind][W] != -1) return dp_matrix[ind][W];

    // Recursive case 1: Do not take the current item `ind`
    // The value remains as the result of the previous items (ind - 1) with the same weight limit `W`
    int notTake = 0 + knapsack_helper(ind -1, W, wt, val,dp_matrix);

    // Recursive case 2: Take the current item `ind`
    // Initialize `take` as a very small number (negative infinity) to represent that we can't take it initially
    int take = INT_MIN;

    // Check if the current item can be taken (i.e., its weight is less than or equal to the current weight limit `W`)
    if (wt[ind] <= W)
    {
        // If we take the item, add its value to the result of the remaining items with the reduced weight limit
        take = val[ind] + knapsack_helper(ind-1, W - wt[ind], wt, val, dp_matrix);
    }

    // Return the maximum of the two cases: taking or not taking the current item
    dp_matrix[ind][W] = max(take, notTake); // store the result first
    return dp_matrix[ind][W];
}

// Main function to start the knapsack calculation
int knapsack_striver_memorization(vector<int> weight, vector<int> value, int n, int maxWeight) // write in 2 function bcz it is neeeded to modify this into "memorisation" and then "tabulation"
{
    //initialize here the dp for memorization
    vector<vector<int>> dp_matrix(n, vector<int>(maxWeight + 1, -1));

    // We start the recursion from the last item (index `n - 1`) with the full weight limit `maxWeight`
    return knapsack_helper(n - 1, maxWeight, weight, value, dp_matrix);
    // Write your code here
}



