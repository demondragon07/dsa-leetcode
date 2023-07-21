//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
   // when order matter-- private:
    
    /* int solve(int n){
          if(n<0){
		      return 0;
		  } 
		   
		   if(n==1){
		        return 1;
		    }
		  if(n==2){
		      return 2;
		  }  
		   return solve(n-1)+solve(n-2);
     }
    */
    
    //when order does not matters
    
    int solve(int n){
        return (n/2)+1;
    }
    //Logic---
    
	public:
		int nthStair(int n){
		    return solve(n);
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
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends