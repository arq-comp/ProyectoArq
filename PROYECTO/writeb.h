#include <iostream>
#include <iomanip>
#include "macros.h"


SC_MODULE (writeb)
{

	//ENTRADAS
    sc_in <sc_uint<INSTRUCTION> > data_memory;
	sc_in <sc_uint<INSTRUCTION_SIZE> > instruction;
	sc_in <bool> clk_in;

	//SALIDAS
	sc_out <sc_uint<INSTRUCTION> > direccion_cache;
    sc_out <bool> enable;
	sc_out <sc_uint<INSTRUCTION> > data_out;
	
void operation () {
	if ( instruction.read().range(INSTRUCTION_SIZE-1, INSTRUCTION_SIZE-4) == LOAD ){
		enable = 1;
		cout<<"paso por writeb\n";
	}
	else{
		enable = 0;
		direccion_cache.write(instruction.read().range(INSTRUCTION_SIZE-9, INSTRUCTION_SIZE-12));
		data_out.write(data_memory.read());
		cout<<data_memory.read()<<"envia los datos a la cache \n";
}
}

SC_CTOR (writeb){
	SC_METHOD(operation);
    	sensitive<<instruction;
    //sensitive<<clk.neg();/////////////////////
  }
};
