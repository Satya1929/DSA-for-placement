// online compiler

#include <bits/stdc++.h>
using namespace std;


void digit_count(int n)
{
  int count = 0;
  do
  {
    n = n / 10;
    count++;
  } while (n > 0);

  // or

  // int count = (int) (log10(x)+1) ;
}

int reverse_a_number(int x)
{
  long long rev = 0;
  while (x != 0)
  {
    rev = rev * 10 + (x % 10); // find remainder and add its to r
    x = x / 10;                // Update the value of x
  }

  // The purpose of the if (ans < INT_MIN || ans > INT_MAX) return 0; statement is to handle integer overflow. Since ans is a long, it can hold larger values than an int. If the reversed value exceeds the range of a 32-bit integer, the function returns 0 to prevent incorrect results due to overflow.
  if (rev < INT_MIN || rev > INT_MAX)
    return 0;

  return int(rev);
}

bool Check_Palindrome(int x)
{
  // We begin by performing an initial check. If the input number x is negative, it cannot be a palindrome since palindromes are typically defined for positive numbers. In such cases, we immediately return false.
  if (x < 0)
  {
    return false;
  }

  long long duplicate = x;
  long long rev = 0;

  while (x != 0)
  {
    rev = rev * 10 + (x % 10); // find remainder and add its to r
    x = x / 10;                // Update the value of x
  }

  if (rev == duplicate)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int GCD_of_bigest_and_smallest_in_a_vector(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int min = nums[0];
  int max = nums[nums.size() - 1];

  int gcd = 1;

  for (int i = 1; i <= min; i++)
  {
    if (max % i == 0 && min % i == 0)
    {
      gcd = i;
    }
  }

  // or

  /*
  The Euclidean algorithm is used to find the GCD: (Best)

  It repeatedly replaces a with b and b with the remainder of a divided by b (a % b).
  This process continues until b becomes 0.
  When b is 0, a contains the GCD of the original pair of numbers.

  while (max != 0) {
      int r = min % max;
      min = max;
      max = r;
  }

  //or

  int a = min ;
  int b = max ;

while (a>0 && b>0)
{
  if (a>b){a=a%b;}
  else //b>a
  {b=b%a;}
  
  if (a==0){return b;)
  else{return a;}
}


  return min ;
  */

  // return gcd after loop bcz if loops doesnot modify gcd from initialization 1 , then that case is considered here
  return gcd;
}

bool isArmstrong(int num) {
    // Write your code here

    int dup = num ;
    int temp = num ;

    int cubesum = 0;

    int total_digit =0 ;

    //However, to correctly check for Armstrong numbers for any number of digits, you need to generalize the logic to handle numbers with any digit count.

    //total digits count
    while (temp !=0) {
        temp = temp/10;
        total_digit++ ;
    }

    //now check genralized armstrong number
    do {
        cubesum = cubesum + pow((dup%10) , total_digit ) ;
        //#concept = use power function and not 2^n . pow(number , power)
        dup = dup/10 ;
    }
    while(dup!=0);

    if(cubesum == num)
    {
        return true;
    } 
    else 
    {
        return false;
        //The reason your code gives "YES" for the input 13 
        //is because the function isArmstrong does not return false
        // when the number is not an Armstrong number. 
        //In C++, if a function that is supposed to return 
        //a boolean does not explicitly return a value,
        // it can lead to undefined behavior.

    }
}

vector<int> getAllDivisors(int n){
    // Write your code here

    vector<int> ans;

    for(int i=1 ; i<=n ; i++)
    {
        if (n%i == 0)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int isPrime(int N){
        // code here
        
        int count = 0;

    // Finding factors in sqrt of n time
    for(int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            count++ ;
            if (N / i != i) {
                count++;
            }
        }
    }

    if (count == 2)
    { 
        return 1;
    }
    else
    {
        return 0;
    }
    }




int main()
{
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    digit_count(n);
  }

  return 0;
}

