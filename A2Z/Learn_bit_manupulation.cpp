#include <bits/stdc++.h>
using namespace std;

void XORswap(int a, int b) {
    // XOR swap
    a = a ^ b;  // a now holds a^b
    b = a ^ b;  // b = a^b^b = a
    a = a ^ b;  // a = a^b^a = b

}

bool check_Kth_Bit_by_rightshift(int n, int k) {
    if ((n>>k) & 1 == 1 ) return true ;
    return false ;
}

bool check_Kth_Bit_by_rightshift(int n, int k) {
    if ((n>>k) & 1 != 0 ) return true ;
    return false ;
}

bool check_Kth_Bit_by_leftshift(int n, int k) {
    // if (n & (1<<k) == 1 ) return true ; //wrong bcz  == has higher precedence than &. You need to enclose the bitwise operation in parentheses.
    if ((n & (1<<k)) != 0 ) return true ; // == 1 never do bcz example 
    //Example:
    // Consider n = 8 (binary: 1000) and k = 3.
    // The expression 1 << 3 results in 1000 (binary) or 8 (decimal).
    // Now, n & (1 << 3) results in 1000 & 1000 = 1000 (decimal 8), which is non-zero, but not necessarily 1.
    return false ;
} 

