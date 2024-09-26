#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> &v, int i, int j, vector<vector<int>> &mem_matrix)
{

    // base case
    if (i >= j)
    {
        return 0;
    }

    // FOR MEMORISATION
    // donot calculate cost if it is already stored in matrix
    if (mem_matrix[i][j] != -1) // i.e stored hai value
    {
        return mem_matrix[i][j];
    }

    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // most important. two way possible according to video
        //  k = i to j-1 , then break (i to k) (k+1 to j)
        //  k = i+1 to j , then break (i to k-1) (k to j)
        //  always check the edge cases (A)(BCD) and (ABC)(D) should be formed
        int temp = cost(v, i, k, mem_matrix) + cost(v, k + 1, j, mem_matrix) + v[i - 1] * v[k] * v[j];

        // min of all temp costs of all partition
        mini = min(temp, mini);
    }

    mem_matrix[i][j] = mini;
    return mini;
}


int matrixMultiplication(vector<int> &v, int n)
{
    int i = 1;
    int j = n - 1;

    // FOR MEMORISATION
    // intialize 2D vector called mem_matrix with dimensions n by n.
    // Each element in the vector is initialized to -1.
    // Essentially, it creates a square matrix of size n where all elements are set to -1
    vector<vector<int>> mem_matrix(n, vector<int>(n, -1));
    // now pass this matrix to cost function to let the function acces it. otherwise declare this matrix globallly

    return cost(v, i, j, mem_matrix);
}

