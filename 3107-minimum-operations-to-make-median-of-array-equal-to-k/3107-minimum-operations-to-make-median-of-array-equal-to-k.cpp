class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long mid = ceil(n/2);
        long long ops = 0;
        
        int lb = lower_bound(nums.begin(),nums.end(),k)-nums.begin();
        if(k > nums[mid]){
            for(int i=mid;i<lb;i++){
                ops += abs(nums[i]-k);
            }
        }else{
            for(int i=lb;i<=mid;i++){
                ops += abs(nums[i]-k);
            }
        }
        return ops;
    }
};
// k=
// 2 5 5 6 8 
