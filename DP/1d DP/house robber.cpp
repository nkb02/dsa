// Nkb108
// Practice is the only shortcut to improve
 
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define m (int) 998244353
#define M (int) 1e9+7
// Big two primes
#define X 1001100011100001111ll
#define all(a) a.begin(),a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define fl(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define vii vector<ii>
#define sz(s) s.size()
#define bits(n) __builtin_popcount(n)
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Byahut cout.tie(NULL);
#define input(x) for(ll i=0;i<x.size();i++)cin>>x[i];
using namespace std;

const int MAXN = (int)((1e5) + 100);
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}
void pr(auto x) {cout << x;}
void prl(int x) {cout << x << endl;}
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> Set;
//bool isPrime(int N){ for(int i=2;i*i<=N;++i){if(N%i==0) return false;}return true;}
int cbrt(int x) { int lo = 1, hi = min(2000000ll, x); while (hi - lo > 1) {int mid = (lo + hi) / 2; if (mid * mid * mid < x) {lo = mid;} else hi = mid;} if (hi * hi * hi <= x) return hi; else return lo;}
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int N =  (int)(2 * 1e5 + 10);


bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
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
ll sumOfDigit(ll n)
{
    if(n== 0)
        return 0;
     int x = n%10;
     return x+ sumOfDigit(n/10);
}   
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

void trial()
{
    int n  = rand() % 10 + 1;
    // [1,2,3,....,8,9,10]

    // cout<<n <<" ";
    string s1= "<>";
    // int l = rand() % 2;
    // cout << l << el;
    string s;
    fl(i,n)
        {
            int k = rand() %2;
            // cout<<k<<" ";
            s.push_back(s1[k]);
        }
        cout<<s<<endl;

   
       
    return;
}


bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
ll poww(ll n, ll p){
    ll ans=1;
    while(p){
        if(p%2==1){
            ans = (ans * n);
        }
        n = (n*n);
        p = p/2;
    }
    return ans;
}
//Code by Byahut
//Practice->Success

int sum(vector<int>&a){
    int n = a.size();

    int prev = a[0];
    int prev2 = 0;
    int cur = INT_MIN;

    for1(i,n-1){
        int pick = a[i];
        if(i> 1)
            pick += prev2;
        int nonpick = 0 + prev;

        cur = max(pick, nonpick);
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

void solveNkb()
{
    int n ;
    cin>>n;
    vector<int> a(n), a1(n-1);
    for0(i,n) cin>>a[i];

    loop(i, 1, n) a1[i-1] = a[i];
    
    int mx = sum(a);
    mx = max(mx, sum(a1));

    cout << mx;
    return;

}


signed main()
{
    Code By Byahut
 
    ll t = 1;
    assert(t<=10000); 
    cin >> t;
    srand(time(NULL));
    // to avoid generation of same no by rand()
    // dont want C++ to seed the value
    
    while (t--)
    {
        solveNkb();
        // trial();
        cout<<endl;
        }
        
        
    return 0;
} 

