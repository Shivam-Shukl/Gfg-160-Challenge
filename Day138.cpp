class Solution {
  public:
    void solve(vector<vector<int>>& adj,unordered_map<int,bool> &visited,vector<int> &ans,int node)
    {
        ans.push_back(node);
        visited[node] = true;
        
        for(int neigh : adj[node])
        {
            if(!visited[neigh])
            {
                solve(adj,visited,ans,neigh);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visited;
        vector<int> ans;
        
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i])
            {
                solve(adj,visited,ans,i);
            }
        }
        return ans;
    }
};
