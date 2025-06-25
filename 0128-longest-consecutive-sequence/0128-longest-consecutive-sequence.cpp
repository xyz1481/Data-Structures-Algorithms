class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //if(nums.size()==0) return 0;
        unordered_map<int,int> mpp;
        for(auto it : nums) mpp[it]++;
        int maxlength = 0;
        for(auto it : mpp){
            if(mpp.count(it.first-1)==0){
                int start = it.first;
                int length = 1;
                while(mpp.count(start+1)!=0){
                    start++;
                    length++;
                }
                maxlength = max(maxlength,length);
            }
        }
        return maxlength;
    }
};