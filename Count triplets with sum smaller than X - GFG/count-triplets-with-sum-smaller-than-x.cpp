//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long  count=0;
	    
	   for(int i=0;i+2<n;i++){
	          long long j=i+1;
	          long long k=n-1;
	          while(k>j){
	              long long res=arr[i]+arr[j]+arr[k];
	              if(res<sum){
	                 count+=k-j;
	                 j++;
	              }else{
	                 k--; 
	              }
	          }
	     }
	    return count;
	}
};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends