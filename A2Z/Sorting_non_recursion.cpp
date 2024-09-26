#include <bits/stdc++.h>
using namespace std;


void selection_sort(int arr[], int n)
{
    // selection sort
    for (int i = 0; i < n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // swap
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    
    int did_swap_in_this_pass = 0 ; 
    
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j <= i-1 ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);  
                did_swap_in_this_pass ++ ;
            }
            
        }
        
        if (did_swap_in_this_pass == 0 )
        {
            break ; 
        }
    }
    
}

void insertionSort(int arr[], int n)  //striver easy logic
{
    for (int i = 1; i < n; i++) 
    {   // Start from the second element
        for (int j = i; j > 0; j--) 
        {  // Iterate backwards from the current position
            if (arr[j] < arr[j - 1]) 
            { // Compare with the previous element
                swap(arr[j - 1], arr[j]);  // Swap if the previous element is greater
            } 
            else 
            {
                break;  // Stop if the current element is in the right position , iskliye hi while better tha here
            }
        }
    }
}









int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insertion_sort(arr, n);

    cout << "After sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}