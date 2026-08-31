class Solution {
public:
    int knapsack(int i,int total_sum,vector<vector<pair<int,int>>> &v,int n,vector<vector<int>> &dp){
        if(total_sum==0) return 0;
        if(total_sum < 0 || i==n) return INT_MAX;
        if(dp[i][total_sum]!=-1) return dp[i][total_sum];
        //pick
        int pick = INT_MAX;
        for(auto it : v[i]){
            int val = it.first;
            int c = it.second;
            int next = knapsack(i+1,total_sum - val,v,n,dp);
            if(next!=INT_MAX) pick = min(pick,c+next);
        }
        int not_pick = knapsack(i+1,total_sum,v,n,dp);
        return dp[i][total_sum]=min(pick,not_pick);
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        //finding all the possible operations and cost 
        // pair<sum,cost>
        for(int i=0;i<n;i++){
            int val = nums[i];
            int cost = 0;
            v[i].push_back({val,0});
            //1st multiplication
            while(val < sum){
                val *= 2;
                cost++;
                v[i].push_back({val,cost});
            }
            //division op
            cost = 0;
            val = nums[i];
            while(val > 0){  // not equal to 0 as causes infinite loop
                val /= 2;
                cost++;
                v[i].push_back({val,cost});
            }
        }
        int ans = knapsack(0,sum,v,n,dp);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};

// recursion approach
// class Solution {
// public:
//     int knapsack(int i,int total_sum,vector<vector<pair<int,int>>> &v,int n){
//         if(total_sum==0) return 0;
//         if(total_sum < 0 || i==n) return INT_MAX;
//         //pick
//         int pick = INT_MAX;
//         for(auto it : v[i]){
//             int val = it.first;
//             int c = it.second;
//             int next = knapsack(i+1,total_sum - val,v,n);
//             if(next!=INT_MAX) pick = min(pick,c+next);
//         }
//         int not_pick = knapsack(i+1,total_sum,v,n);
//         return min(pick,not_pick);
//     }
//     int minOperations(vector<int>& nums, int sum) {
//         int n = nums.size();
//         vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
//         //finding all the possible operations and cost 
//         // pair<sum,cost>
//         for(int i=0;i<n;i++){
//             int val = nums[i];
//             int cost = 0;
//             v[i].push_back({val,0});
//             //1st multiplication
//             while(val < sum){
//                 val *= 2;
//                 cost++;
//                 v[i].push_back({val,cost});
//             }
//             //division op
//             cost = 0;
//             while(val > 0){  // not equal to 0 as causes infinite loop
//                 val /= 2;
//                 cost++;
//                 v[i].push_back({val,cost});
//             }
//         }
//         int ans = knapsack(0,sum,v,n);
//         if(ans == INT_MAX) return -1;
//         else return ans;
//     }
// };


// we didnt need the cost parameter
// class Solution {
// public:
//     int knapsack(int i,int cost,int total_sum,vector<vector<pair<int,int>>> &v,int n){
//         if(total_sum==0) return cost;
//         if(total_sum < 0 || i==n) return INT_MAX;
//         //pick
//         int pick = INT_MAX;
//         for(auto it : v[i]){
//             int val = it.first;
//             int c = it.second;
//             pick = min(pick,knapsack(i+1,cost + c,total_sum - val,v,n));
//         }
//         int not_pick = knapsack(i+1,cost,total_sum,v,n);
//         return min(pick,not_pick);
//     }
//     int minOperations(vector<int>& nums, int sum) {
//         int n = nums.size();
//         vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
//         //finding all the possible operations and cost 
//         // pair<sum,cost>
//         for(int i=0;i<n;i++){
//             int val = nums[i];
//             int cost = 0;
//             v[i].push_back({val,0});
//             //1st multiplication
//             while(val < sum){
//                 val *= 2;
//                 cost++;
//                 v[i].push_back({val,cost});
//             }
//             //division op
//             cost = 0;
//             while(val > 0){  // not equal to 0 as causes infinite loop
//                 val /= 2;
//                 cost++;
//                 v[i].push_back({val,cost});
//             }
//         }
//         int ans = knapsack(0,0,sum,v,n);
//         if(ans == INT_MAX) return -1;
//         else return ans;
//     }
// };
