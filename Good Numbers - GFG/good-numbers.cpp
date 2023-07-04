//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  private:
  
  bool solve(int n,int D,int sum){
     if(n==0){
         return true;
     }
     int temp=n%10;
     if(temp==D || temp<=sum){
         return false;
     }
      return solve(n/10,D,sum+temp);
   }
  
  
  public:
    vector<int> goodNumbers(int L, int R, int D) {
        vector<int>ans;
        for(int n=L;n<=R;n++){
           if(n%10==D){
               continue;
           }
           if(solve(n/10,D,n%10)){
               ans.push_back(n);
           }
        }
        
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends