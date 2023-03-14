//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    
private:

 bool possible_sol(vector<int> &stalls ,int n,int k,int mid){
     int last_pos=stalls[0];
     int cowcount=1;
     for(int i=0;i<n;i++){
         if(stalls[i]-last_pos>=mid){
            cowcount++;
                if(cowcount==k){
                     return true;
                     }
                       last_pos=stalls[i];
      }     
    }
 return false;
 }
    
    
    
    
    
    
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int s=0;
        int maxi=-1;
        int ans=-1;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,stalls[i]);
            
        }
        
         int e=maxi;
      while(s<=e){
          int mid=s+(e-s)/2;
          if(possible_sol(stalls,n,k,mid)){
              ans=mid;
              s=mid+1;
          }else{
              e=mid-1;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends