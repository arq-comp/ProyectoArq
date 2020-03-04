#ifndef ALU_H
#define ALU_H
#include <systemc.h>
#include "macros.h"


class alu: public sc_module
{
	public:
		//ENTRADAS
		sc_in<sc_uint<INSTRUCTION_SIZE> > op_in;
    	sc_in<sc_uint<INSTRUCTION> > a_in;
		sc_in<sc_uint<INSTRUCTION> > b_in;
		sc_in <bool> clk_in;
		
		//SALIDAS
		sc_out<sc_uint<INSTRUCTION> > c_out;
		
		
			SC_CTOR(alu)
			{
				SC_METHOD(operation);
					sensitive<<a_in<<b_in<<op_in ;
			}
	
	private:
		void operation()
		{
			switch(op_in.read().range(INSTRUCTION_SIZE-1, INSTRUCTION_SIZE-4))
			{
				case LOAD:
					break;
					/*{
						c_out.write(a_in.read() + b_in.read());
						break;
					}*/
				case ADD:
					{
						c_out.write(a_in.read() + b_in.read());
						break;
					}
				case SUB:
					{
						c_out.write(a_in.read() - b_in.read());
						break;
					}
					/*
				case STORE:
					{
						c_out.write(a_in.read() / b_in.read());
						break;
					}
	*/
				case BUBBLE:
					{
						break;
					}

				default:
					{
						c_out.write(a_in.read());
					}
			}
		}
};
#endif
