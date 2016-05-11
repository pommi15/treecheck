/*+------------------------+
  |                        |
  |            X           |
  |           XXX          |
  |          XXXXX         |
  |         XXXXXXX        |
  |        XXXXXXXXX       |
  |       XXXXXXXXXXX      |
  |           XXX          |
  |           XXX          |
  |                        |
  |        treecheck       |
  |           by           |
  |                        |
  |     Thomas Rauhofer    |
  |         if15b029       |
  |           and          |
  |      Tobias Watzek     |
  |         if15b038       |
  |                        |
  +------------------------+*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "tree.h"

using namespace std;
/* constructor */
Tree::Tree() {
  /* root is set to nullptr */
  this->root = nullptr;
  this->AVL = true;
}
/* destructor */
Tree::~Tree() {
  /* calls destroy tree with root */
  destroy_tree();
}
/* recursively destroys tree nodes */
void Tree::destroy_tree(node* leaf) {
  if (leaf != nullptr) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
/* calls the private destroy_tree function on root */
void Tree::destroy_tree() {
  destroy_tree(root);
}
/* checks if tree is empty */
bool Tree::empty_check() {
  if (this->root == nullptr) {
    return true;
  }
  return false;
}
/* function to insert values into tree recursively */
void Tree::insert(int key, node* leaf) {
  /* if key is smaller than leaf value it is inserted left */
  if (key < leaf->key_value) {
    if (leaf->left != nullptr) {
      /* node left is not null so insert is called recursivly on leaf left */
      insert(key, leaf->left);
    } else {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = nullptr;
      leaf->left->right = nullptr;
    }
  } else if (key > leaf->key_value) {
    if (leaf->right != nullptr) {
      /* node right is not null so insert is called recursivly on leaf right */
      insert(key, leaf->right);
    } else {
      leaf->right = new node;
      leaf->right->key_value = key;
      /* is lowest node so both sides are set to nullptr*/
      leaf->right->left = nullptr;
      leaf->right->right = nullptr;
    }
  }
}
/* public instert function that calls private insert function from root */
void Tree::insert(int key) {
  if (root != nullptr) {
    /* if there is a vlaue stored in root insert is called again */
    insert(key, root);
  } else {
    /* if root is empty value is stored in root and left and right are created*/
    root = new node;
    root->key_value = key;
    root->left = nullptr;
    root->right = nullptr;
  }
}
/* private function that checks all the trees nodes and gives their AVL value*/
void Tree::AVL_check(node* leaf) {
  /* initial avl value before check */
  int avl_value = 0;
  /* if leaf right is nullptr avl value stays 0,
    but if not avl_value is set to value of height
    and AVL_check is called recursively on leaf right */
  if (leaf->right != nullptr) {
    avl_value = AVL_height(leaf->right);
    AVL_check(leaf->right);
  }
  /* if leaf left is nullptr avl value stays 0,
    but if not avl_value is set to value of height
    and AVL_check is called recursively on leaf left */
  if (leaf->left != nullptr) {
    avl_value -= AVL_height(leaf->left);
    AVL_check(leaf->left);
  }
  /* recursion happens unitl here, the rest is just output */

  /* checks if AVL condition is met for the node gives the respective output */
  if (avl_value < -1 || avl_value > 1) {
    /* beautifies the output to have the "=" even on every line*/
    if (leaf->key_value > 9) {
      cout << "|  bal(" << leaf->key_value << ") = ";
      if (avl_value < 0 || avl_value > 9) {
        cout << avl_value;
      } else {
        cout << " " << avl_value;
      }
    } else {
      if (avl_value < 0 || avl_value > 9) {
        cout << "|  bal (" << leaf->key_value << ") = " << avl_value;
      } else {
        cout << "|  bal (" << leaf->key_value << ") =  " << avl_value;
      }
    }
    cout << " (AVL violation!)"
         << "  |" << endl;
    // if an AVL violation occurs AVL is set to false
    this->AVL = false;
  } else {
    /* beautifies the output to have the "=" even on every line*/
    if (leaf->key_value > 9) {
      if (avl_value < 0 || avl_value > 9) {
        cout << "|  bal(" << leaf->key_value << ") = " << avl_value
             << "                  |" << endl;
      } else {
        cout << "|  bal(" << leaf->key_value << ") =  " << avl_value
             << "                   |" << endl;
      }
    } else {
      if (avl_value < 0 || avl_value > 9) {
        cout << "|  bal (" << leaf->key_value << ") = " << avl_value
             << "                   |" << endl;
      } else {
        cout << "|  bal (" << leaf->key_value << ") =  " << avl_value
             << "                   |" << endl;
      }
    }
  }
}
/* public function that calls the private AVL_check function on root */
void Tree::AVL_check() {
  return AVL_check(root);
}
/* checks hight from a node downwards to make calculate the AVL value with
  AVL_value = AVL_height(right) - AVL_height(left)
*/
int Tree::AVL_height(node* leaf) {
  /* if right and left are nullptr height is 1*/
  if (leaf->right == nullptr && leaf->left == nullptr) {
    return 1;
    /* if only right is nullptr hight of left is checked */
  } else if (leaf->right == nullptr) {
    return AVL_height(leaf->left) + 1;
  } else if (leaf->left == nullptr) {
    return AVL_height(leaf->right) + 1;
  } else {
    return max(AVL_height(leaf->left), AVL_height(leaf->right)) + 1;
  }
}
/* finds out rightmost value in the tree */
void Tree::check_max(node* leaf) {
  if (leaf->right == nullptr) {
    this->max_value = leaf->key_value;
  } else {
    check_max(leaf->right);
  }
}
/* public function that calls the private check_max function on root */
void Tree::check_max() {
  check_max(root);
}
/* finds out leftmost value in the tree */
void Tree::check_min(node* leaf) {
  if (leaf->left == nullptr) {
    this->min_value = leaf->key_value;
  } else {
    check_min(leaf->left);
  }
}
/* public function that calls the private check_min function on root */
void Tree::check_min() {
  check_min(root);
}
/* finds out average tree value */
void Tree::check_avg(node* leaf) {
  this->avg += leaf->key_value;
  this->avg_counter++;
  if (leaf->right != nullptr) {
    check_avg(leaf->right);
  }
  if (leaf->left != nullptr) {
    check_avg(leaf->left);
  }
}
void Tree::check_avg() {
  check_avg(root);
}
