class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(k+1,0));
        vector<vector<int>> temp(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap =1;cap<=k;cap++){
                    if(buy)
                    dp[buy][cap] = max(-prices[index]+temp[0][cap],temp[1][cap]); 
                    else
                    dp[buy][cap] = max(prices[index]+temp[1][cap-1],temp[0][cap]);
                }
            }
            temp = dp;
        }
        return dp[1][k];
    }
};