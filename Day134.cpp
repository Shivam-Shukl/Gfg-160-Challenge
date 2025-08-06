class Solution {
  public:
    int solve(vector<pair<int,int>> &v,int ind, int prev,vector<vector<int>> &dp){
        if(ind == v.size()){
            return 0;
        }
        
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        
        int exc = solve(v,ind+1,prev,dp);
        
        int inc =  0;
        if(prev == -1 || v[prev].second < v[ind].first ){
            inc = 1 + solve(v,ind+1,ind,dp);
        }
        
        return dp[ind][prev+1] = max(exc,inc);
    }
    
    int solveTab(vector<pair<int,int>> &v){
        
        
        int n= v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
    
        for(int ind = n-1;ind >=0;ind--){
            
            for(int prev = n-1;prev >=-1;prev--){
            
                int exc = dp[ind+1][prev+1];
                
                int inc =  0;
                if(prev == -1 || v[prev].second < v[ind].first ){
                    inc =1+dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(exc,inc);
            }
        }
        
        return dp[0][0] ;
    }
    int solveSpace(vector<pair<int,int>> &v){
        
        int n= v.size();
  
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
    
        for(int ind = n-1;ind >=0;ind--){
            
            for(int prev = n-1;prev >=-1;prev--){
            
                int exc = next[prev+1];
                
                int inc =  0;
                if(prev == -1 || v[prev].second < v[ind].first ){
                    inc =1+next[ind+1];
                }
                curr[prev+1] = max(exc,inc);
            }
            next = curr;
        }
        
        return curr[0] ;
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        // int n = start.size();
        // vector<pair<int,int>> v(n,{-1,-1});
        
        // for(int i=0;i<n;i++){
        //     v[i] = {start[i],finish[i]};
        // }
        // sort(v.begin(),v.end());
        // return solveSpace(v);
        
        // int ans = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > p;
        
        for (int i =0;i< start.size() ; i++){
            p.push(make_pair(finish[i],start[i]));
        }
        
        int finishtime = -1;
        
        while(!p.empty()){
            
            pair<int,int> activity = p.top();
            p.pop();
            if(activity.second > finishtime){
                finishtime =activity.first;
                ans++;
            }
        }
        return ans;
    }
};
