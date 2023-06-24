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
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
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
bool isPrimes(ll n)
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

 const int M=1e9+7;
// const int M=998244353;
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

 
 
ll factor( ll n)
{
    for (int i = 2; i*i <= n; ++i)
    {
        if(n % i == 0)
            return i;
    }
}
// Sieve and its application
const int N = 1000;
vector<bool> isPrime(N,1);

void Sieve()
{
    isPrime[0] = isPrime[1] = 0;  // 2 & 1 ARE COMPOSITE SO MARKED AS 0 -> COMPOSITE
        // i*i <= N is more optimed
        for(int i = 2 ; i <= N ; i++)
        {
            if(isPrime[i])
            {
                // i*i is more optimed than i*2
                for(int j = 2*i; j<= N; j+=i)
                  isPrime[j] = 0; //MARKING AS COMPOSITE NOs
            }
            
        }
}
// lp - lowest prime factor
// hp - highest prime factor

vector<int> lp(N,0), hp(N,0); 
void factorsUsing_Sieve()
{
    isPrime[0] = isPrime[1] = 0;  // 2 & 1 ARE COMPOSITE SO MARKED AS 0 -> COMPOSITE
        // i*i <= N is more optimed
        for(int i = 2 ; i <= N ; i++)
        {
            if(isPrime[i])
            {
                lp[i] = hp[i] = i; // for prime nos
                // i*i is more optimed than i*2
                for(int j = 2*i; j<= N; j+=i)
                {
                    isPrime[j] = 0; //MARKING AS COMPOSITE NOs
                    hp[j] = i;
                    if(lp[j] == 0)
                    {
                        lp[j] = i;
                    }
                }
                }
            
        }
// lp - contains lowest prime factor
// hp - contains highest prime factor

}
// divisors using seive algorithm
vector<int> divisors[N];
void divisorsUsing_Seive()
{
    rep(i,2,N)
    {
        for(int j = i; j<N ; j+= i)
        {
            divisors[j].push_back(i);
        }
    }
    // O(N log(N))
}
//Code by Nkb108
//Language C++
// Code begins here ---->

 
void Nkb108()
{ 
    // int n ;
    // cin>>n;
   
    // fl(i,n)
    // {
    //     cout<<a[i]<<" ";
    //     cout<<lp[a[i]]<<" ";
    //     cout<<hp[a[i]]<<"\n";
    // }

// Prime factors of #

     //    vector<int> primeFactors;
     // fl(i,n)
     //    {
     //    while(a[i] > 1){
     //        int prime_factor = hp[a[i]];
     //        while(a[i] % prime_factor == 0)
     //        {
     //            a[i]/= prime_factor;
     //            primeFactors.push_back(prime_factor);
     //        }
     //    }

     //        for(int factor : primeFactors)
     //            cout<<factor<<" " ;   
     //        cout<<'\n';

     //        primeFactors.clear();
     //    }

    // printing divisors using seive
    // divisorsUsing_Seive();
    // rep(i,1,11)
    // {
    //     cout<<i<<" -> ";
    //     for(int div : divisors[i])
    //     {
    //         cout<<div<<" ";
    //     }
    //     cout<<'\n';
    // }


    return;
   
    
}
    
int main()
{
     Code By Nkb
     ll t=1;
     // cin >> t;
     // factorsUsing_Sieve();
    while (t--)
    {
        Nkb108();
        cout<<"\n";
    }
        
    return 0;
}