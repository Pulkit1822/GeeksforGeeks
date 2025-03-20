//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
        int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int dp[n+1] = {0};
        dp[0] = arr[0];
        dp[1] = max(arr[1],arr[0]);
        
        for(int i = 2;i<n;i++)
        {
            dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
        }
        int ans = dp[n-1];
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends