#include <bits/stdc++.h>
using namespace std;

int main()
{
    map <int,string> class_rollnum ; 
    map <string,string> class_bf_gf ; 

    ////////////////////////Initialization

    //1. Assignment = and Subscript [] Operator
    class_rollnum[5] = "sexy satya " ;
    //2. Initializer list
    class_bf_gf = { {"satya" , "shibangi"} , { "prakash" , "preeti" } };
    //3. Array of Pairs
    pair<string,string>old_arr[] = {     // Initialize an array of pair of strings
        make_pair("Ground", "Grass"),
        make_pair("Floor", "Cement"),
    };
    int n = (sizeof(old_arr) / sizeof(old_arr[0]));
    map<string, string>old_map(old_arr, old_arr + n);
    //4.From Another Map - Using map.insert() Method
    map<string, string>New_Map1;
    New_Map1.insert(old_map.begin(),old_map.end());
    //5.From Another Map - Using () Method
    map<string, string>New_Map2(old_map);
    map<string, string>New_Map3(old_map.begin(),old_map.end()); // for a perticular range



    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        mapp[v[i]]++;
    }

    // Find the element that occurs more than n/2 times
    for (auto itr : mapp) {
        if (itr.second > n / 2) 
        {
            return itr.first;
        }
    }









    ///////////////////////////Traverse through the map
    // map sorts element in ascending lexicographical order of keys present in element
   for(auto element : class_bf_gf)
   {
      cout << element.first << " is the key "<< "----->" << element.second << " is the value "<<endl;
   } 


    return 0 ;
}