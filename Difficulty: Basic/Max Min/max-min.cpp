//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	//code here.
    	int min = INT_MAX;    //standard notation for greatest number
    	int max = INT_MIN;    //standard notation for smallest number
    	
    	for(int i=0; i<N; i++)
    	{
    	    if(A[i]>max)
    	    {
    	        max = A[i];
    	    }
    	    if(A[i]<min)
    	    {
    	        min = A[i];
    	    }
    	 }
    	 return max+min;
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends