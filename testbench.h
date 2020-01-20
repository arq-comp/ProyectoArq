#ifndef TESTBENCH
#define TESTBENCH
#include <systemc.h>
#include <iostream>
#include <iomanip>
using namespace std;
SC_MODULE(testbench) {

  sc_in< sc_uint<16> > instruction;
  sc_in< sc_uint<16> > outData;
  sc_in< sc_uint<16> > inData;
  sc_in<bool> clk;

  void print() {
    cout << "\t\t  ";
    
    for (int i = 0; i < 16; ++i){
      cout << instruction.read().range(16-(i+1),16-(i+1));
    cout << "  | " << setw(5) << instruction.read() << " | " << clk.read() << "\n";
    }
    
  
      for(int i = 0; i < 16 ; i++){

     cout << outData.read().range(16-(i+1), 16-(i+1));
    cout << " | " << clk.read() <<std::endl;
    }

    

  }

  void test() {
    cout << "\n"
         << "\t\t Instruction(BIN) | (DEC) | CLK | PIPE | CLK\n"
         << "\t\t-----------------------------------\n";

    for (int i = 0; i < 5 ; ++i) {
      wait();
      print();
    }
    

    sc_stop();
  }

  SC_CTOR(testbench) {
      SC_THREAD(test);
      sensitive<<clk.neg();
  }
};

#endif//TESTBENCH
