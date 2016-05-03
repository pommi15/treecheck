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

TxtImport::TxtImport(){
}
TxtImport::~TxtImport(){
}
void TxtImport::read(std::string filepath){
  /* temp_counter counts how many numbers are read in to make an average */
  double temp_counter = 0.0;
  std::ifstream input(filepath);                   // open the file
  std::string line;                                // temp variable
  while (std::getline(input, line)){               // read lines as long as the file is
    this->input_vector.push_back(std::stoi(line)); // save the line in the vector
    this->avg += std::stoi(line);
    temp_counter++;

  }
  this->avg /= temp_counter;
}
