#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:
      bool isSymmetric(TreeNode* root)
      {
          return isSymmetric(root->left, root->right);
      }

      // helper function
      bool isSymmetric(TreeNode* left, TreeNode* right)
      {
          // if both nodes are null, they're symmetric
          if (left == NULL && right == NULL)
          {
              return true;
          }

          // if either node is null, but the other node is not
          if (left == NULL || right == NULL)
          {
              return false;
          }

          // if both values are equal
          if (left->val == right->val)
          {
              // continue to check 
              // left left compares with right right
              // left right compares with right left
              return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
          }

          // if we reach this point, return false
          return false;
      }
  };

int main()
{
    Solution solution;

    TreeNode left_side_four(4);
    TreeNode left_side_three(3);
    TreeNode left_side_two(2, &left_side_three, &left_side_four);

    TreeNode right_side_four(4);
    TreeNode right_side_three(3);
    TreeNode right_side_two(2, &right_side_four, &right_side_three);

    TreeNode root(1, &left_side_two, &right_side_two);

    cout << "Example One : " << solution.isSymmetric(&root) << endl;

	return 0;
}
