#pragma once
template <class T>
class TreeNode {
 public:
  TreeNode<T>* left;
  TreeNode<T>* right;
  T value;

  TreeNode(T defaultV) {
    value = defaultV;
    left = 0;
    right = 0;
  }
};
