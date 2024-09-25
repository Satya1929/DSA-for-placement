#include <bits/stdc++.h>
using namespace std;

// class Solution { //memorization //70. Climbing Stairs
// public:
//     //dp (count all case)
//     int f(int n , vector<int> &dp)
//     {
//         //base case no need to store in dp , just return it
//         // we will store only what we calculate
//         if (n==0) return 1 ;
//         if (n==1) return 1 ;

//         if(dp[n] != -1) return dp[n] ;

//         int c1 = f(n-1,dp) ;
//         int c2 = f(n-2,dp) ;

//         return dp[n] = c1+c2 ;
//     }

//     int climbStairs(int n) {
//         vector<int> dp1(n+1,-1) ;
//         return f(n , dp1) ;
        
//     }
// };


// class Solution { //tabulation //70. Climbing Stairs
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1) ;
//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i=2 ; i<=n ; i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2] ;
//         }

//         return dp[n] ;
        
//     }
// };


class Solution { //tabulation + space optimized //70. Climbing Stairs
public:
    int climbStairs(int n) {
        if (n==0) return 1 ;
        if (n==1) return 1 ;


        int prev2 = 1;
        int prev1 = 1;
        int curi ;

        for(int i=2 ; i<=n ; i++)
        {
            curi = prev1 + prev2 ;
            prev1 = prev2;
            prev2 = curi;
        }

        return curi ;
        
    }
};



//https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=SUBMISSION
//Frog Jump
#include <bits/stdc++.h> 

// int f(int n, vector<int> &h ,vector<int> dp) //memorization
// {
//     if (n==0) return 0 ;
//     if (dp[n]!=-1) return dp[n];

//     int c1 = f(n-1,h,dp) + abs(h[n]-h[n-1]) ;
//     int c2 = f(n-2,h,dp) + abs(h[n]-h[n-2]);
//     return dp[n]=min(c1,c2) ;
// }

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n+1,-1) ;
//     //zero based indexing for eg 6 items is covered in 0 to 5
//     return f(n-1 , heights, dp);
// }



// int frogJump(int n, vector<int> &h) // tabulation
// {
//     vector<int> dp(n+1,-1) ;
//     //zero based indexing for eg 6 items is covered in 0 to 5

//     dp[0] = 0 ;

//     for(int i=1 ; i<=n-1 ; i++)
//     {
//         int c1 = dp[i-1] + abs(h[i]-h[i-1]) ;

//         int c2 = INT_MAX ; // for case n=1 , used to ger min
//         if(i>=2) c2 = dp[i-2] + abs(h[i]-h[i-2]);

//         dp[i]=min(c1,c2) ;
//     }


//     return dp[n-1]; //bcz zero based indexing
// }



int frogJump(int n, vector<int> &h) // tabulation + space optimization
{
    //zero based indexing for eg 6 items is covered in 0 to 5

    int prev1 = 0 ;
    int prev2 = 0 ; 

    int curi = INT_MAX ;
    for(int i=1 ; i<=n-1 ; i++)
    {
        int c1 = prev1 + abs(h[i]-h[i-1]) ;

        int c2 = INT_MAX ; // for case n=1 , used to ger min
        if(i>=2) c2 = prev2 + abs(h[i]-h[i-2]);

        curi=min(c1,c2) ;
        prev2 = prev1 ;
        prev1 = curi ;

    }


    return curi; //bcz zero based indexing
}




//Frog Jump with k distances
//https://www.naukri.com/code360/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
int solveUtil(int ind, vector<int>& h, vector<int>& dp, int k) { // Function to find the minimum cost to reach the end using at most 'k' jumps
    // Base case: If we are at the beginning (index 0), no cost is needed.
    if (ind == 0) return 0;
    
    // If the result for this index has been previously calculated, return it.
    if (dp[ind] != -1) return dp[ind];
    
    int mmSteps = INT_MAX;
    
    // Loop to try all possible jumps from '1' to 'k' (all cases)
    for (int j = 1; j <= k; j++) {
        // Ensure that we do not jump beyond the beginning of the array
        if (ind - j >= 0) {
            // Calculate the cost for this jump and update mmSteps with the minimum cost
            int jump = solveUtil(ind - j, h, dp, k) + abs(h[ind] - h[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    
    // Store the minimum cost for this index in the dp array and return it.
    return dp[ind] = mmSteps;
}

// Function to find the minimum cost to reach the end of the array
int solve(int n, vector<int>& h, int k) {
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n - 1, h, dp, k); // Start the recursion from the last index
}

int minimizeCost(int n, int k, vector<int> &h){
    solve(n,h,k) ;
}


