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

int main(int argc, char* argv[]) {
  if (argc > 2) {
    cout << "Invalid input!" << endl;
    cout << "Please give a valid filepath!" << endl;
    return 0;
  }
  if (argc == 1) {
    cout << "Invalid input!" << endl;
    cout << "Please give a filepath!" << endl;
    return 0;
  }
  cout << "+---------------------------------+" << endl;
  cout << "|            treecheck            |" << endl;
  cout << "|         let's check some        |" << endl;
  cout << "|       fucking trees, brah!      |" << endl;
  cout << "+---------------------------------+" << endl;
  auto groot = make_shared<Tree>();
  auto import = make_shared<TxtImport>();
  /* read in txt file */
  import->read(argv[1]);
  for (int i : import->input_vector) {
    groot->insert(i);
  }
  /* if file is empty no tree is checked */
  if (groot->empty_check()) {
    cout << "Tree is empty!" << endl;
    return 0;
  }
  /* avl check */
  groot->AVL_check();

  cout << "+---------------------------------+" << endl;
  cout << "|  Is this tree an AVL-Tree?";
  if (groot->AVL) {
    cout << " Yes. |" << endl;
  } else {
    cout << " No.  |" << endl;
  }
  /* min max and avg function are called */
  groot->check_min();
  groot->check_min();
  groot->check_avg();

  cout << "|  maximum entered value: " << groot->max_value << "      |" << endl;
  cout << "|  minimum entered value: " << groot->min_value << "       |"
       << endl;
  if ((groot->avg / groot->avg_counter) > 9.99 ||
      (groot->avg / groot->avg_counter) < 0) {
    cout.precision(4);
    cout << "|  average entered value: " << (groot->avg / groot->avg_counter)
         << "   |" << endl;
  } else {
    cout.precision(3);
    cout << "|  average entered value: " << (groot->avg / groot->avg_counter)
         << "    |" << endl;
  }
  cout << "+---------------------------------+" << endl;

  return 0;
}
