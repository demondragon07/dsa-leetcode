//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    private:
    //recursion+Memorization
    /*int solve(int arr[],int n,int i,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int op1=arr[i]+solve(arr,n,i+2,dp);
        int op2=0+solve(arr,n,i+1,dp);
         dp[i]=max(op1,op2);
        return dp[i];
       
    }*/
    
    private:
    //Bottom -UP or Tabulation
    
    int solve(int arr[],int n){
         vector<int>dp(n+2,0);
        
        for(int i=n-1;i>=0;i--){
             int op1=arr[i]+dp[i+2];
             int op2=0+dp[i+1];
              dp[i]=max(op1,op2);
       
        }
        return dp[0];
       
    }
    
    
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        //vector<int>dp(n+1,-1);
        //int i=0;
       return solve(arr,n);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends