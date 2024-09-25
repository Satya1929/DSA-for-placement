#include <bits/stdc++.h>


int lcs_helper(string &text1, string &text2 , int m , int n , vector<vector<int>> &dp2) {
    //m,n are last index and not string length (so striver code) not gfg code

    //base case
    if(m<0 || n<0) //m or n is negative mean string len = 0 , nothing to check in one string
    {
        return 0 ;
    }



    if(dp2[m][n] != -1) /////extra = value already calculated , so return it
    {
        return dp2[m][n] ;
    }
    else /////extra = value already NOT calculated , so cacculate it + memorize it before return
    {
        //if index matches (from end ofc bcz wahin se start)
        if(text1[m]==text2[n])
        {
            return dp2[m][n] = 1 + lcs_helper(text1,text2,m-1,n-1 ,dp2) ;
        }
        else //if index not matches (move pointer left and right cases, then consider max length returned)
        {
            return dp2[m][n] = max(lcs_helper(text1,text2,m-1,n,dp2) ,lcs_helper(text1,text2,m,n-1,dp2) ) ;
        } 
    }     
    
}

int longestCommonSubsequence(string &text1, string &text2) {

    // a, b are size and not last index
    int a = text1.length() ; //iska last index = m = a-1
    int b = text2.length() ; //iska last index = n = b-1

    /////extra for memorize
    vector<vector<int>> dp2(a, vector<int>(b,-1)) ;
    /////pass this as reference in all lcs_helper

    return lcs_helper(text1, text2, a-1, b-1, dp2);
}
