//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
 
  private:
  
  vector<int>nextsmaele(int arr[],int n){
        
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    
    vector<int>prevsmaele(int arr[],int n){
        
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        
        return ans;
    }
  
   long long getMaxArea(int arr[], int n)
    {
        
        vector<int>next(n);
        next=nextsmaele(arr,n);
        
        vector<int>prev(n);
        prev=prevsmaele(arr,n);
        
        long long area=INT_MIN;
        for(long long i=0;i<n;i++){
            long long l=arr[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            
            long long b=next[i]-prev[i]-1;
            long long  newarea=l*b;
            
            area=max(area,newarea);
        }
        return area;
    }
  
  
   
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
       int area=getMaxArea(M[0],m);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }else{
                    M[i][j]=0;
                }
            }  
             int newArea=getMaxArea(M[i],m);
                area=max(area,newArea);
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends