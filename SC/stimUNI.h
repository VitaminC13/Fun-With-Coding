#ifndef stimUNI_H
#define stimUNI_H

#include "systemc.h"

SC_MODULE(stimUNI)
{
    sc_out <sc_int <4> > in;
    sc_out <sc_lv <3> > Sel;
    sc_out <bool> load;
    sc_out <bool> rst;
    sc_in <bool> clk;
    
    void StimGen()
	{
	    wait();
	    in.write("0b1001");
	    Sel.write("110");
	    load.write(true);
	    rst.write(true);
	    wait();
	    in.write("0b1001");
	    Sel.write("110");
	    load.write(true);
	    rst.write(false);
	    wait();
	    in.write("0b1001");
	    Sel.write("110");
	    load.write(false);
	    rst.write(false);
	    wait();
	    in.write("0b1001");
	    Sel.write("000");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("001");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("010");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("011");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("100");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("101");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("110");
	    load.write(false);
	    rst.write(false);
	    wait();
		in.write("0b1001");
	    Sel.write("111");
	    load.write(false);
	    rst.write(false);
	    wait();
		wait();
		
		sc_stop();
	}
	
	SC_CTOR(stimUNI)
	{
	    SC_THREAD(StimGen);
	    sensitive << clk.neg();	
	}
};
#endif