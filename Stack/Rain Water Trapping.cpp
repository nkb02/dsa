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
    ll n;
    cin>>n;
    ll a[n+5];
    fl(i,n)
        cin>>a[i];

    ll maxL[n], maxR[n];
    maxL[0] = a[0];
    rep(i,1,n)
    {
        if(a[i]> maxL[i-1])
            maxL[i] = a[i];
        else
            maxL[i] = maxL[i-1];
    }
    maxR[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        if(a[i]> maxR[i+1])
            maxR[i] = a[i];
        else
            maxR[i] = maxR[i+1];
    }
    ll sum = 0;
    fl(i,n)
    {
        sum += (min(maxR[i], maxL[i]) - a[i]);
    }
    cout<<sum;
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