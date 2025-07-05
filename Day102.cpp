class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int,int>> s;
        int n  = arr.size();
        vector<int> ans(n,1);
        
        for(int i = 0;i<arr.size();i++)
        {
            int count = 1;
            int ele = arr[i];
            while(!s.empty() && s.top().first <= ele)
            {
                count = count + s.top().second;
                s.pop();
            }
            
            ans[i] = count;
            s.push({arr[i],count});
            
        }
        return ans;
    }
};
