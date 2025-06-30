class Solution {
  public:

    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        
        priority_queue<int , vector<int> , greater<int> > minPq;
   
        for(int i=0;i<arr.size();i++)
        {
     
            if(minPq.size() == k && arr[i] > minPq.top())
            {
                minPq.pop();
                minPq.push(arr[i]);
          
            }else if(minPq.size() <k){
                minPq.push(arr[i]);
            }

        }
        vector<int> ans;
        while(!minPq.empty())
        {
            ans.push_back(minPq.top());
            minPq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
