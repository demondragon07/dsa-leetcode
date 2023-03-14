//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
      string countSort(string arr){
       int count [26]={0};
       string output(arr.length(),' ');
       for(int i=0;i<arr.length();i++){
           count[arr[i]-'a']++;
       }
       
       for(int i=1;i<26;i++){
           count[i]=count[i-1]+count[i];
       }
       for(int i=arr.length()-1;i>=0;i--){
           output[count[arr[i]-'a']-1]=arr[i];
           count[arr[i]-'a']--;
       }
       return output;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends