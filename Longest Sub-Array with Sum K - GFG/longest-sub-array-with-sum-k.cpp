//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int res=0;
        int pre_sum=0;
        
        unordered_map<int,int>m;
        
        for(int i=0;i<N;i++){
              pre_sum+=A[i];
              
             if(pre_sum==K){
                res=i+1;
             }
            
            if(m.find(pre_sum -K)!=m.end()){
                res=max(res,i-m[pre_sum-K]);
            }
            
            if(m.find(pre_sum)==m.end()){
                m[pre_sum]=i;
            }
        }
        
    return res;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends