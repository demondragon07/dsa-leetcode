class Solution {
private:

bool dfs(int i ,int col, int color[],vector<int>adjlist[]){
    color[i]=col;
    for(auto x:adjlist[i]){
        if(color[x]==-1){
          if(dfs(x,!col,color,adjlist)==false)
                return false;       
         } 
       else if(color[x]==col){
             return false;
        }       
    }
return true;

}




public:
    bool isBipartite(vector<vector<int>>& graph) {
        
      int n=graph.size();
      vector<int>adjlist[n];
      
      for(int i=0;i<n;i++){
          for(auto x:graph[i]){
               adjlist[i].push_back(x);
          }
      }
     
    int color[n];
   
    for(int i=0;i<n;i++){
          color[i]=-1;
        }
    
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(dfs(i,0,color,adjlist)==false){
                return false;
            }
        }
    }

return true;

    }
};