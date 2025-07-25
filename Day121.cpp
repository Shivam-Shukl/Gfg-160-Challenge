
class Solution {
public:
    /*
    int solveByRec(vector<int> &num, int target) {
        if (target == 0) {
            return 0;
        }
        if (target < 0) {
            return INT_MAX;
        }
      

        int mini = INT_MAX;
        for (int i = 0; i < num.size(); i++) {
            int ele = num[i];
            int ans = solveByRec(num, target - ele, dp);

            if (ans != INT_MAX) {  // Ensure valid answer before updating
                mini = min(ans + 1, mini);
            }
        }

     
        return mini;
    }
    */
    /*
    int solveBydp(vector<int> &num, int target, vector<int> &dp) {
        if (target == 0) {
            return 0;
        }
        if (target < 0) {
            return INT_MAX;
        }
        if (dp[target] != -1) {
            return dp[target];
        }

        int mini = INT_MAX;
        for (int i = 0; i < num.size(); i++) {
            int ele = num[i];
            int ans = solveBydp(num, target - ele, dp);

            if (ans != INT_MAX) {  // Ensure valid answer before updating
                mini = min(ans + 1, mini);
            }
        }

        dp[target] = mini;  // Store the result in dp
        return dp[target];
    }
    */

    int solvetab(vector<int> &num, int target) {
        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < num.size(); j++) {
                if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - num[j]]);
                }
            }
        }

        return (dp[target] == INT_MAX) ? -1 : dp[target];
    }

    int minCoins(vector<int> &coins, int sum) {
        return solvetab(coins, sum);  // Fixed function call
    }
};


