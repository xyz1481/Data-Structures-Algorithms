class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        vector<int> suffix(n,-1);
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
                if(i+k < n) ans = max(ans,nums[i]+suffix[i+k]);
        }
        return ans;
    }
};