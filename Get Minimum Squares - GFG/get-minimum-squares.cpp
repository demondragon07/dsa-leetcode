//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	
	private:
	
      /*int solve(int n, vector<int>&dp){
	    if(n==0){
	        return 0;
	    }
       if(dp[n]!=-1){
				 return dp[n];
			 }
	    
	    int ans=INT_MAX;
	    
	    for(int i=1;i<=sqrt(n);i++){
				 int square=i*i;
	        ans=min(ans,1+solve(n-square,dp));
	    }
	    
	    return dp[n]=ans;
	}
	*/
	int solvetab(int N){
	     vector<int>dp(N+1,0);
	     
	     
	     
	for(int n=1;n<=N;n++){
	    int ans=INT_MAX;
	    
	    for(int i=1;i<=sqrt(n);i++){
				  int square=i*i;
	         ans=min(ans,1+dp[n-square]);
	       }
	    
	         dp[n]=ans;
	   }
	   
	    return dp[N];
	}
	
	public:
	
	int MinSquares(int n)
	{
	   
	   return solvetab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends