#include <bits/stdc++.h>
using namespace std;


//hashing using ordered/unordered maps

int main() {
    int n;
    cout << "enter size of input array " ;
    cin >> n;
    int arr[n];
    cout << "enter numbers " ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //pre-compute = ordered map use
    map<int, int> mpp; //ordered and for //unordered_map<int, int> mpp; //unordered
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cout << "enter number of queries " ;
    cin >> q; //number of queries
    while (q--) {   //run till q>0
        cout << "enter number for query " ;
        int number; 
        cin >> number;

        //fetch
        cout << "output " ;
        cout <<  mpp[number] << endl;
    }

    return 0;
}


/*
int main() {
    int n;
    cout << "enter size of input array " ;
    cin >> n;
    int arr[n];
    cout << "enter numbers " ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute
    int hashh[n+1] = {0};
    for (int i = 0; i < n; i++) {
        hashh[arr[i]]++;
    }
    
    return 0;
}
*/
