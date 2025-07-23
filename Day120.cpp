
class Solution {
  public:
    
    // int solve(vector<int>&coins, int sum, int ind,vector<vector<int>> &dp){
        
    //     if(sum==0)
    //         return 1;
        
    //     if(ind>=coins.size())
    //         return 0;
        
    //     if(dp[sum][ind]!=-1)
    //         return dp[sum][ind];
        
    //     int ans=0;
        
    //     ans+=solve(coins,sum,ind+1,dp);
        
    //     if(coins[ind]<=sum)
    //         ans+=solve(coins,sum-coins[ind],ind,dp); 
    
    //     return dp[sum][ind]=ans;
    // }
    
    int solveTab(vector<int>&coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(sum+1,vector<int>(n+1,0));
        
        for(int ind = 0;ind<coins.size();ind++)
        {
            dp[0][ind] = 1;
        }
        
        for(int ct = 1;ct<= sum;ct++)
        {
            for(int ind =n-1;ind>=0 ;ind--)
            {
                int inc =0;
                if(ct-coins[ind] >= 0)
                {
                    inc = dp[ct-coins[ind]][ind];
                }
                dp[ct][ind] = dp[ct][ind+1] + inc;
            }
        }
        
        return dp[sum][0];
    }
    
  
    
    int count(vector<int>& coins, int sum) { 
        return solveSpace(coins,sum);
    }
};

