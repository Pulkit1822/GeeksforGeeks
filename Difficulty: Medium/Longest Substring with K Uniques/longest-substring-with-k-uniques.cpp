class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        int result=-1;
        unordered_map<char,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(i<=j&&mp.size()>k){
                mp[s[i]]--;
                if(!mp[s[i]])mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k)result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};