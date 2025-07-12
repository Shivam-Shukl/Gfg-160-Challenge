
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        vector<int>ans;
        deque<int>maxi, mini;
        int maxD=0, ind1=-1, ind2=-1;
        
        int i=0, j=0;
        
        for(; j<n; j++){
            while(!maxi.empty() && maxi.back()<arr[j]){
                maxi.pop_back();
            }
            while(!mini.empty() && mini.back()>arr[j]){
                mini.pop_back();
            }
            maxi.push_back(arr[j]);
            mini.push_back(arr[j]);
            for(; i<n && ((abs(maxi.front()-arr[j]))>x || 
            abs(mini.front()-arr[j])>x); i++){
                if(maxi.front()==arr[i]) maxi.pop_front();
                if(mini.front()==arr[i]) mini.pop_front();
            }
            if(j-i+1>maxD){
                ind1=i;
                ind2=j;
                maxD=j-i+1;
            }
        }
        for(int i=ind1; i<=ind2; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
