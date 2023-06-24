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

unordered_map<string,int> mp;
// not making matrix as here we have 3 changing variable
// i , j, isTrue 
// t[i][j][isTrue] => t[size][size][2]

int solve(string S,int i,int j, bool isTrue)
{
    if(i > j) return 0;
    if(i == j) {
        if(isTrue) 
        { 
            // isTrue  == true and if s[i] = T then returning true i.e. 1
            return S[i] == 'T' ? 1 : 0;
        }
        else
        {
            // isTrue  == false and if s[i] = F then returning true i.e. 1
            // demand fulfilled
            return S[i] == 'F' ? 1 : 0;
        }
    }
    // preparing key = i + " " + j + " " + isTrue
    // unique key 
    // value is the ans calculated during recursion
    string key = to_string(i);
    key.push_back(' ');
    key.append(to_string(j));
    key.push_back(' ');
    key.append(to_string(isTrue));

    // checking if already present
    if(mp.find(key) != mp.end()) {
        // returning value stored at key
        return mp[key];
    }
    
    int ans = 0;
    
    for(int k = i+1; k<=j-1; k=k+2)
    {
        int leftTrue, leftFalse, rightTrue, rightFalse;
        
        // preparing new function calls key         
        string leftTruekey = to_string(i);
        leftTruekey.push_back(' '); 
        leftTruekey.append(to_string(k-1)); 
        leftTruekey.push_back(' '); 
        leftTruekey.append(to_string(true));
        
        string leftFalsekey = to_string(i);
        leftFalsekey.push_back(' '); 
        leftFalsekey.append(to_string(k-1)); 
        leftFalsekey.push_back(' '); 
        leftFalsekey.append(to_string(false));
        
        string rightTruekey = to_string(k+1); 
        rightTruekey.push_back(' '); 
        rightTruekey.append(to_string(j)); 
        rightTruekey.push_back(' '); 
        rightTruekey.append(to_string(true));
        
        string rightFalsekey = to_string(k+1); 
        rightFalsekey.push_back(' '); 
        rightFalsekey.append(to_string(j)); 
        rightFalsekey.push_back(' ');
        rightFalsekey.append(to_string(false));
        // checking if already present or not
        if(mp.find(leftTruekey) != mp.end()) {
            leftTrue = mp[leftTruekey];
        }
        else {
            leftTrue = solve(S,i,k-1,true);
        }
        
        if(mp.find(leftFalsekey) != mp.end()) {
            leftFalse = mp[leftFalsekey];
        }
        else {
            leftFalse = solve(S,i,k-1,false);
        }
        
        if(mp.find(rightTruekey) != mp.end()) {
            rightTrue = mp[rightTruekey];
        }
        else {
            rightTrue = solve(S,k+1,j,true);
        }
        
        if(mp.find(rightFalsekey) != mp.end()) {
            rightFalse = mp[rightFalsekey];
        }
        else {
            rightFalse = solve(S,k+1,j,false);
        }
        // done with calculating temp ans of partitions
        // finding final ans
        if(S[k] == '&') 
        {
            if(isTrue) {
                ans = ans + (leftTrue * rightTrue); 
            }
            else {
                ans = ans + (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse);  
            }
        }
        else if(S[k] == '|') 
        {
            if(isTrue) {
                ans = ans + (leftTrue*rightFalse) + (leftFalse*rightTrue) + (leftTrue*rightTrue);
            }
            else {
                ans = ans + (leftFalse*rightFalse);  
            }
        }
        else // S[k] == "^" 
        {
            if(isTrue) {
                ans = ans + (leftFalse*rightTrue) + (leftTrue*rightFalse); 
            }
            else {
                ans = ans + (leftTrue*rightTrue) + (leftFalse*rightFalse);  
            }
        }
        
    }
    return mp[key] = ans%1003;
}

int countWays(int N, string S){
    // code here
    mp.clear();
    return solve(S,0,N-1,true);
}


int main()
{
    Code By Byahut
 
    ll t=1;
    // cin >> t;
    
    while (t--)
    {
        // solveNkb();
        string s;
        cin>>s;
        int n = s.length();
        cout<<countWays(n,s);
        // cout<<"\n";
    }
        
        
    return 0;
}
