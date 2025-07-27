class Solution {
  public:
    bool solve(vector<int> arr,int target,int ind,vector<vector<int>> &dp)
    {
        if(ind == arr.size())
            return 0;
        
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        bool exc = solve(arr,target, ind+1,dp);
        bool inc = solve(arr, target - arr[ind] , ind+1,dp);
        
        if(exc || inc)
            dp[ind][target]= 1;
        else
            dp[ind][target] = 0;
            
        return dp[ind][target];
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int ele : arr)
        {
            sum += ele;
        }
        if(sum % 2== 0)
        {
            vector<vector<int>> dp(n+1,vector<int>(sum/2 + 1,-1));
            if(solve(arr,sum/2,0,dp))
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        
    }
};
