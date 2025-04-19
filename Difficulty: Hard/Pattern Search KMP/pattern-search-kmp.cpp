//{ Driver Code Starts
//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


// } Driver Code Ends

//User function Template for C++


//Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) 
{ 
	// Your code here
} 

//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    return txt.find(pat)!=string::npos?true:false;
    
}


//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    
cout << "~" << "\n";
}
    
	return 0;
} 

// } Driver Code Ends