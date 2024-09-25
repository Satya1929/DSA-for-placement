#include <bits/stdc++.h>
using namespace std;

class Solution { //normal 
  public:
  
    long long int topDownHelper(int n,vector<long long int> &dp1) {
        if(n<=1) return n ;
        if(dp1[n]!=-1) return dp1[n];
        return dp1[n]=topDownHelper(n-1, dp1)+topDownHelper(n-2, dp1) ;
    }
  
    long long int topDown(int n) {
        vector<long long int> dp1 (n+1 , -1) ;
        return topDownHelper(n,dp1);
    }
    
    
    long long int bottomUp(int n) {
        vector<long long int> dp1 (n+1 , -1) ;
        dp1 [0] = 0;
        dp1 [1] = 1;
        
        for(int i = 2 ; i<=n ; i++)
        {
            dp1[i] = dp1[i-1] + dp1[i-2];
        }
        
        return dp1[n] ;
    }
};


class Solution { //with modulo concept of CP , as on large numbers which are going out of range of variable , it is still a correct wway to represent the answer
public:
    const int MOD = 1e9 + 7;  // Defining the modulo constant

    long long int topDownHelper(int n, vector<long long int> &dp1) {
        if (n <= 1) return n;
        if (dp1[n] != -1) return dp1[n];
        // Recursive relation with modulo applied to prevent overflow
        return dp1[n] = (topDownHelper(n - 1, dp1) + topDownHelper(n - 2, dp1)) % MOD;
    }

    long long int topDown(int n) {
        vector<long long int> dp1(n + 1, -1);
        return topDownHelper(n, dp1);
    }

    long long int bottomUp(int n) {
        vector<long long int> dp1(n + 1, -1);
        dp1[0] = 0;
        dp1[1] = 1;
        
        // Iterative DP solution with modulo to prevent overflow
        for (int i = 2; i <= n; i++) {
            dp1[i] = (dp1[i - 1] + dp1[i - 2]) % MOD;
        }

        return dp1[n];
    }
    
};













int fib(int n) // tabulation
{ 
    // Create an array to store Fibonacci numbers.
    int f[n + 1];

    // Base cases
    f[0] = 0;

    if (n > 0)
    {
        f[1] = 1;

        // Fill the array in a bottom-up manner
        for (int i = 2; i <= n; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
    }

    return f[n];
}