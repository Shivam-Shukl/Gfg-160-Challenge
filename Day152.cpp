
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Relax edges V-1 times
        for (int i = 1; i <= V-1; i++) {
            for (auto &it : edges) {
                int u = it[0], v = it[1], w = it[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycle
        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

