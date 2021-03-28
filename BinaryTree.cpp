//
// Created by yinshuo on 2021/3/28.
//

#include "BinaryTree.h"
#include <stack>
#include <algorithm>
void RecursionPreorder(TreeNode *cur, std::vector<int> v) {
    if(cur == nullptr) return;
    v.push_back(cur->val);
    RecursionPreorder(cur->left, v);
    RecursionPreorder(cur->right, v);
}

void RecursionInorder(TreeNode *cur, std::vector<int> v) {
    if(cur == nullptr) return;
    RecursionInorder(cur->left, v);
    v.push_back(cur->val);
    RecursionInorder(cur->right, v);
}

void RecursionPostorder(TreeNode *cur, std::vector<int> v) {
    if(cur == nullptr) return;
    RecursionPostorder(cur->left, v);
    RecursionPostorder(cur->right, v);
    v.push_back(cur->val);
}

std::vector<int> BinaryTreeTraversal::preOrderTraversal(TreeNode *root) {
    std::vector<int> result;
    RecursionPreorder(root, result);
    return result;
}

std::vector<int> BinaryTreeTraversal::inOrderTraversal(TreeNode *root) {
    std::vector<int> result;
    RecursionInorder(root, result);
    return result;
}

std::vector<int> BinaryTreeTraversal::postOrderTraversal(TreeNode *root) {
    std::vector<int> result;
    RecursionPostorder(root, result);
    return result;
}

std::vector<int> BinaryTreeTraversal::preOrderTraversalStackMethod(TreeNode *root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    if(root == nullptr) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode *tmp = st.top();
        st.pop();
        result.push_back(tmp->val);
        if(tmp->right) st.push(tmp->right);
        if(tmp->left) st.push(tmp->left);
    }
    return result;
}

std::vector<int> BinaryTreeTraversal::inOrderTraversalStackMethod(TreeNode *root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    TreeNode *tmp = root;
    while(tmp != nullptr || !st.empty()) {
        if(tmp) {
            st.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = st.top();
            st.pop();
            result.push_back(tmp->val);
            tmp = tmp->right;
        }
    }
    return result;
}

std::vector<int> BinaryTreeTraversal::postOrderTraversalStackMethod(TreeNode *root) {
    std::vector<int> result;
    std::stack<TreeNode*> st;
    if(root == nullptr) return result;
    st.push(root);
    while(!st.empty()) {
        TreeNode *tmp = st.top();
        st.pop();
        result.push_back(tmp->val);
        if(tmp->right) st.push(tmp->right);
        if(tmp->left) st.push(tmp->left);
    }
    reverse(result.begin(), result.end());
    return result;
}