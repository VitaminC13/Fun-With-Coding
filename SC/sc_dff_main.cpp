#include "systemc.h"
#include "dff.h"

int sc_main(int argc, char* argv[])
{
    sc_signal <bool> din, Q, Qbar;

    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, false);

    dff DUT("dff");
    DUT.din(din);
    DUT.Q(Q);
	DUT.Qbar(Qbar);
    DUT.clk(clk);

    sc_trace_file *fp1;
    fp1 = sc_create_vcd_trace_file("waveDFF");

    sc_trace(fp1, din, "din");
    sc_trace(fp1, Q, "Q");
	sc_trace(fp1, Qbar, "Qbar");
    sc_trace(fp1, clk, "clk");

    din = true;
    sc_start(31, SC_NS);
    din = false;
    sc_start(59, SC_NS);
    din = true;
    sc_start(75, SC_NS);

    return 0;	
}