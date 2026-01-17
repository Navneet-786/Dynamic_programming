class Solution {
public:

    string shortestCommonSupersequence(string s, string t) {
      int n1 = s.size();
      int n2 = t.size();
      vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
      for(int i = 1;i<n1+1;i++){
        for(int j = 1;j<n2+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
      }


      //printing SCS
      int i = n1, j =n2;
      string ans = "";
      while(i>0 && j>0){

        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] < dp[i][j-1]){
                ans += t[j-1];
                j--;
            }
            else{
                ans += s[i-1];
                i--;
            }
        }
      }

      while(i>0){
        ans += s[i-1];
        i--;
      }
      while(j>0){
        ans += t[j-1];
        j--;
      }
    reverse(ans.begin(), ans.end());
    return ans;

    }
};