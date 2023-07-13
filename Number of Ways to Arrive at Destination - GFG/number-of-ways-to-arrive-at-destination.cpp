//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
         
         vector<pair<int,int>>adj[n];
         for(auto x:roads){
             adj[x[0]].push_back({x[1],x[2]});
             adj[x[1]].push_back({x[0],x[2]});
         }
         
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         
         vector<long >dist(n,1e18);
         vector<int>ways(n,0);
         dist[0]=0;
         ways[0]=1;
         pq.push({0,0});
         int mod=(1e9+7);
         
         while(!pq.empty()){
             auto it=pq.top();
             int node=it.second;
             long dis=it.first;
             pq.pop();
             
             for(auto x:adj[node]){
                 int adjnode=x.first;
                long edgewt=x.second;
                 
                 if(dis+edgewt<dist[adjnode]){
                     dist[adjnode]=dis+edgewt;
                     ways[adjnode]=ways[node]%mod;
                     pq.push({dist[adjnode],adjnode});
                 }
                 else if(dis+edgewt==dist[adjnode]){
                     ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                 }
             }
         }
    
     
           return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends