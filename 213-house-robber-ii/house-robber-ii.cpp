class Solution {
public:
    int solve(vector<int>&vec , int b_idx , int n){
        int prev2 = 0, prev = vec[b_idx],curr = 0;
        for(int i = b_idx+1;i<=n;i++){
            curr = max( vec[i]+ ((i>1)?prev2:0),prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if( nums.size()==1)return nums[ nums.size()-1];
        return max(solve(nums,1, nums.size()-1),solve(nums,0, nums.size()-2));
    }
};