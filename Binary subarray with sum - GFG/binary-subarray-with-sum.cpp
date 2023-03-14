//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
   private:
   int atmost(vector<int>& arr, int N, int target){
      
      
       int j=0,i=0;
       int count=0;
       int sum=0;
    
      if(N==0){
          return 0;
      }
    
         while(j<N){
             sum+=arr[j];
                while(sum>target){
                    sum-=arr[i];
                    i++;
                 }
          
                 count+=j-i+1;
                 j++;
              }
      
          return count;
   }
    
    
    
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
    
      return atmost(arr,N,target)-atmost(arr,N,target-1);
      
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends