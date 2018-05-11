#include "systemc.h"
#include "t_ff.h"
#include "stimT_FF.h"

int sc_main(int argc, char* argv[])
{
    sc_signal <bool> t, q, reset;

    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, false);

    stimT_FF StimT_FF("stimulus");
    StimT_FF.t(t);
    StimT_FF.reset(reset);
    StimT_FF.clk(clk);

    t_ff DUT("t_ff");
    DUT.t(t);
	DUT.reset(reset);
	DUT.q(q);
	DUT.clk(clk);
	
	sc_trace_file *fp1;
	fp1 = sc_create_vcd_trace_file("waveT_FF");
	
	sc_trace(fp1, t, "t");
	sc_trace(fp1, reset, "reset");
	sc_trace(fp1, q, "q");
	sc_trace(fp1, clk, "clk");
	
	sc_start(400, SC_NS);
	
	sc_close_vcd_trace_file(fp1);
	
	return 0;
}