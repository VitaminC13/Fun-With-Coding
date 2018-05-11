#ifndef t_ff_H
#define t_ff_H

#include "systemc.h"

SC_MODULE(t_ff)
{
    sc_in <bool> clk;
    sc_in <bool> t;
    sc_in <bool> reset;
    sc_out <bool> q;

    bool q_tmp;

    void p1()
    {
	    if(reset.read())
			q_tmp = false;
		else if(t.read())
			q_tmp = !q_tmp;
		else
			q_tmp = q_tmp;
		
		q.write(q_tmp);
	}

    SC_CTOR(t_ff)
    {
	    SC_METHOD(p1);
		sensitive << clk.pos();
	}
	
};
#endif