class Solution {
  public:
    void dfs(vector<vector<char>>& grid, int r,int c){
        int row = grid.size();
        int col = grid[0].size();
        
        if(r<0 || c<0 || r>=row || c>= col || grid[r][c] != 'L'){
            return ;
        }
        grid[r][c] = 'W';
        vector<int> rNbr = {-1,-1,-1,0,0,1,1,1};
        vector<int> cNbr = {-1,0,1,-1,1,-1,0,1};
        
        for(int i=0;i<8;i++){
            int newR = r + rNbr[i];
            int newC = c + cNbr[i];
            dfs(grid,newR,newC);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        
        for(int i=0 ;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 'L'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};
