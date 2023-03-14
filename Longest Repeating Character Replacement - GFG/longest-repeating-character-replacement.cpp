//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
   unordered_map<char,int>m;
     
      int count=INT_MIN;
      int j=0,i=0;
      int ans=0;
      
    while(j<S.length()){
            m[S[j]]++;
            count=max(count,m[S[j]]);
        
          if(j-i+1-count>K){
                    m[S[i]]--;
                     i++;
         }
        ans=max(ans,j-i+1);
        j++;
     }
    return ans;
 }


     
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends