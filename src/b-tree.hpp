#ifndef TRE_B_TREE_HPP
#define TRE_B_TREE_HPP
/*
 * binary tree
 *
 *
 * */

namespace tre {

struct node {
  int data{};
  node *left{};
  node *right{};
};

struct list {
  node *root;
  void insert(int data, node *root = nullptr);
  void clean();
};

// insert cases:
// case 1: list is empty
// case 2: there is exactly one node
// case 3: there is more than one node
void list::insert(int data, node *root) {
  auto new_node = new node{data, nullptr, nullptr};
  if (root == nullptr) {
    // case 1
    this->root = new_node;
  } else if (this->root->left == nullptr && this->root->right == nullptr) {
    // case 2
    if (this->root->data > data) {
      this->root->left = new_node;
    } else if (this->root->data < data) {
      this->root->right = new_node;
    }
  } else {
    // case 3
    node *curr_node = root;
    if (curr_node->data > data) {
      curr_node = curr_node->right;
      if (curr_node->right != nullptr) {
        this->insert(data, curr_node);
      } else {
        curr_node = new_node;
      }
    } else if (curr_node->data < data) {
      curr_node = curr_node->left;
      if (curr_node->left != nullptr) {
        this->insert(data, curr_node);
      } else {
        curr_node = new_node;
      }
    }
  }
}

// clean cases
// case 1: list is empty
// case 2: there is one node
// case 3: there is more than one node
void list::clean() {
  // case 1
  if (this->root == nullptr) {
    return;
  }
}
}  // namespace tre

#endif  // TRE_B_TREE_HPP
