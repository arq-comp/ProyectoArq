#ifndef DECODE_H
#define DECODE_H

#include <string>
#include <iomanip>
#include "macros.h"
#include "systemc.h"

using namespace std;

SC_MODULE (decodificador)
{
  //ENTRADAS
  sc_in <bool> clk;
  sc_in <bool> wb_enable;
  sc_in < sc_uint < INSTRUCTION_SIZE > > instruction;
  sc_in < sc_uint < INSTRUCTION > > wb_dirA, wb_dato_A;


  //SALIDAS
  sc_out < sc_uint < INSTRUCTION > > dato_cache;
  sc_out < sc_uint < INSTRUCTION_SIZE > > instruction_out;
  sc_out < sc_uint < INSTRUCTION > > datoA_out;
  sc_out < sc_uint < INSTRUCTION > > datoB_out;
  //sc_out < sc_uint < INSTRUCTION > > dato_A; //CACHE

    //CACHE
    sc_uint<INSTRUCTION> cache[16];


        sc_uint<INSTRUCTION> direccioncacheA, direccioncacheB;


  void write() {
    if(clk.read() == 1 && wb_enable.read() == 1) {
      cache[wb_dirA.read()]=wb_dato_A.read();
     // dato_cache=cache[wb_dirA.read()] ;
      cout<<"paso por cache\n";
    }
  }
   void debug() {
    if(clk.read() == 1)
      return;
    for(int i=0; i<16; i++){
     cout<<cache[i]<<"  ";
    }
  }

  void operation(){
    cout << "se ejecutó la operación operation\n";
      switch(instruction.read().range(INSTRUCTION_SIZE-1, INSTRUCTION_SIZE-4)){
        case LOAD:
        {
          cout << "pasó por LOAD\n";
          instruction_out.write(instruction.read());
          break;
        }
        case ADD:
        {
cout << "pasó por ADD\n";
          instruction_out.write(instruction.read());
          datoA_out = cache[instruction.read().range(INSTRUCTION_SIZE-5, INSTRUCTION_SIZE-8)];
          datoB_out = cache[instruction.read().range(INSTRUCTION_SIZE-9, INSTRUCTION_SIZE-12)];
          break;
        }
        default:

          cout << "pasó por el default\n";
      }
  }

 SC_CTOR (decodificador)
  { 
    SC_METHOD(debug);
    sensitive<<clk.pos();
      SC_METHOD(operation);
        sensitive<<instruction;

      SC_METHOD(write);
        sensitive<<clk.pos()<< wb_dirA<< wb_dato_A;
      //<< wb_enable.read();
  }

  ~decodificador(){  }
};

#endif
