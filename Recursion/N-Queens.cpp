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

void queens(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          
          queens(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
}
void solveNkb()
{
    int n;
    cin >> n ;
    vector < vector < string >> ans;
    vector < string > board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      queens(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      // cout<<ans.size();
    for(int i = 0 ; i < ans.size(); i++){
        for(auto it: ans[i]) cout<< it<<el;
            cout<<el;
    }
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

