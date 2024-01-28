#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2){
	if(s1.size() != s2.size() + 1) return false;

	int first = 0;
	int second = 0;
	while(first < s1.size()){
		if(second < s2.size() 
			&& s1[first] == s2[second])
		{
			first++;
			second++;
		}
		else first++;
	}

	if(s1.size() == first && s2.size() == second)
		return true;

	return false;
}



bool comp(string &s1, string &s2)
{
	return s1.size() < s2.size();
}
int LIS(vector<string> &arr, int n){
	sort(arr.begin(), arr.end(), comp);

	vector<int> dp(n, 1);
	// vector<int> hash(n, 1);
	int maxi = 1;
	for(int i =0 ; i< n; i++){
		// hash[i] = i;
		for (int prev = 0; prev < i ; ++prev)
		{
			if(compare(arr[i], arr[prev])
				&& dp[i] < 1+ dp[prev]){
				
				// hash[i] = prev;
				dp[i] =  1+ dp[prev];
			}
		}
		maxi = max(maxi, dp[i]);
	}


	return maxi;	
}

int main(){
	
	vector<string> words = {"a","b","ba","bca","bda","bdca"};
	int n = words.size();
	
	cout<< "Length of Longest String Chain => "<< LIS(words, n);
	return 0;	
}