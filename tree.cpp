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

#include "tree.h"

using namespace std;
/* constructor */
Tree::Tree(){
  /* root is set to NULL */
  this->root = NULL;
  this->AVL = true;
}
/* destructor */
Tree::~Tree(){
  /* calls destroy tree with root */
  destroy_tree();
}
/* recursively destroys tree nodes */
void Tree::destroy_tree(node *leaf){
  if(leaf!=NULL){
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
/* calls the destroy_tree function on root */
void Tree::destroy_tree(){
  destroy_tree(root);
}
/* function to insert values into tree recursively */
void Tree::insert(int key, node *leaf){
  if(key<this->min){
    this->min = key;
  }
  if(key>this->max){
    this->max = key;
  }

  if(key < leaf->key_value){
    if(leaf->left!=NULL){
     insert(key, leaf->left);
    }else{
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }
  }else if(key>=leaf->key_value){
    if(leaf->right!=NULL){
      insert(key, leaf->right);
    }else{
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}
/* calls insert function from root */
void Tree::insert(int key){
  if(root!=NULL){
    insert(key, root);
  }else{
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}
/* searches through tree recursively */
node *Tree::search(int key, node *leaf){
  if(leaf!=NULL){
    if(key==leaf->key_value){
      return leaf;
    }
    if(key<leaf->key_value){
      return search(key, leaf->left);
    }else{
      return search(key, leaf->right);
    }
  }else{
   return NULL;
  }
}
/* calls search on root */
node *Tree::search(int key){
  return search(key, root);
}
void Tree::AVL_check(node *leaf){
  int avl_value = 0;
  if(leaf->right != NULL){
    ++avl_value;
    AVL_check(leaf->right);
  }
  if(leaf->left != NULL){
    --avl_value;
    AVL_check(leaf->left);
  }
  cout << "bal(" << leaf->key_value << ") = " << avl_value << endl;
}
void Tree::AVL_check(){
  return AVL_check(root);
}
































//
