#include<bits/stdc++.h>
using namespace std;


int LIS(vector<int> &arr, int n){
	sort(arr.begin(), arr.end());
	vector<int> dp(n, 1);
	vector<int> hash(n, 1);
	for(int i =0 ; i< n; i++){
		hash[i] = i;
		for (int prev = 0; prev < i ; ++prev)
		{
			if(arr[i] % arr[prev] == 0  
				&& dp[i] < 1+ dp[prev]){
				
				hash[i] = prev;
				dp[i] =  1+ dp[prev];
			}
		}
	}

	int ans = -1;
	// for(auto x: dp) ans = max(ans, x);

	int lastIndex = -1;
	for (int i = 0; i < n; ++i)
	{
		if(dp[i] > ans ){
			lastIndex = i;
			ans = dp[i];
		}
	}

	vector<int> lisa;
	lisa.push_back(arr[lastIndex]);

	while(hash[lastIndex] != lastIndex)
	{
		lastIndex = hash[lastIndex];
		lisa.push_back(arr[lastIndex]);
	}

	reverse(lisa.begin(),lisa.end());

	for(auto x: lisa) cout<< x<<" ";

		cout<<endl;
	return ans;	
}

int main(){
	
// 5
// 1 16 7 8 4
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout<< "Length of Longest Divisible Set => "<< LIS(arr, n);
	return 0;	
}