class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int l1 = s.size();
        int l2 = l1;
        string s1 = s;
        //reverse the string
        reverse(s1.begin(), s1.end());
        vector<vector<int>>dp(l1+1,vector<int>(l1+1,0));
        
        for(int i = 1;i<l1+1;i++){
            for(int j = 1;j<l2+1;j++){
                if(s1[i-1]==s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);                }
            }
        }
        
        return dp[l1][l1];
        
    }
};