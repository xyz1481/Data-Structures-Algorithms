class Solution {
public:
    bool check(string &a,string &b){
        int n = a.size();
        int m = b.size();
        if(m-n != 1) return false;
        int i =0,j=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                i++;
                j++;
            }else j++;
        }
        if(i==n && j<=m) return true;
        return false;
    }
    int f(int curr,int prev,vector<string>& words,vector<vector<int>> &dp){
        int n = words.size();
        if(curr == n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        //pick
        int pick = INT_MIN;
        if(prev==-1 || check(words[prev],words[curr])) pick = 1+f(curr+1,curr,words,dp);
        //not pick 
        int not_pick = f(curr+1,prev,words,dp);
        return dp[curr][prev+1] = max(pick,not_pick);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,string &b){
            return a.size() < b.size();
        });
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,words,dp);
    }
};



// class Solution {
// public:
//     bool check(string &a,string &b){
//         int n = a.size();
//         int m = b.size();
//         if(m-n != 1) return false;
//         int i =0,j=0;
//         while(i<n && j<m){
//             if(a[i]==b[j]){
//                 i++;
//                 j++;
//             }else j++;
//         }
//         if(i==n && j<=m) return true;
//         return false;
//     }
//     int f(int curr,int prev,vector<string>& words){
//         int n = words.size();
//         if(curr == n) return 0;
//         //pick
//         int pick = INT_MIN;
//         if(prev==-1 || check(words[prev],words[curr])) pick = 1+f(curr+1,curr,words);
//         //not pick 
//         int not_pick = f(curr+1,prev,words);
//         return max(pick,not_pick);
//     }
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),[](const string &a,string &b){
//             return a.size() < b.size();
//         });
//         return f(0,-1,words);
//     }
// };
