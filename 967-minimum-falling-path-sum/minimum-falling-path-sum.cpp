class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();

        vector<int>prevRow(m,0);
        for(int i = 0;i<m;i++)prevRow[i] = matrix[0][i]; 

        for(int i = 1;i<n;i++){
            vector<int>currRow(m,0);
            for(int j = 0;j<m;j++){
                int prevDiag = INT_MAX;
                int frontDiag = INT_MAX;
                int top = prevRow[j];

                if(j>0){
                    prevDiag = prevRow[j-1];
                }
                if(j!=m-1){
                    frontDiag = prevRow[j+1];
                }

                currRow[j] = matrix[i][j] + min(top, min(prevDiag, frontDiag));
            }
            prevRow = currRow;
        }

        int ans = INT_MAX;
        for(auto &it:prevRow){
            ans = min(ans, it);
        }
        return ans;
    }
};