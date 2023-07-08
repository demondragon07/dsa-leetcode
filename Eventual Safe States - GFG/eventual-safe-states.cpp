//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 private:
 bool checksafe(int node,int vis[],int pathvis[],int check[],vector<int>adj[])
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto x:adj[node]){
            if(!vis[x]){
                if(checksafe(x,vis,pathvis,check,adj)==true){
                    check[node]=0;
                     return true;
                }
            }
            
             else if(pathvis[x]){
                    check[node]=0;
                    return true;
                }
            
        }
        
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
 
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
      
      int vis[V]={0};
      int pathvis[V]={0};
      int check[V]={0};
      vector<int>safe;
      
      
      for(int i=0;i<V;i++){
          if(!vis[i]){
              checksafe(i,vis,pathvis,check,adj);
          }
      }
      
      for(int i=0;i<V;i++){
          if(check[i]==1){
              safe.push_back(i);
          }
      }
      
      return safe;
      
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends