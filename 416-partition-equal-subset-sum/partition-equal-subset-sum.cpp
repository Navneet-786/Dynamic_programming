class Solution {
public:

// bool solve(vector<int>&nums, int n, int sum){
//     if(sum == 0)return true;
//     if(n==0)return false;

//     int notTake = solve(nums, n-1, sum);
//     int take = false;
//     if(nums[n-1]<= sum){
//         take = solve(nums, n-1, sum -  nums[n-1]);
//     }
//     return take || notTake;
// }

    bool canPartition(vector<int>& nums) {
        auto sum = 0;
        for(auto &it:nums){
            sum+=it;
        }
        if(sum&1)return false;

        sum = sum/2;

       vector<int>prevRow(sum+1,0);
       prevRow[0] = 1;

       for(int i =1;i<nums.size();i++){
        vector<int>currRow(sum+1, 0);
        currRow[0] = 1;
        for(int j =1;j<sum+1;j++){
            int notTake = prevRow[j];
            int take = false;
            if(nums[i-1]<= j){
                take = prevRow[j-nums[i-1]];
            }
            currRow[j] = take || notTake;
        }
        prevRow = currRow;
       }

       return prevRow[sum];
    }
};