//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
     int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        int d1 = arr[1]-arr[0];
        int d2 = arr[n-1]-arr[n-2];
        int d;
        if(d1==d2 || d1<d2){
            d = d1;
        }
        else{
            d = d2;
        }
        
        int i=1;
        while(i<=n){
            if(arr[i-1]+d == arr[i]){
                i++;
            }
            else{
                return arr[i-1]+d;
            }
        }
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends