class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int output = 0;
        for(int i=0; i<arr.size(); i++)
        {
            output = output ^ i ^ arr[i];
        }
        return output;
    }
};

