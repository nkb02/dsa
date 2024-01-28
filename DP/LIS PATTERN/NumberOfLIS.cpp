#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n){
	
	vector<int> dp(n, 1);
	vector<int> ct(n, 1);

	
	int maxi = -1;

	for(int i =0 ; i< n; i++){
	
		for (int prev = 0; prev < i ; ++prev)
		{
			if((arr[i] > arr[prev])
				&& dp[i] < 1+ dp[prev]){
				
				dp[i] =  1+ dp[prev];
				// inherit
				ct[i] = ct[prev];
			}
			else if((arr[i] > arr[prev])
				&& dp[i] == 1+ dp[prev]){
				
				// Increase the count 
				ct[i] =  ct[i] + ct[prev];
			}
		}
		maxi = max(maxi, dp[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if(dp[i] == maxi){
			ans += ct[i];
		}
	}

	return ans;	
}

int main(){
	
	vector<int> arr = {1,5,4,3,2,6,7,2};
	int n = arr.size();
	// Approach
	// find lis
	// maintain cnt of lis at that index 

	cout<< "Number of Longest Increasing Subsequences => "<< LIS(arr, n);
	return 0;	
}