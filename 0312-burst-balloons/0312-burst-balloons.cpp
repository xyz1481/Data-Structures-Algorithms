class Solution {
private:
    int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int index=i;index<=j;index++){
            int cost = nums[i-1]*nums[index]*nums[j+1] + f(i,index-1,nums,dp) + f(index+1,j,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        return f(1,n,nums,dp);
    }
};