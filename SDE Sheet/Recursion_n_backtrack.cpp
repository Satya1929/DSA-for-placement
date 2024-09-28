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

void nextPermutation(vector<int>& nums) {

    next_permutation(nums.begin(), nums.end());
    
}


class Solution {//51. N-Queens // Most optimized = three direction hasharray made
public:

    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow,
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) 
    {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0
                && upperDiagonal[n - 1 + col - row] == 0) {

                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }



};




class Solution {//51. N-Queens // Not optimized = three direction check do by going to each cell
    public:

    bool isSafe(int row, int col, vector<string> board, int n) {
        int duprow = row; //store present cell's row and column in temporary variables
        int dupcol = col;

        //left upper diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') 
                return false;
            row--;
            col--;    
        }

        col = dupcol; // bring attention to present cell's row and column
        row = duprow;

        //left check (same row)
        while (col >= 0) {
            if (board[row][col] == 'Q') 
                return false;
            col--;
        }

        row = duprow; // bring attention to present cell's row and column
        col = dupcol;

        //left lower diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') 
                return false;
            row++;
            col--;
        }

        return true;
    }


    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        //base case is last column reach
        if (col == n) {
            ans.push_back(board);
            return;
        }

        //L6 recursion (pre-requisit of DP)
        for(int row = 0; row < n; row++) 
        {
            if (isSafe(row, col, board, n)) 
            {
                board[row][col] = 'Q'; //take
                solve(col+1, board, ans, n);
                board[row][col] = '.'; //not take
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) 
        {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }

};













int main() {
    vector<int> arr = {1, 2, 3};

    // Call the permute function
    permute(arr);

    return 0;
}


