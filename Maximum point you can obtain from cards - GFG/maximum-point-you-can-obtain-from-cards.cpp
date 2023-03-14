//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
            long long j=N-1;
            long long i=0;
            long long score=0;
            long long count=0;
            
            for(int i=0;i<k;i++){
                count+=cardPoints[i];
            }
            score=count;
            
            for(int i=k-1;i>=0;i--){
             count+=cardPoints[j]-cardPoints[i];
             score=max(score,count);
             j--;
            }
            
         return score;
} 
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends