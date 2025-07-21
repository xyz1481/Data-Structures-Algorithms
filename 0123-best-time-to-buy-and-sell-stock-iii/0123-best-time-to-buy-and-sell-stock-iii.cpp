class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(3,0));
        vector<vector<int>> temp(2,vector<int>(3,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                        if(buy)
                         dp[buy][cap] = max(-prices[index]+temp[0][cap],temp[1][cap]); 
                        else
                         dp[buy][cap] = max(prices[index]+temp[1][cap-1],temp[0][cap]);
                }
            }
            temp = dp;
        }
        return dp[1][2];
    }
};



// tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                 for(int cap=1;cap<=2;cap++){
//                         if(buy)
//                          dp[index][buy][cap] = max(-prices[index]+dp[index+1][0][cap],dp[index+1][1][cap]); 
//                         else
//                          dp[index][buy][cap] = max(prices[index]+dp[index+1][1][cap-1],dp[index+1][0][cap]);
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
// };


//memorization
// class Solution {
// private:
//     int f(int index,int buy,int cap,int n,vector<int> &prices,vector<vector<vector<int>>> &dp){
//         if(cap == 0 || index==n) return 0;
//         if(dp[index][buy][cap]!= -1) return dp[index][buy][cap];
//         if(buy)
//         return dp[index][buy][cap] = max(-prices[index]+f(index+1,0,cap,n,prices,dp),f(index+1,1,cap,n,prices,dp)); 
//         else
//         return dp[index][buy][cap] = max(prices[index]+f(index+1,1,cap-1,n,prices,dp),f(index+1,0,cap,n,prices,dp));
//     }
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
//         return f(0,1,2,n,prices,dp);
//     }
// };