//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    
    vector<int>nextsmaele(long long arr[],int n){
        
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
    
    
    vector<int>prevsmaele(long long arr[],int n){
        
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
    
    
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
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
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends