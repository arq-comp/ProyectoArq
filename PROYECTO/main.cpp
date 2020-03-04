#include "systemc.h"
#include <cassert>
#include <string>
#include <iomanip>
#include "macros.h"
#include "fetch.h"
#include "testbench.h"
#include "decode.h"
#include "pipe.h"
#include "alu.h"
#include "pipe2.h"
#include "pipe3.h"
#include "pipe4.h"
#include "writeb.h"
#include "memory_data.h"


int sc_main(int argv, char* argc[])
{
   
  sc_time PERIOD(10, SC_NS);
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true);
    
    fetch ft("fetch");
    testbench tb("tb");
    Pipe p1("pipe1");
    Pipe2 p2("pipe2");
    Pipe3 p3("pipe3");
    Pipe4 p4("pipe4");
    decodificador dec("dec");
    alu alu("alu");
    memory_data memory("memory");
    writeb writeb("writeb");


      //SEÑALES
      sc_signal< sc_uint < INSTRUCTION_SIZE> > instruction_sg; 
      //DECODER PIPE1
      sc_signal< sc_uint < INSTRUCTION_SIZE> > p1_sg; 
      //DECODER-WRITEBACK
      sc_signal< sc_uint < INSTRUCTION> > op1_sg,op2_sg;
      //DECODER-PIPE2
      sc_signal< sc_uint < INSTRUCTION_SIZE> > inst_sg, pipe2_sg;
      //PIPE3-DATAMEMORY
      sc_signal< sc_uint < INSTRUCTION_SIZE> > pipe3_sg;
      //DATAMEMORY-WRITEBACK
      sc_signal< sc_uint < INSTRUCTION> > dato_memory_sg;
      sc_signal< sc_uint < INSTRUCTION_SIZE> >inst_out_sg;
      //DECODE TESHBECH
      sc_signal< sc_uint < INSTRUCTION > > cache_sg;
      //PIPE5-WRITEBACK
      sc_signal< sc_uint < INSTRUCTION> > datopipe5_sg;
      sc_signal< sc_uint < INSTRUCTION_SIZE> > instructionpipe5_sg;
      //DECODER-PIPE2
      sc_signal< sc_uint < INSTRUCTION> > datoApipe2_sg, datoBpipe2_sg,salidaApipe2_sg,salidaBpipe2_sg;
      //ALU - PIPE3
      sc_signal< sc_uint < INSTRUCTION> > out_alu_sg,dato_alu_memory_sg; 

      sc_signal< bool > enable_sg;

  
    //TESTBENCH
    tb.instruction(instruction_sg);
    tb.clk(clock);
    tb.dato(cache_sg);
  
  //--------------------------------------------------------------------------
    //FETCH

    ft.instruction(instruction_sg);
    ft.clk(clock);
  
    //PIPE1

     p1.data_in(instruction_sg);
     p1.data_out(p1_sg);
     p1.clk_in(clock);

     //DECODER
     dec.clk(clock);
     dec.instruction(p1_sg);
     dec.wb_dirA(op1_sg);
     dec.wb_dato_A(op2_sg);
     dec.dato_cache(cache_sg);
     dec.wb_enable(enable_sg);
     dec.instruction_out(inst_sg);
     dec.datoA_out(datoApipe2_sg);
     dec.datoB_out(datoBpipe2_sg);

     //PIPE2
     p2.data_in(inst_sg);
     p2.data_out(pipe2_sg);
     p2.datoA_in(datoApipe2_sg);
     p2.datoB_in(datoBpipe2_sg);
     p2.datoA_out(salidaApipe2_sg);
     p2.datoB_out(salidaBpipe2_sg);
     p2.clk_in(clock);

    //ALU
     alu.op_in(pipe2_sg);
     alu.a_in(salidaApipe2_sg);
     alu.b_in(salidaBpipe2_sg); 
     alu.c_out(out_alu_sg);
     alu.clk_in(clock);
     
     //PIPE3
     p3.resultado_alu_in(out_alu_sg);
     p3.resultado_alu_out(dato_alu_memory_sg);
     p3.data_in(pipe2_sg);
     p3.data_out(pipe3_sg);
     p3.clk_in(clock);   

     //DATAMEMORY
     memory.instruction(pipe3_sg);
     memory.datoaluwrite(dato_alu_memory_sg);
     memory.dato(dato_memory_sg);
     memory.data_out(inst_out_sg);
     memory.clk(clock);
     
     //PIPE4
     p4.instruction_in(inst_out_sg);
     p4.dato_in(dato_memory_sg);
     p4.instruction_out(instructionpipe5_sg);
     p4.dato_out(datopipe5_sg);
     p4.clk_in(clock);
     
     //WRITEBACK
     writeb.data_memory(datopipe5_sg);
     writeb.instruction(instructionpipe5_sg);
     writeb.enable(enable_sg);
     writeb.clk_in(clock);
     writeb.direccion_cache(op1_sg);
     writeb.data_out(op2_sg); 
//-----------------------------------------------------------------------------------------
      
      sc_start();
  

 return 0; 
}

