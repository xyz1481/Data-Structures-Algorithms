class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            //lower bound find and replace it with that element
            //if not found insert at last
            if(nums[i] > ans.back()) ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
};

//  int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,1);
//         for(int index=1;index<n;index++){
//             for(int i=0;i<index;i++){
//                if(nums[i] < nums[index]) dp[index] = max(dp[index],1+dp[i]);
//             }
//         }
//         int ans =1;
//         for(auto it : dp) ans = max(ans,it);
//         return ans;
//     }


// class Solution {
// private:
//     int f(int index,int prev_index,int n,vector<int> &nums,vector<vector<int>> &dp){
//         if(index==n) return 0;
//         if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
//         //not pick
//          dp[index][prev_index+1] = 0 + f(index+1,prev_index,n,nums,dp);
//         //pick
//         if(prev_index==-1 || nums[index]>nums[prev_index]) 
//             dp[index][prev_index+1] = max(dp[index][prev_index+1],1 + f(index+1,index,n,nums,dp));
//         return dp[index][prev_index+1];
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+1,0),temp(n+1,0);
//         for(int index=n-1;index>=0;index--){
//             for(int prev_index=index-1;prev_index>=-1;prev_index--){
//                 dp[prev_index+1] = 0 + temp[prev_index+1];
//                 if(prev_index==-1 || nums[index]>nums[prev_index]) 
//                     dp[prev_index+1] = max(dp[prev_index+1],1 + temp[index+1]);
//             }
//             temp = dp;
//         }
//         return dp[0];
//     }
// };
