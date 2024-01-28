
                  Dynamic Programming

===============================================================================================

1.1 Introduction

Fibonacci

Memoization: 

int f(int n, vector<int>& dp){
  if(n<=1) return n;
  
  if(dp[n]!= -1) return dp[n];
  return dp[n]= f(n-1,dp) + f(n-2,dp);
}

Tabulation:

vector<int> dp(n+1,-1);

dp[0]= 0;
dp[1]= 1;

for(int i=2; i<=n; i++){
    dp[i] = dp[i-1]+ dp[i-2];
}


===============================================================================================

                           1D DP

===============================================================================================

1. Climbing Stairs

  Fibonacci

2. Frog Jump

2.1 Memoization
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}

2.2 Tabulation

vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];

3. Frog Jump with k Distances

3.1 Memoization
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
        int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
              mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

3.2 Tabulation

int solveUtil(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

4. Maximum sum of non-adjacent elements

4.1 Memoization

int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(ind==0) return arr[ind];
    if(ind<0)  return 0;
    
    int pick= arr[ind]+ solveUtil(ind-2, arr,dp);
    int nonPick = 0 + solveUtil(ind-1, arr, dp);
    
    return dp[ind]=max(pick, nonPick);
}

4.2 Tabulation

int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0] = arr[0];
    for (int ind = 1; ind < n; ++ind)
    {

      int pick= arr[ind];
      if(ind >=2 ) pick += dp[ind-2];

      int nonPick = 0 + dp[ind-1];
      
       dp[ind]=max(pick, nonPick);
    }
    return dp[n-1];

}

5.  House Robber 

The approach to solving this problem can be summarized as:

Make two reduced arrays – arr1(arr-last element) and arr2(arr-first element).
Find the maximum of non-adjacent elements as mentioned in Ques 4 on arr1 and arr2 separately. Let’s call the answers we got ans1 and ans2 respectively.
Return max(ans1, ans2) as our final answer.

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;
    
    if(n==1)
       return arr[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = solveUtil(arr1);
    long long int ans2 = solveUtil(arr2);
    
    return max(ans1,ans2);
}


===============================================================================================

                           2D/3D DP

===============================================================================================


1. Ninja’s Training
The same activity can’t be performed on two consecutive days. 
To find the maximum merit points the ninja can attain in N Days.

1.1 Memoization


int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return f(n - 1, 3, points, dp);
}

1.2 Tabulation

int ninjaTraining(int n, vector < vector < int > > & points) {


  vector < vector < int > > dp(n, vector < int > (4, 0));

  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; ++day)
  {
      for (int last = 0; last < 4; last++) {
        dp[day][last] = 0;
        for (int task = 0; task <= 2; task++) {
          if (task != last) {
            int activity = points[day][task] + dp[day - 1][task];
            dp[day][last] = max(dp[day][last], activity);
          }
        }
      }

  }
  return dp[n-1][3];
}

2. Grid Unique Paths

2.1 Memoization

int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = countWaysUtil(i-1,j,dp);
  int left = countWaysUtil(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}

int countWays(int m, int n){
    vector<vector<int> > dp(m,vector<int>(n,-1));
    return countWaysUtil(m-1,n-1,dp);
    
}

2.2  Tabulation

int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
  for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
          
          //base condition
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[m-1][n-1];

  
}

3. Grid Unique Paths 2

almost summarized

3.1 Memoization

int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int> > 
&dp) {
  if(i>0 && j>0 && maze[i][j]==-1) return 0; 
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = mazeObstaclesUtil(i-1,j,maze,dp);
  int left = mazeObstaclesUtil(i,j-1,maze,dp);
  
  return dp[i][j] = up+left;
  
}

3.2 Tabulation

int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze,vector<vector<int>>
 &dp) 
{
  for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base conditions
          if(i>0 && j>0 && maze[i][j]==-1){
            dp[i][j]=0;
            continue;
          }
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[n-1][m-1];

  
}

4. Minimum Path Sum In a Grid 

4.1 Memoization

int minSumPathUtil(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
  if(i==0 && j == 0)
    return matrix[0][0];
  if(i<0 || j<0)
    return 1e9;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = matrix[i][j]+minSumPathUtil(i-1,j,matrix,dp);
  int left = matrix[i][j]+minSumPathUtil(i,j-1,matrix,dp);
  
  return dp[i][j] = min(up,left);
  
}

4.2 Tabulation

int minSumPath(int n, int m, vector<vector<int> > &matrix){
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = matrix[i][j];
            else{
                
                int up = matrix[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = matrix[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
}

5. Minimum path sum in Triangular Grid 

5.1 Memoization

int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, 
vector<vector<int> > &dp) {
  
  if(dp[i][j]!=-1)
  return dp[i][j];
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return minimumPathSumUtil(0,0,triangle,n,dp);
    
}

5.2 Tabulation

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    
}

6. Minimum/Maximum Falling Path Sum

6.1 Memoization

int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
vector<vector<int> > &dp){
    
    // Base Conditions
    if(j<0 || j>=m)
        return -1e9;
    if(i==0)
        return matrix[0][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
    return dp[i][j]= max(up,max(leftDiagonal,rightDiagonal));
    
}

int getMaxPathSum(vector<vector<int> > &matrix){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    int maxi = INT_MIN;
    
    for(int j=0; j<m;j++){
        int ans = getMaxUtil(n-1,j,m,matrix,dp);
        maxi = max(maxi,ans);
    }
    
    return maxi;
}

7. 3-d DP : Ninja and his friends [HARD]

7.1 Memoization


int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >> 
& grid, vector < vector < vector < int >>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {

  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
  > (m, -1)));

  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}


7.2 Tabulation

int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
  // Write your code here.
  vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];

}

