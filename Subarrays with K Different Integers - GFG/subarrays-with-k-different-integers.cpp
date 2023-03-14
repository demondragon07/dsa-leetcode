//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 
  private:
  int atmost(vector<int> &arr, int N, int k){
      vector<int>m(N+1,0);
      int i=0,j=0;
      int count=0;
      int ans=0;
      
      while(j<N){
          if(m[arr[j]]==0){
               count++;
          }
           m[arr[j]]++;
    
          while(count>k){
              m[arr[i]]--;
              if(m[arr[i]]==0){
                  count--;
              }
               i++;
            } 
         ans+=j-i+1;
         j++;
    }
      return ans;
      
  }
  
  
  public:
    int subarrayCount(vector<int> &arr, int N, int k) {
      int answer=0;
      
      int first=atmost(arr,N,k);
      int second=atmost(arr,N,k-1);
      
       answer=first-second;
       return answer;
      
    }
 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends