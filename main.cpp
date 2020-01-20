#include <systemc.h>
#include <string>
#include <iomanip>
#include "testbench.h"
#include "fetch.h"

int sc_main(int argv, char* argc[])
 {
  sc_time PERIOD(10,SC_NS);
  sc_time DELAY(10,SC_NS);
  sc_clock clock("clock",PERIOD,0.5,DELAY,true);

  fetch ft("ft");
  testbench tb("tb");

  sc_signal< sc_uint<16> > inst;
  sc_signal< sc_uint<16> > out;

    ft.instruction(inst);
    ft.outData(out);
    ft.clk(clock);

    tb.inData(inst);
    tb.outData(out);
    tb.clk(clock);

    sc_start();

    return 0;
}
