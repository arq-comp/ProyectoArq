
#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include "macros.h"

SC_MODULE(testbench) {
  
  sc_in<sc_uint < INSTRUCTION_SIZE> > instruction;
  sc_in<bool> clk;
  sc_in< sc_uint < INSTRUCTION_SIZE> > pipe1;

  
   void printf( )   { 
 cout << "\t";
    
    for (int i = 0; i < INSTRUCTION_SIZE; ++i)
      cout << "\n"<<instruction.read().range(INSTRUCTION_SIZE-(i+1),INSTRUCTION_SIZE-(i+1));

    cout << "  | " << setw(5) << instruction.read() << " | " << clk.read()<<"\n";
  cout << "\t";
     for (int i = 0; i < INSTRUCTION_SIZE; ++i)// Imprime el primer pipe
      cout << "\n"<<pipe1.read().range(INSTRUCTION_SIZE-(i+1),INSTRUCTION_SIZE-(i+1));

   cout << " | "; cout <<"\n";
  }
  void test() {
    cout << "\n"
         << "\t\t Instruction(BIN) | (DEC) | CLK | pipe\n"
         << "\t\t--------------------------------------\n";

    for (int i = 0; i < INSTRUCTIONS; ++i) {
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
