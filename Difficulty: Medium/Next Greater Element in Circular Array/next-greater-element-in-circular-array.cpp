class Solution {
  public:
   vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size(), i = 0;
        vector <int> ans(n, -1); 
        stack <int> s;
        
        while(i < 2*n){
            while(!s.empty() && arr[s.top()] < arr[i%n]) {
                ans[s.top()] = arr[i%n];
                s.pop();
            }
            
            s.push(i%n); i++;
        }
        
        return ans;
    }
};