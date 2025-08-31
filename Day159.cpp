class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int ele = 0;
        int n = arr.size();
        for(int i =0;i<n;i++){
            ele = ele xor arr[i];
        }
        return ele;
    }
};
