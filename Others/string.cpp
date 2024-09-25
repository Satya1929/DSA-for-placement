int strStr(string haystack, string needle) {
    // Find the first occurrence of 'needle' in 'haystack'
    size_t pos = haystack.find(needle);
    
    // Convert size_t to int and return the result
    if (pos != string::npos) 
    {
        // string::npos is a constant static member of the std::string class. It represents the largest possible value for a size_t type (which is the type returned by the find method). Essentially, it is used to indicate that a search operation did not find the requested substring.
        return (int)pos;
    } 
    else 
    {
        return -1;  // Return -1 if 'needle' is not found
    }
}


    int lengthOfLastWord(string s) {

        int n = s.size() ;
        int j = 0 ;
        int count = 0 ;

        for(int i=n-1 ; i>=0 ; i--)
        {
            if (s[i] == ' ') continue ;
            else
            {
                j=i ;
                break ;
            }
        }

        // for( j ; j== ' ' ; j--)
        // {
        //     count ++ ;
        // }
        
        // Count the length of the last word
        for(; j >= 0 && s[j] != ' '; j--) {
            count++;
        }

        return count ;
        
    }

    void reverseString(vector<char>& s) {
        int left = 0;               // Initialize left pointer
        int right = s.size() - 1;   // Initialize right pointer

        // Swap characters from both ends
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }