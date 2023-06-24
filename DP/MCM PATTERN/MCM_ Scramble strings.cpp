#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define el "\n"
#define F first
#define S second
#define rep(i, m, n) for (ll i = m; i < n; i++)
#define rev(i, n, m) for(ll i=n-1; i>=m; i--)
#define pb push_back
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pi 3.141592653589793238
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Byahut cout.tie(NULL);
using namespace std;

    unordered_map<string, bool> mp;
    bool solve(string a,string b)
    {
        if(a.compare(b)==0)
            return true;
        if(a.length()<=1)
            return false;
        string t="";
        t+=a+" "+b;
        if(mp.find(t)!=mp.end())
            return mp[t];
        int n=a.length();
        bool flag=false;
        for(int i=1;i<=n-1;i++)
        {
            bool cond1,cond2;
            cond1=cond2=false;
            if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true)
                cond1=true;
            if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true)
                cond2=true;
            if(cond1 || cond2)
                {
                    flag=true;
                    break;
                }
        }
        return mp[t]=flag;
    }


    bool isScramble(string a, string b){

    if(a.length()==0 && b.length()==0)
        return true;

    int n=a.length();
    int m=b.length();

    if(n>m || m>n)
        return false;

    mp.clear();
    return solve(a,b);
    }

    int main()
    {
        Code By Byahut
     
        ll t=1;
        // cin >> t;
        
        while (t--)
        {
            // solveNkb();
            // cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<isScramble(a,b);
        }
            
            
        return 0;
    }
