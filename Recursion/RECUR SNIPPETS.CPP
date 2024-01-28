#height of a binary tree

int height(int *node){
    if(node == NULL) return 0;

    int lt = height(node->left);
    int rt = height(node->right);

    return 1 + max(lt, rt);
}

# sort an array using recursion

void insert(vector<int>&v, int temp){
    if(v.size()== 0 || v.back() <= temp){
        v.push_back(temp);
        return;
    }

    int val = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
    return;
}
void sort(vector<int> &v){
    if(v.size() == 0){
        return;
    }

    int temp = v.back();
    v.pop_back();

    insert(v, temp);
    return;
}

# Delete middle element of stack
stack<int> midDel(stack<int>&s, int size){
    if(st.size() == 0) 
        return s;
    int k = (size+1)/2;
    solve(s, k);
    return s;
}

void solve(stack<int> &st, int k){
    if(k == 1) {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k-1);
    st.push(temp);
    return;
}


# print all the subs 
=> given arr print all subset

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

1. print all the subs with sum k

void fun( int arr[], int ind, int n, vector<int> &ds, int sum, int s){
    // base case
    if(ind < 0){
        if(s== sum){
           for(auto x : ds) cout<< x <<" ";

            cout<<endl;

        }
        return;
    }

    // not take
    fun(arr, ind-1, n, ds, sum, s);

    // take
    ds.push_back(arr[ind]);
    s+= arr[ind];
    fun(arr, ind-1, n, ds, sum, s);
    s-= arr[ind];   
    ds.pop_back();
    

}


2. print any subs with sum k 

bool flag = true;
void fun( int arr[], int ind, int n, vector<int> &ds, int sum, int s){
    // base case
    if(ind < 0){
        if(s== sum && flag== true){
           for(auto x : ds) cout<< x <<" ";

            cout<<endl;
        flag = false;

        }
        return;
    }

    // not take
    fun(arr, ind-1, n, ds, sum, s);

    // take
    ds.push_back(arr[ind]);
    s+= arr[ind];
    fun(arr, ind-1, n, ds, sum, s);
    s-= arr[ind];   
    ds.pop_back();
    

}

            [OR]

bool fun( int arr[], int ind, int n, vector<int> &ds, int sum, int s){
    // base case
    if(ind < 0){
        if(s== sum ){
           for(auto x : ds) cout<< x <<" ";

            cout<<endl;
            return true;
        }
        return false;
    }

    // not take
    if(fun(arr, ind-1, n, ds, sum, s)){
        return true;
    }

    // take
    ds.push_back(arr[ind]);
    s+= arr[ind];
    if(fun(arr, ind-1, n, ds, sum, s))
        return true;
    s-= arr[ind];   
    ds.pop_back();

    return false;
    

}

3. count num of subs with sum  = k

int fun( int arr[], int ind, int n, int sum, int s){
    // base case
    if(ind < 0){
        if(s== sum ){
            return 1;
        }
        return 0;
    }

    // not take
    int notTake = fun(arr, ind-1, n, sum, s);

    // take
    s+= arr[ind];
    int take = fun(arr, ind-1, n, sum, s);
    s-= arr[ind]; 

    return take + notTake;
    
}

==> 
    cout<< fun(a, n-1, n,sum, 0);

4.  Combination Sum 


void printSubs(vector<int> &arr, int n, int index, vector<int>&ds, int target){
    if(index == n){
        if(target == 0){
            for(auto it: ds) cout<<it<<" ";
        
            cout<<endl;
        }
        return;
    }
    // pick
    if(arr[index] <= target){
        ds.push_back(arr[index]);
        
        printSubs(arr, n, index, ds, target-arr[index]);
        ds.pop_back();
        
    }

    printSubs(arr, n, index+1, ds, target);
    return;
    // not pick
}


5.  Combination Sum  II

ar[] 1 1 1  2 2

unique comb for sum equal to 4
op =>
        1 1 2
        2 2

void printSubs(vector<int> &arr, int n, int index, vector<int>&ds, int target){

    if(target == 0){
        for(auto it: ds) cout<<it<<" ";
        cout<<endl;
    
        return;
    }
    for (int i = index; i < n; ++i)
    {
        // check if unique or first appearance
        if(i> index && arr[i] == arr[i-1]) continue;

        // take if arr[i] <= target
        if(arr[i] > target)
            break;
        ds.push_back(arr[i]);
        
        printSubs(arr, n, i+1, ds, target-arr[i]);
        ds.pop_back();
    }
    return;
}
 

6. subset sum I


void subsetSum(vector<int> &arr, int n, int index, int sum){
    if(index == n){
        cout<<sum << endl;
        return;
    }
    // not pick

    subsetSum(arr, n, index+1, sum);
    // pick
    subsetSum(arr, n, index+1, sum+arr[index]);
    return;
}

7.  subset sum II #striver

void subset(int a[], int n, vector<int> &ds, vector<vector<int>> &ans, int ind ){
  ans.push_back(ds);
  for (int i = ind; i < n; ++i)
  {
     if(ind != i && a[i] ==a[i-1] ) continue;

     //pick
     ds.push_back(a[i]);
     subset(a, n, ds, ans, ind+1);
     ds.pop_back();
  }
}

8. permuations print all I
    
void printPermuations(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int freq[]){
        if(ds.size() == nums.size() )
        {
            ans.push_back(ds);
    
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);  
                printPermuations(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }   
        }       
    }

9. permuations print all  II (no extra space)

    

void printPermuations(int index, vector<int> &nums, vector<vector<int>> &ans){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        swap(nums[index], nums[i]);
        printPermuations(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
    return;
}


10.  Generate Parentheses

 void braces(string &op, vector<string> &ans, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        
        if(open !=  0 ){
            string op1 = op;
            op1.push_back('(');
            braces(op1, ans, open-1, close);
        }
        if(open < close){
            string op2 = op;
            op2.push_back(')');
            braces(op2, ans, open, close-1);
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op ="";
        
        braces(op, ans, open, close);
        return ans;
    }

11. pow(x, n)

double myPow(double x, int n) {
          double ans = 1.0;
          long long nn = n;
          if (nn < 0) nn = -1 * nn;
          while (nn) {
            if (nn % 2) {
              ans = ans * x;
              nn = nn - 1;
            } else {
              x = x * x;
              nn = nn / 2;
            }
          }
          if (n < 0) ans = (double)(1.0) / (double)(ans);
          return ans;
    }

// Implementation

1. reverse a stack using recursion


void insert(stack<int> &s, int elem){
    if(s.size() == 0){
        s.push(elem);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(s, elem);

    s.push(temp);
    return;
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.size() == 1)
    return;

    int temp= stack.top();
    stack.pop();
    reverseStack(stack);

    insert(stack, temp);
    return;
}

# Tower of HANOI (gfg)

long long count = 0;
long long toh(int N, int source, int dest, int helper) {
    count++;
    if(N == 1){
        cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<dest<<'\n';
        return count;
    }
    toh(N-1, source, helper, dest);
    cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<dest<<'\n';
    toh(N-1, helper, dest, source);
    return count;
    
}


// HARD 

1. Palindrome Partitioning

 vector < vector < string >> partition(string s) {
      vector < vector < string > > res;
      vector < string > path;
      partitionHelper(0, s, path, res);
      return res;
    }

  void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    // base case
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }


  2. N QUEENS 

    ** USE HASHING FOR CHECKING VALID OR NOT THAT O(N) WHILE LOOPS

   void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
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
          
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          
          // back tracking
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;

        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }


3. RAT IN A MAZE


 void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, 
    string move, vector < vector < int >> & vis, int di[], int dj[]) 
 {
    // base case
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }
    
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];

      // cell validity , not visited,  is reacheable a[i][j] == 1
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && 
        !vis[nexti][nextj] && a[nexti][nextj] == 1) 
      {
        vis[i][j] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }


  vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = {+1, 0, 0, -1};
      int dj[] = {0,  -1,  1,  0};
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
 


 4. M- coloring problems

 Problem Statement: Given an undirected graph and a number m, determine if the graph can be
  colored with at most m colors such that no two adjacent vertices of the graph are colored 
  with the same color.

 Solution 1: Backtracking

Approach:

Basically starting from vertex 0 color one by one the different vertices. 

Base condition:

If I have colored all the N nodes return true.

Recursion:

Trying every color from 1 to m with the help of a for a loop.

Is safe function returns true if it is possible to color it with that color i.e none of the adjacent nodes have the same color.

In case this is an algorithm and follows a certain intuition, please mention it. 

Color it with color i then call the recursive function for the next node if it returns true we will return true.

And If it is false then take off the color.

Now if we have tried out every color from 1 to m and it was not possible to color it with any of the m colors then return false.



bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}


5. Sudoku Solver

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) 
    {
      if (board[i][j] == '.') 
      {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solveSudoku(board))
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