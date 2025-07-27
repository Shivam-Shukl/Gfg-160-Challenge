
class Solution {
  public:
    
    bool solveTab(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
   
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
  
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;
    
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool exclude = dp[i - 1][target];
                bool include = false;
                if (arr[i] <= target)
                    include = dp[i - 1][target - arr[i]];
                dp[i][target] = include || exclude;
            }
        }
    
        return dp[n - 1][sum];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
     
        return solveTab(arr,sum);
    }
};

