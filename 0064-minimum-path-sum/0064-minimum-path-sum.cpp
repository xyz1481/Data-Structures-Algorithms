class Solution {
private:
    int f(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0),temp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[j] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j] + dp[j];
                    if(j>0) left = grid[i][j] + temp[j-1];
                    temp[j] = min(up,left);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return f(grid);
    }
};



// class Solution {
// private:
//     int f(int row,int col,vector<vector<int>> & grid){
//         if(row == 0 && col == 0) return grid[0][0];
//         if(row <0 || col<0) return 1e6;
//         int up = grid[row][col] + f(row-1,col,grid);
//         int left =grid[row][col] + f(row,col-1,grid);
//         return min(up,left);
//     }
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         return f(m-1,n-1,grid);
//     }
// };