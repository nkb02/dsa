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
// a in range of 10^18
// we can take  a%m initially and then same process
// const int M = 1e7 +9;
// what if M is in 10^18 ??
// then we cant multiply a* a or a* res as it will exceed ll range 10^18
// we use binary multiplication technique 
const int M = 1e7 + 18;
// n in range of 10^9
int binaryMultiply( ll a ,ll b)
{
    int ans = 0;
    while(b>0)
    {
        if(b&1)
        {
            // we cannot multiply hence adding n times
            ans = (ans + a)% M;
        }
        a = (a + a) % M;
        b >>=1;
    }
    return ans;
}
ll binaryExp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
    	if(n&1) // if bit is set
        	{
                res = binaryMultiply(res, a); 
            }    	
        
    	   a = binaryMultiply(a,a); 
           n >>= 1;
       
    }
    return res;
	}
int main()
{
     Code By Nkb
     ll t;
    cin >> t;
    while (t--)
    {
    	int base ;
    	int n;
    	cin>>base>>n;
        cout<<binaryExp(base,n)<<'\n';
    }
    return 0;
}


