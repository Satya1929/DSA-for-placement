#include <bits/stdc++.h>
using namespace std;

// class Solution { //746. Min Cost Climbing Stairs , only recursion
// public:
//     //all possible count = recursion
//     //overlapping so DP
//     //step 1 - represent in terms of index = zero based index
//     //all cases incorporate
//     //min find of them (use basic formula by striver)

//     int f(int index ,vector<int>& cost)
//     {
//         //base case of recursion (input less hote jayega , top-down)
//         if (index == 0) return cost[0] ;
//         if (index == 1) return cost[1] ;

//         int c1 = f(index-1 , cost) + cost[index] ;
//         int c2 = f(index-2 , cost ) + cost[index] ;

//         return min(c1,c2) ;
//     }


//     int minCostClimbingStairs(vector<int>& cost) {
//         int index = cost.size() ;
//         //  You can reach the top by either stepping from the last step (cost[n-1]) or the second last step (cost[n-2]), so you need to calculate the minimum cost between those two.
//         return min(f(index-1 , cost),f(index-2 , cost)) ;        
//     }
// };



// class Solution { //746. Min Cost Climbing Stairs , recursion + memorization
// public:
//     //all possible count = recursion
//     //overlapping so DP
//     //step 1 - represent in terms of index = zero based index
//     //all cases incorporate
//     //min find of them (use basic formula by striver)

//     //recursion to memorization
//     //changing parameter is index , declare index+1 dp of -1 values
//     // store before return
//     // check after base case && before calculate  

//     int f(int index ,vector<int>& cost , vector<int> &dp)
//     {
//         //base case of recursion (input less hote jayega , top-down)
//         if (index == 0) return cost[0] ;
//         if (index == 1) return cost[1] ;

//         if (dp[index] != -1) return dp[index] ;

//         int c1 = f(index-1 , cost ,dp) + cost[index] ;
//         int c2 = f(index-2 , cost ,dp) + cost[index] ;

//         return dp[index] = min(c1,c2) ;
//     }


//     int minCostClimbingStairs(vector<int>& cost) {\
//         int index = cost.size() ;

//         vector<int> dp(index+1,-1) ;
        
//         //  You can reach the top by either stepping from the last step (cost[n-1]) or the second last step (cost[n-2]), so you need to calculate the minimum cost between those two.
//         return min(f(index-1 , cost ,dp),f(index-2 , cost,dp)) ;        
//     }
// };



// class Solution { //746. Min Cost Climbing Stairs , recursion + tabulation
// public:
//     //all possible count = recursion
//     //overlapping so DP
//     //step 1 - represent in terms of index = zero based index
//     //all cases incorporate
//     //min find of them (use basic formula by striver)

//     //recursion to memorization
//     //changing parameter is index , declare index+1 dp of -1 values
//     // store before return
//     // check after base case && before calculate  

//     //memo to tabulation (bottom-up = base case to result come using array)
//     //declare same dp array as in memorization in the main function (not in helper fucntion)
//     //write equivalent base case
//     //write equivalent non base base execution (copy paste same execution , remove other parameters in argument than index (changing one) also change () to [])
//     // return statement also change like non base execution

//     int minCostClimbingStairs(vector<int>& cost) {
//         int index = cost.size() ;

//         vector<long long> dp(index+1,-1) ;

//         //Equivalent of base case
//         dp[0] = cost[0] ;
//         dp[1] = cost[1] ;

//         //Equivalent of no base case execution
//         for(int i=2 ; i<= index-1 ; i++)
//         {
//             //wrong
//             int c1 = dp[i-1] + cost[i] ;
//             int c2 = dp[i-2] + cost[i] ;
//             dp[i] = min(c1,c2) ;

//             //   or
//             //  dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
//         }

//         //  You can reach the top by either stepping from the last step (cost[n-1]) or the second last step (cost[n-2]), so you need to calculate the minimum cost between those two.
//         return min(dp[index - 1], dp[index - 2]);       
//     }
// };



class Solution { //746. Min Cost Climbing Stairs , tabulation + space optimization
public:
    //all possible count = recursion
    //overlapping so DP
    //step 1 - represent in terms of index = zero based index
    //all cases incorporate
    //min find of them (use basic formula by striver)

    //recursion to memorization
    //changing parameter is index , declare index+1 dp of -1 values
    // store before return
    // check after base case && before calculate  

    //memo to tabulation (bottom-up = base case to result come using array)
    //declare same dp array as in memorization in the main function (not in helper fucntion)
    //write equivalent base case
    //write equivalent non base base execution (copy paste same execution , remove other parameters in argument than index (changing one) also change () to [])
    // return statement also change like non base execution

    //tabu to space optimization
    //removed the declared array
    //declare prev1,prev2 and then replace in (index-1,index-2) everywhere i.e in equivalent base case ,for loop
    //declare curi outside for loop , replace dp[i] with curi 
    //inside for loop do prev2 = prev1 , prev1 = curi


    int minCostClimbingStairs(vector<int>& cost) {
        int index = cost.size() ;

        //Equivalent of base case
        int prev2 = cost[0] ;
        int prev1 = cost[1] ;

        int curi = INT_MAX ;

        //Equivalent of no base case execution
        for(int i=2 ; i<= index-1 ; i++)
        {
            //wrong
            int c1 = prev1 + cost[i] ;
            int c2 = prev2 + cost[i] ;
            curi = min(c1,c2) ;
            prev2 = prev1; 
            prev1 = curi; 

        }

        //  You can reach the top by either stepping from the last step (cost[n-1]) or the second last step (cost[n-2]), so you need to calculate the minimum cost between those two.
        return min(prev1,prev2);       
    }
};