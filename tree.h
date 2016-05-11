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
#ifndef TREE_H_
#define TREE_H_
#include <string>
#include <iostream>
#include <vector>

struct node {
  int key_value;
  node* left;
  node* right;
};

class Tree {
 public:
  Tree();
  ~Tree();
  void insert(int key);  // inserting into tree
  void destroy_tree();  // destroying the tree
  void AVL_check();  // checking if the is tree is an AVL tree
  int max_value;  // maximum entered value
  int min_value;  // minimum entered value
  bool AVL;  // bool to hold if tree is AVL
  double avg;
  double avg_counter;
  void check_max();
  void check_min();
  void check_avg();
  bool empty_check();

 private:
  void check_max(node* leaf);
  void check_min(node* leaf);
  void check_avg(node* leaf);
  int AVL_height(node* leaf);  // checking the remaining height vrom a node
  void destroy_tree(node* leaf);  // private part of the destroy function
  void insert(int key, node* leaf);  // private part of the insert function
  node* root;  // variable for root
  void AVL_check(node* leaf);  // private part of the AVL-check function
};

#endif  // TREE_H_
