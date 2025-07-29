class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),maxi=1,max_index=0;
        vector<int> dp(n,1),hash(n,0);
        for(int i=1;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j; 
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                max_index = i;
            } 
        }
        vector<int> res;
       int index = max_index;
        while(hash[index]!=index){
            res.push_back(nums[index]);
            index = hash[index];
        } 
        res.push_back(nums[index]);
        return res;

    }
};