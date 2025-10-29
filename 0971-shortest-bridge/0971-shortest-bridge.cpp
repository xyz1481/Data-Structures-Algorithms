class Solution {
    void dfs(int r,int c,int n,vector<vector<int>> &temp,queue<pair<int,int>> &q){
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        temp[r][c] = 2;
        q.push({r,c});
        for(int i=0;i<4;i++){
            int nr = delrow[i] + r;
            int nc = delcol[i] + c;
            if(nc>=0 && nc<n && nr>=0 && nr<n && temp[nr][nc]==1){
                dfs(nr,nc,n,temp,q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int first_island=0;
        vector<vector<int>> temp = grid;
        queue<pair<int,int>> q;
       
        for(int i=0;i<n;i++){
            if(first_island==0){
                for(int j=0;j<n;j++){
                  if(temp[i][j]==1){
                    dfs(i,j,n,temp,q);
                    first_island = 1;
                    break;
                  }  
                }
            }
        }
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            int flips = 0;
            while(!q.empty()){
                int size = q.size();
                while(size){
                    auto it = q.front();
                    int r = it.first;
                    int c = it.second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nr = delrow[i] + r;
                        int nc = delcol[i] + c;
                        if(nr>=0 && nr<n && nc>=0 && nc<n && temp[nr][nc]!=2){
                            if(temp[nr][nc]==1) return flips;
                            temp[nr][nc]=2;
                            q.push({nr,nc});
                        }
                    }
                    size--;
                }
                flips++;
            }
            return -1;
    }
  
};


