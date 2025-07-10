class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<int> dp(n+1,0),temp(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) temp[j] = 1 + dp[j-1];
                else temp[j] = max(temp[j-1],dp[j]); 
            }
            dp = temp;
        }
        return n - dp[n];
    }
};