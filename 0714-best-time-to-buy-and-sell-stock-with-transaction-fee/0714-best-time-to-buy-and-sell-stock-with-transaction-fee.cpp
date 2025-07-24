class Solution {
private:
    int f(int index,int buy,int n,vector<int>& prices, int fee,vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy) return dp[index][buy] = max(-prices[index]+f(index+1,0,n,prices,fee,dp),f(index+1,1,n,prices,fee,dp));
        else return dp[index][buy] = max(prices[index]-fee+f(index+1,1,n,prices,fee,dp),f(index+1,0,n,prices,fee,dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2,0),temp(2,0);
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<=1;buy++){
                if(buy) dp[buy] = max(-prices[index]+temp[0],temp[1]);
                else dp[buy] = max(prices[index]-fee+temp[1],temp[0]);
            }
            temp = dp;
        }
        return dp[1];
    }
};