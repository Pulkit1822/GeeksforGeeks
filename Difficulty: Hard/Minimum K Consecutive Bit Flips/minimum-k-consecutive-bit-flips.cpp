//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
         int n = arr.size();
        int flips = 0;
        int flipped = 0; 
        queue<int>q;

        for (int i = 0; i < n; i++) {
           
            if (!q.empty() && q.front() == i) {
                q.pop();
                flipped ^= 1; 
            }

            if ((arr[i] ^ flipped) == 0) { 
                if (i + k > n) return -1; 
                
                flips++;
                q.push(i + k); 
                flipped ^= 1;
            }
        }
        return flips;
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        cout << ob.kBitFlips(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends