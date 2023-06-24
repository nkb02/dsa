#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fstream derr;
	derr.open("C:/Driver/error.txt");
	int t = 1;
	int n ;cin>>n;
	// /*is Single Test case?*/ cin >> t;
	while (t--) {
		int ans = solve(n);
		derr<<"hii"<<"\n";
		cout << ans<<"\n";
	}

	return 0;
}
int solve(int n)
{
	cout<<"hey!\n";
    if(n <=1)
    	return 1;
    return n*solve(n-1);
}
