// online compiler

#include <bits/stdc++.h>
using namespace std;

void print_1_to_N(int N, int i = 1)
{

    // Normal recursion
    // so print line *before the recursion call

    // Base case
    if (i > N)
    {
        return;
    }

    cout << i << " ";
    printNos(N, i + 1);

    // by backtracking///////////////////////////////////
    // so print line *after the recursion call

    /*
    // Base case
    if (N < 1) {
        return;
    }

    // Recursive call with N-1
    printNos(N - 1);

    // Print current number
    cout << N << " ";
    */
}

void print_Gfg_N_times(int N, int i = 1)
{
    // Code here
    if (i > N)
    {
        return;
    }

    cout << "GFG" << " ";
    printGfg(N, i + 1);
}

void print_N_to_1(int N, int i = 1)
{
    // by backtracking///////////////////////////////////
    // so print line *after the recursion call

    // Base case
    if (i > N)
    {
        return;
    }

    // Recursive call with N-1
    printNos(N, i + 1);

    // Print current number
    cout << i << " ";
}

// or

/*
void printNos(int N) {
    // code here


    //Normal recursion
    //so print line *before the recursion call


    // Base case
    if (N < 1) {
        return;
    }

    // Print current number
    cout << N << " ";

    // Recursive call with N-1
    printNos(N - 1);

}
*/


//Given an integer n, calculate the sum of series 1^3 + 2^3 + 3^3 + 4^3 + … till n-th term.
long long sumOfSeries(long long n){
    // code here

    // Base case
    if (n == 0)
    {
        return 0;
    }
    // Recursive case: sum of cubes up to n
    return n * n * n + sumOfSeries(n - 1);
}

//OR

/*
long long sumOfSeries(long long n, long long sum = 0) {
// Base case
if (n < 1) {
    return sum;
}

// Calculate the cube of the current number and add to the sum
long long cube = pow(n, 3);
sum = sum + cube;

// Recursive call
return sumOfSeries(n - 1, sum);
}
*/


//Factorial of a number
// this code is unoptimized
/*
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code
        
        vector<long long> ans;
        for (int i=1; i<=n ; i++)
        {
            long long b = factorial(i);
            if (b < n)
            {
                ans.push_back(b);
            }
        }
        

        
        return ans;
        
        
    }
    
    long long factorial(long long n) {

        if (n <= 1)
        {
            return 1 ;
        }
        
        return n*factorial(n-1);
    }
    
};
*/
//most optimised code
//directly find next factorial number and check for the condition less than n. 
//And not find factorial of all numbers less than n
vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    long long fact = 1;
    for (long long i = 1; fact <= n; ++i) {
        ans.push_back(fact);
        fact *= i + 1;
    }
    return ans;
}




int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        print_N_to_1(n);
    }

    return 0;
}




bool isPalindrome(string s) {
    return checkPalindrome(s, 0, s.size() - 1);
}


bool checkPalindrome(const string& s, int l, int r) {
    // Base case: if pointers have crossed, it's a palindrome
    if (l >= r) return true;

    // Skip non-alphanumeric characters
    if (!isalnum(s[l])) return checkPalindrome(s, l + 1, r);
    if (!isalnum(s[r])) return checkPalindrome(s, l, r - 1);

    // Compare characters
    if (tolower(s[l]) != tolower(s[r])) return false;

    // Move pointers towards the center
    return checkPalindrome(s, l + 1, r - 1);
}