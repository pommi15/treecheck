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

struct node
{
  int key_value;
  node *left;
  node *right;
};

class Tree {
public:
  Tree();
  ~Tree();
  void insert(int key);   //inserting into tree
  void destroy_tree();    //destroying the tree
  void AVL_check();       //checking if the is tree is an AVL tree
  int max_value;          //maximum entered value
  bool first;             //bool to check if value is the first entered
  int min_value;          //minimum entered value
  bool AVL;               //bool to hold if tree is AVL

private:
  int AVL_height(node *leaf);
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *root;
  void AVL_check(node *leaf);
};

#endif  // TREE_H_
