class Solution {
private:

int solve(vector<int>&num,int i,int j){
    if(i>j){
        return 0;
    }

    if(i==j){
        return num[i];
    }

    int op1=num[i]+min(solve(num,i+2,j),solve(num,i+1,j-1));
    int op2=num[j]+min(solve(num,i+1,j-1),solve(num,i,j-2));

    return max(op1,op2);
}

public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
      int p1_score=solve(nums,0,n-1);
      int totalsum=0;
      for(int i=0;i<n;i++){
          totalsum+=nums[i];
      }
        int p2_score=totalsum-p1_score;
        if(p1_score>=p2_score){
            return true;
        }else{
            return false;
        }
    }
};