class Solution {
  private:  
    vector<int> artPoints;
    int timer;

    void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj,
    vector<int> &discTime, vector<int> &lowTime){
        timer++;
        vis[node] = 1;
        discTime[node] = lowTime[node] = timer;
        int children = 0;

        for(int it: adj[node]){
            if(it == parent) continue;

            if(!vis[it]){
                children++;
                dfs(it, node, vis, adj, discTime, lowTime);
                lowTime[node] = min(lowTime[node], lowTime[it]);

                if(discTime[node]<=lowTime[it] && parent != -1)
                    artPoints.push_back(node);
               
            }
            else lowTime[node] = min(lowTime[node], discTime[it]);
        }

        if(parent == -1 && children>1) artPoints.push_back(node);
    }

  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        timer = 0;
        vector<vector<int>> adj(V);
        for(vector<int> it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> discTime(V), lowTime(V);
        vector<bool> vis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]) dfs(i, -1, vis, adj, discTime, lowTime);
        }

        sort(artPoints.begin(), artPoints.end());
        artPoints.erase(unique(artPoints.begin(), artPoints.end()), artPoints.end());
       
        return artPoints.empty()?vector<int> {-1}:artPoints;
    }
};
