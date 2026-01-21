class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        //initalize
        int i = 0;
        while(i<grid.size()){
           if(grid[i][0]==1)break;
            dp[i][0] =1;
            i++;
        }

        int j = 0;
        while(j<grid[0].size()){
           if(grid[0][j]==1)break;
            dp[0][j] = 1;
            j++;
        }

        for(int i = 1;i<grid.size();i++){
            for(int j = 1;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dp[i][j] = 0;
                     continue;
                }


                int topWay = dp[i-1][j];
                
                int leftWay = dp[i][j-1];
                

                dp[i][j] = leftWay + topWay;

            }
        }

    return dp[grid.size()-1][grid[0].size()-1];
    }
};