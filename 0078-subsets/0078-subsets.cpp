class Solution {
public:
    void find_subsets(int index,vector<int> &nums,vector<vector<int>>&ans,vector<int> subseq){
        if(index==nums.size()){
            ans.push_back(subseq);
            return;
        } 
        //pick 
        subseq.push_back(nums[index]);
        find_subsets(index+1,nums,ans,subseq);
        subseq.pop_back();
        //not pick
        find_subsets(index+1,nums,ans,subseq);
    }

    //using recursion
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subseq;
        find_subsets(0,nums,ans,subseq);
        return ans;
    }
};