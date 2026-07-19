class Solution {
public:
    int cal_paths(vector<string> &grid,int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='#') dp[i][j] = 0;
                else if(i>0 && j>0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else if(j>0) dp[i][j] = dp[i][j-1];
                else if(i>0) dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
    bool backtrack(vector<string> &grid, int m,int n,int idx,int k){
        int paths = cal_paths(grid,m,n);
        if (paths == k) return true;
        //if paths is lesser than k adding more obstacles decreases the paths so no use of going ahead
        if (paths < k) return false;
        //if paths is greater than k we can further add more obstacles to reduce the paths 
        //if we cross the m*n value then no use we are going out of the grid
        if (idx == m * n) return false;
        //place a obstacle 
        int row = idx/n;
        int col = idx%n;
        if((row == 0 && col == 0) || (row==m-1 && col == n-1))
            return backtrack(grid,m,n,idx+1,k);
        grid[row][col] = '#';
        if(backtrack(grid,m,n,idx+1,k)) return true;
        //remove the obstacle
        grid[row][col] = '.';
        //try without any obstacle
        if(backtrack(grid,m,n,idx+1,k)) return true;
        return false;

    }
    vector<string> createGrid(int m, int n, int k) {
      vector<string> grid(m,string(n,'.'));
      if(backtrack(grid,m,n,0,k)) return grid;
      return {};
    }
};