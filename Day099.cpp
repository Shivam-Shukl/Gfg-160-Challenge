
class Solution {
  public:
    bool isOpening(char ch)
    {
        if(ch == '{' || ch == '(' || ch == '[')
        {
            return true;
        }else{
            return false;
        }
    }
    
    bool isCond(char ch1,char ch2)
    {
        if( (ch1 =='{' && ch2 == '}') || (ch1 == '[' && ch2 == ']')  || (ch1 == '('  &&  ch2 == ')') )
        {
            return true;
        }else{
            return false;
        }
    }
    
    bool isBalanced(string& k) {
        // code here
        stack<int> st;
        for(char ch : k)
        {
            if(isOpening(ch))
            {
                st.push(ch);
            }else{
                if(st.empty())
                {
                    return false;
                }else{
                    char ch1 = st.top();
                    char ch2 = ch;
                    if(isCond(ch1,ch2))
                    {
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        
        if(st.empty())
        {
            return true;
        }else{
            return false;
        }
        
    }
};
