//
// Created by yinshuo on 2021/3/28.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTreeTraversal {
public:
    std::vector<int> preOrderTraversal(TreeNode *root);
    std::vector<int> inOrderTraversal(TreeNode *root);
    std::vector<int> postOrderTraversal(TreeNode *root);

    //栈实现
    std::vector<int> preOrderTraversalStackMethod(TreeNode *root);
    std::vector<int> inOrderTraversalStackMethod(TreeNode *root);
    std::vector<int> postOrderTraversalStackMethod(TreeNode *root);
};

#endif //UNTITLED_BINARYTREE_H
