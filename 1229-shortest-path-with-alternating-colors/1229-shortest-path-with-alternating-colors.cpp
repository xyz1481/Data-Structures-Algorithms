class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto it : blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dis(n,vector<int>(2,INT_MAX));
        q.push({{0,0},0});
        q.push({{0,0},1});
        //dist {{node,dist},color}
        dis[0][0] = 0;
        dis[0][1] = 0;
        while(!q.empty()){
            int node = q.front().first.first;
            int dist = q.front().first.second;
            int color = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                if(it.second != color && dist+1 < dis[it.first][it.second]){
                    q.push({{it.first,dist+1},it.second});
                    dis[it.first][it.second] = dist+1;
                }
            }

        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
                ans[i] = min(dis[i][0],dis[i][1]);
                if(ans[i]==INT_MAX) ans[i] = -1; 
        }
        return ans;
    }
};