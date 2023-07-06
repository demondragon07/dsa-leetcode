//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   
    private:
    
    /*int solveTab(int W, int wt[], int val[], int n){
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int index=n-1;index>=0;index--){
            for(int capacity=0;capacity<=W;capacity++){
                
                  int include=0;
              if(capacity>=wt[index]){
                 include=val[index]+dp[index+1][capacity-wt[index]];
        }
        
        
            int exclude=0+dp[index+1][capacity];
        
             dp[index][capacity]=max(include,exclude);
            }
      }
      
      return dp[0][W];
        
    }*/
    
    int solvespace(int W, int wt[], int val[], int n){
        
        vector<int>curr(W+1,0);
        vector<int>next(W+1,0);
        
           for(int index=n-1;index>=0;index--){
            for(int capacity=0;capacity<=W;capacity++){
                
                  int include=0;
              if(capacity>=wt[index]){
                 include=val[index]+next[capacity-wt[index]];
        }
        
        
            int exclude=0+next[capacity];
        
            curr[capacity]=max(include,exclude);
            }
            next=curr;
      }
      
      return curr[W];
        
    }
        
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      
       return solvespace(W,wt,val,n);
       
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