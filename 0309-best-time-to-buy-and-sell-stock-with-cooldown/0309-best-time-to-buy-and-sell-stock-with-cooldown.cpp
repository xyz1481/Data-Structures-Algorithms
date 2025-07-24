class Solution {
private:
    int f(int index,int buy,int n,vector<int>& prices,vector<vector<int>> &dp){
        if(index>=n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy) return dp[index][buy] = max(-prices[index] + f(index+1,0,n,prices,dp),f(index+1,1,n,prices,dp));
        else return dp[index][buy] = max(prices[index]+f(index+2,1,n,prices,dp),f(index+1,0,n,prices,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2,0),front1(2,0),front2(2,0);
        for(int index=n-1;index>=0;index--){
            //for(int buy=0;buy<=1;buy++){ will still work
                dp[1] = max(-prices[index] + front1[0],front1[1]);
                dp[0] = max(prices[index]+front2[1],front1[0]);
            //}
            front2 = front1;
            front1 = dp;
        }
        return dp[1];
    }
};