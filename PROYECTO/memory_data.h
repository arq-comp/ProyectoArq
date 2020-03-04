#include "systemc.h"
#include <fstream>
#include "macros.h"

#define DM_filename "memory_data.txt"

SC_MODULE(memory_data) {

    //ENTRADAS

    sc_in<sc_uint<INSTRUCTION_SIZE> > instruction;
    sc_in<sc_uint<INSTRUCTION> >datoaluwrite;
    sc_in<bool> clk;
    // sc_int<sc_uint<INSTRUCTION> > data;
    
    //SALIDAS
    sc_out<sc_uint<INSTRUCTION> > dato;
    sc_out<sc_uint<INSTRUCTION_SIZE> > data_out;
    

        fstream md;

    //void write_memory() {
      //  sc_uint<INSTRUCTION> operation = /*se saca la op*/
        //bool escribo = false;

        //if (operation == STORE || operation == 2 || operation == 3)
          //  escribo = true;

        //if (not escribo || clk.read()==0)
          //  return;

        // escribir en el archivo <<
    //}

    void read_memory() {
        
    sc_uint<INSTRUCTION> temp;
    string s;

        if(clk.read()==1){//clk 
            return;
            int l = instruction.read().range(INSTRUCTION_SIZE-5, INSTRUCTION_SIZE-8);
            md.seekg((INSTRUCTION+1)*l);
            //
            md >> s;
            //sc_uint<INSTRUCTION> temp;
        }
        for (int i = 0; i < INSTRUCTION; ++i){
            temp[i] = s[INSTRUCTION-(i+1)]-'0';
            dato.write(temp);
        }
        
            data_out.write(instruction.read());
            //cout<<temp<<"paso por la memory data\n";
    }
    

    SC_CTOR(memory_data) {
      
       md.open(DM_filename);

        SC_METHOD(read_memory); 
            sensitive<<clk.neg();/////////////////////
    }

    ~memory_data() {
        
        md.close();
    }
};
