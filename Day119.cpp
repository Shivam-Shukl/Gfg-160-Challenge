
class Solution {
  public:

    int Solve(vector<int> &val, vector<int> &wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);
    
        for (int i = wt[0]; i <= capacity; i++) {
            prev[i] = val[0];
        }
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                int include = 0;
                if (wt[i] <= j) {
                    include = val[i] + prev[j - wt[i]];
                }
                int exclude = prev[j];
                curr[j] = max(include, exclude);
            }
            prev= curr;
        }
        return prev[capacity]; 
    }


    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code her
     
        return Solve(val ,wt,W);
        
    }
};

