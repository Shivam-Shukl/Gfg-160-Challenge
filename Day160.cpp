class Solution {
  public:
    vector<int> singleNum(vector<int> &arr) {
    
        int xorVal = 0;
        for (auto i : arr) {
            xorVal = i ^ xorVal;
        }
    
        xorVal &= -xorVal;
    
        vector<int> res(2, 0);
        
        for (int num : arr) {
   
            if ((num & xorVal) == 0) { 
                res[0] ^= num;
            }
            
            else { 
                res[1] ^= num;
            }
        }
    
        if (res[0] > res[1]) {
            swap(res[0], res[1]);
        }
    
        return res;
    }
};
