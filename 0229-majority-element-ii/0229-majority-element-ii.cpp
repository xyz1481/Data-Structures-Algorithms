class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int val = floor(n/3);
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        for(auto it : mpp){
            if(it.second > val) ans.push_back(it.first);
        }
        return ans;
    }
};