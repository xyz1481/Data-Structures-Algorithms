class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m+1,0),temp(m+1,0);
        for(int j=0;j<=m;j++) dp[j] = j;
        for(int i=1;i<=n;i++){
            temp[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]) temp[j] = dp[j-1];
                else{
                    temp[j] = 1 +  min(dp[j-1],min(dp[j],temp[j-1]));
                }
            }
            dp = temp;
        }
        return dp[m];
    }
};


//tabulation
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n+1,vector<int> (m+1,0));
//         for(int i=0;i<=n;i++) dp[i][0] = i;
//         for(int j=0;j<=m;j++) dp[0][j] = j;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
//                 else{
//                     dp[i][j] = 1 +  min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
//                 }
//             }
//         }
//         return dp[n][m];
//     }
// };

//memorization
// class Solution {
// private:
//     int f(int i,int j,string &word1,string &word2,vector<vector<int>> &dp){
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(word1[i]==word2[j]) return dp[i][j] = f(i-1,j-1,word1,word2,dp);
//         return dp[i][j] =  1 + min(f(i-1,j,word1,word2,dp),min(f(i,j-1,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n,vector<int> (m,-1));
//         return f(n-1,m-1,word1,word2,dp);
//     }
// };


//recursion
// class Solution {
// private:
//     int f(int i,int j,string &word1,string &word2){
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(word1[i]==word2[j]) return f(i-1,j-1,word1,word2);
//         return 1 + min(f(i-1,j,word1,word2),min(f(i,j-1,word1,word2),f(i-1,j-1,word1,word2)));
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         return f(n-1,m-1,word1,word2);
//     }
// };