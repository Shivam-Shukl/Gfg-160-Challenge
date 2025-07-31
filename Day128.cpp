
class Solution {
  public:
    int solve(vector<int> &arr)
    {
        int n= arr.size();
        if(arr.size() == 1)
        {
            return arr[0];
        }
        int pre1 = arr[0];
        int pre2 = max(arr[0],arr[1]);
    
        for(int i=2;i<n;i++)
        {
            int curr = max(arr[i]+ pre1 , pre2);
            pre1 = pre2;
            pre2 = curr;
        }
        return pre2;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<int> arr1 ,arr2;
        for(int i=0;i<n-1;i++)
        {
            arr1.push_back(arr[i]);
        }
        for(int i=1 ;i<n;i++)
        {
            arr2.push_back(arr[i]);
        }
        
        int a = solve(arr1);
        int b = solve(arr2);
        return max(a ,b);
    }
};


