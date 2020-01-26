#include <systemc.h>
#include <string>
#include <iomanip>
#include "macros.h"
#include "fetch.h"
#include "testbench.h"

int sc_main(int argv, char* argc[])
{
  sc_time PERIOD(10, SC_NS);
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true);
  
  fetch ft("fetch");
  testbench tb("tb");
  Pipe p1("pipe1");

  sc_signal< sc_uint < INSTRUCTION_SIZE>> instruction_sg,p1_sg;
 
  ft.instruction(instruction_sg);
  ft.clk(clock);
	
  tb.instruction(instruction_sg);
  tb.clk(clock);
  tb.pipe1(p1_sg);


  //tb.pipe2(pipe2_sg);
  
   p1.data_in(instruction_sg);
   p1.data_out(p1_sg);
   p1.clk_in(clock);



  sc_start();
  return 0;
}
