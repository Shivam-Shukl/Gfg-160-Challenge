class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        int val=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        image[sr][sc]=newColor;
        vis[sr][sc]=1;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto x:dir){
                int d1=i+x.first;
                int d2=j+x.second;
                if(d1>=0 && d2>=0 && d1<n && d2<m && !vis[d1][d2] && image[d1][d2]==val){
                    image[d1][d2]=newColor;
                    vis[d1][d2]=1;
                    q.push({d1,d2});
                }
            }
            
        }
        return image;
        
    }
};

