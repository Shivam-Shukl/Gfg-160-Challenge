class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
 
        unordered_map<int,int> mp;
        int sum =0;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0) 
                arr[i] = -1;
            
            sum += arr[i];
            if(sum == 0)
            {
                ans = max(ans,i+1);
            }
            if(mp.find(sum) != mp.end())
            {
                int ind = mp[sum];
                ans = max(ans,i-ind);
            }else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};
