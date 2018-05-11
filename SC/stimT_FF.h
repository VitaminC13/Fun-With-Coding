#ifndef stimT_FF_H
#define stimT_FF_H

#include "systemc.h"

SC_MODULE(stimT_FF)
{
    sc_out <bool> t;
    sc_out <bool> reset;
    sc_in <bool> clk;

    void StimGen()
    {
	    wait();
		t.write(true);
		reset.write(true);
		wait();
		t.write(true);
		reset.write(false);
		wait();
		t.write(false);
		reset.write(false);
		wait();
		t.write(true);
		reset.write(false);
		wait();
		wait();
		
		sc_stop();
	}	
	SC_CTOR(stimT_FF)
	{
	    SC_THREAD(StimGen);
	sensitive << clk.neg();	
	}
};
#endif