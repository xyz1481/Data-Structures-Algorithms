class Solution {
private:
    int f(vector<int> &nums,int target){
        int n = nums.size();
        vector<int> dp(target+1,0);
        if(nums[0] <= target) dp[nums[0]] += 1;
        dp[0] += 1;
        for(int i=1;i<n;i++){
            for(int j=target;j>=0;j--){
                int notTake = dp[j];
                int take = 0;
                if(nums[i] <= j) take = dp[j-nums[i]];
                dp[j] = notTake + take;
            }
        }
        return dp[target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 
        int totalSum = 0;
        for(auto it : nums) totalSum += it;
        if(abs(target) > totalSum ||(target + totalSum)%2) return 0;
        return f(nums,(target+totalSum)/2);
    }
};
//how to handle -ve sum
//range of ans from -total_sum to total_sum 
// a clever trick
// class Solution {
// private:
//     int f(int index,int sum,int n,vector<int> &nums,int target,vector<vector<int>> &dp){
//         if(sum == target && index==n) return 1;
//         if(index==n) return 0;
//         if(dp[index][sum]!= -1) return dp[index][sum];
//         int l = f(index+1,sum+nums[index],n,nums,target,dp);
//         int r = f(index+1,sum-nums[index],n,nums,target,dp);
//         return dp[index][sum] = l + r;
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int sum =0;
//         for(auto it : nums) sum += it;
//         vector<vector<int>> dp(n+1,vector<int> (2*sum+1,-1));
//         return f(0,sum,n,nums,target+sum,dp);
//     }
// };

// s1 - s2 = d
// s1 + s2 = totalSum
// s1 - (totalSum - s1) = d;
// s1 = (d + totalSum)/2