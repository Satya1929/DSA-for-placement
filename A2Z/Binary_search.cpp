#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& v, int target) { //iterative

        int n = v.size();

        int low = 0 ;
        int high = n-1 ;

        while(low <= high)
        {
            int mid = (low + high) / 2 ;
            //wrong bcz of operational precedence
            //int mid = low + high / 2 ;

            if ( target == v[mid])
            {
                return mid ;
            }
            else if ( target > v[mid])
            {
                low = mid + 1 ;
            }
            else
            {
                high = mid - 1 ;
            }
        }
        return -1 ;
        
    }

int binarySearch(vector<int>& nums, int low, int high, int target) { //recursive

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}












