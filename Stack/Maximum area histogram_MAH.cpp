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

// Let's code it --> it's quite long but it is easy
 vector<long long> nextSmallerElementToLEFT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = -1;
        for(long long i = 0; i < n; i++)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i],i});
        }
        return nge;
        
    }

 vector<long long> nextSmallerElementToRIGHT(vector<long long> arr, int n){
        vector<long long> nge(n);
        stack<pair<long long, long long>> s;
        int pseudoIndex = n;
        for(long long i = n-1; i >=0; i--)
        {
            if(s.size() == 0 )
            {
                nge[i]= pseudoIndex;
            }
            else if(s.size() > 0 && s.top().first < arr[i]){
                nge[i] = s.top().second;
            }
            else if(s.size() > 0 && s.top().first >= arr[i]){
                while(s.size() > 0 && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                if(s.size() == 0)
                {
                    nge[i]= pseudoIndex;
                }
                else
                {
                    nge[i] = s.top().second;
                }
            }
            s.push({arr[i], i});
        }
        return nge;
        
    }
 

 
void solveNkb()
{ 
    ll n;
    cin>>n;
    vector<long long> a(n), width(n), area(n);
    fl(i,n)
        cin>>a[i];

    vector<long long> left,right;
    left = nextSmallerElementToLEFT(a,n);
    right = nextSmallerElementToRIGHT(a,n); 
    // print(left,n);
    // print(right,n);
    fl(i,n)
    {
        width[i]= right[i] - left[i] -1;
    }
    fl(i,n)
    {
        area[i] = a[i] * width[i];
    }    
    cout<<*max_element(area.begin(), area.end());
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