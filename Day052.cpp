class Solution {
  public:

    int countPairs(vector<int> &arr, int target) {
        
        sort(arr.begin(),arr.end());
        int n = arr.size(),i =0;
        int j= n-1;
        int cnt = 0;
        while(i<j)
        {
            if(arr[i] + arr[j]>=target)
            {
                j--;
                
            }
            else 
            {
                cnt += j - i;
                i++;
            }
        }
        return cnt;
        
        
    }
};
