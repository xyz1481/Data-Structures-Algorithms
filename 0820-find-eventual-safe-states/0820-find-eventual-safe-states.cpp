class Solution {
    bool dfs(int node,vector<vector<int>>& graph,vector<int> &check,vector<int> &vis,vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,check,vis,pathVis)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> check(V, 0), vis(V, 0), pathVis(V, 0);
        for(int i=0;i<V;i++){
          if(!vis[i])  dfs(i,graph,check,vis,pathVis);
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
           if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};