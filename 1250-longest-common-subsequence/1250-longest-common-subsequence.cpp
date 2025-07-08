class Solution {
public://ig for this method even traversing back doesnt work for sc of O(m) 
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m+1,0),temp(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(dp[j],temp[j-1]);
            }
            dp = temp;
        }
        return dp[m];
    }
};




//memorization
// class Solution {
// private:
//     int f(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
//         if(i<0 || j<0) return 0;
//         if(dp[i][j]!= -1) return dp[i][j];
//         //match
//         if(text1[i]==text2[j]) return dp[i][j] = 1 + f(i-1,j-1,text1,text2,dp);
//         //no match
//         return dp[i][j] = max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return f(n-1,m-1,text1,text2,dp);
//     }
// };



//pure recursion
// class Solution {
// private:
//     int f(int i,int j,string &text1,string &text2){
//         if(i<0 || j<0) return 0;
//         //match
//         if(text1[i]==text2[j]) return 1 + f(i-1,j-1,text1,text2);
//         return max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();
//         return f(n-1,m-1,text1,text2);
//     }
// };