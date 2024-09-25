#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    vecotr<vector<int>> matrix ;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a ;
            cin << a ;
            matrix[i-1][j-1] = a ;
        }
        
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
    func(n);
  }

  return 0;
}