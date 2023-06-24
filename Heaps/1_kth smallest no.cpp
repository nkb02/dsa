#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define rev(i, n, m) for(ll i=n-1; i>=m; i--)
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
 // const int M=1e9+7;
        const int M=998244353;
 
 
        long long mod(long long x){
            return ((x%M + M)%M);
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
//Code by Nitish Byahut
//Language C++
//Practice->Success
 
// const int  N = 501;
// ll n,a[N],pref[N],suff[N];
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
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
} 
bool dfs(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto it :adj[node] ){
        if(!vis[it]){
            if(dfs(it, node, adj, vis) == true)
            {
                return true;
            }
        }
        else if(parent != it)
            {
                return true;
                // has cycle
            }
        }
    
    return false;
} 
 bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, adj, vis) == true) return true; 
           }
       }
       return false; 
    }

// int n,x,t[100000],last,ans,j;
ll factor(int x){
    for(int i = 2; i*i <= x; i++)
    {
        if(x % i == 0)
            return i;
    }
}

// square root of int in int
ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

const int N = 1e5+10;
ll n,k;
ll a[N];
ll presum[N]; 
// max heap
ll maxh(){
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; ++i)
    {
        maxHeap.push(a[i]);
        if(maxHeap.size() >k)
            maxHeap.pop();
    }
    return maxHeap.top();
}
// min heap
void minh(){
    priority_queue<int,vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; ++i)
    {
        minHeap.push(a[i]);
        if(minHeap.size() >k)
            minHeap.pop();
    }
    while(minHeap.size() > 0){
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
}
void solveNkb(){
    cin>>n>>k;
    fl(i,n)
        cin>>a[i];

    cout<<maxh(); 



    return;
}
    
int main()
{
     Code By Nkb
        ll t=1;
    cin >> t;
    while (t--)
    {
        solveNkb();
        cout<<"\n";
    }
        
        
    return 0;
}
