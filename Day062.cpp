class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        unordered_map<int,int> prefSum;
        int sum =0;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum == k)
            {
                ans = max(ans,i+1);
            }
            if(prefSum.find(sum - k) != prefSum.end())
            {
                int ind = prefSum[sum-k];
                int len = i -ind;
                ans = max(ans,len);
            }
            if(prefSum.find(sum) == prefSum.end()){
               prefSum[sum] =i; 
            }
            
        }
        return ans;
    }
};
