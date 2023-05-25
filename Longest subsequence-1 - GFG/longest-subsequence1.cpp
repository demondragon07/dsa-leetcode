//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:

int solve(int arr[],int N,int curr,int prev){
     if(curr==N){
           return 0;
       }
       
       int pick=0;
       int nopick=0;
       if( prev==-1 || abs(arr[curr]-arr[prev])==1){
           pick=1+solve(arr,N,curr+1,curr);
       }
    
      nopick=solve(arr,N,curr+1,prev);
      return max(pick,nopick);

}


public:

    int longestSubsequence(int N, int A[])
    {
       return solve(A,N,0,-1);
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends