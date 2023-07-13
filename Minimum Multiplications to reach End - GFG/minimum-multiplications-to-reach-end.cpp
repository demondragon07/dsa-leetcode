//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       queue<pair<int,int>>q;
       q.push({start,0});
       vector<int>dist(100000,1e9);
       int mod=100000;
       dist[start]=0;
       
       while(!q.empty()){
           auto it=q.front();
           int num=it.first;
           int steps=it.second;
           q.pop();
           
           for(auto x:arr){
               int newnum=(x*num)%mod;
               if(steps+1<dist[newnum]){
                   if(newnum==end){
                   return steps+1;
               }
                   dist[newnum]=steps+1;
                   q.push({newnum,steps+1});
               }
           }
           
       }
       if(start==end){
           return 0;
       }
      
       return -1;
       
       
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends