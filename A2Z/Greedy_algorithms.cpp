#include <bits/stdc++.h>
using namespace std;

int Assign_Cookies(vector<int> &g, vector<int> &s)
{
    int gsize = g.size();
    int ssize = s.size();

    int gitr = 0;
    int sitr = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (gitr < gsize && sitr < ssize)
    {
        if (s[sitr] >= g[gitr])
        {
            // Child satisfied, move both cookie and child iterators ahead
            gitr++;
            sitr++;
        }
        else
        {
            // Cookie too small, try the next cookie
            sitr++;
        }
    }

    return gitr;
}

bool comparator(pair<int, int> &a, pair<int, int> &b)
{ // always use pass by reference in comparator function
    // first comes more weight per unit value
    double x = (double)a.second / (double)a.first;
    double y = (double)b.second / (double)b.first;

    if (x > y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Fractional_Knapsack(vector<pair<int, int>> &w_v_pair, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    // knapsack of size ‘W’.
    // ‘N’ items

    double total_value = 0;

    sort(w_v_pair.begin(), w_v_pair.end(), comparator);

    for (int i = 0; i < n; i++)
    {
        if (w_v_pair[i].first <= w)
        {
            w = w - w_v_pair[i].first;
            total_value += w_v_pair[i].second;
        }
        else
        {
            double val = w * ((double)w_v_pair[i].second / (double)w_v_pair[i].first); // value per weight * weight put n bag
            total_value += val;
            // w = 0 so break , as bag is full
            break;
        }
    }

    return total_value;
}


struct Job
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// Comparator function must be static (inside the class) or it should be place (outside the class)

bool static compp (Job a , Job b) {
    return a.profit > b.profit ; 
}

vector<int> Job_Sequencing_Problem(Job arr[], int n) 
{ 
    // Q = each job element(Jobid, Deadline, Profit)

    // Making slot array of maximun size  = maximum dealine
    int maxi = 0 ; 
    for (int i = 0; i < n ; i++)
    {
        maxi = max(maxi , arr[i].dead) ; 
    }

    int slot[maxi+1] ;
    for (int i = 0; i < maxi+1; i++)
    {
        slot[i] = -1 ; 
    }


    //sort job array according to proft of each job's element
    sort(arr , arr+n , compp) ;

    //iterate through Job arr and do the work , where starting is from max profit job
    //Do that job , as late as possible according to it's deadline
    //also keep count of proft and total jobs done to return in answer

    int totaljobdone = 0 ;
    int totalprofit = 0 ; 

    for (int i = 0; i < n; i++) // job arr
    {
        for (int j = arr[i].dead; j > 0  ; j--) // slot arr
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id ; 
                totalprofit += arr[i].profit ; 
                totaljobdone ++;
                break ;
            }
            
        }
        
    }
    
    // Return the result as a vector
    return {totaljobdone, totalprofit};

    /* note = Loop Boundaries: The inner loop that checks for an available slot starts from arr[i].dead and goes down to j >= 0. However, the valid slots start from 1, not 0. If j reaches 0, it will still try to assign the job to an invalid slot, causing incorrect job counting and profit calculation.*/


} 




// Comparator function must be static (inside the class) or it should be place (outside the class)
bool static compp (vector<int> &a,vector<int> &b) {
    return a[2] > b[2] ; 
}

vector<int> Job_Sequencing_Problem(vector<vector<int>> & v) 
{ 
    int n = v.size();

    // Q = each job element(Jobid, Deadline, Profit)

    // Making slot array of maximun size  = maximum dealine
    int maxi = 0 ; 
    for (int i = 0; i < n ; i++)
    {
        maxi = max(maxi , v[i][1]) ; 
    }

    int slot[maxi+1] ;
    for (int i = 0; i < maxi+1; i++)
    {
        slot[i] = -1 ; 
    }


    //sort job array according to proft of each job's element
    sort(v.begin() , v.end() , compp) ;

    //iterate through Job arr and do the work , where starting is from max profit job
    //Do that job , as late as possible according to it's deadline
    //also keep count of proft and total jobs done to return in answer

    int totaljobdone = 0 ;
    int totalprofit = 0 ; 

    for (int i = 0; i < n; i++) // job arr
    {
        for (int j = v[i][1]; j > 0  ; j--) // slot arr
        {
            if (slot[j] == -1)
            {
                slot[j] = v[i][0] ; 
                totalprofit += v[i][2] ; 
                totaljobdone ++;
                break ;
            }
            
        }
        
    }
    
    // Return the result as a vector
    return {totaljobdone, totalprofit};

    /* note = Loop Boundaries: The inner loop that checks for an available slot starts from arr[i].dead and goes down to j >= 0. However, the valid slots start from 1, not 0. If j reaches 0, it will still try to assign the job to an invalid slot, causing incorrect job counting and profit calculation.*/

} 


