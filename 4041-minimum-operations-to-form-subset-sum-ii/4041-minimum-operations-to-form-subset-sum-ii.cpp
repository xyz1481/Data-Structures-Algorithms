class Solution {
public:
    int find(int i,int total_sum,vector<vector<pair<int,int>>> &v,int n,vector<vector<int>> &dp){
        if(total_sum==0) return 0;
        if(total_sum < 0 || i==n) return INT_MAX;
        if(dp[i][total_sum]!=-1) return dp[i][total_sum];
        //pick
        int pick = INT_MAX;
        for(auto it : v[i]){
            int val = it.first;
            int c = it.second;
            int next = find(i+1,total_sum - val,v,n,dp);
            if(next!=INT_MAX) pick = min(pick,c+next);
        }
        int not_pick = find(i+1,total_sum,v,n,dp);
        return dp[i][total_sum]=min(pick,not_pick);
    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<pair<int,int>>> v(n+1,vector<pair<int,int>>());
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        for(int i=0;i<n;i++){
            int val = nums[i];
            int cost = 0;
            while(val > sum){
                cost++;
                val = val/2;
            }
            //bfs
            vector<int> dist(sum+1,INT_MAX);
            dist[val] = cost;
            queue<pair<int,int>> q;
            q.push({val,cost});
            while(!q.empty()){
                int node = q.front().first;
                int c = q.front().second;
                q.pop();
                //2 possibilities
                //multiply
                int m = node*2;
                if(m <= sum && dist[m] > c+1){
                    dist[m] = c+1;
                    q.push({m,c+1});
                }
                int d = node/2;
                if(d<=sum && dist[d] > c+1){
                    dist[d] = c+1;
                    q.push({d,c+1});
                }
            }
            for(int j=0;j<sum+1;j++){
                if(dist[j]!=INT_MAX) v[i].push_back({j,dist[j]});
            }
        }
        int ans = find(0,sum,v,n,dp);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};