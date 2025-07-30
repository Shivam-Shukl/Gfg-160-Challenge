class Solution {
  public:
    int solveTopDown(vector<int>& arr,int ind,vector<int> &dp)
    {
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int exc = solveTopDown(arr, ind +1,dp);
        int inc = arr[ind] + solveTopDown(arr,ind+2,dp);
        
        return dp[ind] = max(exc,inc);
    }
    
    int solveTab(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> dp(n+2,0);
       
        for(int ind = n-1 ;ind>=0;ind--)
        {
            dp[ind] = max(dp[ind+1],arr[ind] + dp[ind+2]); 
        }
        return dp[0];
    }
    
    int solveSpace(vector<int>& arr)
    {
        int n = arr.size(),next1 = 0,next2 =0,curr=0;
    
        for(int ind = n-1;ind>=0;ind--)
        {
            curr = max(next1 , arr[ind] + next2);
            next2 = next1;
            next1= curr;
        }
        return curr;
    }
    
    int findMaxSum(vector<int>& arr) {
        // code here
        // int n = arr.size();
        // vector<int> dp(n,-1);
        // return solveTopDown(arr,0,dp);
        
        return solveSpace(arr);
    }
};
