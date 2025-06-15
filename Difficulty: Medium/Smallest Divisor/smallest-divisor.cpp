class Solution {
    bool isPossible(vector<int> &arr,int k,int val){
        int sum = 0;
        for(int i:arr){
            sum+=ceil((double)i/val);
        }
        return sum<=k;
    }
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int start = 1;
        int end = 0;
        for(int i:arr) end = max(end,i);
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(isPossible(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return ans;
    }
};
