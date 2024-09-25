#include <bits/stdc++.h>
using namespace std;

int main()
{
    /////////////////initialize
    string s1 = "Satya is sexy";
    string s2("Satya looks good");
    string s3 ;
    s3 = "Satya is hot";
    string s4;
    string word;
    string line ;
    string ans = "" ; //empty string not like '' ,but for one character use 'A' and not "A"

    /////////////////Access 
    int n = s1.length() ;
    //or
    int m = s1.size() ;
    cout << n << endl ;
    cout << s1[0] << endl ;
    cout << s1.at(0);
    cout << s1[n-1] << endl ;

    /////////////////Concatenation
    s4 = s1 + " and " + s3 ;

    s1 = s1.append(" adding at the end ") ; //Caution : append function is designed to append entire strings or character arrays, not single characters
    s1 = s1.append(s2) ;
    //single character append using
    int index = 0 ;
    s2.append(s1[index]);       // so , This is incorrect
    s2.push_back(s1[index]); 
    s2 += s1[index];


    /////////////////Change String Characters
    // s1[0] = "M" ; wrong to use " "
    s1[0] = 'M' ;

    ////////////////Special Characters = 
    string txt = "To put upper comma we use \"Vikings\" and similarly for \\ and \'";

    ////////////////User Input
    cout << "input word only : "; //cin considers a space (whitespace, tabs, etc) as a terminating character
    cin >> word;
    cout << "input a line : " ;
    cin.ignore() ; // Ignore leftover newline character . You need it when you have used cin to take input (like cin >> variable) before getline(). The reason is that cin >> leaves a newline ('\n') in the input buffer, which getline() reads as an empty line.
    getline (cin, line);

    /////////////////Print
    cout << s1 << endl ;
    cout << n << endl ;
    cout << m << endl ;
    cout << s2 << endl ;
    cout << s3 << endl ;
    cout << s4 << endl ;
    cout << txt << endl ;
    cout << word << endl ;
    cout << line << endl ;
    

    /////////////////check if empty
    if (!s1.empty())
    if(s1.size() > 0)


    ////////////////Make string empty (clear it)
    s1 = "" ;      //redefine it as empty   
    s1.clear();      


    ////////////////reverse the string (must rem)
    reverse(s1.begin(), s1.end()); // whole string

    // Define the range you want to reverse
    int start = 7; // Starting index (inclusive)
    int end = 12;  // Ending index (exclusive) 
    // reverse the specified range (arguments are iterators i.e pointer to start and index after the end)
    reverse(s1.begin() + start, s1.begin() + end);


    ///////////////checking even odd digit in string without typecast
    if ((s1[i] - '0') % 2 != 0) return true ; //If s[i] is '3', then s[i] - '0' is 51 - 48, which equals 3. (dealing with ASCII)


    ////////////////conversions
    //string to int
    string s6 = stoi(num_string) ; 
    //int to string
    int a = to_string(integerr);

    return 0;
}









#include <iostream>
#include <algorithm> // Include the algorithm header for std::reverse
#include <string>    // Include the string header for std::string

int main() {
    std::string s1 = "Hello, World!";
    
    // Define the range you want to reverse
    int start = 7; // Starting index (inclusive)
    int end = 12;  // Ending index (exclusive)
    
    // Use std::reverse to reverse the specified range
    std::reverse(s1.begin() + start, s1.begin() + end);
    
    // Output the modified string
    std::cout << "Modified string: " << s1 << std::endl;
    
    return 0;
}
