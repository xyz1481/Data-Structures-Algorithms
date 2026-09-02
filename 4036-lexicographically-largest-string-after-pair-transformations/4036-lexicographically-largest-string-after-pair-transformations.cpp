class Solution {
public:
    string find(int num){
        string ans="";
        for(int bits=30;bits>=0;bits--){
            if(num & 1<<bits){
                char alpha = char('a' + bits);
                if(alpha > 'z'){
                    int cnt = 1<<bits-25;
                    ans += string(cnt,'z');
                } 
                else ans += alpha;
            }
        }
        return ans;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(find(nums[i]));
        }
        return ans;
    }
};