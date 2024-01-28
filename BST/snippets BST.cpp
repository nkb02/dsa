1. DELETE A NODE FROM BST

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
          return NULL;
        }
        if (root->val == key) {
           return helper (root);
        }
        TreeNode* dummy= root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } 
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right= helper(root->right);
                break;
                } else {
                    root = root->right;
                }
            }
        }
        
        return dummy;
    }
    TreeNode* helper (TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        else if (root->right == NULL) {
            return root->left;
        }
        
        TreeNode* rightChild =  root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
         return root;
        }
        return findLastRight(root->right);
    }




2. kth smallest 

   		=>  in O(1) space


node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}

if kth largest
then traverse find length
then find n-k  kthsmallest


3. Check if a tree is a BST or BT

bool isValidBST(TreeNode* root) {
  return isValidBST(root, LLONG_MIN,  LLONG_MAX);
}
bool isValidBST(TreeNode* root, long mn, long mx) {
    if(!root) return true;
    if(root->val >= mx || root->val <= mn) return false;
    
    return isValidBST( root->left, mn, root->val) &&
        isValidBST( root->right, root->val, mx);
}

4. LCA 

=> FIRST TIME WHERE IT SPLITS IS THE lowestCommonAncestor

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int cur = root->val;
        if(cur <p->val && cur < q->val){
            // go left
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if(cur > p->val && cur > q->val){
            // go right
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }

5.  Construct a BST from a preorder traversal

brute force : O(n*n)
    goto each node compare nd place it 

better:

sort the preorder nd get inorder
then make bst using preorder and inorder

tc: O(nlogn) + O(n)
sc; O(n)

optimal
tc : O(N)
sc : O(1)

  TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);   
    }
    TreeNode* build (vector<int> &a, int &i, int bound){
        if(i == a.size() || a[i] > bound) return NULL;

        TreeNode* root = new TreeNode(a[i++]);
        root->left = build(a, i, root->val);
        root->right = build(a, i, bound);
        return root;
    }

6. Inorder Successor/Predecessor in BST

brute :
find inorder 
then return next/ prev elem 
O(N), O(N)

better:
first elem greater than node is ans
O(N)


optimal:
O(H), O(1)

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* Successor = NULL;
    while(!root){
        if(p->val >= root->val)
            root = root->right;
        else
        {
            Successor = root;
            root =root->left;
        }
    }
    return Successor;
}


Node* findPredecessor(Node* root, Node* p) {
    if(!root)
    {
        return NULL;
    }
    Node* predecessor=NULL;
    Node* curr=root;
    while(curr)
    {
        if(curr->data < p->data)
        {
            predecessor=curr;
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    return predecessor;
}

7. Binary Search Tree Iterator | BST | O(H) Space

brute: 
store inorder 
done 
sc O(N)

optimal:
recursive inorder so that max space is O(H)

class BSTIterator {
private: 
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
         pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAll(tmpNode ->right);
        return tmpNode -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
private:
// PUSHES ALL ELEMENTS IN LEFT IN THE STACK 
    void pushAll(TreeNode* node)
    {
        while(node!= NULL)
        {
            st.push(node);
            node = node -> left;
        }
        return;
    }
};

8. two sum

brute:
inorder traversal
two pointer
over
tc: O(N) + O(N)
sc: O(N)

optimal:

using bst Iterator
tc: O(N)
sc : O (H)

# just need a before feature
using a boolean isReverse to check if its asking next or before
then minor changes in pushAll and next funtion

class BSTIterator {
private:
    stack<TreeNode *> st;
    bool reverse = true;
    // true -> before
    // false -> after
public:
    // constructor  
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    // RETURNS THE NEXT SMALLEST NUMBER
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        if(!reverse)
            pushAll(tmpNode ->right);
        else
            pushAll(tmpNode ->left);
        return tmpNode -> val;
    }
    // RETURNS WHETHER THERE IS NEXT SMALLEST NUMBER
    bool hasNext() {
        return !st.empty();
    }

private:
// PUSHES ALL ELEMENTS IN LEFT IN THE STACK 
    void pushAll(TreeNode* node)
    {
        while(node!= NULL)
        {
            st.push(node);
            if(!reverse)
                node = node -> left;
            else
                node = node->right;
        }
        return;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator L(root, false); // next
        BSTIterator R(root, true); // before

        int i = L.next();
        int j = R.next();
        while(i < j)
        {
            if(i + j == k)
                return true;
            else if( i + j < k)
            {
                i = L.next();
            }
            else
                j = R.next();
        }
        return false;
    }
};



9. recover the bst => two nodes swapped

brute ;
do inorder traversal
sort it 
then again inorder traversal, wherever it mismatches change it 

tc: O(N) + O(nlogn) + O(N)
sc : O(N)

optimal:

class Solution {
private:
    TreeNode* first; 
    TreeNode* prev;
    TreeNode*  last;
    TreeNode*  middle;
    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        if(prev !=NULL && (root-> val < prev -> val))
        {
            //IF FIRST VIOLATION
            if(first == NULL){
                first = prev;
                middle = root;
            }
            // IF 2nd VIOLATION
            else
            {
                last = root;
            }
        }
        // store cur node as prev
        prev = root;
        inorder(root-> right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder( root );
        if(first && last)
            swap(first->val , last->val);
        else if( first && middle)
             swap(first->val , middle->val);
    }
};

10. Largest BST in Binary Tree
// using post order traversal

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution {
private:
    NodeValue largestBSTSubtreeHelper (TreeNode<int>* root) {
    // An empty tree is a BST of size 0.
    if (!root) {
        return NodeValue (INT_MAX, INT_MIN, 0);
    }
            // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper (root->left);
        auto right largestBSTSubtreeHelper (root->right);
        // Current node is greater than max in left AND smaller than min in right, it is a
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            return NodeValue (min(root->val, left.minNode), max(root->val, right.maxNode),
            left.maxSize + right.maxSize + 1);
            }
            // Otherwise, return [-inf, inf] so that parent can't be valid BST
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
        public:
        int largestBSTSubtree(TreeNode<int>* root) {
        return largestBSTSubtreeHelper (root).maxSize;
    }
};