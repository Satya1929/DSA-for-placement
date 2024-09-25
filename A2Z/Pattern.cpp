/*

// local compiler

#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << '*';
    }
    cout << endl;
  }
}

int main()
{
  int n;
  cin >> n;
  pattern(n);

  return 0;
}

*/

// online compiler

#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern2(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern3(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

void pattern4(int n)
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}

void pattern5(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= n - i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern6(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << "*";
    }

    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }
}

void pattern7(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space

    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 2 * n - (2 * i) - 1; j >= 1; j--)
    {
      cout << "*";
    }

    cout << endl;
  }
}

void pattern8(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << "*";
    }

    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < n; i++)
  {
    // space

    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 2 * n - (2 * i) - 1; j >= 1; j--)
    {
      cout << "*";
    }

    cout << endl;
  }
}

void pattern9(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << "*";
    }

    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < n - 1; i++)
  {
    // space

    cout << " ";

    for (int j = 0; j < i; j++)
    {
      cout << " ";
    }

    // star
    for (int j = 2 * (n - 1) - (2 * i) - 1; j >= 1; j--)
    {
      cout << "*";
    }

    cout << endl;
  }
}

void pattern10(int n)
{
  // pattern 2
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // pattern 5
  for (int i = 0; i < n; i++)
  {
    for (int j = 2; j <= n - i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }
}

void pattern11(int n)
{
  int start;

  for (int i = 0; i <= n; i++)
  {
    if (i % 2 == 0)
    {
      int start = 0;

      for (int j = 0; j < i; j++)
      {
        cout << start << " ";
        start = 1 - start;
      }
      cout << endl;
    }
    else
    {
      int start = 1;

      for (int j = 0; j < i; j++)
      {
        cout << start << " ";
        start = 1 - start;
      }
      cout << endl;
    }
  }
}

void pattern12(int n)
{

  for (int i = 0; i < n; i++)
  {
    // star

    for (int j = 0; j < i + 1; j++)
    {
      cout << j + 1;
    }

    // space
    for (int j = 0; j < 2 * n - 2 * (i + 1); j++)
    {
      cout << " ";
    }

    // star

    for (int j = 0; j < i + 1; j++)
    {
      cout << j + 1;
    }

    cout << endl;
  }
}

void pattern13(int n)
{
  for (int i = 0; i < n; i++)
  {
    // star

    for (int j = 0; j < i + 1; j++)
    {
      cout << j + 1 << " ";
    }

    // space
    for (int j = 0; j < 2 * n - 2 * (i + 1); j++)
    {
      cout << "  ";
    }

    // star

    for (int j = i + 1; j > 0; j--)
    {
      cout << j << " ";
    }

    cout << endl;
  }
}

void pattern14(int n)
{
  int a = 1;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      cout << a << " ";
      a++;
    }
    cout << endl;
  }
}

void pattern15(int n)
{
  char start = 'A';
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++, start++)
    {
      cout << start << " ";
    }
    cout << endl;
    start = 'A';
  }
}

void pattern16(int n)
{
  char start = 'A';
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= n - i; j++, start++)
    {
      cout << start << " ";
    }
    cout << endl;
    start = 'A';
  }
}

void pattern17(int n)
{
  char start = 'A';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << start << " ";
    }
    cout << endl;
    start++;
  }
}

void pattern18(int n)
{
  for (int i = 0; i < n; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }

    // star
    char start = 'A';
    int breakpoint = (2 * i + 1) / 2;
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      if (j > breakpoint)
      {
        cout << start;
        start--;
      }
      else
      {
        cout << start;
        start++;
      }
    }

    cout << endl;
  }
}

void pattern19(int n)
{
  char AAA = 'A';

  for (int i = 0; i < n - 1; i++)
  {
    AAA++;
  }
  char start = AAA;
  char begin = start;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < i; j++, begin--)
    {
      cout << begin << " ";
    }
    cout << endl;
    begin = start;
  }
}

void pattern20(int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "*";
    }

    // star
    for (int j = 1; j <= 2 * i + 1; j++)
    {
      cout << " ";
    }

    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  for (int i = 0; i < n - 1; i++)
  {
    // space
    cout << "*";
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }

    // star
    for (int j = 2 * (n - 1) - (2 * i) - 1; j >= 1; j--)
    {
      cout << " ";
    }

    // space
    cout << "*";
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }

    cout << endl;
  }
}

void pattern21(int n)
{
  for (int i = 0; i < n; i++)
  {
    //star
    for (int j = 1; j <= n-i; j++)
    {
      cout << "*";
    }

    //space
    for (int j = 1; j <= 2*i; j++)
    {
      cout << " ";
    }

    //star
    for (int j = 1; j <= n-i; j++)
    {
      cout << "*";
    }

    cout << endl ;
  }

  for (int i = 0; i < n; i++)
  {
    //star
    for (int j = 1; j <= i+1; j++)
    {
      cout << "*";
    }

    //space
    for (int j = 1; j <= 2*(n-i-1); j++)
    {
      cout << " ";
    }

    //star
    for (int j = 1; j <= i+1; j++)
    {
      cout << "*";
    }

    cout << endl;
    
  }

  // cout << endl ;

}

void pattern22(int n)
{

  for (int i = 0; i < n; i++)
  {
    //star
    for (int j = 1; j <= i+1; j++)
    {
      cout << "*";
    }

    //space
    for (int j = 1; j <= 2*(n-i-1); j++)
    {
      cout << " ";
    }

    //star
    for (int j = 1; j <= i+1; j++)
    {
      cout << "*";
    }

    cout << endl;
    
  }

  for (int i = 1; i < n; i++)
  {
    //star
    for (int j = 1; j <= n-i; j++)
    {
      cout << "*";
    }

    //space
    for (int j = 1; j <= 2*i; j++)
    {
      cout << " ";
    }

    //star
    for (int j = 1; j <= n-i; j++)
    {
      cout << "*";
    }

    cout << endl ;
  }

  // cout << endl ;

}

void pattern23(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i==0 || i==n-1 || j==0 || j==n-1)
      {
        cout << "*" ;
      }
      else
      {
        cout << " " ;
      }
    }

    cout << endl ;
    
  }
  
}

void pattern24(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i==0 || i==n-1 || j==0 || j==n-1)
      {
        cout << "*" ;
      }
      else
      {
        cout << " " ;
      }
    }

    cout << endl ; 
  }
  
}

void pattern25(int n)
{
  for (int i = 0; i < 2*n-1; i++)
  {
    for (int j = 0; j < 2*n-1; j++)
    {
      int top = i;
      int right = j;
      int down = (2*n-2) - i ;
      int left = (2*n-2) - j ;

      cout <<(n- min(min(left,right),min(top,down))) ;
    }

    cout << endl ; 
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
    pattern25(n);
  }

  return 0;
}


