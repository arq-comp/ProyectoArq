
#ifndef PIPE
#define PIPE
#include <systemc.h>
using namespace std;

SC_MODULE(Pipe){

sc_in<bool> clk;

sc_in< sc_uint<16> > inData;
sc_uint< 16 > data;
sc_out< sc_uint<16> > outData;

void read(){
  
    outData = data;
  }
  



void write(){
 
    data = inData;
  
}


SC_CTOR(Pipe){
  SC_METHOD(read);
   sensitive<<clk.pos()<<inData;

  SC_METHOD(write); 
  sensitive<<clk.neg();
}


};

#endif//REGISTER