#include <fstream>
#include <string>
#include "macros.h"
#include "pipe.h"

using namespace std;

#ifndef HALF_ADDER
#define HALF_ADDER

#define MI_filename "inst.txt"

SC_MODULE (fetch) {
  ifstream MI;
  sc_in<bool> clk;
  sc_out<sc_uint < INSTRUCTION_SIZE> > instruction;

  void Fetch() {
    string line;
    getline(MI,line);
    sc_uint<INSTRUCTION_SIZE> temp;
    for (int i = 0; i < INSTRUCTION_SIZE; ++i)
    temp[i] = line[INSTRUCTION_SIZE-(i+1)]-'0';
    instruction.write(temp);
  }


  SC_CTOR (fetch) {
    MI.open(MI_filename);
    SC_METHOD(Fetch);
    sensitive<<clk.neg();
  }

  ~fetch() {
    MI.close();
  }
};

#endif//HALF_ADDER
