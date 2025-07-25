class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX,min2 = INT_MAX;
        for(auto it : nums){
            if(it <= min1) min1 = it;
            else if(it <=min2) min2 = it;
            else return true; 
        }
        return false;
    }
};



// class Solution {
// private:
// int f(int index,int prev_index,int n,int count,vector<int> &nums,vector<vector<bool>> &dp){
//     if(count==3) return true;
//     if(index==n) return false;
//     if(dp[index][prev_index+1]!=false) return dp[index][prev_index+1];
//     //not pick
//         dp[index][prev_index+1] = f(index+1,prev_index,n,count,nums,dp);
//     //pick
//     if(prev_index==-1 || nums[index]>nums[prev_index]) 
//         dp[index][prev_index+1] = (dp[index][prev_index+1] || f(index+1,index,n,count+1,nums,dp));
//     return dp[index][prev_index+1];
// }
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
//         return f(0,-1,n,0,nums,dp);
//     }
// };