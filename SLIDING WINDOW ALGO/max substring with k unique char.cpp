#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define el "\n"
#define F first
#define S second
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define rev(i, n, m) for(ll i=n-1; i>=m; i--)
#define pb push_back
#define mp make_pair
#define fl(i, n) for (long long i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pi 3.141592653589793238
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Byahut cout.tie(NULL);
using namespace std;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
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
// Modular calculation 
const int M= 1e9 + 7;


long long mod(long long a){
    return ((a%M + M)%M);
}
long long add(long long a, long long b){
    return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

ll modPow(ll a, ll b){
    if(b==0)
        return 1LL;
    if(b==1)
        return a%M;
    ll res=1;
    while(b){
        if(b%2==1)
            res=mul(res,a);
        a=mul(a,a);
        b=b/2;
    }
    return res;
}
const int inf = 1e9 + 10;
char get(int i){
    return 'a'+i-1;
}
ll fact(int n);
 
ll nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
ll fact(int n)
{
      if(n==0)
      return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = mul(res,i);
    return res;
}

void print(vector<ll> arr, ll n)
{
    fl(i, n) cout << arr[i]<<" ";
    // cout << "\n";
}
//Code by Byahut
//Practice->Success
 int longestKSubstr(string s, int k) {
    int start, end;
    start =end  =0;
    unordered_map<char, int>mp;
    int mx = 0;
    while(end< s.size())
    {
        mp[s[end]]++;
        if(mp.size()< k)
            end++;
        else if(mp.size() == k)
          {
            mx = max(mx, end-start+1);
            end++;
          }
        else if(mp.size() > k)
         {
            while(mp.size() > k)
            {
                mp[s[start]]--;
                if(mp[s[start]] == 0)
                    mp.erase(s[start]);
                start++;
            }
            end++;
        
         }
    }
    return mx;
 }
 
void solveNkb(){
    string s;
    int k;
    cin>>s>>k;
    cout<<longestKSubstr(s,k);
}
    
int main()
{
    Code By Byahut
 
    ll t=1;
    cin >> t;
    while (t--)
    {
        solveNkb();
        cout<<"\n";
    }
        
        
    return 0;
}