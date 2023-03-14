//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>ans;
        int starti=0;
        int endi=r-1;
        int startj=0;
        int endj=c-1;
        int count=0;
        int total=r*c;
        
        while(count<total){
            
            for(int i=startj; i<=endj && count<total ; i++){
                ans.push_back(matrix[starti][i]);
                count++;
            }
            starti++;
            
            for(int i=starti; i<=endi && count<total ; i++){
                ans.push_back(matrix[i][endj]);
                count++;
            }
            endj--;
            
            for(int i=endj; i>=startj && count<total ; i--){
                ans.push_back(matrix[endi][i]);
                count++;
            }
            endi--;
            
            for(int i=endi; i>=starti && count<total ; i--){
                ans.push_back(matrix[i][startj]);
                count++;
            }
            startj++;
            
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends