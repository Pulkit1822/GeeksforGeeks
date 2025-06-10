class Solution {
  public:
    int countStrings(string &s) {
        int n = s.length();
        vector <int> freq(26, 0);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;;
            if(freq[s[i] - 'a'] > 1) ans = 1;
        }
        
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']--;
            
            for(int j = 0; j < 26; j++){
                if(j != (s[i] - 'a')) ans += freq[j];
            }
        }
        
        return ans;
    }
};
