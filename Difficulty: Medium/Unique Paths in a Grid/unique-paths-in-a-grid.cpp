class Solution {
  public:
//   vector<vector<int>>dp;
//   int solve(vector<vector<int>> &grid, int n, int m){
//       if(n == 0 && m ==0)return 1;
//       if(n<0 || m < 0)return 0;
//       if(grid[n][m]==1)return 0;
      
//       if(dp[n][m]!=-1)return dp[n][m];
      
//       int up = solve(grid, n-1,m);
//       int left = solve(grid, n,m-1);
      
      
//       return dp[n][m] = up + left;
//   }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m =grid[0].size();
        

        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return 0;
        
        
        vector<int>prevRow(m,0);
        //initialize prev row
        for(int j = 0;j<m;j++){
            if(grid[0][j]==1)break;
            prevRow[j] =1;
        }
        
        for(int i = 1;i<n;i++){
            vector<int>currRow(m,0);
            
            if(grid[i][0]==0){
                currRow[0] = prevRow[0];
            }
            
            for(int j = 1 ;j < m;j++){
                
                if(grid[i][j]==1){
                    currRow[j] = 0;
                }
                else{
                    currRow[j] = prevRow[j] + currRow[j-1];
                }
            }
            
            prevRow = currRow;
        }
        
        return prevRow[m-1];
        
    //     //fill the first row
    //     int j = 0;
    //     while(j<m && grid[0][j] !=1){
    //         dp[0][j] = 1;
    //         j++;
    //     }
        
    //     //fill the first column
    //     int i = 0;
    //     while(i<n &&  grid[i][0]!=1){
    //         dp[i][0] = 1;
    //         i++;
    //     }
        
        
    //     for(i = 1;i<n;i++){
    //         for(j=1;j<m;j++){
    //             if(grid[i][j]==1){
    //                 dp[i][j] = 0;
    //                 continue;
    //             }
    //             dp[i][j] =dp[i-1][j] + dp[i][j-1];
    //         }
    //     }
    //   return  dp[n-1][m-1];
    }
};