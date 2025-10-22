class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            int el = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            if(row == n-1 && col == n-1) return el;

            for(int i=0;i<4;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                int max_el;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    max_el = max(el,grid[nrow][ncol]);
                    pq.push({max_el,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};

// we need to find the path with the least max elivation as the distance we can travel is infinite in 0 time

