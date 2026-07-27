class Solution {
public:
//for tabulation
    const int MOD = 1e9 + 7;
    int f(int i,int curr_profit,int count,int n,int minProfit,vector<int>&group,vector<int>&profit, vector<vector<vector<int>>> &dp){
        int m = group.size();
        vector<vector<int>> temp1(minProfit+1,vector<int> (n+1,-1));
        vector<vector<int>> temp2(minProfit+1,vector<int> (n+1,-1));
        for(int p=0;p<=minProfit;p++){
            for(int c=0;c<=n;c++){
                temp1[p][c] = (p==minProfit);
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int p=0;p<=minProfit;p++){
                for(int c=0;c<=n;c++){
                    int new_profit = min(p+profit[i],minProfit);
                    int pick = 0;
                    if(c+group[i]<=n) pick = temp1[new_profit][c+group[i]];
                    int not_pick = temp1[p][c];
                    temp2[p][c] = (pick+not_pick)%MOD;
                }
            }
            temp1 = temp2;
        }
        return temp2[0][0];
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(minProfit + 1,vector<int>(n + 1, -1)));
        return f(0,0,0,n,minProfit,group,profit,dp);
    }
};


//for tabulation
//     const int MOD = 1e9 + 7;
//     int f(int i,int curr_profit,int count,int n,int minProfit,vector<int>&group,vector<int>&profit, vector<vector<vector<int>>> &dp){
//         int m = group.size();
//         for(int p=0;p<=minProfit;p++){
//             for(int c=0;c<=n;c++){
//                 dp[m][p][c] = (p==minProfit);
//             }
//         }
//         for(int i=m-1;i>=0;i--){
//             for(int p=0;p<=minProfit;p++){
//                 for(int c=0;c<=n;c++){
//                     int new_profit = min(p+profit[i],minProfit);
//                     int pick = 0;
//                     if(c+group[i]<=n) pick = dp[i+1][new_profit][c+group[i]];
//                     int not_pick = dp[i+1][p][c];
//                     dp[i][p][c] = (pick+not_pick)%MOD;
//                 }
//             }
//         }
//         return dp[0][0][0];
//     }
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         int m = group.size();
//         vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(minProfit + 1,vector<int>(n + 1, -1)));
//         return f(0,0,0,n,minProfit,group,profit,dp);
//     }
// };


// class Solution {
// public:
// //for memorization i was only thinking of dp size like this considering the constraints
// //vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (10001 ,vector<int>(10001,-1)));
// //but since we are concerned with only valid states we can further reduce the size of dp table
// // int m = group.size();
// // vector<vector<vector<int>>> dp(m,vector<vector<int>>(minProfit + 1,vector<int>(n + 1, -1)));
//     const int MOD = 1e9 + 7;
//     int f(int i,int curr_profit,int count,int n,int minProfit,vector<int>&group,vector<int>&profit, vector<vector<vector<int>>> &dp){
//         if(i==group.size() && count <= n){
//             return curr_profit == minProfit;
//         }
//         if(count > n) return 0;
//         if(dp[i][curr_profit][count]!=-1) return dp[i][curr_profit][count];
//         int new_profit = min(curr_profit+profit[i],minProfit);
//         int pick = f(i+1,new_profit,count+group[i],n,minProfit,group,profit,dp);
//         int not_pick = f(i+1,curr_profit,count,n,minProfit,group,profit,dp);
//         return dp[i][curr_profit][count] = (pick+not_pick)%MOD;
//     }
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         int m = group.size();
//         vector<vector<vector<int>>> dp(m,vector<vector<int>>(minProfit + 1,vector<int>(n + 1, -1)));
//         return f(0,0,0,n,minProfit,group,profit,dp);
//     }
// };



//this recursion forms the basis for memorization(3d dp) and tabulation(3d dp) and then at last space optimization(2d dp)
//going form recursion to space optimization directly is not intutive at all
//so refering to such sols doesnt make sense
// class Solution {
// public:
//     int f(int i,int curr_profit,int count,int n,int minProfit,vector<int>&group,vector<int>&profit){
//         if(i==group.size()){
//             if(minProfit <= curr_profit && count<=n) return 1;
//             else return 0;
//         }
//         if(count > n) return 0;
        
//         int pick = f(i+1,curr_profit+profit[i],count+group[i],n,minProfit,group,profit);
//         int not_pick = f(i+1,curr_profit,count,n,minProfit,group,profit);
//         return pick+not_pick;
//     }
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         return f(0,0,0,n,minProfit,group,profit);
//     }
// };
