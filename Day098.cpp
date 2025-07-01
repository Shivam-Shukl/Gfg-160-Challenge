
class Solution {
public:
   
     vector<double> getMedian(vector<int> &arr) {
         
        priority_queue<int>leftmax;
        priority_queue<int,vector<int>,greater<>>rightmin;
        vector<double>res;
        
        for(int i =0;i<arr.size();i++){
            
            leftmax.push(arr[i]);
            rightmin.push(leftmax.top());
            leftmax.pop();
            
            if (rightmin.size()>leftmax.size()){
                leftmax.push(rightmin.top());
                rightmin.pop();
            }
            
            if (rightmin.size()!=leftmax.size()) res.push_back((double)leftmax.top());
            else {
                res.push_back((double)(rightmin.top() + leftmax.top())/2);
            }
        }
        return res;
    }
};



