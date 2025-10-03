class Solution {
private:
    bool dfs(vector<vector<char>> &board,int n,int m,int row,int col,string &word,int cnt,vector<vector<int>> &vis){
        if(cnt == word.size()) return true;
        vis[row][col]=1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]==word[cnt]){
                 if(dfs(board,n,m,nrow,ncol,word,cnt+1,vis)) return true;
            }
        }
        vis[row][col] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    //start dfs
                    vector<vector<int>> vis(n,vector<int> (m,0));
                    if(dfs(board,n,m,i,j,word,1,vis)) return true;
                }
            }
        }
        return false;
    }
};