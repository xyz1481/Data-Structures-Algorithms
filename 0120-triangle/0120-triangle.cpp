class Solution {
private:
    int f(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
               dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(triangle);
    }
};


// class Solution {
// private:
//     int f(int row,int col,int n,vector<vector<int>>& triangle){
//         if(row== n-1) return triangle[row][col];
//         int l = triangle[row][col] + f(row+1,col,n,triangle);
//         int r = triangle[row][col] + f(row+1,col+1,n,triangle);
//         return min(l,r); 
//     }
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         return f(0,0,n,triangle);
//     }
// };