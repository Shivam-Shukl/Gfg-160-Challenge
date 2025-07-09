class Solution {
  public:
    int stringToInt(string s)
    {
        int ans = 0;
        int i =0;
        bool isNeg = false;
        if(s[0] == '-')
        {
            isNeg = true;
            i++;
        }
        for(;i<s.size();i++)
        {
            char ch = s[i];
            ans = ans*10 +(ch -'0');
        }
        if(isNeg)
        {
            return -ans;
        }
        return ans;
    }
    int Operation(int fir , int sec , string op)
    {
        if(op == "/")
        {
            return sec/fir;
        }else if(op == "*")
        {
            return sec*fir;
        }else if(op == "+")
        {
            return sec+fir;
        }else
        {
            return sec-fir;
        }
    }
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] == "*" || arr[i] == "+" || arr[i] == "-" || arr[i] == "/")
            {
                int fir = st.top();
                st.pop();
                int sec = st.top();
                st.pop();
                int val = Operation(fir,sec,arr[i]);
                st.push(val);
            }else{
                int val = stringToInt(arr[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};
