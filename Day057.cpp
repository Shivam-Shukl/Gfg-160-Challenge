class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i =0;i<k;i++)
        {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());
        int index = 0;
        for(int i=k;i<n;i++)
        {
            freq[arr[i]]++;
            if(freq[arr[index]] == 1)
            {
                freq.erase(arr[index]);
            }else{
                freq[arr[index]]--;
            }
            index++;
            ans.push_back(freq.size());
        }
        return ans;
    }
};
