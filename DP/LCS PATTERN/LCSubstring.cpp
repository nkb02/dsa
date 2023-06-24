 #include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define rep(i, m, n) for (int i = m; i < n; i++)
#define rev(i, n, m) for(int i=n-1; i>=m; i--)
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pi 3.141592653589793238
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Nkb cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }
void printarr(ll arr[], ll n)
{
    fl(i, n) cout << arr[i] << " ";
    cout << "\n";
}

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
//Code by Nitish Byahut
//Language C++
//Practice->Success

int static t[1001][1001];  // table to memoize program

// length of longest common subsequene
// TOP-DOWN

int LCSubstring(string x, string y, int n, int m){
	
	// INITIALIZATION
	
	fl(i,n+1){
		fl(j,m+1)
	    {
	    	if(j == 0 || i == 0)
					 t[i][j] = 0; 
	
		}
    }
	//choice diagram
    
	rep(i,1,n+1)
	    rep(j,1,m+1)
	    {
		         // If last letter is common then reduce size by 1 of both strings and add 1 to output
		   	if(x[i-1] == y[j-1])
		        t[i][j] = 1 + t[i-1][j-1];
			else
			    t[i][j] = 0; 
			    // If last letter is NOT common then 0
	   }
	int max = -1;
		
	fl(i,n+1){
		fl(j,m+1)
	    {
	    	if(t[i][j]> max)
					max = t[i][j] ; 
	
		}
    }  
	return max;
}

int main()
{
     Code By Nkb
     
        ll t1;
    cin >> t1;
    while (t1--)
    {
        int n , m;  // size of x : n ;size of y : m
        string x, y;
        
        cin>>x>>y;

		n = x.length();
		m = y.length();
		 
		int ans1 = LCSubstring(x,y,n,m);
	 	cout<<ans1;
		
    }
    return 0;
}


