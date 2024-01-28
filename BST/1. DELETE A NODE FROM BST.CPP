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
