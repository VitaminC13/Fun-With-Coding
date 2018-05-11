#include "systemc.h"
#include "X_system.h"
#include "stimX.h"

sc_main(int argc,char*argv[])
{
    sc_signal <sc_uint <5> > X;
    sc_signal <sc_lv <2> > Sel;
	sc_signal <bool> type;
    sc_signal <sc_int <22> > Z;
	
    sc_clock clk("clk", 10, SC_NS, 0.5);

    stimX StimX("Stimulus");
    StimX.X(X);
	StimX.type(type);
    StimX.Sel(Sel);
    StimX.clk(clk);

    X_system DUT("X_System");
    DUT.X(X);
	DUT.type(type);
	DUT.Sel(Sel);
	DUT.Z(Z);
	
	sc_trace_file *fp1;
	fp1 = sc_create_vcd_trace_file("Wave_XSys");
	
	sc_trace(fp1, X, "X");
	sc_trace(fp1, Sel, "Sel");
	sc_trace(fp1, type, "type");
	sc_trace(fp1, Z, "Z");
    sc_trace(fp1, clk, "clk");

    sc_start(400, SC_NS);

    sc_close_vcd_trace_file(fp1);

    return 0;	
}