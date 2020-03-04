#ifndef PIPE3_H
#define PIPE3_H
#include <systemc.h>
#include <iostream>
#include <iomanip>
#include "macros.h"


class Pipe3 : public sc_module
{
public:
	//ENTRADAS
	sc_in <sc_uint<INSTRUCTION_SIZE> > data_in;
	sc_in <sc_uint<INSTRUCTION> > resultado_alu_in;
	sc_in <bool> clk_in;
	
	//SALIDAS
	sc_out <sc_uint<INSTRUCTION_SIZE> > data_out;
	sc_out <sc_uint<INSTRUCTION> > resultado_alu_out;


	SC_CTOR(Pipe3)
	{
		this->data = 0;
		SC_METHOD(operation);
			sensitive << clk_in << data_in;
	}
	
	~Pipe3(){}

	private:
		sc_uint<INSTRUCTION_SIZE>  data;
		sc_uint<INSTRUCTION> resultado_alu1;

	void operation(){

		if (!clk_in.read() and data_in.read()){
			data = data_in;
			resultado_alu1 = resultado_alu_in;
			cout<<"paso por el pipe 4\n";
		}
		 else if (clk_in.read()){

		 	resultado_alu_out = resultado_alu1;
			data_out = data;
		}
    
  }
};

#endif//PIPE3_H