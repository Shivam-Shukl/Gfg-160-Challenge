

class Solution {

private:
    vector<int> nextSmallerElement(const vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, n); // Initialize the answer vector with n
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(const vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1); // Initialize the answer vector with -1
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }

  public:
    // Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(vector<int> &heights) {
        // Your code here
        int n = heights.size();
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);
        int area = 0;

        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

};



