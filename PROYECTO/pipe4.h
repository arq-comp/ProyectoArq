#ifndef PIPE4_H
#define PIPE4_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include "macros.h"


class Pipe4 : public sc_module
{
public:

	//ENTRADAS
	sc_in <sc_uint<INSTRUCTION_SIZE> > instruction_in;
	sc_in <sc_uint<INSTRUCTION> > dato_in;
	sc_in <bool> clk_in;

	//SALIDAS
	sc_out <sc_uint<INSTRUCTION> > dato_out;
	sc_out <sc_uint<INSTRUCTION_SIZE> > instruction_out;

	SC_CTOR(Pipe4)
	{
		//this->data = 0;
		SC_METHOD(operation);
			sensitive << clk_in;
	}

	~Pipe4(){}

private:

		sc_uint<INSTRUCTION_SIZE>  instruction;
		sc_uint<INSTRUCTION>  dato;

	void operation(){

		if (!clk_in.read()){
			instruction = instruction_in;
			dato = dato_in;
			cout<<"paso por el pipe 4\n";
		}
		 else if (clk_in.read()){
			instruction_out = instruction;
			dato_out = dato;
		}
  }
};

#endif//PIPE4_H
