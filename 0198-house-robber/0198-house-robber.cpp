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
//private:
//Recursion+ Memorization
   /* int solve(vector<int>& nums,int i,vector<int>&dp){
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
       
    }*/

  //  private:
    //Bottom-UP
   /*  int solve(vector<int>& nums){
         vector<int>dp(nums.size()+2,0);
        
        for(int i=nums.size()-1;i>=0;i--){
             int op1=nums[i]+dp[i+2];
             int op2=0+dp[i+1];
              dp[i]=max(op1,op2);
       
        }
        return dp[0];
    }
    */
    private:
    int solve(vector<int>& nums){
       int next1=0;
       int next2=0;
       int curr;
        
        for(int i=nums.size()-1;i>=0;i--){
             int op1=nums[i]+next2;
             int op2=0+next1;
              curr=max(op1,op2);
        
           next2=next1;
           next1=curr;
         
        }
        return curr;
  }

public:
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size()+2,-1);
       //return solve(nums,0,dp);
       return solve(nums);
    }
};