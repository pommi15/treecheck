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

int main(int argc, char* argv[]){
  if(argc>2){
    cout << "Invalid input!" << endl;
    cout << "Please give a valid filepath!" << endl;
    return 0;
  }
  auto groot = std::make_shared<Tree>();
  auto import = std::make_shared<TxtImport>();
  import->read(argv[1]);
  for(int i : import->input_vector) {
    groot->insert(i);
  }
  groot->AVL_check();
  if(groot->AVL){
    cout << "AVL: yes" << endl;
  }else{
    cout << "AVL: no" << endl;
  }
  cout << "max: "<< groot->max << " " << "min: " << groot->min << " "  << "avg: " << import->avg << endl;



  return 0;
}
