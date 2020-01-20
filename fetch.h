#include <systemc.h>
#include <fstream>
#include <string>
#include <pipe.h>

using namespace std;


#define MI_filename "instruction_m.txt"

SC_MODULE (fetch) {
  ifstream MI;
  sc_in<bool> clk;
  sc_out< sc_uint<16> > instruction;
  sc_out< sc_uint<16> > outData;
  Pipe *pipe1;
  void Fetch() {
    string line;
    getline(MI,line);
    sc_uint<16> temp;
    for (int i = 0; i < 16; ++i){
      temp[i] = line[16-(i+1)]-'0';
    }


    instruction = temp;
  }

  SC_CTOR (fetch) {
    pipe1  = new Pipe("pipe"); 
    MI.open(MI_filename);
    SC_METHOD(Fetch);
    sensitive<<clk.neg();
    	pipe1 -> clk(clk);
		pipe1 -> inData(instruction);
		pipe1 -> outData(outData);
  }

  ~fetch() {
    MI.close();
    delete pipe1;
  }
