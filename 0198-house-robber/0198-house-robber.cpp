class Solution {
//private:
//Recursion--
 /*   int solve(vector<int>& nums ,int i){
        if(i>=nums.size()){
            return 0;
        }
        
        int op1=nums[i]+solve(nums,i+2);
        int op2=0+solve(nums,i+1);
        return max(op1,op2);
    }
*/
private:
    int solve(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int op1=nums[i]+solve(nums,i+2,dp);
        int op2=0+solve(nums,i+1,dp);
         dp[i]=max(op1,op2);
        return dp[i];
       
    }
public:
    int rob(vector<int>& nums) {
         vector<int>dp(nums.size()+2,-1);
       return solve(nums,0,dp);
       
    }
};