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

void printSubs(vector<int> &arr, int n, int index, vector<int>&ds){
    if(index == n){
        if(ds.size() == 0){
            cout<<"{}"<<endl;
        }
        else
            for(auto it: ds) cout<<it<<" ";
        
        cout<<endl;
        return;
    }
    // pick
    ds.push_back(arr[index]);
    printSubs(arr, n, index+1, ds);
    ds.pop_back();

    printSubs(arr, n, index+1, ds);
    return;
    // not pick
}
void solveNkb()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    fl(i,n) cin>> arr[i];

    vector<int>ds;
    int index = 0;
    printSubs(arr, n, index, ds);
    return;
}


signed main()
{
    Code By Byahut
 
    ll t = 1;
   
    cin >> t;
    srand(time(NULL));
    // to avoid generation of same no by rand()
    // dont want C++ to seed the value
    while (t--)
    {
        solveNkb();
        // trial();
        cout<<"\n";
    }
        
        
    return 0;
} 

