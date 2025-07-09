class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s; 
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<int> temp(n+1,0),dp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(dp[j],temp[j-1]); 
            }
            dp = temp;
        }
        return dp[n];
    }
};

//if we reverse the given string we get a new string s2
//comparing lcs for s1 and s2 we should get longest palindromic subsequence