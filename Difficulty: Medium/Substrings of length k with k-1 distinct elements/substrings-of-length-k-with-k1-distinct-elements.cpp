class Solution {
  public:
    int substrCount(string &s, int k) {
        int alphabets[26]={};
        int cntUniq = 0;
        int r = 0,l = 0;
        int ans = 0;
        
        while(r<s.length()){
            alphabets[s[r]-'a']++;
            if(alphabets[s[r]-'a'] == 1){
                cntUniq++;
            }
            r++;
            
            while((r-l)>k){
                alphabets[s[l]-'a']--;
                if(alphabets[s[l]-'a'] == 0){
                    cntUniq--;
                }
                l++;
            }
            
            if((r-l==k) and cntUniq==k-1){
                ans++;
            }
        }
        
        return ans;
    }
};