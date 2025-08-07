class Solution {
public:
    vector<int> palQueries(string &s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<int> result;
        const int base = 911382629;
        const int mod = 1e9 + 7;
        vector<long long> prefix(n + 1, 0);
        vector<long long> power(n + 1, 1);
        for (int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * base) % mod;
            prefix[i + 1] = (prefix[i] * base + s[i]) % mod;
        }
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        vector<long long> rev_prefix(n + 1, 0);
        for (int i = 0; i < n; i++) rev_prefix[i + 1] = (rev_prefix[i] * base + rev_s[i]) % mod;
        
        auto get_hash = [&](const vector<long long> &pre, int l, int r) { return (pre[r + 1] - pre[l] * power[r - l + 1] % mod + mod) % mod; };
        
        for (auto &q : queries) result.push_back(get_hash(prefix, q[0], q[1]) == get_hash(rev_prefix, n - 1 - q[1], n - 1 - q[0]) ? 1 : 0);
        
        return result;
    }
};