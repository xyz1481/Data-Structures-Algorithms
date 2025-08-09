class Solution {
private:
    int f(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int index = i;index<=j;index++){
            int cost = cuts[j+1]-cuts[i-1] + f(i,index-1,cuts,dp) + f(index+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int m, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(m);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int> (c+2,0));

        for(int i=c;i>0;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini = INT_MAX;
                for(int index = i;index<=j;index++){
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};