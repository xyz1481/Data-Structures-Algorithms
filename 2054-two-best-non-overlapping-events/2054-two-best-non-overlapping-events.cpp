class Solution {
public:
    int f(int i,int cnt,int n,vector<vector<int>>& events,vector<vector<int>> &dp){
        if(i==n || cnt==0) return 0;
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        int s = events[i][0];
        int e = events[i][1];
        int val = events[i][2];
        auto lb = lower_bound(events.begin()+i+1,events.end(),e+1,[](const vector<int>&v,int e){
            return v[0]<e;
        })-events.begin();
        int val1 = val +f(lb,cnt-1,n,events,dp);
        int val2 = f(i+1,cnt,n,events,dp);
        return dp[i][cnt] = max(val1,val2);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return f(0,2,n,events,dp);
    }
};