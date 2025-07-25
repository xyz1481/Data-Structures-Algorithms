class Solution {
private:
    int f(int index,int prev_index,int n,vector<int> &nums,vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
        //not pick
         dp[index][prev_index+1] = 0 + f(index+1,prev_index,n,nums,dp);
        //pick
        if(prev_index==-1 || nums[index]>nums[prev_index]) 
            dp[index][prev_index+1] = max(dp[index][prev_index+1],1 + f(index+1,index,n,nums,dp));
        return dp[index][prev_index+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};