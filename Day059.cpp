class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 1;
        int right = arr.size() -2;
        
        int lMax = arr[left - 1];
        int rMax = arr[right + 1];
        
        int res = 0;
        while(left <= right)
        {
            if(rMax <= lMax)
            {
                res += max(0,rMax - arr[right]);
                rMax = max(rMax,arr[right]);
                right -= 1;
            }else{
                res += max(0,lMax -arr[left]);
                lMax = max(lMax,arr[left]);
                left+=1;
            }
        }
        return res;
    }
};
