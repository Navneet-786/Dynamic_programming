class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        // code here
        int n = mat.size()-1;
        int m = mat[0].size()-1;
        
        vector<int>prevRow(m+1,0);
        for(int i = 0;i<=m;i++){
            prevRow[i] = mat[0][i];
        }
        
        for(int i =1;i<=n;i++){
            vector<int>currRow(m+1, 0);
            for(int j = 0;j<=m;j++){
                int up = prevRow[j];
                
                int diagLeft= INT_MAX;
                if(j>0)
                    diagLeft = prevRow[j-1];
                
                int diagRight = INT_MAX;
                if(j+1 < mat[i].size())
                    diagRight = prevRow[j+1];
                    
                    
                currRow[j] = mat[i][j] + min(up, min(diagLeft, diagRight));
            }
            
            prevRow =currRow;
        }
        
        int ans =  INT_MAX;
        for(auto it: prevRow){
            ans = min(ans, it);
        }
        return ans;
    }
};
