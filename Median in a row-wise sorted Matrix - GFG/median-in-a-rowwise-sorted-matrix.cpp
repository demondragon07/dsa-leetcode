//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
             int s=0;
       int e=2000;
       int n=R*C;

       while(s<=e){
             int mid=s+(e-s)/2;
             int ans=0;
           for(int i=0;i<R;i++){
               int l=0;
               int h= C-1;
               while(l<=h){
                   int m=l+(h-l)/2;
                   if(matrix[i][m]<=mid){
                      l=m+1; 
                   }else{
                       h=m-1;
                   }
               }
               ans+=l;
           }
           
           if(ans>n/2){
               e=mid-1;
           }else{
               s=mid+1;
           }
       }
       return s;
   
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends