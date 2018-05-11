#include "systemc.h"
#include "d_ff_comp.h"
#include "stimDFF_comp.h"

sc_main(int argc, char* argv[])
{
    sc_signal <bool> din;
    sc_signal <bool> Q, Qbar;
    
    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, false);

    stimDFF_comp StimDFF_comp("Stimulus");
    StimDFF_comp.din(din);
    StimDFF_comp.clk(clk);

    d_ff_comp DUT("D_FF_comp");
    DUT.din(din);
    DUT.Q(Q);
    DUT.Qbar(Qbar);
    DUT.clk(clk);

    sc_trace_file *fp1;
    fp1 = sc_create_vcd_trace_file("waveD_FF_C");

    sc_trace(fp1, din, "din");
    sc_trace(fp1, Q, "Q");
    sc_trace(fp1, Qbar, "Qbar");
    sc_trace(fp1, clk, "clk");

    sc_start(400, SC_NS);

    sc_close_vcd_trace_file(fp1);

    return 0;	
}