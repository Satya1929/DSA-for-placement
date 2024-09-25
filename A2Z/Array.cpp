#include <bits/stdc++.h>
using namespace std;

int largest_in_array(vector<int> &arr, int n)
{
    /*
    //brute force , time = nlogn
    sort(arr.begin(), arr.end());
    return arr[n - 1];
    */

    // most optimal is the following

    // Initial max element
    int max = arr[0];

    // Iterate through the array to find the maximum element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int 2nd_largest_in_array(vector<int> &arr)
{

    /*
    /////////////////////Brute force , sorting so nlogn time

    int n = arr.size();

    // Check if the array has at least two elements
    if (n < 2) {
        return -1; // Return an invalid value or handle as needed
    }

    sort(arr.begin(), arr.end());

    // Find the second largest element
    int largest = arr[n - 1];
    int secondLargest = -1;

    // Traverse the array from the end to find the second largest element
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != largest) { // Find the first different element from the largest
            secondLargest = arr[i];
            break;
        }
    }

    return secondLargest;
    */

    // most optimal , to do in 1 pass is O(n)

    int n = arr.size();

    if (n < 2)
    {
        return INT_MIN; // Not enough elements to find the second largest
    }

    int largestt = arr[0];
    int slargestt = INT_MIN; // Initialize to the smallest possible integer
    // we should not set slargestt to INT_MAX. The reason is that INT_MAX represents the maximum possible integer value, which would interfere with the logic of finding the second largest element.
    // arr[i] > slargestt = always false aa jayega which is wrong

    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] > largestt)
        {
            slargestt = largestt;
            largestt = arr[i];
        }
        else if (arr[i] > slargestt && arr[i] < largestt)
        // The expression largestt > arr[i] > slargestt does not work as intended in C++
        {
            slargestt = arr[i];
        }
    }

    // If slargestt is still INT_MIN, it means there was no second largest element found
    if (slargestt == INT_MIN)
    {
        return -1; // Or another suitable value indicating no second largest element
    }

    return slargestt;
}

bool Check_if_Array_Is_Sorted_and_Rotated(vector<int> &nums)
{
    vector<int> ans(nums.begin(), nums.end());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums == ans)
        {
            return true;
        }
        // rotate left 1 by 1 till n times
        rotate(nums.begin(), nums.begin() + 1, nums.end());
    }
    return false;

    /*
    Rotate function always rotate left

    Rotate left by 3 positions
    rotate(vec1.begin(), vec1.begin()+3, vec1.end());

    Roatte right by 3 position
    rotate(vec2.begin(), vec2.begin()+(vec2.size()-3), vec2.end());
    */

    /*
Intuition
To determine if v vector can be rotated into v sorted order, we need to check if any rotation of the vector matches the sorted version of the vector. The idea is to:

Sort the Vector:
First, we create v sorted copy of the original vector. This sorted vector represents the desired non-decreasing order.

Check All Rotations:
Next, we rotate the original vector through all possible rotations. For each rotation, we check if it matches the sorted vector.

Rotation Mechanism:
We use the std::rotate function to shift the elements of the vector. By rotating the vector one position at v time and checking if it matches the sorted vector, we can determine if it’s possible to obtain v sorted order through rotations.
    */
}

bool arraySortedOrNot(vector<int> &arr)
{
    // code here
    int n = arr.size();

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int Remove_Duplicates_from_Sorted_Array(vector<int> &arr)
{

    /*
    // brute force bcz insert take n log n time, store in set data structure

    set<int> set;
    int n = arr.size() ;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }

    int index = 0;
    for (int x : set)
    {
        arr[index] = x;
        index++ ;
    }

    int k = set.size();
    return k;
    */

    // most optimized way ,one pass , two pointer approach

    int n = arr.size();
    int i = 0;

    for (int j = 1; j <= n - 1; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1; // unique element index+1  = size
}

vector<int> Left_Rotate_an_Array_by_One(vector<int> &v, int n)
{
    // Write your code here.

    int temp = v[0];
    for (int i = 1; i <= n - 1; i++)
    {
        v[i - 1] = v[i];
    }
    v[n - 1] = temp;
    return v;

    // space used is O(n) , but extra spaced used is only O(1)  bcz of temp variable
}

void rotate_the_array_to_the_right_by_k_steps(vector<int> &nums, int k)
{

    // Normalize k to ensure it is within the bounds of the array length
    int n = nums.size();
    k = k % n;

    // Rotate the array using std::rotate
    std::rotate(nums.begin(), nums.begin() + (n - k), nums.end());
}

void move_Zeroes_to_end(vector<int> &v)
{

    int j = -1;

    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            j = i;
            break;
        }
    }

    // // no non-zero elements:
    // if (j == -1)
    //     return v;

    for (int i = j + 1; i < n; i++)
    {
        if (v[i] != 0)
        {
            swap(v[i], v[j]);
            j++;
        }
    }

    // return v;
}

int Linear_search(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

// brute force
int missing_Number(vector<int> &v)
{

    int N = v.size();

    // for numbers
    for (int i = 1; i <= N; i++)
    {

        // flag variable to check
        // if an element exists
        int flag = 0;

        // Search the element using linear search:
        for (int j = 0; j < N; j++)
        {
            if (v[j] == i)
            {
                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing

        if (flag == 0)
            return i;
    }

    // Optional: Return a default value or handle error
    // Since the problem guarantees that one number is missing, this return should never be reached.
    // It is just to avoid warnings.
    return -1;
}
// better with hasing
int missing_Number(vector<int> &v)
{

    int n = v.size();

    // pre-compute
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    // fetch
    for (int i = 0; i <= n; i++)
    {
        if (mpp[i] == 0)
        {
            return i;
        };
    }

    // Optional: Return a default value or handle error
    // Since the problem guarantees that one number is missing, this return should never be reached.
    // It is just to avoid warnings.
    return -1;
}
// optimal = sum of all natural numbers
int missing_Number(vector<int> &v)
{

    int N = v.size();

    // Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N; i++)
    {
        s2 += v[i];
    }

    int missingNum = sum - s2;
    return missingNum;

    // Optional: Return a default value or handle error
    // Since the problem guarantees that one number is missing, this return should never be reached.
    // It is just to avoid warnings.
    return -1;
}
// most optimal = XOR
int missing_Number(vector<int> &v)
{

    // Note: Among the optimal approaches, the XOR approach is slightly better than the summation one because the term (N * (N+1))/2 used in the summation method cannot be stored in an integer if the value of N is big (like 105). In that case, we have to use some bigger data types. But we will face no issues like this while using the XOR approach.

    int N = v.size();

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N; i++)
    {
        xor2 = xor2 ^ v[i]; // XOR of array elements
        xor1 = xor1 ^ (i);  // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; // XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number

    // Optional: Return a default value or handle error
    // Since the problem guarantees that one number is missing, this return should never be reached.
    // It is just to avoid warnings.
    return -1;
}

int find_Max_Consecutive_Ones(vector<int> &v)
{
    int n = v.size();
    int maxxx = 0;
    int count1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            count1++;
            maxxx = max(maxxx, count1);
        }
        else
        {
            count1 = 0;
        }
    }

    return maxxx;
}

int singleNumber(vector<int> &arr)
{
    // size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int getLongestSubarray(vector<int> &v, int k)
{
    // most optimal for + and 0 and - numbers , store the sum if if that sum not existed before , bcz we want left most array smaalest ho to get largest ans array


    int n = v.size();
    int len = 0;

    map<long long, int> presum;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i];

        if (sum == k)
        {
            len = max(len, i + 1);
        }

        long long rem = sum - k;

        if (presum.find(rem) != presum.end())
        {
            int sublen = i - presum[rem];
            len = max(len, sublen);
        }

        // //for only positive integer
        // presum[sum] = i ;

        // most optimal for + and 0 and - numbers , store the sum if if that sum not existed before , bcz we want left most array smaalest ho to get largest ans array
        if (presum.find(sum) == presum.end())
        {
            presum[sum] = i;
        }
    }

    return len;
}

int subarraySum(vector<int>& a, long long k) {
    //Most optimal for + and 0 numbers


    int n = a.size(); // size of the array.
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;


    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // if sum <= k , increase the sub array
        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}










int main()
{
    vector<int> arr = {2, 3, 5, 1, 4};
    int n = arr.size();

    int maxElement = largest(arr, n);
    cout << "The largest element is: " << maxElement << endl;

    return 0;
}


int majorityElement(vector<int>& v) 
{
        int n = v.size();
        map<int, int> mapp;

        // Count occurrences of each element
        for (int i = 0; i < n; i++) {
            mapp[v[i]]++;
        }

        // Find the element that occurs more than n/2 times
        for (auto itr : mapp) {
            if (itr.second > n / 2) {
                return itr.first;
            }
        }

        return -1; // This line will never be reached as per problem constraints.
}



int longestConsecutive(vector<int>& v) {
    int n = v.size();
    if (n == 0) return 0; // Handle empty input case

    // Sort the vector
    sort(v.begin(), v.end());

    // Variable to store the length of the longest consecutive sequence
    int longestStreak = 1;
    int currentStreak = 1;

    // Iterate through the sorted array and count consecutive sequences
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1]) { // To avoid duplicates
            if (v[i] == v[i-1] + 1) {
                // Increment current streak if consecutive
                currentStreak++;
            } else {
                // Reset current streak
                longestStreak = max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
    }

    // Final check for the last streak
    longestStreak = max(longestStreak, currentStreak);

    return longestStreak;
}