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
#include <memory>
#include "tree.h"

using namespace std;

int main(){
  auto groot = std::make_shared<Tree>();
  groot->insert(4);
  groot->insert(3);
  groot->insert(2);
  int shout = groot->search(4)->key_value;
  cout << shout << endl;

  return 0;
}
