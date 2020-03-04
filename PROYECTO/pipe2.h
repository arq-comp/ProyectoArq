#ifndef PIPE2_H
#define PIPE2_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include "macros.h"

using namespace std;


SC_MODULE (Pipe2){
	sc_in <sc_uint<INSTRUCTION_SIZE> > data_in;
	sc_in <bool> clk_in;
	sc_out <sc_uint<INSTRUCTION_SIZE> > data_out;
	sc_uint<INSTRUCTION_SIZE>  data;

	sc_in <sc_uint<INSTRUCTION> > datoA_in,datoB_in;
	sc_out <sc_uint<INSTRUCTION> > datoA_out,datoB_out;


	sc_uint<INSTRUCTION>  datoAA, datoBB;
	


	
void operation (){
//    switch(data_in.read().range(INSTRUCTION_SIZE-1, INSTRUCTION_SIZE-4)){
  //  case 0:
//	{
			if (!clk_in.read() and data_in.read()){
				
				data = data_in;
				cout <<" paso por el pipe 3\n";
				datoAA = datoA_in;
				datoBB = datoB_in;
				// la otra data = la otra entrada
			} else if (clk_in.read()){
				data_out = data;
				datoA_out = datoAA;
				datoB_out = datoBB; 
				// la otra salida = la otra data
			}		
//	    break;
//	  }
	}


	SC_CTOR (Pipe2)
	{
	    SC_METHOD (operation);
		sensitive << data_in << clk_in;
		}

	//~pipe3(){}

};

#endif//PIPE2_H