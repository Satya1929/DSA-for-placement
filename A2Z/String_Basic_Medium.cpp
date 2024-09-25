#include <bits/stdc++.h>
using namespace 

string reverseWords(string s) {
    string ans = ""; // Initialize the answer string
    int n = s.size(); // Get the size of the input string
    int i = 0; // Initialize the index


    while (i < n) { // iterate whole string
        string temp_word; // Temporary string to store each word

        // Skip leading spaces before words
        while (s[i] == ' ' && i < n) {
            i++; 
        }

        // Collect the word
        while (s[i] != ' ' && i < n) {
            temp_word += s[i]; 
            i++;
        }

        //Adding word to answer
        if (temp_word.size() > 0) {
            if (ans.size() == 0) {
                ans.append(temp_word); // Append the first word
            } else {
                ans = temp_word + ' ' + ans; // Prepend the word to the answer
                temp_word = ""; // Reset the temporary word
            }
        }
    }
    return ans; // Return the final reversed string
}


string largestOddNumber(string s) {
    // Iterate from the end of the string to the beginning
    for (int i = s.size() - 1; i >= 0; --i) {
        // Check if the current character is an odd digit
        if ((s[i] - '0') % 2 != 0) {
            // Return the substring from the start to the current position
            return s.substr(0, i + 1);
        }
    }
    // If no odd digit is found, return an empty string
    return "";


    ///donot try to convert string to number then deal with it , bcz string might be long to overload the variable
}



bool isIsomorphic(string s, string t) {
    // If the lengths of the strings are not equal, they cannot be isomorphic
    if (s.length() != t.length()) return false;

    // Maps to store character mappings from s to t and t to s
    unordered_map<char, char> map_s_to_t;
    unordered_map<char, char> map_t_to_s;

    // Iterate through each character in the strings
    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i]; // Character from string s
        char c2 = t[i]; // Character from string t

        // Check if c1 is already mapped to a different character in t
        if (map_s_to_t.count(c1) && map_s_to_t[c1] != c2) {
            return false;
        }
        // Check if c2 is already mapped to a different character in s
        if (map_t_to_s.count(c2) && map_t_to_s[c2] != c1) {
            return false;
        }

        // Create the mapping from c1 to c2 and from c2 to c1
        map_s_to_t[c1] = c2;
        map_t_to_s[c2] = c1;
    }

    // If all characters are consistently mapped, the strings are isomorphic
    return true;


    /*
    s = "badc"
    t = "baba"
    Output = false is correct
    so have to chect one-one mapping so check both directions of c1 to c2 and c2 to c1*/

}





// Function to find the longest common prefix among a vector of strings
string longestCommonPrefix(vector<string>& v) {
    int n = v.size(); // Get the number of strings in the vector
    if (n == 0) return ""; // If the vector is empty, return an empty string
    if (n == 1) return v[0]; // If there's only one string, return it

    string ans = ""; // Initialize the answer string to store the common prefix
    int min_size = v[0].size(); // Initialize min_size with the size of the first string
    
    // Find the minimum size among all strings
    for (int i = 1; i < n; i++) {
        int newww = v[i].size() ;
        min_size = min(min_size, newww ); // Update min_size with the smallest string size
        //min_size = min(min_size, v[i].size()); wrong bcz not same data type in arguments
    }

    // Iterate over each character position up to the minimum string size
    for (int i = 0; i < min_size; i++) {
        char current_char = v[0][i]; // Get the current character from the first string
        for (int j = 1; j < n; j++) {
            // If the current character does not match in any string, return the current prefix
            if (v[j][i] != current_char) {
                return ans;
            }
        }
        ans += current_char; // Append the current character to the answer string
    }

    return ans; // Return the longest common prefix
}









