class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
      
        vector<int>prevRow(1,0);
        prevRow[0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            vector<int>currRow(triangle[i].size(),0);
            currRow[0] =triangle[i][0] + prevRow[0];
            for(int j =1;j<=i;j++){
                int top = INT_MAX;
                int diag = prevRow[j-1];
                if(i!=j) top = prevRow[j];                
                currRow[j] = triangle[i][j] + min(top, diag);
            }
            prevRow = currRow;
        }
        int ans = INT_MAX;
        for(auto it:prevRow){
            ans = min(ans,it);
        }
        return ans;
    }
};