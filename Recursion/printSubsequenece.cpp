#include <bits/stdc++.h>
#define ll long long
#define int ll
#define lld long double
#define el "\n"
#define sp " "
#define F first
#define S second
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define rev(i, n, m) for(ll i=n-1; i>=m; i--)
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (ll i = n; i >= m; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pi 3.141592653589793238
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Byahut cout.tie(NULL);
#define input(x) for(ll i=0;i<x.size();i++)cin>>x[i];
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
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
// Modular calculation 
const ll M= 1e9 + 7;


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
const ll inf = 1e9 + 7;
char get(ll i){
    return 'a'+i-1;
}
ll fact(ll n);
 
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
ll fact(ll n)
{
      if(n==0)
      return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = mul(res,i);
    return res;
}

void prll(vector<ll> arr)
{
    ll n = arr.size();
    fl(i, n) cout << arr[i]<<" ";
    // cout << "\n";
}
//Code by Byahut
//Practice->Success
ll sumOfDigit(ll n)
{
    if(n== 0)
        return 0;
     int x = n%10;
     return x+ sumOfDigit(n/10);
}   
// long long lim = 1e6 + 7;
   // st int M = 1e9 + 7;
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
// generate string
   //      string s; int n = 5;
   // fl(i,n)
   // {
   //    int k = rand() % n;
   //    s+= 'a'+ k;
   // }
   // cout<<s;
void trial()
{
    int n  = rand() % 10 + 2;
    cout<<n <<" ";
    int l = rand() % 10;
    int r = rand() % 10 ;
    cout<<l<<" "<<r<<el;
    int b[n];
    int a[n];

    fl(i,n)
        {
            int k = rand() %20 + 1;
            a[i] = k;
            b[i] = a[i];
            cout<<k<<" ";
        }
        cout<<el;
        sort(b+l, b+ r);
    fl(i,n)
    {
        cout<<b[i]<<" ";
    }
    cout<<el;
    return;
}

void printSubset(int a[], int i, vector<int> &v, int n )
{
    if(i == n){
        for(auto it : v)
        {
            cout<<it<<" ";
        }
        if(v.size() == 0){
            cout<<"{}";
        }
        cout<<el;
        return;
    }
    printSubset(a, i+1, v, n);
    v.push_back(a, i+1, v, n);
    printSubset(a, i+1, v, n);
    v.pop_back();

    return;
}
 void solveNkb(){ 
    ll n;
    cin >> n;
    ll a[n];
    fl(i,n){
        cin>>a[i];
    }
    vector<int> v;
    printSubset(a, 0, v, n);
    return;
 }
signed main()
{
    Code By Byahut
 
    ll t = 1;
   
    cin >> t;
    // srand(time(NULL));
    while (t--)
    {
        solveNkb();
        // trial();
        cout<<"\n";
    }
        
        
    return 0;
} 
