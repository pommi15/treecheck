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
#ifndef TXTIMPORT_H_
#define TXTIMPORT_H_
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>

class TxtImport {
public:
  TxtImport();                      //constructor
  ~TxtImport();                     //destructor
  std::vector<int> input_vector;    //vector for the read in numbers
  void read(std::string filepath);  //function to read the numbers into the vector from given file
  double avg;
};
  #endif //TXTIMPORT_H_
