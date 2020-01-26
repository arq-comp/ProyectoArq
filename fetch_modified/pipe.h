#ifndef PIPE_H
#define PIPE_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include "macros.h"
using namespace std;


class Pipe : public sc_module
{
public:
	sc_in <sc_uint<INSTRUCTION_SIZE> > data_in;
	sc_in <bool> clk_in;
	sc_out <sc_uint<INSTRUCTION_SIZE> > data_out;

	SC_CTOR(Pipe)
	{
		this->data = 0;
		SC_METHOD(write_operation);
		sensitive << clk_in << data_in ;
		SC_METHOD(read_operation);
		sensitive << clk_in;
	}
	~Pipe(){}
private:
	sc_uint<INSTRUCTION_SIZE>  data;

	void write_operation()
	{

		if (!clk_in.read() and data_in.read())
			data = data_in;
	}
	void read_operation()
	{
		if (clk_in.read()){
			data_out = data;
		}
		
	}
};

#endif//PIPE_H


