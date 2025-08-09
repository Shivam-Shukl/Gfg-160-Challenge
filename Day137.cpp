class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        vector<int> idx(26,0);
        
        for(int i=0;i<s.length();++i){
            idx[s[i] -'a'] = i;
        }
        
        int cnt =0,last =0;
        
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            last = max(last,idx[ch - 'a']);
            if(last ==i) cnt++;
        }
        return cnt;
    }
};
