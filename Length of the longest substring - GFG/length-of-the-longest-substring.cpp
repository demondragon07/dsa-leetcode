//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
       
       int i=0,j=0;
       int m[26]={0};
       int ans=0;
        
       while(j<S.length()){
           m[S[j]-'a']++;
           
           while(m[S[j]-'a']>1){
               m[S[i]-'a']--;
               i++;
           }
        
        ans=max(ans,j-i+1);
        j++;
       }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends