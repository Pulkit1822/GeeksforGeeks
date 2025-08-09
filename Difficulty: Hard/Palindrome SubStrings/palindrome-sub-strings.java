class Solution {
    public int countPS(String s) {
        // code here 
        int n = s.length();
        int count = 0;
        int l,r = 0;
        for(int i = 0;i<n;i++)
        {
            l = i-1;
            r = i;
            while(l>=0 && r<n && s.charAt(l)==s.charAt(r))
            {
                count++;
                l--;
                r++;
            }
            l = i-1;
            r = i+1;
            while(l>=0 && r<n && s.charAt(l)==s.charAt(r))
            {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
}