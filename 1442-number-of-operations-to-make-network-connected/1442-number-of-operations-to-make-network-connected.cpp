class DisjointSet{
    vector<int> rank,size,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } 
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        if(rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<pair<int,pair<int,int>>> edges;
        
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            int ulp_u = ds.findUPar(u);
            int ulp_v = ds.findUPar(v);
            if(ulp_u != ulp_v){
                ds.unionByRank(u,v);
            }else{
                extraEdges++;
            }
        }
        int noOfComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i) noOfComponents++;
        }
        if(noOfComponents-1 <= extraEdges) return noOfComponents-1;
        else return -1;
    }
};