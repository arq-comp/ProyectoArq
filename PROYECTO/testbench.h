#ifndef TESTBENCH
#define TESTBENCH

#include <iomanip>
#include "macros.h"
#include "systemc.h"


SC_MODULE(testbench) {
	//FETCH
	sc_in<sc_uint < INSTRUCTION_SIZE> > instruction;
	sc_in<bool> clk;
	// sc_in< sc_uint < INSTRUCTION_SIZE> > pipe1;
	sc_in< sc_uint < INSTRUCTION> > dato;

	
   	void print() { 
		cout << "\t\t\t";
		for (int i = 0; i < INSTRUCTION_SIZE; ++i)
			cout <<instruction.read().range(INSTRUCTION_SIZE-(i+1),INSTRUCTION_SIZE-(i+1));
		cout << "  | " << setw(5) << instruction.read() << " | " << clk.read() << "\t";
		
		for (int i = 0; i < INSTRUCTION; ++i)// Imprime el dato_A en el pipe 2
			cout <<dato.read().range(INSTRUCTION-(i+1),INSTRUCTION-(i+1));
		cout << "  | ";
		cout << endl;
	}



	void test() {
		cout << "\n"
		     << "\t\t Instruction(BIN) |         (DEC)         | CLK        | dato       \n"
		     << "\t\t--------------------------------------\n";

		for (int i = 0; i < 12; ++i) {
			wait();
			print();
		}

		sc_stop();
	}

	SC_CTOR(testbench) {
		cout<<"paso por el constructor"<<endl;
		SC_THREAD(test);
		sensitive<<clk;
	}
};

#endif//TESTBENCH
