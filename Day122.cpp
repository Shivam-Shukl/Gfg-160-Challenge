class Solution {
  public:
    long long solve(vector<int> &arr, int ind,vector<long long> &dp)
    {
        if(ind >= arr.size() -1 )
        {
            return 0;
        }
        
        if(dp[ind] != -1)
            return dp[ind];
            
        long long ele = arr[ind];
        if(ele == 0) return INT_MAX;
        long long ans =INT_MAX;
        for(int i=1;i<=ele;i++)
        {
            long long a = 1+solve(arr,ind+i,dp);
            ans = min(ans,a);
        }
        return dp[ind] = ans;
    }
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<long long> dp(n,-1);
        int ans = solve(arr,0,dp);
        if(ans == INT_MAX)
        {
            return -1;
        }else{
            return ans;
        }
    }
};
