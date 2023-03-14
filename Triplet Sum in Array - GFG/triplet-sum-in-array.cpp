//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        if(n<3){
            return false;
        }
        
        sort(A,A+n);
        int i,l,r;
        for(int i=0;(i+2)<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
            int res=A[i]+A[l]+A[r];
            if(res==X){
                return true;
            }else if(res>X){
                r=r-1;
            }else{
                l=l+1;
            }
        }
    }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends