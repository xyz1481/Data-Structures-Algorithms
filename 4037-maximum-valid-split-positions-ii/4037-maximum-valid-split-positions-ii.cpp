class Solution {
public:
    int solve(vector<int> &prefix,vector<int> &suffix,vector<int> &nums,int skip){
        int cnt = 0;
        int n = nums.size();
        //calculating prefix
        for(int i=1;i<=n;i++){
            if(i==skip+1){
                prefix[i] = prefix[i-1];
            }else{
                prefix[i] = gcd(prefix[i-1],nums[i-1]);
            }
        }
        //calculating suffix
        for(int i=n-1;i>=0;i--){
            if(i==skip){
                suffix[i] = suffix[i+1];
            }else{
                suffix[i] = gcd(suffix[i+1],nums[i]);
            }
        }
        //forming splits
        for(int i=0;i<n-1;i++){
            if(i==skip) continue;
            if(prefix[i+1]==suffix[i+1]) cnt++;
        }
        return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        vector<int> premain(n+1,0);
        for(int i=1;i<=n;i++){
            premain[i] = gcd(premain[i-1],nums[i-1]);
        }
        for(int i=1;i<=n;i++){
            if(premain[i]!= premain[i-1]){
                vector<int> prefix(n+1,0);
                vector<int> suffix(n+1,0);
                ans = max(ans,solve(prefix,suffix,nums,i-1));
            }
        }
        vector<int> prefix(n+1,0);
        vector<int> suffix(n+1,0);
        ans = max(ans,solve(prefix,suffix,nums,-1));
        return ans;
    }
};