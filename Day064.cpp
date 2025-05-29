class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt = 0;
        vector<int> ans(n,0);
        int mul = 1;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0){
                cnt++;
                continue;
            }
            mul *= arr[i];
        }
        if(cnt >1) return ans;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 0)
                ans[i] = mul;
            else{
                if(cnt ==1)
                {
                    ans[i] =0;
                }else{
                    ans[i] = mul/arr[i];
                }
            }
                
        }
        return ans;
    }
};
