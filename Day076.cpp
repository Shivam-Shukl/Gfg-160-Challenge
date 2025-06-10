class Solution {
  public:
    double solve(double b ,int e)
    {
        if(e == 0)
            return 1;
        
        if(e < 0)
            return solve(1/b,-e);
        
        double half = solve(b,e/2);
        
        if(e%2 == 0)
            return half*half;
        else
            return b*half*half;
    }
    double power(double b, int e) {
        // code here
        return solve(b,e);
    }
};
