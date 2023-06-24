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

const int  N = 501;
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

// dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[], vector<int> &ls) {
        // mark the more as visited

        vis[node] = 1; 
        ls.push_back(node);
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis, ls); 
            }
        }
    }

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    vis[0] = 1; 
    queue<int> q;
    int count = 0;
    // push the initial starting node 
    q.push(0); 
    vector<int> bfs; 
    // iterate till the queue is empty 
    while(!q.empty()) {
       // get the topmost element in the queue 
        int node = q.front(); 
        q.pop(); 
        // count++ ;
        bfs.push_back(node); 
        // traverse for all its neighbours 
        for(auto it : adj[node]) {
            // if the neighbour has previously not been visited, 
            // store in Q and mark as visited 
            if(!vis[it]) {
                vis[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}  
ll factor( ll n)
{
    for (int i = 2; i*i <= n; ++i)
    {
        if(n % i == 0)
            return i;
    }
}
void solveNkb()
{
    ll n, d;
    cin>>n>>d;
    vector<ll> a(n);
    ll last = -1, first = -1;
    fl(i,n)
    {
        cin>>a[i];
    }
    int lo = 0;
    int hi = n-1;
    int mid;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(a[mid]== d){
            last = mid;
            lo = mid+1;
        }
        else if(a[mid] < d)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid -1;
        }    
    }
    lo = 0;
    hi = n-1;
     while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(a[mid]== d){
            first = mid;
            hi = mid-1;
        }
        else if(a[mid] < d)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid -1;
        }    
    }
    cout<<last-first+1;
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