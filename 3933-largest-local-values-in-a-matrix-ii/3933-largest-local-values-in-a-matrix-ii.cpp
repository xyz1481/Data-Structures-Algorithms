class Solution {
public:
    int get_sum(int x,int r_s,int r_e,int c_s,int c_e,vector<vector<vector<int>>> &pfx){
        if(r_s > r_e || c_s > c_e) return 0;
        return pfx[x][r_e+1][c_e+1] - pfx[x][r_e+1][c_s] - pfx[x][r_s][c_e+1] + pfx[x][r_s][c_s];
    }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<vector<int>>> pfx(201,(vector<vector<int>>(m+1,vector<int>(n+1,0))));
        //calculating prefix matrix
        for(int k=0;k<=200;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    pfx[k][i][j] = pfx[k][i-1][j] + pfx[k][i][j-1] - pfx[k][i-1][j-1];
                    if(matrix[i-1][j-1] > k) pfx[k][i][j]++;
                }
            }
        }        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = matrix[i][j];
                if(x==0) continue;
                int r_s = max(0,i-x);
                int c_s = max(0,j-x);
                int r_e = min(m-1,i+x);
                int c_e = min(n-1,j+x);
                int cnt = get_sum(x,r_s,r_e,c_s,c_e,pfx);
               
                //corners
                    if(i-x >=0 && j-x >=0 && matrix[i-x][j-x] > x) cnt--;
                    if(i-x>=0 && j+x<n && matrix[i-x][j+x] > x) cnt--;
                    if(i+x<m && j-x>=0 && matrix[i+x][j-x] > x) cnt--;
                    if(i+x<m && j+x<n && matrix[i+x][j+x] > x) cnt--;
    
                //then if cnt == 0 ans++;
                if(cnt==0) ans++;
            }
        }
        return ans;

    }
};