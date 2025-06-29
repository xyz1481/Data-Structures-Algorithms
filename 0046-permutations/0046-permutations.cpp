class Solution {
private:
    void f(int index,vector<int> &sub,vector<int> &nums,vector<vector<int>> &ans,int n){
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            f(index+1,sub,nums,ans,n);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub; 
        vector<vector<int>> ans;
        int n = nums.size();
        f(0,sub,nums,ans,n);
        return ans;
    }
};