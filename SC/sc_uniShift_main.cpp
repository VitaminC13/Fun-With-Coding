#include "systemc.h"
#include "uni_shift.h"
#include "stimUNI.h"

sc_main(int argc, char* argv[])
{
    sc_signal <sc_int <4> > in;
    sc_signal <sc_lv <3> > Sel;
    sc_signal <bool> load;
    sc_signal <bool> rst;
    sc_signal <sc_int <4> > result;

    sc_clock clk("clk", 10, SC_NS, 0.5, 10, SC_NS, false);

    stimUNI StimUNI("Stimulus");
    StimUNI.in(in);
    StimUNI.Sel(Sel);
    StimUNI.load(load);
    StimUNI.rst(rst);
    StimUNI.clk(clk);

    uni_shift DUT("Uni_Shift");
    DUT.in(in);
    DUT.Sel(Sel);
    DUT.load(load);
    DUT.rst(rst);
    DUT.clk(clk);
    DUT.result(result);
    
    sc_trace_file *fp1;
    fp1 = sc_create_vcd_trace_file("wave_Uni_Shift");

    sc_trace(fp1, in, "in");
    sc_trace(fp1, Sel, "Sel");
    sc_trace(fp1, load, "load");
    sc_trace(fp1, rst, "rst");
    sc_trace(fp1, clk, "clk");
    sc_trace(fp1, result, "result");

    sc_start(400, SC_NS);
    
    sc_close_vcd_trace_file(fp1);

    return 0;	
}

