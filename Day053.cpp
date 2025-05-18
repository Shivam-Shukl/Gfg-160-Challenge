// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> res;
        int minDif = INT_MAX;
        
        int i =0,j=n-1;
        while(i<j)
        {
            int currSum = arr[i] + arr[j];
            if(abs(target - currSum) < minDif)
            {
                minDif = abs(target - currSum);
                res = {arr[i],arr[j]};
            }
            if(currSum <target)
            {
                i++;
            }else if(currSum > target)
            {
                j--;
            }
            else{
                return res;
            }
        }
        return res;
    }
};
