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
void print(vector<ll> arr, ll n)
{
    fl(i, n) cout << arr[i] << " ";
    cout << "\n";
}

  
void solveNkb()
{ 
   ll n, w;
   cin>>n>>w;
   ll a[n];
   priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> minHeap;
   fl(i,n)
   {
    cin>>a[i];

    if(a[i] <= w)
    minHeap.push({a[i], i+1});

   } 
   vector<ll> v;
   while(w>0 && minHeap.size() != 0)
   {
        if(minHeap.top().first <= w)
            v.push_back(minHeap.top().second);
        w -= minHeap.top().first;
        minHeap.pop();
   }
   
   if(v.size() == 0)
   {
    cout<<-1;
    return;
   }
   else{
      sort(v.begin(), v.end());
      cout<<v.size()<<'\n';  
      for(auto x: v)
       cout<<x<<" ";
    }
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