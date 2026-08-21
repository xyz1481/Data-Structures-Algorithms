class Solution {
public:
    long long f(int i,int n,int m ,vector<vector<int>> &rides,vector<long long> &dp){
        if(i==m) return 0;
        if(dp[i]!=-1) return dp[i];
        //possible
        int s = rides[i][0];
        int e = rides[i][1];
        int tip = rides[i][2];
        
        auto lb = lower_bound(rides.begin()+i+1,rides.end(),e,[](const vector<int>&v,int e){
            return v[0] < e;
        }) - rides.begin();
        long long cost1 = (1LL*(e-s+tip))+f(lb,n,m,rides,dp);
        
        long long cost2 = f(i+1,n,m,rides,dp);
        return dp[i] = max(cost1,cost2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(),rides.end());
        vector<long long> dp(m,-1);
        return f(0,n,m,rides,dp);
    }
};



//MLE not accepted
// class Solution {
// public:
//     long long f(int i,int drop,int n,int m ,vector<vector<int>> &rides,vector<vector<int>> &dp){
//         if(i==m) return 0;
//         if(dp[i][drop]!=-1) return -1;
//         //possible
//         int s = rides[i][0];
//         int e = rides[i][1];
//         int tip = rides[i][2];
//         long long cost1 = 0;
//         if(drop <= s){
//             cost1 = (e-s+tip)+f(i+1,e,n,m,rides,dp);
//         }
//         long long cost2 = f(i+1,drop,n,m,rides,dp);
//         return dp[i][drop] = max(cost1,cost2);
//     }
//     long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
//         int m = rides.size();
//         sort(rides.begin(),rides.end());
//         vector<vector<int>> dp(1e5,vector<int>(1e5,-1));
//         return f(0,0,n,m,rides,dp);
//     }
// };