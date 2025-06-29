class Solution {
private:
    void f(int index,vector<int>& nums,vector<int> &sub,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(sub);
            return;
        }
        ans.push_back(sub);
        for(int i = index;i<nums.size();i++){
            if(i > index && nums[i]==nums[i-1]) continue;
            sub.push_back(nums[i]);
            f(i+1,nums,sub,ans);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> sub;
        f(0,nums,sub,ans);
        return ans;
    }
};