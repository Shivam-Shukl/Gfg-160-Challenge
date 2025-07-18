class Solution {
  public:
    void helper(string s, int j,int k,int &cnt)
    {
        int n = s.size();
        while(j>=0 && k<n && s[j] == s[k])
        {
            int len = k-j+1;
            if(len>=2)
            {
                cnt++;
            }
            j--,k++;
        }
    }
    int countPS(string &s) {
        
        int n = s.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            int j = i,k=i;
            helper(s,j,k,cnt);
    
            j=i,k=i+1;
            helper(s,j,k,cnt);
        }
        return cnt;
    }
};
