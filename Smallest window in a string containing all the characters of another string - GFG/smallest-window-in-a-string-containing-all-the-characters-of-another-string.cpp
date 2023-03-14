//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int>m;
        int i=0,j=0,start=0;
        int ans=INT_MAX;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
        
        int count=m.size();
        
        while(j<s.length()){
            
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
            }
            
            if(count==0){
                while(count==0){
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]==1){
                            count++;
                        if(j-i+1<ans){
                            ans=j-i+1;
                           start=i;
                        }
                    }
                }
                i++;
            }
        }
        j++;
    }
     if(ans!=INT_MAX){
         return s.substr(start,ans);
     }else{
         return "-1";
     }
    
 } 
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends