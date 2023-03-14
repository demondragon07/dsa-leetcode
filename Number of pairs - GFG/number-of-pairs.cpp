//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 

class Solution{
    private:
    int getindex(int arr[],int n,int c){
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>c){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    
    
    
    public:
    
    // X[], Y[]: input array
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
       sort(Y,Y+N);
      
      long zeros=0,one=0,two=0,three=0,four=0;
      for(int i=0;i<N;i++){
          if(Y[i]==0){
              zeros++;
          }else if(Y[i]==1){
              one++;
          }else if(Y[i]==2){
              two++;
          }else if(Y[i]==3){
              three++;
          }else if(Y[i]==4){
              four++;
          }
      }
      
      long ans=0;
      
      for(int i=0;i<M;i++){
           if(X[i]==0){
              continue;
          }else if(X[i]==1){
              ans+=zeros;
          }else if(X[i]==2){
              int index=getindex(Y,N,2);
              if(index!=-1){
                  ans+=N-index;
              }
              ans-=three;
              ans-=four;
              ans+=one+zeros;
          }else if(X[i]==3){
          int index=getindex(Y,N,3);
          if(index!=-1){
              ans+=N-index;
          }
          ans+=two;
          ans+=one+zeros;
      }else{
          int index=getindex(Y,N,X[i]);
          if(index!=-1){
              ans+=N-index;
          }
          ans+=one+zeros;
      }
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}
// } Driver Code Ends