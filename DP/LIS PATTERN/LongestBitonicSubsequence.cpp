#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n){
	
	vector<int> dp1(n, 1);
	vector<int> dp2(n, 1);

	for(int i =0 ; i< n; i++){
	
		for (int prev = 0; prev < i ; ++prev)
		{
			if((arr[i] > arr[prev])
				&& dp1[i] < 1+ dp1[prev]){
				
				dp1[i] =  1+ dp1[prev];
			}
		}
	}


	// longest decreasing subsequence -- LDS


	for(int i =n-1; i >= 0; i--){
	
		for (int prev = n-1; prev > i ; --prev)
		{
			if((arr[i] > arr[prev])
				&& dp2[i] < 1+ dp2[prev]){
				
				dp2[i] =  1+ dp2[prev];
			}
		}
	}
	int maxi = -1;

	for (int i = 0; i < n; ++i)
	{
		maxi = max(maxi, dp1[i] + dp2[i] - 1);
	}
	return maxi;	
}

int main(){
	
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	int n = arr.size();
	// Approach
	// 1. Same algo used in printing LIS
	// 2. find LIS - store in dp1
	// 3. find LDS - store in dp2
	// 	(reverse loops direction :)
	// 4. return max of (dp1[i] + dp2[i] - 1)

	cout<< "Length of Longest Bitonic Subsequence => "<< LIS(arr, n);
	return 0;	
}