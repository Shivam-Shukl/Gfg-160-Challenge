class Solution {
  public:
    
    int solve(vector<vector<int>> &mat){
        
        int ans = 0;
        queue<pair<pair<int,int>,int>> q;
        
        int n= mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                
                if(mat[i][j] == 2){
                    q.push({{i,j},0});
                }
                
            }
        }
        
        while(!q.empty()){
            
            pair<pair<int,int>,int> front = q.front();
            
            pair<int,int> cor = front.first;
            int cst = front.second;
            ans = max(ans,cst);
            
            int i =cor.first,j=cor.second;
            
            // up i-1
            if(i-1 >=0 && mat[i-1][j] == 1){
                mat[i-1][j] = 2;
                q.push({{i-1,j},cst+1});
            }
            
            // down i+1
            if(i+1 < n && mat[i+1][j] == 1){
                mat[i+1][j] = 2;
                q.push({{i+1,j},cst+1});
            }
            // left j-1
            if(j-1 >= 0 && mat[i][j-1] == 1){
                mat[i][j-1] = 2;
                q.push({{i,j-1},cst+1});
            }
            // right j+1
            if(j+1 < m && mat[i][j+1] == 1){
                mat[i][j+1] = 2;
                q.push({{i,j+1},cst+1});
            }
            q.pop();
        }
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                
                if(mat[i][j] == 1){
                    return -1;
                }
                
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        return solve(mat);
    }
};
