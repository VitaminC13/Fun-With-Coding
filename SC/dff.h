#ifndef dff_H
#define dff_h

#include "systemc.h"

SC_MODULE(dff)
{
    sc_in <bool> din;
    sc_in <bool> clk;
    sc_out <bool> Q;
	sc_out <bool> Qbar;

    void p1()
    {
        Q.write(din.read());
		Qbar.write(!(din.read()));
    }

    SC_CTOR(dff)
    {
	    SC_METHOD(p1);
		sensitive << clk.pos();
	}	
};
#endif