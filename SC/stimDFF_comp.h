#ifndef stimDFF_comp_H
#define stimDFF_comp_H

#include "systemc.h"

SC_MODULE(stimDFF_comp)
{
    sc_out <bool> din;
	sc_in <bool> clk;
	
	void StimGen()
	{
	    wait();
	    din.write(true);
	    wait();
	    din.write(false);
	    wait();
	    din.write(true);
	    wait();
	    din.write(false);
	    wait();
	    din.write(true);
	    wait();
	    din.write(false);
	    wait();
		wait();
		
		sc_stop();
	}
	
	SC_CTOR(stimDFF_comp)
	{
	    SC_THREAD(StimGen);
	    sensitive << clk.neg();	
	}
};
#endif