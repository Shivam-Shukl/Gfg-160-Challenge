class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        
        priority_queue<int,vector<int>,greater<int>> platformInfo;
        
        int n = arr.size();
        vector<pair<int,int>> TrainInfo(n,{-1,-1});
        
        for(int i =0;i<n;++i){
            TrainInfo[i] = {arr[i],dep[i]};
        }
        sort(TrainInfo.begin(),TrainInfo.end());
        
        int platformCnt= 1;
        
        platformInfo.push(TrainInfo[0].second);
        
        for(int i=1;i<n;i++){
            int top = platformInfo.top();
            if(platformInfo.top() < TrainInfo[i].first){
                platformInfo.pop();
                platformInfo.push(TrainInfo[i].second);
            }else{
                platformInfo.push(TrainInfo[i].second);
                platformCnt++;
            }
        }
        return platformCnt;
    }
};
