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
#include <iostream>
#include <fstream>

#include "txtImport.h"

using namespace std;

TxtImport::TxtImport() {}
void TxtImport::read(string filepath) {
  ifstream input(filepath);       // open the file
  string line;                    // temp variable
  while (std::getline(input, line)) {  // read lines as long as the file is
    this->input_vector.push_back(
        std::stoi(line));  // save the line in the vector
  }
}
