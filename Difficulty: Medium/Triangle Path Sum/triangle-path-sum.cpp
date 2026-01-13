class Solution {
  public:
//   vector<vector<int>>dp;
//   int solve(vector<vector<int>>& triangle, int n,int m){
//       if(n==0 && m==0)return triangle[0][0];
      
//       if(dp[n][m]!=-1)return dp[n][m];
//       int up = INT_MAX;
//       if(m< triangle[n-1].size()){
//           up = solve(triangle, n-1,m);
//       }
//       int diag = INT_MAX;
//       if(m-1>=0){
//           diag = solve(triangle, n-1,m-1);
//       }
      
//       return dp[n][m] = triangle[n][m] + min(up, diag);
      
//   }
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        if(triangle.size()==1)return triangle[0][0];
        
        int n = triangle.size()-1;
        int m = triangle[n].size()-1;
        
        vector<int>prevRow(1,0);
        prevRow[0] = triangle[0][0];
   
        for(int i =1;i<=n;i++){
            vector<int>currRow(prevRow.size()+1,0);
            for(int j = 0; j < currRow.size();j++){
                int up = INT_MAX;
                
                if(j< prevRow.size()){
                    up = prevRow[j];
                }
                
                int diag = INT_MAX;
                if(j>0){
                    diag = prevRow[j-1];
                }
                
                currRow[j] = triangle[i][j] + min(up, diag);
            }
            
            prevRow.resize(currRow.size());
            for(int i = 0;i<currRow.size();i++){
                prevRow[i] = currRow[i];                
            }
        }
    
      int ans = INT_MAX;
      for(auto it:prevRow){
          ans = min(ans, it);
      }
      return ans;
    
    }
};