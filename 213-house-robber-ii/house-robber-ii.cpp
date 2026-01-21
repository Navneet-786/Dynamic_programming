class Solution {
public:
vector<int>dp;
int solve(vector<int>&nums, int startIndex, int endIndex){
    int n = endIndex - startIndex+1;
   dp.assign(n, -1);
   dp[0] = nums[startIndex];
   dp[1] = max(nums[startIndex], nums[startIndex+1]);

   for(int i =2;i<n;i++){
    dp[i] = max(nums[startIndex+i] + dp[i-2], dp[i-1]);
   }

   return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        if(n==0)return nums[0];
        if(n==1)return max(nums[0], nums[1]);
        int ans1 = solve(nums, 0,n-1);
       
        int ans2 = solve(nums,1, n);
        return max(ans1, ans2);

    }
};