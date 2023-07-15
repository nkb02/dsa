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
  * If cur is not pointing to NULL, it means then we simply push that value to the stack and move the cur pointer to its left child because we want to explore the left child before the root or the right child.
  * If the cur is pointing to NULL, it means we can’t go further left, then we take a variable temp and set it to  cur’s parent’s right child (as we have visited the left child, now we want to visit the right child). We have node cur’s parent at the top of the stack.
  * If node temp is not pointing to NULL, we simply initialise cur as node temp so that we can again start looking at the left of node temp from the next iteration.
  * If node temp is pointing to NULL, then first of all we are sure that we have visited both children of temp’s parent, so it’s time to print it. Therefore we set temp to its parent( present at the top of stack), pop the stack and then print temp’s value. Additionally,  this new temp(parent of NULL-pointing node) can be the right child of the node present at the top of stack after popping.In that case the node at top of the stack is parent of temp and the next node to be printed. Therefore we run an additional while loop to check if that is the case, if true then again move temp to its parent and print its value.

vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
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
      } else cur = temp;
    }
  }
  return postOrder;

}


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

      return ((node1 -> data == node2 -> data) && isIdentical(node1 -> left, node2 -> left) && isIdentical(node1 -> right, node2 -> right));
    }

    6. Zig Zag Traversal Of Binary Tree
        
        == > levelOrder traversal just m aint leftToRight variable


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
