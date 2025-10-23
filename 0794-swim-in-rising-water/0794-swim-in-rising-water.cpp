class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,pair<int,int>>> cell;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            cell.push_back({grid[i][j],{i,j}});
            }
        }
        //sort according to the height
        sort(cell.begin(),cell.end());
        DisjointSet ds(n*n);
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int height = 0;
        vector<vector<int>> flooded(n,vector<int> (n,0));
        for(auto it : cell){
             height = it.first;
            int row = it.second.first;
            int col = it.second.second;
            flooded[row][col] = 1;
            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && flooded[nrow][ncol]){
                    int node = row*n + col;
                    int adjNode = nrow*n + ncol;
                    int ultp_u = ds.findUPar(node);
                    int ultp_v = ds.findUPar(adjNode);
                    if(ultp_u != ultp_v)  ds.unionByRank(node,adjNode);
                }
            }
            if(ds.findUPar(0)==ds.findUPar(n*n - 1)) return height;
        }
        return height;
    }
};