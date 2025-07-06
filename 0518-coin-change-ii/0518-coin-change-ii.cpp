class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount+1,0),temp(amount+1,0);
        dp[0] += 1;
        for(int i=coins[0];i<=amount;i++){
            if(i%coins[0]==0) dp[i] += 1; 
        }
        for(int i = 1;i < n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long notTake = dp[j];
                unsigned long long take = 0;
                if(coins[i]<= j) take = temp[j - coins[i]];
                temp[j] = take+notTake;
            }
            dp = temp;
        }
        return dp[amount];
    }
};


//recursion
// class Solution {
// private:
//     int f(int index,int n,int amt,vector<int>& coins){
//         if(index==0){
//             return (amt%coins[index]==0);
//         }
//         int notTake = f(index-1,n,amt,coins);
//         int take = 0;
//         if(coins[index] <= amt) take = f(index,n,amt-coins[index],coins);
//         return notTake + take;
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         return f(n-1,n,amount,coins);
//     }
// };