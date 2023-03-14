//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  int atmost(int n, vector<int>& nums, int k){
       int i=0,j=0;
        int count=0;
        int ans=0;
        while(j<n){
            if(nums[j]%2!=0){
                count++;
            }
            
            while(count>k){
                if(nums[i]%2!=0){
                    count--;
                }
                i++;
            }
            
            ans+=j-i+1;
            j++;
        }
        return ans;
  }
    
    
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        int answer;
        answer=atmost(n,nums,k)-atmost(n,nums,k-1);
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends