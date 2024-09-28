#include <bits/stdc++.h>
using namespace std;


class Solution { //3190. Find Minimum Operations to Make All Elements Divisible by Three
// Intuition
// just finding the minimum distance between the multiples of 3 and the nums gives the answer
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};


class Solution { //3099. Harshad Number
public:

    int sumdigits(int x)
    {
        int summ = 0 ;
        while (x>0)
        {
            int digit = x%10;
            summ += digit ;
            x = x/10 ;
        }
        return summ ;
    }

    int sumOfTheDigitsOfHarshadNumber(int x) {
        if (x%sumdigits(x) == 0) return sumdigits(x);
        return -1 ;        
    }
};

class Solution { //3024. Type of Triangle
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        if(nums[0] == nums[1] || nums[1] == nums[2]) return "isosceles";
        return "scalene";
    }
};

class Solution { //2965. Find Missing and Repeated Values
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;  // Total numbers expected
        
        // Step 1: Use a hash map to store the frequency of each number
        unordered_map<int, int> freq;
        
        // Step 2: Count occurrences of each number in the grid
        for (auto& row : grid) {
            for (auto& num : row) {
                freq[num]++;
            }
        }
        
        // Step 3: Find the duplicate (a) and missing (b) numbers
        int a = -1, b = -1;
        for (int num = 1; num <= n2; num++) {
            if (freq[num] == 2) a = num;  // The duplicate number
            if (freq[num] == 0) b = num;  // The missing number , int map associates 0 automatically there
        }
        
        return {a, b};  // Return the duplicate and missing numbers
    }
};

class Solution { //2894. Divisible and Non-divisible Sums Difference
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        
        // Loop through all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                // Add to num2 if divisible by m
                num2 += i;
            } else {
                // Add to num1 if not divisible by m
                num1 += i;
            }
        }
        
        // Return the difference
        return num1 - num2;
    }
};


class Solution { //2864. Maximum Odd Binary Number
public:
    string maximumOddBinaryNumber(string s) {
        int count1 = 0 ;
        int count0 = 0 ;

        for(int i=0 ; i<= s.size()-1 ; i++)
        {
            if(s[i]-'0' == 0) count0++ ;
            if(s[i]-'0' == 1) count1++ ;
        }

        string ans ;
        for(int i=0 ; i<= count1-2 ; i++)
        {
            ans.push_back('1') ;
        }
        for(int i=0 ; i<= count0-1 ; i++)
        {
            ans.push_back('0') ;
        }
        ans.push_back('1') ;

        return ans;
        
    }
};


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

class Solution { //2729. Check if The Number is Fascinating
public:
    bool isFascinating(int n) {
        // Concatenate n, 2*n, and 3*n into a single string
        string eww = to_string(n) + to_string(2 * n) + to_string(3 * n);
        
        //hash array
        // Check if the resulting string contains all digits from 1 to 9 exactly once
        vector<int> count(10, 0); // Array to count occurrences of digits 0-9

        // Count occurrences of each digit in the concatenated string
        for (char c : eww) {
            count[c - '0']++; // Increment the count for this digit
        }
        
        // Check for the required conditions
        // Digits from 1 to 9 must occur exactly once and 0 must not occur
        for (int i = 1; i <= 9; i++) {
            if (count[i] != 1) return false; // Each must appear exactly once
        }
        
        if (count[0] != 0) return false; // No zeros allowed
        
        return true; // All conditions satisfied, number is fascinating
    }
};


class Solution { //2413. Smallest Even Multiple
public:
    int smallestEvenMultiple(int n) {
        int i=1 ;
        while((n)%2 != 0 )
        {
            i++ ;
            n = n*i ;
        }

        return n ;
        
    }
};

class Solution { //2235. Add Two Integers
public:
    int sum(int num1, int num2) {
        return num1+num2 ;        
    }
};

class Solution { //1822. Sign of the Product of an Array
public:
    int arraySign(vector<int>& nums) {
        int negativeCount = 0; // Initialize counter for negative numbers
        
        for (int num : nums) {
            if (num < 0) { // Check if the number is negative
                negativeCount++;
            } else if (num == 0) { // If any number is zero, product is zero
                return 0;
            }
        }
        
        // If the count of negative numbers is even, the product is positive
        // If it's odd, the product is negative
        return (negativeCount % 2 == 0) ? 1 : -1;
    }
};


class Solution { //1523. Count Odd Numbers in an Interval Range
public:
    int countOdds(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (i % 2 != 0) { // Check if the number is odd
                count++;
            }
        }
        return count;
    }
};

class Solution { //1295. Find Numbers with Even Number of Digits
public:
    bool isans(int a)
    {
        int count = 0 ;
        while(a>0)
        {
            count++ ;
            a /= 10 ;
        }

        if(count%2 == 0) return true ;
        return false;
    }

    int findNumbers(vector<int>& v) {
        int ans = 0 ;
        for(int i=0 ; i<= v.size()-1 ; i++)
        {
            if(isans(v[i])) ans++ ;
        }

        return ans ;
        
    }
};

class Solution { //1281. Subtract the Product and Sum of Digits of an Integer
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while (n > 0) { // cannot do using for
            int digit = n % 10; // Get the last digit
            product *= digit;    // Update the product
            sum += digit;        // Update the sum
            n /= 10;             // Remove the last digit
        }

        return product - sum; // Return the difference
    }
};


class Solution { //1232. Check If It Is a Straight Line

public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // Get the first two points
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        // Calculate the differences
        int dx = x1 - x0;
        int dy = y1 - y0;

        // Check the slope for each point
        for (int i = 2; i <= coordinates.size()-1; i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // Compare the cross product to avoid division and floating-point inaccuracies
            if (dy * (x - x0) != dx * (y - y0)) { //another version to equate slope
                return false;
            }
        }

        return true;
    }
};


class Solution { //1137. N-th Tribonacci Number
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};

class Solution { //728. Self Dividing Numbers
public:
    bool isSelfDividing(int num) {
        int original = num;
        while (num > 0) {
            int digit = num % 10;
            // Check for zero or if the number is not divisible by the digit
            if (digit == 0 || original % digit != 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};

class Solution { //3295. Report Spam Message
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int n = message.size() ;
        int m = bannedWords.size();
        map <string , int> mapps ;

        for (int i=0 ; i<=m-1 ; i++)
        {
            mapps[bannedWords[i]] ++  ;
        }

        int count = 0 ;
        for (int i=0 ; i<=n-1 ; i++)
        {
            if( mapps[message[i]] >= 1 )
            {
                count ++ ;
            }
        }

        if (count >=2) return true ;
        return false ;
        
    }
};

class Solution { //507. Perfect Number
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;  // Perfect numbers are greater than 1.
        
        int sum = 1;  // Start with 1 as it is a divisor for all numbers.
        
        // Loop from 2 to sqrt(num) to find divisors.
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) 
            {  // i is a divisor
                sum += i;
                if (i != num / i) // corresponding 
                {  // Add the corresponding divisor
                    sum += num / i;
                }
            }
        }
        
        return sum == num;  // Check if sum of divisors equals the number
    }
};


// class Solution { //415. Add Strings
// public:
//     string addStrings(string num1, string num2) { // wrong in case of numbers bigger than long long
//         // Convert strings to long long using stoll (string to long long)
//         long long n1 = stoll(num1);
//         long long n2 = stoll(num2);
        
//         // Add the two numbers
//         long long sum = n1 + n2;
        
//         // Convert the result back to string using to_string
//         return to_string(sum);
//     }
// };


class Solution { //415. Add Strings
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;

        // Add digits from the end to the beginning
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = 0;
            int digit2 = 0;

            // Get the digits from num1 and num2 or 0 if out of bounds
            if (i >= 0) {
                digit1 = num1[i] - '0'; //string to integer conversion
                i--;
            }
            if (j >= 0) {
                digit2 = num2[j] - '0';
                j--;
            }

            // Sum the digits along with carry
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;  // Update carry
            // Add current digit to result
            result.push_back((sum % 10) + '0');  // digit to string conversion
        }

        reverse(result.begin(), result.end());  // Reverse result as we added digits backwards
        return result;
    }
};

class Solution { //263. Ugly Number
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) n /= 2; // all 2 factors out
        while (n % 3 == 0) n /= 3; // all 3 factors out
        while (n % 5 == 0) n /= 5; // all 5 factors out
        return n == 1;
    }
};


class Solution { //258. Add Digits
public:
    int addDigits(int num) {
        while (num >= 10) //do it until the number is 2 digit
        {

            // sum of digits code below
            int sum = 0;
            while (num > 0) 
            {
                sum += num % 10; // Add the last digit
                num /= 10;       // Remove the last digit
            }
            num = sum; // Set num to the sum of its digits
        }
        return num;
    }
};

class Solution { //231. Power of Two
public:
    bool isPowerOfTwo(int n) {
        // Check if n is positive
        if (n <= 0) {
            return false;  // Powers of two must be positive
        }
        
        // Keep dividing n by 2 while it's divisible by 2
        while (n % 2 == 0) {
            n /= 2;  // Divide n by 2
        }
        
        // If n is reduced to 1, it's a power of 2
        // if n is not 1 then it's multiple of 2
        return n == 1;
    }
};

class Solution { //342. Power of Four
public:
//dry run 8 (multiple but not power) and 16 (multiple and power) 
    bool isPowerOfFour(int n) {
        // Check if the number is positive. Powers of four are always positive.
        // If n is less than or equal to 0, return false because it can't be a power of four.
        if (n <= 0) {
            return false;  // Negative numbers and zero are not powers of four.
        }
        
        // Use a loop to keep dividing n by 4 while it's divisible by 4.
        // If n is divisible by 4, we continue dividing it to reduce n.
        while (n % 4 == 0) {
            n /= 4;  // Divide n by 4 and update the value of n.
        }
        
        // After the loop, if n has been reduced to 1, it means that n was
        // a power of four (because repeated division by 4 leads to 1).
        // If n is 1, return true; otherwise, return false.
        // if n is not 1 then it's multiple of 4
        return n == 1;
    }
};

class Solution { //2540. Minimum Common Value
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        
        // Two-pointer approach
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];  // Found the smallest common element
            } else if (nums1[i] < nums2[j]) {
                i++;  // Move pointer in nums1 forward
            } else {
                j++;  // Move pointer in nums2 forward
            }
        }
        
        // If no common element is found, return -1
        return -1;
    }
};

class Solution { //2529. Maximum Count of Positive Integer and Negative Integer
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negCount = 0;
        int posCount = 0;

        // Count the number of negative integers
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negCount++;
            } else if (nums[i] > 0) {
                // Start counting positive integers after 0
                posCount++;
            }
        }

        // Return the maximum of the two counts
        return max(negCount, posCount);
    }
};

class Solution { //2089. Find Target Indices After Sorting Array
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Step 1: Sort the nums array
        sort(nums.begin(), nums.end());
        
        // Step 2: Create a vector to store the target indices
        vector<int> result;
        
        // Step 3: Traverse the sorted array and find target indices
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }
        
        // Step 4: Return the result containing target indices
        return result;
    }
};

class Solution { //1539. Kth Missing Positive Number
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0; // To count the missing positive numbers
        int current = 1; // Start checking from 1
        int index = 0; // Index for the array

        while (missingCount < k) {
            if (index < arr.size() && arr[index] == current) {
                // If the current number is found in the array, move to the next number
                index++;
            } 
            else 
            {
                // If current number is missing
                missingCount++;
                if (missingCount == k) {
                    return current; // Return the current number when we find the kth missing
                }
            }
            current++; // Check the next number
        }
        
        return -1; // In case no answer found, though it shouldn't reach here with given constraints
    }
};

class Solution { //69. Sqrt(x)
public:
    int mySqrt(int x) { // binary search over 0 to x (without generating the array)
        if (x < 2) return x;  // Handle cases for 0 and 1 directly
        
        int left = 2, right = x / 2;  // Start binary search bounds
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Prevent overflow
            long long square = (long long)mid * mid;  // Calculate mid squared
            
            if (square == x) {
                return mid;  // Found exact square root
            } else if (square < x) {
                left = mid + 1;  // Move to the right half
            } else {
                right = mid - 1;  // Move to the left half
            }
        }
        
        return right;  // When loop ends, right is the largest integer with right*right <= x
    }
};

class Solution { //2562. Find the Array Concatenation Value

public:
    long long findTheArrayConcVal(vector<int>& v) {
        int n = v.size();
        int l = 0 ;
        int r = n-1 ;
        vector<long long> llans ;
        
        while(l<r)
        {
            string ls = to_string(v[l]);
            string rs = to_string(v[r]);

            string tempps = ls+rs ;
            long long inttempp = stoll(tempps) ;

            llans.push_back(inttempp) ;
            l++ ;
            r-- ;
        }
        if (l==r) 
        {

            int inttempp2 = (long long)v[l] ;           
            llans.push_back(inttempp2);
        }


        long long sum=0;

        for (auto ele : llans)
        {
            sum+=ele ;
        }

        return sum ;
        
    }



};

class Solution {//2441. Largest Positive Integer That Exists With Its Negative
public:
    int findMaxK(vector<int>& v) {
        int n = v.size();
        
        // Sort the array to handle pairs
        sort(v.begin(), v.end());
        
        int l = 0;
        int r = n - 1;

        // Loop until all pairs are checked
        while (l < r) {
            // If we find a matching positive-negative pair
            if (v[l] * (-1) == v[r]) {
                return v[r]; // Return the largest positive value
            }
            // If current r is greater than the absolute value of l, move r to smaller number
            else if (v[r] > abs(v[l])) {
                r--;
            }
            // If current l is smaller than the negative of r, move l to larger number
            else {
                l++;
            }
        }
        
        return -1; // If no such k exists, return -1
    }
};

class Solution { //2367. Number of Arithmetic Triplets
public:
    // Helper function to check if an element exists in the vector
    bool exists(vector<int>& v, int a) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == a) return true; // Return true if the element is found
        }
        return false; // Otherwise, return false
    }

    // Main function to find the number of arithmetic triplets
    int arithmeticTriplets(vector<int>& v, int diff) {
        int n = v.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Check if both v[i] + diff and v[i] + 2*diff exist in the vector
            if (exists(v, v[i] + diff) && exists(v, v[i] + 2 * diff)) {
                count++; // Increment the count for each valid triplet
            }
        }

        return count;
    }
};

class Solution {//2108. Find First Palindromic String in the Array
public:

    bool isPalindrome(const string &s) {
        int n = s.size();
        int left = 0 ;
        int right = n-1 ;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& v) {
        int n = v.size() ;
        string ans = "" ;

        for(int i=0 ; i<=n-1 ; i++)
        {
            if (isPalindrome(v[i]))
            {
                ans+=v[i];
                break;
            }
        }

        return ans ;
        
    }
};

class Solution { //1768. Merge Strings Alternately
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size() ;
        int n2 = word2.size() ;

        int w1 = 0 ;
        int w2 = 0 ;

        string ans = "" ;
        
        while( w1<=n1-1 && w2<=n2-1)
        {
            ans += word1[w1] ;
            ans += word2[w2] ;
            // ans.append(word1[w1]);
            // ans.append(word2[w2]);

            w1++ ;
            w2++ ;
        }

        while( w1<=n1-1)
        {
            ans += word1[w1] ;
            w1++ ;
        }

        while( w2<=n2-1)
        {
            ans += word2[w2] ;
            w2++ ;
        }

        return ans ;

    }
};


class Solution {//680. Valid Palindrome II
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Use two pointers to check the string from both ends
        while (left < right) {
            // If characters do not match
            if (s[left] != s[right]) {
                // Check by skipping either the left character or the right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            // Move both pointers inward
            left++;
            right--;
        }
        
        // If no mismatch was found, it's already a palindrome
        return true;
    }

};

class Solution {//557. Reverse Words in a String III
public:
   string reverseWords(string &s) {
        // The correct approach should treat apostrophes and other non-alphabetic characters as part of the word so donot use isalpha() only
        int n = s.size();
        int i = 0;

        while (i < n) {
            // Find the start of the word (i)
            while (i < n && s[i] == ' ') {
                i++;
            }

            int j = i;  // Set j to the start of the word

            // Find the end of the word (j) where non-alphabetic characters or spaces appear
            while (j < n && s[j] != ' ') {
                j++;
            }

            // Reverse the word between i and j-1 (all characters in the word)
            reverse(s.begin() + i, s.begin() + j);

            // Move i to j for next iteration (after the current word)
            i = j;
        }

        return s;
    }

};


class Solution { //541. Reverse String II

public:

// let's say k = 3 , 2k = 6
// so 0 to k/less than k = always reverse
// k+1 to 2k always leave untouched

// Case 1: Full 2k segments (so first k reverse)
// Case 2: Fewer than k characters left (all of them reverse)
// Case 3: Between k and 2k characters left (so first k reverse)

// so basically 2 case
// case a =  first k reverse
// case b =  all of them reverse


    string reverseStr(string s, int k) { //541. Reverse String II
        int n = s.size(); 
        
        // Loop through the string in steps of 2k (processing one segment of 2k characters at a time)
        for (int i = 0; i < n; i += 2 * k) // whenever this is done , it means till i ofc all processing done , but i to i+2k processing also done (see by dry run)
        {
            
            // Case A: Full 2k segments / between k and 2k characters
            // Reverse the first k characters within this segment
            if (i + k <= n) 
            {
                reverse(s.begin() + i, s.begin() + i + k);
            } 
            
            // Case B: Fewer than k characters left at the end of the string
            // Reverse all the remaining characters
            else 
            { 
                reverse(s.begin() + i, s.end());
            }

            // No need to touch the characters between `k` and `2k`, they are left unchanged.
        }

        // Return the modified string after all segments are processed
        return s;
    }



};

class Solution {//367. Valid Perfect Square
public:
    bool isPerfectSquare(int num) {
        int a = sqrt(num) ;
        // cout << a << endl ;
        // cout << num ;
        return a*a==num ;
    }
};

class Solution { //917. Reverse Only Letters
public:

    // Function to check if a character is a letter
    bool ischar(char c) {
        return isalpha(c); // isalpha checks if the character is a letter
    }

    string reverseOnlyLetters(string s) {
        int left = 0;               // Initialize left pointer
        int right = s.size() - 1;   // Initialize right pointer

        // Swap characters from both ends
        while (left < right) {
            if (!ischar(s[left])) { // Check if the character at left is not a letter
                left++;
            } else if (!ischar(s[right])) { // Check if the character at right is not a letter
                right--;
            } else {
                // Swap letters and move pointers
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;  
    }

};

class Solution { //796. Rotate String
public:
    bool rotateString(string s, string goal) {
        int n = s.size() ;

        for(int i = 0 ; i<=n-1 ; i++)
        {
            rotate(s.begin() ,s.begin() + 1 , s.end() );
            if(s == goal) return true ;
        }
        
        return false ;
    }
};

class Solution { //709. To Lower Case
public:
    string toLowerCase(string s) {
        for (char &c : s) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
        return s;
    }
};

class Solution { //520. Detect Capital
public:
    bool detectCapitalUse(string word) {
        // Check if all letters are uppercase
        bool allCaps = true;
        bool allLower = true;
        bool onlyfirstCaps = true;
        
        for (int i = 0; i < word.size(); ++i) {
            if (isupper(word[i])) {
                allLower = false; // There is at least one uppercase letter
                if (i > 0) {
                    onlyfirstCaps = false; // If any uppercase letter is not at the beginning
                }
            } 
            else //islower true 
            {
                allCaps = false; // There is at least one lowercase letter
                if (i == 0) {
                    onlyfirstCaps = false; // If the first letter is lowercase
                }
            }
        }
        
        // Return true if any of the conditions is satisfied
        return allCaps || allLower || onlyfirstCaps;
    }
};

class Solution { //392. Is Subsequence
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t
        
        // Traverse through both strings
        while (i < m && j < n) {
            // If characters match, move pointer in s
            if (s[i] == t[j]) {
                i++;
            }
            // Always move pointer in t
            j++;
        }
        
        // If i has reached the end of s, all characters of s were found in t
        return i == m;
    }

};

class Solution { //345. Reverse Vowels of a String
public:

    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';

    }

    string reverseVowels(string s) {
        int left = 0;               // Initialize left pointer
        int right = s.size() - 1;   // Initialize right pointer

        // Swap characters from both ends
        while (left < right ) {

            if(isvowel(s[left]) == false)
            {
                left++;
            }

            else if(isvowel(s[right]) == false)
            {
                right--;
            }

            else if(isvowel(s[left]) && isvowel(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            

        }

        return s;  
    }



};

class Solution { //344. Reverse String
public:
    void reverseString(vector<char>& s) {
        int left = 0;               // Initialize left pointer
        int right = s.size() - 1;   // Initialize right pointer

        // Swap characters from both ends
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

class Solution { //58. Length of Last Word
public:
    int lengthOfLastWord(string s) {

        int n = s.size() ;
        int j = 0 ;
        int count = 0 ;

        for(int i=n-1 ; i>=0 ; i--)
        {
            if (s[i] == ' ') continue ;
            else
            {
                j=i ;
                break ;
            }
        }

        // for( j ; j== ' ' ; j--)
        // {
        //     count ++ ;
        // }
        
        // Count the length of the last word
        for(; j >= 0 && s[j] != ' '; j--) {
            count++;
        }

        return count ;
        
    }
};

class Solution { //28. Find the Index of the First Occurrence in a String
public:

int strStr(string haystack, string needle) {
    // Find the first occurrence of 'needle' in 'haystack'
    size_t pos = haystack.find(needle);
    
    // Convert size_t to int and return the result
    if (pos != string::npos) 
    {
        // string::npos is a constant static member of the std::string class. It represents the largest possible value for a size_t type (which is the type returned by the find method). Essentially, it is used to indicate that a search operation did not find the requested substring.
        return (int)pos;
    } 
    else 
    {
        return -1;  // Return -1 if 'needle' is not found
    }
}

};

class Solution { //1550. Three Consecutive Odds
public:

bool threeConsecutiveOdds(vector<int>& arr) {
    // Check if the array has fewer than 3 elements
    if (arr.size() < 3) {
        return false;  // Can't have 3 consecutive odd numbers in such cases
    }
    
    // Loop through the array and check three consecutive numbers
    for (int i = 0; i <= arr.size() - 3; ++i) {
        if (arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[i+2] % 2 != 0) {
            // If all three numbers are odd, return true
            return true;
        }
    }
    // If no such triplet is found, return false
    return false;
}

};

class Solution { //1089. Duplicate Zeros
public:
    void duplicateZeros(vector<int>& v) {
        int n = v.size();
        vector<int> ans ;

        for(int i=0 ; i<= n-1 ; i++)
        {
            int siz = ans.size() ;
            if (siz == n) break ;

            if(v[i]==0) ans.push_back(0);

            ans.push_back(v[i]);

        }

        for(int i=0 ; i<= n-1 ; i++)
        {
            v[i] = ans[i];
        }
        
    }
};

class Solution { //561. Array Partition
public:
    int arrayPairSum(vector<int>& v) {

        int n = v.size() ;
        sort(v.begin() , v.end());
        int sum = 0;

        for(int i=0 ; i<=n-1 ; i+=2 )
        {
            sum += v[i] ;
        }

        return sum;
    }
};

class Solution { //628. Maximum Product of Three Numbers
public:
    // int maximumProduct(vector<int>& v) {
    //     int n = v.size() ;
    //     int maxi = INT_MIN ;
    //     for(int i = 0 ; i<= n-4 ; i++)
    //     {
    //         int temp ; 
    //         temp = v[i]*v[i+1]*v[i+2] ;
    //         maxi = max(maxi , temp) ;
    //     }
    //     return maxi ;
        
    // }

int maximumProduct(vector<int>& v) {
    // Step 1: Sort the array
    sort(v.begin(), v.end());
    
    // Step 2: Calculate the product of the last three elements (the largest ones)
    int n = v.size();
    int product1 = v[n-1] * v[n-2] * v[n-3];
    
    // Step 3: Calculate the product of the two smallest and the largest element
    int product2 = v[0] * v[1] * v[n-1];
    
    // Step 4: Return the maximum of the two products
    return max(product1, product2);
}


};

class Solution { //349. Intersection of Two Arrays
public:

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());  // Convert nums1 to set
        set<int> result;  // Set to store the result
        
        // Check each element in nums2 if it exists in set1
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) {
                result.insert(num);  // Add to result if it's an intersection
            }
        }

        // Convert set to vector
        return vector<int>(result.begin(), result.end());
    }

};

class Solution { //219. Contains Duplicate II
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        int n = v.size();

        for (int i = 0; i <= n - 1; i++) {
            if (k == 0) return false;

            // Ensure j does not go out of bounds
            for (int j = i + 1; j <= i + k && j < n; j++) {
                if (v[i] == v[j]) return true;
            }
        }

        return false;
    }
};

class Solution { //217. Contains Duplicate
public:
    bool containsDuplicate(vector<int>& v) {
        map<int,int> mapp ;
        int n = v.size() ;

        for(int i=0 ; i<=n-1 ; i++)
        {
            mapp[v[i]]++ ; 
        }

        for(auto it : mapp)
        {
            if (it.second != 1) return true ;
        }

        return false ;

    }
};

class Solution { //66. Plus One
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0; // If current digit is 9, set it to 0 and continue
        }
        
        // If all digits were 9, we need to add a leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

class Solution { //35. Search Insert Position
public:
    int searchInsert(vector<int>& v, int target) {
        auto a = lower_bound(v.begin(),v.end(),target)-v.begin();
        return a ;

    // lower_bound(start_ptr, end_ptr, num): This function finds the first position where num could be inserted to keep the array sorted.
    // If num exists once, it returns the position of num.
    // If num exists multiple times, it returns the first occurrence.
    // If num doesn’t exist, it returns the position where num could be inserted to maintain order.
    // To get the index of this position, subtract the starting pointer (vect.begin()) from the result.

    }
};

class Solution { //1. Two Sum
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size() ;
        vector<int> ans ;

        for(int i=0 ; i<= n-1 ; i++)
        {
            for(int j=i+1 ; j<= n-1 ; j++)
            {
                if (v[i]+v[j] == target)
                { 
                ans.push_back(i);
                ans.push_back(j);
                return ans ;
                }
            }
        }

        return {-1} ;
        
    }
};


bool threeConsecutiveOdds(vector<int> &arr)
{
    // Check if the array has fewer than 3 elements
    if (arr.size() < 3)
    {
        return false; // Can't have 3 consecutive odd numbers in such cases
    }

    // Loop through the array and check three consecutive numbers
    for (int i = 0; i <= arr.size() - 3; ++i)
    {
        if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
        {
            // If all three numbers are odd, return true
            return true;
        }
    }
    // If no such triplet is found, return false
    return false;
}

void duplicateZeros(vector<int> &v)
{
    int n = v.size();
    vector<int> ans;

    for (int i = 0; i <= n - 1; i++)
    {
        int siz = ans.size();
        if (siz == n)
            break;

        if (v[i] == 0)
            ans.push_back(0);

        ans.push_back(v[i]);
    }

    for (int i = 0; i <= n - 1; i++)
    {
        v[i] = ans[i];
    }
}

int arrayPairSum(vector<int> &v)
{

    int n = v.size();
    sort(v.begin(), v.end());
    int sum = 0;

    for (int i = 0; i <= n - 1; i += 2)
    {
        sum += v[i];
    }

    return sum;
}

int maximumProduct(vector<int> &v)
{
    // Step 1: Sort the array
    sort(v.begin(), v.end());

    // Step 2: Calculate the product of the last three elements (the largest ones)
    int n = v.size();
    int product1 = v[n - 1] * v[n - 2] * v[n - 3];

    // Step 3: Calculate the product of the two smallest and the largest element
    int product2 = v[0] * v[1] * v[n - 1];

    // Step 4: Return the maximum of the two products
    return max(product1, product2);
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    set<int> set1(nums1.begin(), nums1.end()); // Convert nums1 to set
    set<int> result;                           // Set to store the result

    // Check each element in nums2 if it exists in set1
    for (int num : nums2)
    {
        if (set1.find(num) != set1.end())
        {
            result.insert(num); // Add to result if it's an intersection
        }
    }

    // Convert set to vector
    return vector<int>(result.begin(), result.end());
}

bool containsNearbyDuplicate(vector<int> &v, int k)
{
    int n = v.size();

    for (int i = 0; i <= n - 1; i++)
    {
        if (k == 0)
            return false;

        // Ensure j does not go out of bounds
        for (int j = i + 1; j <= i + k && j < n; j++)
        {
            if (v[i] == v[j])
                return true;
        }
    }

    return false;
}

bool containsDuplicate(vector<int> &v)
{
    map<int, int> mapp;
    int n = v.size();

    for (int i = 0; i <= n - 1; i++)
    {
        mapp[v[i]]++;
    }

    for (auto it : mapp)
    {
        if (it.second != 1)
            return true;
    }

    return false;
}

void merge(vector<int> &v1, int m, vector<int> &v2, int n)
{
    int left = 0;
    int right = 0;
    vector<int> ans;
    while (left <= m - 1 && right <= n - 1)
    {
        if (v1[left] <= v2[right])
        {
            ans.push_back(v1[left]);
            left++;
        }
        else
        {
            ans.push_back(v2[right]);
            right++;
        }
    }

    while (left <= m - 1)
    {
        ans.push_back(v1[left]);
        left++;
    }

    while (right <= n - 1)
    {
        ans.push_back(v2[right]);
        right++;
    }

    // Copy back the merged result to v1
    for (int i = 0; i <= m + n - 1; i++)
    {
        v1[i] = ans[i];
    }
}

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            digits[i] += 1;
            return digits;
        }
        digits[i] = 0; // If current digit is 9, set it to 0 and continue
    }

    // If all digits were 9, we need to add a leading 1
    digits.insert(digits.begin(), 1);
    return digits;
}

int searchInsert(vector<int> &v, int target)
{
    auto a = lower_bound(v.begin(), v.end(), target) - v.begin();
    return a;
}

vector<int> twoSum(vector<int> &v, int target)
{
    int n = v.size();
    vector<int> ans;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (v[i] + v[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return {-1};
}


class Solution { //409. Longest Palindrome
public:
    // donot use DP bccz of lot permuation nhi ho sakta udhar , and if hoga then too much complex
    int longestPalindrome(string s) {
        vector<int> v(1000, 0); // Frequency vector for letters
        int odd = 0; // Count of characters which have odd frequency
        int m = s.size(); // Length of string

        // Loop through each character in the string
        for (int i = 0; i <= m-1; i++) {
            // Increment frequency of the character
            v[s[i] - 'A']++;

            // If the frequency of that character becomes odd, increment 'odd', otherwise decrement 'odd'
            if (v[s[i] - 'A'] % 2 == 1) {
                odd++;
            } else {
                odd--;
            }
        }

        // If more than one character has odd frequency, return the adjusted palindrome length
        if (odd > 1) {
            return m - odd + 1;
            // so basicaly this works by removing one characters from each of the characters that appeared odd number of times hencing making each of those character's occurence even times. then just add 1 of them to place in center of palindrome
        }
        
        return m; // If no or only one odd frequency, the entire string can be a palindrome
    }
};




class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& v) { //448. Find All Numbers Disappeared in an Array
        int n = v.size() ;
        vector<int> hashv(n+1,0) ;
        vector<int> ans ;

        for ( int ele : v)
        {
            hashv[ele]++ ;
        }

        for(int i=1 ; i<= hashv.size()-1 ; i++)\
        {
            if(hashv[i] == 0) ans.push_back(i);
        }

        return ans ;

        
    }
};






class Solution { //859. Buddy Strings
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;

        vector<int> diff;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }

        if (diff.size() == 2) {
            // Check if swapping makes them equal
            return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
        }

        // If both strings are the same
        if (diff.empty()) {
            // Check for duplicates in the string
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
                if (count[c - 'a'] > 1) return true; // Found a duplicate
            }
            return false; // No duplicates found
        }

        return false; // More than 2 indix where they differ
    }
};

