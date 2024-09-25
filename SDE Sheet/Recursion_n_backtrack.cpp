#include <bits/stdc++.h>
using namespace std;

void recurPermute(vector<int> &ds_permute, vector<int> & given_v, vector<vector<int>> &final_anwers, int freq[])
{
    //base case
    if (ds_permute.size() ==  given_v.size()) //i.e when ds_permute have a full length of given-v's arrangement  
    {
        final_anwers.push_back(ds_permute); // store that permute in final_answer vector
        return;
    }


    //iterate frequency array
    for (int i = 0; i <= given_v.size()-1; i++)
    {
        if (freq[i] == 0) //if unmarked (not of 0 is 1  is true) = if (!freq[i])
        {
            ds_permute.push_back( given_v[i]); //pust that element to find a permute
            freq[i] = 1; // mark that as 1 (taken) in freq vector

            recurPermute(ds_permute,  given_v, final_anwers, freq); //recursion call

            freq[i] = 0; // unmark that as 0 (while moving back)
            ds_permute.pop_back(); //also remove that element
        }
    }
}

vector<vector<int>> permute(vector<int> & given_v) //All permutation of array in lexicographical order using recursion only
{
    vector<vector<int>> final_anwers;

    vector<int> ds_permute;
    
    int freq[ given_v.size()];
    for (int i = 0; i <=  given_v.size()-1; i++)
        freq[i] = 0;
    
    recurPermute(ds_permute,  given_v, final_anwers, freq);
    
    return final_anwers;
}


/////OR

vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Step 1: Sort the array to start with the smallest lexicographical permutation
        sort(nums.begin(), nums.end());
        
        // Step 2: Generate permutations using next_permutation
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return result;
    }


/// for string

vector<string> permute(string& str) {
        vector<string> result;
        
        // Step 1: Sort the string to start with the smallest lexicographical permutation
        sort(str.begin(), str.end());
        
        // Step 2: Generate permutations using next_permutation
        do {
            result.push_back(str);
        } while (next_permutation(str.begin(), str.end()));
        
        return result;
    }








void permute(vector<int>& arr)  // print all permutations using c++ STL
{
    // Sort the array first
    sort(arr.begin(), arr.end());

    // Loop to print all permutations
    /*do Block: Inside the do block, we print the current permutation of the array. The loop ensures that we start by printing the sorted permutation first.
    next_permutation(): This function rearranges the elements into the next lexicographical permutation. It returns false when the array is rearranged to its largest possible permutation (e.g., [3, 2, 1] for the array [1, 2, 3]), and no more permutations are possible.
    The loop continues generating and printing permutations until next_permutation() returns false, which means we've generated all possible permutations.*/
    do {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));
    /*next_permutation() rearranges the elements of the array into the next lexicographical permutation. For example, for an array [1, 2, 3], the next permutation is [1, 3, 2].*/
}


///////OR



void permute(vector<int>& v)  // print all permutations using c++ STL without loop dry run 
{
    // Sort the array first (must to generate all lexicographical order)
    /*Before using next_permutation(), we first sort the array. This ensures that we start generating permutations from the lexicographically smallest arrangement (which is the sorted order). For example, [1, 2, 3].
    This is important because next_permutation() works by generating the next lexicographically larger permutation in the sequence. If the array is not sorted initially, the function will start generating permutations in an unordered manner.*/ 
    sort(v.begin(), v.end());

    // Print the array (which now contains the next lexicographical permutation)
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    next_permutation(v.begin(), v.end());
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    next_permutation(v.begin(), v.end());
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    next_permutation(v.begin(), v.end());
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    next_permutation(v.begin(), v.end());
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    next_permutation(v.begin(), v.end());
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Generate the next permutation and print it
    if (!next_permutation(v.begin(), v.end())) {
        cout << " false hua ";
    }
    for (int i = 0; i <= v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}















int main() {
    vector<int> arr = {1, 2, 3};

    // Call the permute function
    permute(arr);

    return 0;
}


void nextPermutation(vector<int>& nums) {

    next_permutation(nums.begin(), nums.end());
    
}