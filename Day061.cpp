class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int leftSum =0;
        int rightSum =0;
        
        for(int i=0;i<n;i++)
        {
            rightSum += arr[i];
        }
        
        for(int i=0;i<n;i++)
        {
            rightSum -= arr[i];
            if(i !=0)
            leftSum += arr[i-1];
            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};
