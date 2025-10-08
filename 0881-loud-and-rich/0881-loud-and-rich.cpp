class Solution {
vector<int> dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int>& quiet,vector<int> &ans){
    //vis arry will store the quietness if visited else will be -1
    if(vis[node]!=-1) return {quiet[node],node};
    if(adj[node].size()==0){
        vis[node] = quiet[node];
        ans[node] = node;
        //{quietness,candidate}
        return {quiet[node],node};
    } 
    int mini = quiet[node];
    int res=node;
    for(auto it : adj[node]){
       if(vis[it]==-1){
            auto temp = dfs(it,adj,vis,quiet,ans);
            if(temp[0] < mini){
                mini = temp[0];
                res = temp[1];
           }
        }
        else{
            if(vis[it] < mini){
                mini = vis[it];
                res = ans[it];
            }
        }
        //we dont need the quitness instead need the person with that quoetness
    }
    ans[node] = res;
    vis[node] = mini; 
    return {mini,res}; //we were returning 0
}
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //make a graph and apply dfs
        int V = quiet.size();
        vector<int> vis(V, -1); 
        vector<int> ans(V);
        vector<vector<int>> adj(V);
        for(auto &it : richer){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            dfs(i,adj,vis,quiet,ans);
        }
        return ans;
    }
};