class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int curr = lower;
        for(int i=0;i<n;i++){
            if(nums[i] < lower || nums[i] > upper) continue;
            if(nums[i] > curr){
                ans.push_back({curr,nums[i]-1}); 
            }
            curr = nums[i]+1;
        }
        if(curr <= upper) ans.push_back({curr,upper});
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         int n = nums.size();
//         if(nums[0]>lower) ans.push_back({lower,nums[0]-1});
//         for(int i=0;i<n-1;i++){
//             if(nums[i]>=lower && nums[i+1]<=upper && nums[i]!=nums[i+1]){
//                 ans.push_back({nums[i]+1,nums[i+1]-1});
//             }
//         }
//         if(nums[n-1] < upper) ans.push_back({nums[n-1]+1,upper});        
//         return ans;
//     }
// };






// while(nums[n-1]>upper){
//             nums.pop_back();
//             n--;
//         }
        // while(nums[0]<lower){
        //     nums.erase(nums.begin());
        //     n--;
        // }



// 3 7 9 
// 1 ............. 12