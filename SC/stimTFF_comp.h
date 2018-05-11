#ifndef stimTFF_comp_H
#define stimTFF_comp_H

#include "systemc.h"

SC_MODULE(stimTFF_comp)
{
    sc_out <bool> t;
    sc_in <bool> clk;

    void StimGen()
    {
	    wait();
		t.write(true);
		wait();
		t.write(false);
		wait();
		t.write(true);
		wait();
		t.write(false);
		wait();
		t.write(true);
		wait();
		t.write(false);
		wait();
		wait();
		
		sc_stop();
	}	
	
	SC_CTOR(stimTFF_comp)
	{
	    SC_THREAD(StimGen);
	    sensitive << clk.neg();	
	}
};
#endif