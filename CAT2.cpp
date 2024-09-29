#include <bits/stdc++.h>
using namespace std;


void KMPsearch(string &pat, string &txt) { //naive algorithm
    int m = pat.size();
    int n = txt.size();

    // A loop to slide pat[] one by one
    for (int i = 0; i <= n - m; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j <= m-1; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }

        // If j reches m values i.e not break in betwwen then pattern found
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}






class Solution { //KMP
// Q link = https://www.geeksforgeeks.org/problems/search-pattern0205/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    void computeLPS(string &pat, vector<int> &LPS, int m) {
        int len = 0;  // Length of the previous longest prefix suffix
        LPS[0] = 0;   // LPS[0] is always 0
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];  // Try the previous longest prefix suffix
                } else {
                    LPS[i] = 0;  // If no match, set LPS[i] to 0
                    i++;
                }
            }
        }
    }

    // KMP Search Function
    vector<int> KMPsearch(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> result;  // To store the indices of pattern matches
        vector<int> LPS(m, 0);  // LPS array to hold the longest prefix suffix values

        // Compute LPS array for the pattern
        computeLPS(pat, LPS, m);

        int i = 0;  // Index for txt
        int j = 0;  // Index for pat

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {  // A match is found
                result.push_back(i - m); //and (i-m+1) for 1 based indexing
                j = LPS[j - 1];  // Use LPS to skip unnecessary comparisons
            } else if (i < n && txt[i] != pat[j]) {  // Mismatch after j matches
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};
