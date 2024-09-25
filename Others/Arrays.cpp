#include <bits/stdc++.h>
using namespace std;

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

    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int left = 0 ;
        int right = 0 ;
        vector<int> ans ;
        while(left <= m-1 && right <= n-1)
        {
            if(v1[left]<=v2[right])
            {
                ans.push_back(v1[left]);
                left++ ;
            }
            else
            {
                ans.push_back(v2[right]);
                right++ ;
            }
        }

        while(left <= m-1 )
        {
            ans.push_back(v1[left]);
            left++ ;
        }


        while(right <= n-1 )
        {
            ans.push_back(v2[right]);
            right++ ;
        }

        // Copy back the merged result to v1
        for(int i = 0; i <= m + n - 1; i++) {
            v1[i] = ans[i];
        }

        
    }


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

    int searchInsert(vector<int>& v, int target) {
        auto a = lower_bound(v.begin(),v.end(),target)-v.begin();
        return a ;
    }

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