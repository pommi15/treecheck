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
#include "txtImport.h"

using namespace std;

int main(){
  auto groot = std::make_shared<Tree>();
  auto import = std::make_shared<TxtImport>();
  import->read("test.txt");
  for(int i : import->input_vector) {
    groot->insert(import->input_vector[i]);
  }

  return 0;
}
