1. bfs

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        // push the initial starting node 
        q.push(0); 
        vector<int> bfs; 
        // iterate till the queue is empty 
        while(!q.empty()) {
           // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }

Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list


2. dfs

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1; 
    ls.push_back(node); 
    // traverse all its neighbours
    for(auto it : adj[node]) {
        // if the neighbour is not visited
        if(!vis[it]) {
            dfs(it, adj, vis, ls); 
        }
    }
}

Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.


3. no of provinces

 int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
        
    }

4. Rotten Oranges : Min time to rot all oranges

int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0,
         tot = 0, cnt = 0;

        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) days++;
        }
        
        return tot == cnt ? days : -1;
    }

5. Flood fill algorithm

void dfs(int row, int col, vector<vector<int>>&ans,
 vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
 int iniColor)
  {
    // color with new color
    ans[row][col] = newColor; 
    int n = image.size();
    int m = image[0].size(); 
    // there are exactly 4 neighbours
    for(int i = 0;i<4;i++) {
        int nrow = row + delRow[i]; 
        int ncol = col + delCol[i]; 
        // check for valid coordinate 
        // then check for same initial color and unvisited pixel
        if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, 
        int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }


6. detect a cycle bfs

bool detect(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  } 
    // Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }    

7.detect a cycle dfs

// Function to detect cycle in an undirected graph.

bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj) == true) return true; 
           }
       }
       return false; 
    }

bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1; 
    // visit adjacent nodes
    for(auto adjacentNode: adj[node]) {
        // unvisited adjacent node
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true) 
                return true; 
        }
        // visited node but not a parent node
        else if(adjacentNode != parent) return true; 
    }
    return false; 
}

8. nearest distance to 1

vector<vector<int>>nearest(vector<vector<int>>grid)
    {
        int n = grid.size(); 
        int m = grid[0].size(); 
        // visited and distance matrix
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> dist(n, vector<int>(m, 0)); 
        // <coordinates, steps>
        queue<pair<pair<int,int>, int>> q; 
        // traverse the matrix
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // start BFS if cell contains 1
                if(grid[i][j] == 1) {
                    q.push({{i,j}, 0}); 
                    vis[i][j] = 1; 
                }
                else {
                    // mark unvisited 
                    vis[i][j] = 0; 
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0}; 
        int delcol[] = {0, +1, 0, -1}; 
        
        // traverse till queue becomes empty
        while(!q.empty()) {
            int row = q.front().first.first; 
            int col = q.front().first.second; 
            int steps = q.front().second; 
            q.pop(); 
            dist[row][col] = steps; 
            // for all 4 neighbours
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i]; 
                int ncol = col + delcol[i]; 
                // check for valid unvisited cell
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1; 
                    q.push({{nrow, ncol}, steps+1});  
                }
            }
        }
        // return distance matrix
        return dist; 
    }

9. Surrounded Regions | Replace O’s with X’s

* first row, col; last row, col if any zero call dfs for it
mark as visited nd call dfs for 0

* finally mark as unvisited 0s as X return matrix


vector<vector<char>> fill(int n, int m, 
    vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vector<vector<int>> vis(n, vector<int>(m,0)); 
        // traverse first row and last row 
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol); 
            }
            
            // last row 
            if(!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1,j,vis,mat, delrow, delcol); 
            }
        }
        
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol); 
            }
            
            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat, delrow, delcol); 
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return mat; 
    }

void dfs(int row, int col, vector<vector<int>> &vis, 
vector<vector<char>> &mat, int delrow[], int delcol[]) {
    vis[row][col] = 1; 
    int n = mat.size();
    int m = mat[0].size();
    
    // check for top, right, bottom, left 
    for(int i = 0;i<4;i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i]; 
        // check for valid coordinates and unvisited Os
        if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
        && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
            dfs(nrow, ncol, vis, mat, delrow, delcol); 
        }
    }
}

10. Number of Enclaves

approach: 
* traverse boundary cells if it is  1 push in queue

* perform bfs for all elements if any adj cell has 1 push it mark as 1
* count no of cells having 1 but not visited , return cnt

 int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }

11. Word Ladder – I **

Given are the two distinct words startWord and targetWord, 
and a list denoting wordList of unique words of equal lengths.
 Find the length of the shortest transformation sequence from startWord to targetWord.

approach:
* create a queue to store bfs traversal
* hash set to store elements present in word list, and search, delete them in O(1)


  int wordLadderLength(string startWord, string targetWord,
                         vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }


12. Word Ladder-II **

Given two distinct words startWord and targetWord,
 and a list denoting wordList of unique words of equal
  lengths. Find all shortest transformation sequence(s) from startWord to targetWord. 
  You can return them in any order possible.


vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
{
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Creating a queue ds which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        // BFS traversal with pushing the new formed sequence in queue 
        // when after a transformation, a word is found in wordList.

        q.push({beginWord});

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
       
        // A vector to store the resultant transformation sequence.
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // Now, erase all words that have been
            // used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {   
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    { 
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }


13. Number of Islands

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
  // mark it visited
  vis[row][col] = 1; 
  queue<pair<int,int>> q;
  // push the node in queue
  q.push({row, col}); 
  int n = grid.size(); 
  int m = grid[0].size(); 
  
  // until the queue becomes empty
  while(!q.empty()) {
      int row = q.front().first; 
      int col = q.front().second; 
      q.pop(); 
      
      // traverse in the neighbours and mark them if its a land 
      for(int delrow = -1; delrow<=1;delrow++) {
          for(int delcol = -1; delcol <= 1; delcol++) {
              int nrow = row + delrow; 
              int ncol = col + delcol; 
              // neighbour row and column is valid, and is an unvisited land
              if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
              && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                  vis[nrow][ncol] = 1; 
                  q.push({nrow, ncol}); 
              }
          }
      }
  }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(); 
    int m = grid[0].size(); 
    // create visited array and initialise to 0
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    int cnt = 0; 
    for(int row = 0; row < n ; row++) {
        for(int col = 0; col < m ;col++) {
            // if not visited and is a land
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++; 
                bfs(row, col, vis, grid); 
            }
        }
    }
    return cnt; 
}


14. bipartite Graph

    * make a dfs call with col = 0, if unvisited, then on each call if(col == color[it]) return false
    * any dfs call returns false then return false
    * else return true

bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i = 0;i<V;i++) color[i] = -1; 
    
    // for connected components
    for(int i = 0;i<V;i++) {
        if(color[i] == -1) {
            if(dfs(i, 0, color, adj) == false) 
                return false; 
        }
    }
    return true; 
}

 bool dfs(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col; 
    
    // traverse adjacent nodes
    for(auto it : adj[node]) {
        // if uncoloured
        if(color[it] == -1) {
            if(dfs(it, !col, color, adj) == false) return false; 
        }
        // if previously coloured and have the same colour
        else if(color[it] == col) {
            return false; 
        }
    }
    
    return true; 
}

15. Detect cycle in a directed graph 
    
   * algo of undirectedgraph wont work here as if last node is already visited doenst means its a isCycle
   * keep two array : visite, pathVis
   * mark pathVis at everycall then unmark it before the call ends
   * if node is visited and pathVis then its a cycle.

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node]) {
        // when the node is not visited
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

16. Topological Sort Algorithm

Intution: node will be marked as visited immediately after making 
          the DFS call and before returning from the DFS call, 
          the node will be pushed into the stack.

vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void dfs(int node, int vis[], stack<int> &st,
    vector<int> adj[]) 
{
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}

17. Kahn’s Algorithm | Topological Sort Algorithm |

initial req: indegree[], queue, ans[]
algo:
    * initialise indegree by 0
    * traverse adj[] indegree[it]++, hence indegree[] formed
    * push elem having indegree[i] => 0 in queue
    * while queue not empty, push q.front() in ans[]
    * traverse through adj[node]  indegree[it]--, if(indegree[it] == 0) push in queue

vector<int> topoSort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }

18. Cycle Detection in Directed Graph usign Kahn algorithm

if size of topoSort != # vertcies it isnt DAG i.e. it is Cyclic

vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    // vector<int> topo;
    int topo = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // topo.push_back(node);
        topo++;
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo != V;
}



19. Course Schedule I and II 

pair of prerequisite tasks
hence topoSort
if topoSort size == #vertcies => possible
if possible then probable answer is topoSort

20.Find Eventual Safe States 

Safe States  = > outdegree[node] = 0
Algorithm:
    1. reverse the Graph
    2. now calc indegree
    3. perform topoSort
    4. sort the topoSort

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            // i -> it
            // it -> i
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }


21. alien dictionary

Algorithm:
    1. run a loop in all strings in dict 
    2. where s1[i] != s2[i] push it in adj[] : s1[ptr] -> s2[ptr]
    3. adj[] is ready
    4. no of letters is K
    5. perform topoSort (form nodes by s[ptr] - 'a') 
    6. return topoSort 
    7. store string by topo[i] + 'a'

vector<int> topoSort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }

string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo) {
            ans = ans + char(it + 'a');
        }
        return ans;
    }


==================================================================================

         Shortest Path Algorithms and Problems

===================================================================================

22. Shortest Path in Undirected Graph with unit

To find the shortest path from the source to all other nodes in this graph.

Algorithm:
    1. make adj[] if not given
    2. declare a dist[] with 1e9 initially
    3. mark dist[src] = 0
    4. make a queue, push source
    5. perform bfs if dist[node] + 1 < dist[it] , update it nd push in queue
    6. if dist[node] == 1e9 mark it as -1 as unreachable

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }

23. Shortest Path in Directed Acyclic Graph Topological Sort

Algorithm:
    1. create adj[] (u, {v, wt})
    2. create a vis[N]
    3. create a stack
    4. perform dfs topoSort
    5. while(!st.empty()) if(dist[node] + wt < dist[it]), update it


 vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      //We create a graph first in the form of an adjacency list.
      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {
        0
      };
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }

void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }

24. Dijkstra’s Algorithm – Using Set 

Algorithm:
    1. set<pair<int, int>> and dist[V] = 1e9
    2. insert (0,src) in set, dist[s] = 0
    3. if(dist + edw < dist[adjNode]) update, delete the previous one if it waas present
    4. push new dist nd node in set
    5. return dist[]

  //Function to find the shortest distance of all the vertices
    //from the source vertex S.

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
// Create a set ds for storing the nodes as a pair {dist,node}
// where dist is the distance from source to the node.
// set stores the nodes in ascending order of the distances 
set<pair<int,int>> st; 

// Initialising dist list with a large number to
// indicate the nodes are unvisited initially.
// This list contains distance from source to the nodes.
vector<int> dist(V, 1e9); 

st.insert({0, S}); 

// Source initialised with dist=0
dist[S] = 0;

// Now, erase the minimum distance node first from the set
// and traverse for all its adjacent nodes.
while(!st.empty()) {
    auto it = *(st.begin()); 
    int node = it.second; 
    int dis = it.first; 
    st.erase(it); 
    
    // Check for all adjacent nodes of the erased
    // element whether the prev dist is larger than current or not.
    for(auto it : adj[node]) {
        int adjNode = it[0]; 
        int edgW = it[1]; 
        
        if(dis + edgW < dist[adjNode]) {
            // erase if it was visited previously at 
            // a greater cost.
            if(dist[adjNode] != 1e9) 
                st.erase({dist[adjNode], adjNode}); 
                
            // If current distance is smaller,
            // push it into the queue
            dist[adjNode] = dis + edgW; 
            st.insert({dist[adjNode], adjNode}); 
         }
    }
}
// Return the list containing shortest distances
// from source to all the nodes.
return dist; 
}

24.2 using pq 

 vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});

        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        return distTo;
    }

almost same only adv in set is we can erase some nodes and save time of few iterations

25. Shortest Distance in a Binary Maze
Algo:
    1. check if src nd dest are same return 0
    2. create 2d dist with 1e9 initially
    3. create queue of (dist, {x, y})
    4. push (0, srcx, srcy) in queue
    5. check if newr newc are vaild grid is 1 then dist is smaller then update it nd push in queue

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }

26.   Path With Minimum Effort

same as previous - just now edge wt is diff all the time 
hence using priority_queue

calculate newEffort:
    =>  newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

int MinimumEffort(vector<vector<int>> &heights)
    {

        // Create a priority queue containing pairs of cells 
        // and their respective distance from the source cell in the 
        // form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            if (row == n - 1 && col == m - 1)
                return diff;
           
            for (int i = 0; i < 4; i++)
            {
                // row - 1, col
                // row, col + 1
                // row - 1, col
                // row, col - 1
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // Effort can be calculated as the max value of differences 
                    // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }

27. Cheapest Flights Within K Stops
Algorithm:
    1. create adj[]
    2. q.push({0, {src, 0}});
    3. vector<int> dist(n, 1e9);
        dist[src] = 0;
    4. if (stops > K) continue; 
    5. if (cost + edW < dist[adjNode] && stops <= K)
        {
            dist[adjNode] = cost + edW;
            q.push({stops + 1, {adjNode, cost + edW}});
        }


int CheapestFLight(int n, vector<vector<int>> &flights,
                   int src, int dst, int K)
{
    // Create the adjacency list to depict airports and flights in
    // the form of a graph.
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    // Create a queue which stores the node and their distances from the
    // source in the form of {stops, {node, dist}} with ‘stops’ indicating 
    // the no. of nodes between src and current node.
    queue<pair<int, pair<int, int>>> q;
    
    q.push({0, {src, 0}});

    // Distance array to store the updated distances from the source.
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // Iterate through the graph using a queue like in Dijkstra with 
    // popping out the element with min stops first.
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        // We stop the process as soon as the limit for the stops reaches.
        if (stops > K)
            continue;
        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            // We only update the queue if the new calculated dist is
            // less than the prev and the stops are also within limits.
            if (cost + edW < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }
    // If the destination node is unreachable return ‘-1’
    // else return the calculated dist from src to dst.
    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}

28.  Number of Ways to Arrive at Destination
Algorithm:
    1. everthing same as normal dijkstra
    2. maintain a new array ways[], mark ways[src] = 1
    3. current dist value is the same as the previously stored dist value at the same index, 
        increment the number of ways by 1 at that index.

int countPaths(int n, vector<vector<int>> &roads)
{
    // Creating an adjacency list for the given graph.
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Defining a priority queue (min heap). 
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initializing the dist array and the ways array
    // along with their first indices.
    vector<int> dist(n, INT_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    // Define modulo value
    int mod = (int)(1e9 + 7);

    // Iterate through the graph with the help of priority queue
    // just as we do in Dijkstra's Algorithm.
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            // This ‘if’ condition signifies that this is the first
            // time we’re coming with this short distance, so we push
            // in PQ and keep the no. of ways the same.
            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }

            // If we again encounter a node with the same short distance
            // as before, we simply increment the no. of ways.
            else if (dis + edW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    // Finally, we return the no. of ways to reach
    // (n-1)th node modulo 10^9+7.
    return ways[n - 1] % mod;
}


29. Minimum Multiplications to Reach End

Algorithm:
    1.Create a queue for storing the numbers as a result of multiplication
      of the numbers in the array and the start number.    
    2. dist array to store the no. of multiplications to reach
        a particular number from the start number.
    3. if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;

                // Whenever we reach the end number
                // return the calculated steps
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
int minimumMultiplications(vector<int> &arr,
                           int start, int end)
{
    // Create a queue for storing the numbers as a result of multiplication
    // of the numbers in the array and the start number.
    queue<pair<int, int>> q;
    q.push({start, 0});

    // Create a dist array to store the no. of multiplications to reach
    // a particular number from the start number.
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;

    // Multiply the start no. with each of numbers in the arr
    // until we get the end no.
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int num = (it * node) % mod;

            // If the no. of multiplications are less than before
            // in order to reach a number, we update the dist array.
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;

                // Whenever we reach the end number
                // return the calculated steps
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    // If the end no. is unattainable.
    return -1;
}

30. Bellman Ford Algorithm
used if graph as negative edgW

Algorithm:
    1. do N-1 times relaxation
        relaxation=> if it is reachable and dist[u] + wt < dist[v], update it
    2. to check for negative cycle do Nth relaxation if val still decreases it has a neg Cycle

**Costly algorithm as dijkstra take N log V it takes n*V but useful for neg edges

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return { -1};
            }
        }


        return dist;
    }

31. Floyd Warshall Algorithm

unique:
    1. multi source shortestpath
    2. adj matri is used
    3. negative cycle can be detected

void shortest_distance(vector<vector<int>>&matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
            if (i == j) matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }




    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

** for negative cycle if matrix[i][j ]< 0 then it has negative cycle

32. Find the City With the Smallest Number of Neighbours at a Threshold Distance


int findCity(int n, int m, vector<vector<int>>& edges,
    int distanceThreshold) 
{
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    for (auto it : edges) {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for (int city = 0; city < n; city++) {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++) {
            if (dist[city][adjCity] <= distanceThreshold)
                cnt++;
        }

        if (cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;

}

==================================================================================================

         MinimumSpanningTree/Disjoint Set and Problems

==================================================================================================


Minimum Spanning Tree: 
    * A spanning tree is a tree in which we have N nodes(i.e. All the nodes
        present in the original graph) 
    and N-1 edges and all nodes are reachable from each other.

    * Among all possible spanning trees of a graph, the minimum spanning tree is the one 
    for which the sum of all the edge weights is the minimum.

1. Prim’s Algorithm

algorithm;
    1. uses priority_queue
    2. push(0,0) wt, nodes
    3. mark as visited
    4. add to sum
    5. if adj nodes not visited push in priority_queue

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int> >, greater<pair<int, int>>> pq;

    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1) continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

2.Disjoint Set | Union by Rank | Union by Size | Path Compression


class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

3. Kruskal’s Algorithm – Minimum Spanning Tree

Algorithm:
    1. create vector<pair<pair<int, int>>> edges
    2. sort it
    3. initialise object ds (V)
    4. for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            // if ultimate paretn is not same
            // add its wt to mst
            // perform union on them
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
    5. return mst
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }

4. Number of Operations to Make Network Connected 
algorithm:
    1. if same ulp then count the extra edge
    2. for counting components find #ds.parent[i] == i
    3. total nodes req = cntC -1

int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }

5. Most Stones Removed with Same Row or Column

int maxRemove(vector<vector<int>>& stones, int n) {
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes; 
    for (auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes) {
        if (ds.findUPar(it.first) == it.first) {
            cnt++;
        }
    }
    return n - cnt;
}