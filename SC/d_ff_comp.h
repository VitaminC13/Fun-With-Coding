#ifndef d_ff_comp_H
#define d_ff_comp_H

#include "systemc.h"
#include "nnd2.h"

SC_MODULE(d_ff_comp)
{
    sc_in <bool> din;
    sc_in <bool> clk;
    sc_out <bool> Q;
    sc_out <bool> Qbar;
	
	nnd2 ND1, ND2, ND3, ND4;
	
    sc_signal <bool> tmp1, tmp2, Qtmp, Qbartmp;
	sc_signal <bool> Ndin;
	
	void p1();

    SC_CTOR(d_ff_comp) : ND1("ND1"), ND2("ND2"), ND3("ND3"),ND4("ND4")
    {
	    ND1.a(din);
		ND1.b(clk);
		ND1.f(tmp1);
		
		ND2.a(clk);
		ND2.b(Ndin);
		ND2.f(tmp2);
		
		ND3.a(tmp1);
		ND3.b(Qbartmp);
		ND3.f(Q);
		
		ND4.a(Qtmp);
		ND4.b(tmp2);
		ND4.f(Qbar);
		
		SC_METHOD(p1);
		sensitive << clk.pos();
    }	
};

    void d_ff_comp::p1()
    {
	    Ndin.write(!(din.read()));
	    Qtmp.write(din.read());
	    Qbartmp.write(!(din.read()));	
	}
#endif