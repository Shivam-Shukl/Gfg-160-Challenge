class Solution {
  public:
    vector<int> bruteForce(vector<int>& arr, int target)
    {

        int sum =0;
        int n = arr.size();
    
        for(int i=0;i<n;i++)
        {
            sum =0;
            for(int j=i;j<n  ;j++)
            {
                sum += arr[j];
                if(sum == target)
                {
                    return {i+1,j+1};
                    break;
                }
                if(sum > target) break;
            }
        }
        
        return {-1};
        
    }
    vector<int> OptimumApp(vector<int> &arr,int target)
    {
        unordered_map<int,int> prefSum;
        int sum =0;
        for(int i=0;i<arr.size();i++)
        {
            sum +=arr[i];
            
            if(sum == target)
            {
                return {1,i+1};
            }
            if(prefSum.find(sum-target) != prefSum.end())
            {
                return {prefSum[sum-target]+2,i+1};
            }
            prefSum[sum] =i;
        }
        return {-1};
    }
    vector<int> LinearTimeForNonNegative(vector<int> &arr,int target){
        int n = arr.size();
        int i =0;
        int j = 1;
        int sum = arr[0];
        vector<int> v;
        while(i<=j && j<n)
        {
            while(sum < target && j<n)
            {
                sum += arr[j];
                j++;
            }
    
            while(sum > target && i<n)
            {
                sum -= arr[i];
                i++;
            }
            if(sum == target)
            {
                v.push_back(i+1);
                v.push_back(j);
                break;
            }
        }
        if(v.empty())
        {
            v.push_back(-1);
        }
        return v;
    }
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        return bruteForce(arr,target);
        
    }
};
