1. Binary Tree Traversal : Inorder Preorder Postorder

  # Inorder Traversal 
  
   a.  Algorithm of Inorder Traversal - recursive

    1. Traverse the left subtree
    2. Print the root
    3. Traverse the right subtree


     left - root - right

    struct node {
      int data;
      struct node * left, * right;
    };

    void inOrderTrav(node * curr, vector < int > & inOrder) {
      if (curr == NULL)
        return;

      inOrderTrav(curr -> left, inOrder);
      inOrder.push_back(curr -> data);
      inOrderTrav(curr -> right, inOrder);
    }
    b. Approach: The algorithm approach can be stated as: iterative

      * We first take an explicit stack data structure and set an infinite loop.
      * In every iteration we check whether our current node is pointing to NULL or not.
      * If it is not pointing to null, we simply push the current value to the stack and move the current node to its left child.
      * If it is pointing to NULL, we first check whether the stack is empty or not. If the stack is empty, it means that we have traversed the tree and we break out of the loop.
      * If the stack is not empty, we pop the top value of the stack, print it and move the current node to its right child.

    vector < int > inOrderTrav(node * curr) {
      vector < int > inOrder;
      stack < node * > s;
      while (true) {
        if (curr != NULL) {
          s.push(curr);
          curr = curr -> left;
        } else {
          if (s.empty()) break;
          curr = s.top();
          inOrder.push_back(curr -> data);
          s.pop();
          curr = curr -> right;
        }
      }
      return inOrder;
    }


=> Applications of Inorder Traversal

  * If inorder traversal of Binary Search Tree (BST) is done , we get increasing order.
  * We can get reversed order / Decreasing order by doing inorder traversal in reverse order ( where right subtree is called first and then left subtree is called)



# Preorder Traversal 

   Algorithm of Preorder Traversal (recursive)

    1. Print the root
    2. Traverse the left subtree
    3. Traverse the right subtree 

    root - left - right


    void preOrderTrav(node * curr, vector < int > & preOrder) {
      if (curr == NULL)
        return;

      preOrder.push_back(curr -> data);
      preOrderTrav(curr -> left, preOrder);
      preOrderTrav(curr -> right, preOrder);
    }

   =>  Applications of Preorder Traversal

      * The main use of Preorder is to get copy of Tree.
      * Other use is to generate Prefix expression.


  @ Algorithm of Preorder Traversal (iterative)
    * We first take an explicit stack data structure and push the root node to it.(if the root node is not NULL).
    * Then we use a while loop to iterate over the stack till the stack remains non-empty.
    * In every iteration we first pop the stack’s top and print it. 
    * Then we first push the right child of this popped node and then push the left child, if they are not NULL. We do so because stack is a last-in-first-out(LIFO) data structure. We need to access the left child first, so we need to push it at the last.
    * The execution continues and will stop when the stack becomes empty. In this process, we will get the preorder traversal of the tree.


    vector < int > preOrderTrav(node * curr) {
      vector < int > preOrder;
      if (curr == NULL)
        return preOrder;

      stack < node * > s;
      s.push(curr);

      while (!s.empty()) {
        node * topNode = s.top();
        preOrder.push_back(topNode -> data);
        s.pop();
        if (topNode -> right != NULL)
          s.push(topNode -> right);
        if (topNode -> left != NULL)
          s.push(topNode -> left);
      }
      return preOrder;

    }

  # Postorder Traversal  

      left - right - root

      void postOrderTrav(node * curr, vector < int > & postOrder) {
        if (curr == NULL)
          return;

        postOrderTrav(curr -> left, postOrder);
        postOrderTrav(curr -> right, postOrder);
        postOrder.push_back(curr -> data);
      }


      => Applications of Postorder Traversal

      * The main use of Postorder is to delete the tree ( Before deleting the parent, we should delete children first ).
      * Other use is to generate Postfix expression.

Solution 1: Using two stacks

    // Iterative approach
    The algorithm approach can be stated as:

    * We take two explicit stacks S1 and S2.
    * We insert our node to S1(if it’s not pointing to NULL).
    * We will set up a while loop to run till S1 is non-empty.
    * In every iteration, we pop out the top of S1 and then push this popped node to S2. Moreover we will push the left child and right child of this popped node to S1.(If they are not pointing to NULL).
    * Then we start the next iteration with the next node as top of S1.
    * We stop the iteration when S1 becomes empty.
    * At last we start popping at the top of S2 and print the node values, we will get the postorder traversal.   * 


vector < int > postOrderTrav(node * curr) {

  vector < int > postOrder;
  if (curr == NULL) return postOrder;

  stack < node * > s1;
  stack < node * > s2;
  s1.push(curr);
  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr -> left != NULL)
      s1.push(curr -> left);
    if (curr -> right != NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
  }
  return postOrder;
}


*** Solution 2: Using a single stack:
  The algorithm steps can be stated as:

  * We take an explicit data structure and a cur pointer pointing to the root of the tree.
  * We run a while loop till the time the cur is not pointing to NULL or the stack is non-empty.
  * If cur is not pointing to NULL, it means then we simply push that value to the stack and 
  move the cur pointer to its left child because we want to explore the left child before the
   root or the right child.

  * If the cur is pointing to NULL, it means we can’t go further left, then we take a variable
   temp and set it to  cur’s parent’s right child (as we have visited the left child, now we want
    to visit the right child). We have node cur’s parent at the top of the stack.
  * If node temp is not pointing to NULL, we simply initialise cur as node temp so that we can again
   start looking at the left of node temp from the next iteration.

  * If node temp is pointing to NULL, then first of all we are sure that we have visited both
   children of temp’s parent, so it’s time to print it. Therefore we set temp to its parent
   ( present at the top of stack), pop the stack and then print temp’s value. Additionally,
    this new temp(parent of NULL-pointing node) can be the right child of the node present
    at the top of stack after popping.In that case the node at top of the stack is parent
    of temp and the next node to be printed. Therefore we run an additional while loop to
    check if that is the case, if true then again move temp to its parent and print its value.

vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } 
    else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } 
      else cur = temp;
    }
  }
  return postOrder;}


    # Levelorder Traversal


      * Algorithm of Levelorder Traversal

        1. Remove a node from queue.
        2. Print the node.
        3. Add all of its children in the queue

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 

        if(root == NULL) return ans; 

        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->val); 
            }

            ans.push_back(level); 
        }

        return ans; 
    }

    => Applications of Level order Traversal

        * Level order traversal is actually Breadth First Search.
        * Finding connected components in graph data structure.


   ## post , pre , inorder in one Algorithm
Approach: 

The algorithm steps can be described as follows:

We take a stack data structure and push a pair<val, num> to it. Here Val is the value of the root node 
and num the visit to the node. Initially, the num is 1 as we are visiting the root node for the first 
time. We also create three separate lists for preorder, inorder and postorder traversals. Then we set 
an iterative loop to run till the time our stack is non-empty. 

    void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
      
      stack < pair < node * , int >> st;
      st.push({
        root,
        1
      });
      if (root == NULL) return;

      while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        // increment 1 to 2 
        // push the left side of the tree
        if (it.second == 1) {
          pre.push_back(it.first -> data);
          it.second++;
          st.push(it);

          if (it.first -> left != NULL) {
            st.push({
              it.first -> left,
              1
            });
          }
        }

        // this is a part of in 
        // increment 2 to 3 
        // push right 
        else if (it.second == 2) {
          in .push_back(it.first -> data);
          it.second++;
          st.push(it);

          if (it.first -> right != NULL) {
            st.push({
              it.first -> right,
              1
            });
          }
        }
        // don't push it back again 
        else {
          post.push_back(it.first -> data);
        }
      }
    }


// medium problems

  1. Maximum depth of a Binary Tree (Height of tree)

   int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }

    2. Check if the Binary Tree is Balanced Binary Tree

    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (TreeNode *root) {

        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);

        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);

        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }

    3. Calculate the Diameter of a Binary Tree

      this path may or may not pass from the root.


      int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
 
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    4. Maximum Sum Path in Binary Tree

    int findMaxPathSum(node * root, int & maxi) {
      if (root == NULL) return 0;

      int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
      int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
      int val = root -> data;
      maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
      return max(leftMaxPath, rightMaxPath) + val;

    }

    int maxPathSum(node * root) {
      int maxi = INT_MIN;
      findMaxPathSum(root, maxi);
      return maxi;

    }


    5. Check if two trees are identical

    bool isIdentical(node * node1, node * node2) {
      if (node1 == NULL && node2 == NULL)
        return true;
      else if (node1 == NULL || node2 == NULL)
        return false;

      return ((node1 -> data == node2 -> data) && isIdentical(node1 -> left, node2 -> left) 
        && isIdentical(node1 -> right, node2 -> right));
    }

6. Zig Zag Traversal Of Binary Tree

        
  == > levelOrder traversal just maintain leftToRight variable


vector < vector < int >> zigzagLevelOrder(Node * root) {
        vector < vector < int >> result;
        if (root == NULL) {
          return result;
        }

        queue < Node * > nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
          int size = nodesQueue.size();
          vector < int > row(size);
          for (int i = 0; i < size; i++) {
            Node * node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node -> val;
            if (node -> left) {
              nodesQueue.push(node -> left);
            }
            if (node -> right) {
              nodesQueue.push(node -> right);
            }
          }
          // after this level
          leftToRight = !leftToRight;
          result.push_back(row);
        }
        return result;
      }

7. Boundary Traversal of a Binary Tree (good ques)

Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}


8. Vertical Order Traversal of Binary Tree

vector < vector < int >> findVertical(node * root) {
  map < int, map < int, multiset < int >>> nodes;
  queue < pair < node * , pair < int, int >>> todo;
  todo.push({
    root,
    {
      0,
      0
    }
  }); //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node * temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset

    if (temp -> left) {
      todo.push({
        temp -> left,
        {
          x - 1,
          y + 1
        }
      });
    }
    if (temp -> right) {
      todo.push({
        temp -> right,
        {
          x + 1,
          y + 1
        }
      });
    }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) {
    vector < int > col;
    for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}


9. Top view of a Binary Tree

 vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }


    10. Bottom view of a Binary Tree

    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }

    11. Right/Left view of binary tree

    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }


    // right

    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }


12. Check for Symmetrical Binary Tree

    
    bool isSymmetricUtil(node * root1, node * root2) {
      if (root1 == NULL || root2 == NULL)
        return root1 == root2;
      return (root1 -> data == root2 -> data) && isSymmetricUtil(root1 -> left, root2->
      right) && isSymmetricUtil(root1 -> right, root2 -> left);
    }
    bool isSymmetric(node * root) {
      if (!root) return true;
      return isSymmetricUtil(root -> left, root -> right);
    }




========================= HARD ==========================

1. Print Root to Node Path in a Binary Tree


The algorithm steps can be stated as follows:

We pass the function with our root node, the path list and node V.
For the base case, if root is pointing to NULL, we return false as clearly node V can’t be found.
Now we first push the node to our path list.
Then we check whether the current node is the target node or not, if it is then no further execution is needed and we return to the parent function.
If not, then we recursively call its left and right child to find the target node V. If any one of them returns true, it means we have found node V at lower levels and return true from the current function.
If the value is not found at the current node and neither in any of the recursive calls, it means that the value is not present in the current sub-tree, therefore we pop out the current node from the path list and return false.



bool getPath(TreeNode* root, vector<int> &arr, int x){
  if(!root) return false;

  arr.push_back(root->val);

  if(root->val == x)
    return true;

  if(getPath(root->left, arr, x) || getPath(root->left, arr, x))
    return true;

  arr.pop_back();
  return false;
}

2. Maximum Width of a Binary Tree


The algorithm approach can be stated as:

  * We take a queue and push the root node along with index 0.
  * We traverse the tree using a level order traversal.
  * In the level order traversal we set another loop to run for the size of the queue, so that we visit the same level nodes inside it.
  * Before a level starts, we use a variable(say curMin) to store the index of the first node.
  * We assign an index to every node, and to its children as described above.
  * When the inner loop is at the first node of a level, we store its index in another variable(sayleftMost)
  * When the inner loop is at the last node of a level, we store its index in another variable(say rightMost)
  * After a level  in the outer loop, we calculate the width of the level as (rightMost – leftMost +1).
  * We return the maximum width as the answer.


int widthOfBinaryTree(node * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < node * , int >> q;
  q.push({
    root,
    0
  });
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({
          temp -> left,
          cur_id * 2 + 1
        });
      if (temp -> right)
        q.push({
          temp -> right,
          cur_id * 2 + 2
        });
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}


3. Check for Children Sum Property in a Binary Tree

The algorithm approach can be stated as follows:

  * We perform a simple dfs traversal on the tree.
  * For the base case, if the node is pointing to NULL, we simply return.
  * At every node, first we find the sum of values of the children( For a NULL child, value is assumed to be 0).
  * If node’s value > sum of children node value, we assign both the children’s value to their parent’s node value.
  * Then we visit the children using recursion.
  * After we return to the node after visiting its children, we explicitly set its value to be equal to the sum of its values of its children.


void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}

4. construct a binary tree from inOrder and preOrder

 = > L 34

TreeNode* constructTree( vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart], NULL, NULL);
        int elem = mp[ root -> val];
        int nelem = elem - inStart;
        root -> left = constructTree(preorder, preStart + 1, preStart + nelem , inorder,
         inStart, elem - 1, mp);
        root -> right = constructTree(preorder, preStart + nelem + 1, preEnd, inorder,
         elem + 1, inEnd, mp);

        return root; 
    }

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;
        map<int, int> mp;
        for(int i= inStart; i<= inEnd ; i++)
        {
            mp[inorder[i]] = i;
        }
        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }


5. construct a binary tree from inOrder and postOrder


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size()-1;
        map<int, int> mp;
        for(int i= inStart; i<= inEnd ; i++)
        {
            mp[inorder[i]] = i;
        }
        return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }

TreeNode* constructTree( vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(postStart > postEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int elem = mp[postorder[postEnd]];
        int nelem = elem - inStart;
        root -> left = constructTree(postorder, postStart, postStart + nelem - 1 , inorder,
         inStart, elem - 1, mp);
        root -> right = constructTree(postorder, postStart + nelem, postEnd-1, inorder,
         elem + 1, inEnd, mp);

        return root; 
    } 


6. LCA OF BT 

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p ||  root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        return root;
    }


7. Count Number of Nodes in a Binary Tree

int findHeightLeft(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->left; 
        }
        return hght; 
    }

int findHeightRight(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->right; 
        }
        return hght; 
    }

int countNodes(node* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1; 
    
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    
    return 1 + leftNodes + rightNodes; 
}

8. Print all the Nodes at a distance of K in Binary Tree 

void markParent(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur -> left) {
                q.push(cur->left);
                parent[cur->left] = cur;
            }
            if(cur -> right)
            {
                q.push(cur->right);
                parent[cur->right] = cur;
            }
        }
        return;
    }

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode* , TreeNode*> parent;
    unordered_map<TreeNode* , bool> visited; // visited node
    
    markParent(root, parent);
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int distance = 0;

    while(!q.empty())
    {
        int size = q.size();
        if(distance++ == k)
            break;
        for(int i = 0 ; i < size ; i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur -> left && !visited[cur -> left]) {
                q.push(cur->left);
                visited[cur->left] = true;
            }
            if(cur -> right && !visited[cur -> right]) {
                q.push(cur->right);
                visited[cur->right] = true;
            }
            if(parent[cur] && !visited[parent[cur]]) {
                q.push(parent[cur]);
                visited[parent[cur]] = true;
            }
        }
    }
    vector<int>result;
    while(!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop();
        result.push_back(cur->val);
    }
    return result;
}

10.  Minimum time taken to BURN the Binary Tree from a Node


int findMaxDistance (map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp,
BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>* > q;
    q.push(target);

    map<BinaryTreeNode<int>*, int> vis;
    vis[target] = 1;
    
    int maxi = 0;
    
    while (!q.empty()) {
        int sz= q.size();
        int fl = 0;
        for(int i=0;i<sz;i++) {
            auto node =q.front();
            q.pop();
            if(node->left && !vis [node->left]) {
                fl = 1;
                vis [node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis [node->right]) {
                fl = 1;
                vis [node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !vis[mpp[node]]) {
              fl = 1;
              vis[mpp[node]] = 1;
              q.push(mpp[node]);
            }
        }
         if(fl) maxi++;
        }
    return maxi;
}


BinaryTreeNode<int>* bfsToMapParents (BinaryTreeNode<int>* root,
map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &mpp, int start) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    BinaryTreeNode<int>* res;
    while(!q.empty()) {
        BinaryTreeNode<int>* node =q.front();
        if(node->data== start) res = node;
        
        q.pop();
        
        if(node->left) {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            mpp [node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mpp;
    BinaryTreeNode<int> *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance (mpp, target);
    return maxi;
}

11. serialize and desearlize
  using levelorder here

    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
                s.append("#,");
            else
                s.append(to_string(node->val) + ',');
            
            if(node != NULL)
            {
                q.push(node->left);
                q.push(node-> right);
            }
        }
        return s; 
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#")
                node-> left = NULL;
            else
                {
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            getline(s, str, ',');
            if(str == "#")
                node-> right = NULL;
            else
                {
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
        }
        return root;  
    }


12. morris traversal - inorder traversal
tc ~ O(N)
sc~ O(1) ##

vector<int> inorderTraversal(TreeNode* root) {
        // MORRIS TRAVERSAL
        vector<int>inorder;
        TreeNode* cur = root;
        while(cur != NULL)
        {
            // CASE - I 
            // IF LEFT TREE IS EMPTY
            if(cur-> left == NULL)
            {
                inorder.push_back(cur-> val);
                cur = cur-> right;
            }
            // CASE - II 
            // IT HAS A LEFT SUB TREE
            else
            {
                // we dont wanna lose cur hence creating new one
                TreeNode* prev = cur->left;
                // traverse right untill it is either null or points to itself;
                while(prev -> right && prev-> right != cur)
                {
                    prev = prev -> right;
                }
                // case I if right becomes null
                if(prev -> right == NULL)
                {
                    prev -> right = cur;
                    // now move cur to left
                    cur  = cur-> left;
                }
                else
                {
                    // case II it is already pointing to someone
                    // make it null
                    prev-> right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur-> right;
                }
            }

        }
        // TC - O(N) + del(N) ~ O(N)
        // SC - O(1)
        return inorder;

    }


13. morris traversal - preorder traversal
tc ~ O(N)
sc~ O(1) ##
one line change from inOrder

vector<int> preorderTraversal(TreeNode* root) {
        // MORRIS TRAVERSAL
        vector<int>preorder;
        TreeNode* cur = root;
        while(cur != NULL)
        {
            // CASE - I 
            // IF LEFT TREE IS EMPTY
            if(cur-> left == NULL)
            {
                preorder.push_back(cur-> val);
                cur = cur-> right;
            }
            // CASE - II 
            // IT HAS A LEFT SUB TREE
            else
            {
                // we dont wanna lose cur hence creating new one
                TreeNode* prev = cur->left;
                // traverse right untill it is either null or points to itself;
                while(prev -> right && prev-> right != cur)
                {
                    prev = prev -> right;
                }
                // case I if right becomes null
                if(prev -> right == NULL)
                {
                    prev -> right = cur;
                    preorder.push_back(cur->val);
                    // now move cur to left
                    cur  = cur-> left;
                }
                else
                {
                    // case II it is already pointing to someone
                    // make it null
                    prev-> right = NULL;
                   
                    cur = cur-> right;
                }
            }

        }
        // TC - O(N) + del(N) ~ O(N)
        // SC - O(1)
        return preorder;

    }

14. flatten bt to LL 

 void flatten(node* root) {
        node* cur = root;
    while (cur)
    {
      if(cur->left)
      {
        node* pre = cur->left;
        while(pre->right)
        {
          pre = pre->right;
        }
        pre->right = cur->right;
        cur->right = cur->left;
        cur->left = NULL;
      }
      cur = cur->right;
    }
    }

