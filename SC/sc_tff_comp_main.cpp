#include "systemc.h"
#include "t_ff_comp.h"
#include "stimTFF_comp.h"

sc_main(int argc, char* argv[])
{
    sc_signal <bool> t;
    sc_signal <bool> Q, Qbar;
    
    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, false);
	
	stimTFF_comp StimTFF_comp("Stimulus");
	StimTFF_comp.t(t);
	StimTFF_comp.clk(clk);
	
	t_ff_comp DUT("T_FF_Comp");
	DUT.t(t);
	DUT.Q(Q);
	DUT.Qbar(Qbar);
	DUT.clk(clk);
	
	sc_trace_file *fp1;
	fp1 = sc_create_vcd_trace_file("wave_TFF_Comp");
	
	sc_trace(fp1, t, "t");
	sc_trace(fp1, Q, "Q");
	sc_trace(fp1, Qbar, "Qbar");
	sc_trace(fp1, clk, "clk");
	
	sc_start(400, SC_NS);
	
	sc_close_vcd_trace_file(fp1);
	
	return 0;
}