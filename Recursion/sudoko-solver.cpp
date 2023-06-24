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

bool isValid(vector<vector<char>> &board, int row, int  col, char c){
    for (int i = 0; i < 9; ++i)
    {
        // whole column checked
        if(board[i][col] == c)
            return false;
        // whole row checked
        if(board[row][i] == c)
            return false;
        // whole 3x3 small sq checked
        if(board[3* (row / 3) + i / 3 ][ 3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool sudoko(vector < vector < char >> & board) {
      for (int i = 0; i < board.size(); ++i)
      {
         for (int j = 0; j < board[0].size(); ++j)
         {

            if(board[i][j] == '.'){

                for(char c = '1' ; c <='9'; c++){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;

                        if(sudoko(board) == true)
                            return true;
                        else
                            board[i][j] = '.'; 
                    }
                }
                return false;
            }
         }
      }
      return true;
}
void solveNkb()
{
    int n = 9;
    // cin >> n ;
    vector < vector < char >> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    // fl(i,n){
    //     fl(j,n)
    //     {
    //         char ch ;
    //         cin>> ch;
    //         board[i][j].push_back(ch);
    //     }
    // }

    sudoko(board);
    fl(i,n){
        fl(j,n)
        {
            cout<<board[i][j]<<" ";
        }
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

