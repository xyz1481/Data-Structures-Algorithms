class Solution {
private: 
    int f(int m,int n){
        vector<int> dp(n,0),temp(n,0);
        
        for(int i=0;i<m;i++){
            int prevLeft = 0;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                     temp[j] = 1;
                     prevLeft = 1;
                } 
                else{
                        temp[j] = dp[j]+prevLeft;
                        prevLeft = temp[j];
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1)); 
        return f(m,n);
    }
};


// using tabulation
// class Solution {
// private: 
//     int f(int m,int n){
//         vector<vector<int>> dp(m,vector<int>(n,0));
//         dp[0][0] = 1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) dp[0][0] = 1;
//                 else{
//                     if(i>0){
//                         int row = dp[i-1][j];
//                         dp[i][j] += row;
//                     } 
//                     if(j>0){ 
//                         int col = dp[i][j-1];
//                         dp[i][j] +=col;
//                         }
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int> (n,-1)); 
//         return f(m,n);
//     }
// };


//usign memorization
// class Solution {
// private: 
//     int f(int row,int col,int m,int n,vector<vector<int>> &dp){
//         if(row == m-1 && col == n-1) return 1;
//         if(row == m || col == n) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         int right = f(row,col+1,m,n,dp);
//         int down = f(row+1,col,m,n,dp);
//         return dp[row][col] = right+down;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int> (n,-1)); 
//         return f(0,0,m,n,dp);
//     }
// };


// recursion
// class Solution {
// private: 
//     int f(int row,int col,int m,int n){
//         if(row == m-1 && col == n-1) return 1;
//         if(row == m || col == n) return 0;
//         int right = f(row,col+1,m,n);
//         int down = f(row+1,col,m,n);
//         return right+down;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return f(0,0,m,n);
//     }
// };