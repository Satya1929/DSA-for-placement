#include <bits/stdc++.h>
using namespace std;

string string_Int_to_binary(string s){ //string integer to string binary
    int v = stoi(s); //string to integer

    //normal DSD subject mehord for conversion
    string t = "";
    while(v != 0){
        if(v%2 == 1)t.push_back('1');
        else if (v%2 == 0) t.push_back('0');
        v/=2;
    }
    reverse(t.begin(),t.end());

    return t;
}

string string_Int_to_binary_STL1(string s) {
    // Convert the string to an integer
    int num = stoi(s);

    // Convert to binary and remove leading zeros
    return bitset<32>(num).to_string().substr(bitset<32>(num).to_string().find('1'));
}

//or

string string_Int_to_binary_STL1_expanded(string s) {
    // Convert the string to an integer
    int num_int = stoi(s);

    // Convert the integer to a 32-bit binary string
    bitset<32> variable(num_int); // Create a bitset of size 32 with the binary value of integer num_int
    string binaryString = variable.to_string();

    // Find the position of the first '1'
    size_t firstOnePos = binaryString.find('1');

    // Extract the binary substring from the first '1'
    string result = binaryString.substr(firstOnePos);

    return result;
}



int main()
{
    string s1 = "8" ;
    string s2 = string_Int_to_binary(s1) ;
    string s3 = string_Int_to_binary_STL1_expanded(s1) ;
    cout << s2 << endl; 
    cout << s3 << endl; 
    return 0 ;
}
