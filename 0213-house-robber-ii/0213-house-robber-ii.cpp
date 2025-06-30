class Solution {
private:
    int f(int index,vector<int> nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int pick = nums[i] + prev2;
            int not_pick = 0 + prev;
            prev2 = prev;
            prev = max(pick,not_pick);
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> nums1(n-1,0),nums2(n-1,0);
        for(int i=0;i<n;i++){
            if(i!=n-1) nums1.push_back(nums[i]);
            if(i!=0) nums2.push_back(nums[i]);
        } 
        return max(f(0,nums1),f(0,nums2));
    }
};