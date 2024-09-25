#include <bits/stdc++.h>
using namespace std;

int winningPlayerCount(int n, vector<vector<int>> &pick)
{
    int arr[n];

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k <= 1; k++)
        {
            arr[j] += pick[j][k];
        }
    }

    int winner = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] > i;
        winner++;
    }

    return winner;
}

int winningPlayerCount(int n, vector<vector<int>> &pick)
{

    int winner = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                int arr[n + 2];
                arr[j] += pick[j][k];

                for (int l = 0; l < n + 3; l++)
                {
                    if (arr[l] > l)
                    {
                        winner++;
                        break;
                    }
                }
            }
        }
    }

    return winner;
}

int winningPlayerCount(int n, vector<vector<int>> &pick)
{
    vector<int> v[n][n];

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k <= 1; k++)
        {
            v[j].push_back(pick[j][k]);
        }
    }

    int winner = 0;

    for (int i = 0; i < n; i++)
    {
        v[i] > i;
        winner++;

        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                
            }
            

        }
    }

    return winner;
}

int main()
{

    return 0;
}