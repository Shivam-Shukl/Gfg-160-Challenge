class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        int i =0,j=n-1;
        int cnt =0;
        while(i<j)
        {
            int sum = arr[i] + arr[j];
            if(sum == target)
            {
                if(arr[i] == arr[j])
                {
                    int len = j -i +1;
                    cnt += (len *(len-1)) / 2;
                    break;
                }
                else{
                    int left = 1, right =1;
                    while(i+1<j && arr[i] == arr[i+1])
                    {
                        left++;
                        i++;
                    }
                    while(j-1 > i && arr[j] == arr[j-1])
                    {
                        right++;
                        j--;
                    }
                    cnt += left*right;
                    i++;
                    j--;
                }
            }else if(sum <target)
            {
                i++;
            }else{
                j--;
            }
        }
            
           
     
        return cnt;
    }
};
