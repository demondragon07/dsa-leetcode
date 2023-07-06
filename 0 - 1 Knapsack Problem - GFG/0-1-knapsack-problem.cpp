//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   
    private:
    
    int solve(int val[],int wt[], int n, int index,int capacity,vector<vector<int>>&dp){
        
        if(index==n || capacity==0){
            return 0;
        }
        
        if(dp[index][capacity]!=-1){
          return dp[index][capacity] ;  
        }
        
        int include=0;
        if(capacity>=wt[index]){
            include=val[index]+solve(val,wt,n,index+1,capacity-wt[index],dp);
        }
        
        
        int exclude=0+solve(val,wt,n,index+1,capacity,dp);
        
        return dp[index][capacity]=max(include,exclude);
    
    }
    
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solve(val,wt,n,0,W,dp);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends