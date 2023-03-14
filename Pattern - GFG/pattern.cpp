//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n){
     
       int star=1;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n-i;j++){
               cout<<" ";
           }
           
           for(int j=1;j<=star;j++){
               cout<<"*"<<" ";
           }
           
           star+=1;
           cout<<endl;
       }
        int tara =n;
       for(int i=1;i<=n;i++){
        
           for(int j=1;j<i;j++){
               cout<<" ";
           }
           
           for(int j=1;j<=tara;j++){
               cout<<"*"<<" ";
           }
    
         
           tara-=1;
           cout<<endl;
       }
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends