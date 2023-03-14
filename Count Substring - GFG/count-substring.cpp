//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
     int i=0,j=0;
     int n=s.length();
     int count=0;
     int a=0,b=0,c=0;
     
     while(j<n){
      if(s[j]=='a'){
          a++;
      }
      
      else if(s[j]=='b'){
          b++;
      }
       
      else if(s[j]=='c'){
          c++;
      } 
    
     while(a>0 && b>0 && c>0){
         count+=n-j;
         if(s[i]=='a'){
             a--;
         }
         else if(s[i]=='b'){
             b--;
         }
         else if(s[i]=='c'){
             c--;
         }
         i++;
     }
         
       j++;  
         
     }
     return count;
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends