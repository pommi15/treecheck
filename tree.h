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
  void insert(int key);
  node *search(int key);
  void destroy_tree();
  void AVL_check();
  int max;
  int min;
private:
  void destroy_tree(node *leaf);
  void insert(int key, node *leaf);
  node *search(int key, node *leaf);
  node *root;
  void AVL_check(node *leaf);
};

#endif  // TREE_H_
