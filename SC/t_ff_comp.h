#ifndef t_ff_comp_H
#define t_ff_comp_H

#include "systemc.h"
#include "and3.h"
#include "nor2.h"

SC_MODULE(t_ff_comp)
{
    sc_in <bool> t;
	sc_in <bool> clk;
	sc_out <bool> Q;
	sc_out <bool> Qbar;
	
	and3 a1, a2;
	nor2 n1, n2;
	
	sc_signal <bool> tmp1,tmp2;
	sc_signal <bool> Qtmp, Qbartmp;
	
	void p1();
	
	SC_CTOR(t_ff_comp) : a1("a1"), a2("a2"), n1("n1"), n2("n2")
    {
	    a1.a(Qtmp);
		a1.b(t);
		a1.c(clk);
		a1.f(tmp1);
		
		a2.a(clk);
		a2.b(t);
		a2.c(Qbartmp);
		a2.f(tmp2);
		
		n1.a(tmp1);
		n1.b(Qbartmp);
		n1.f(Q);
		
		n2.a(Qtmp);
		n2.b(tmp2);
		n2.f(Qbar);
		
		SC_METHOD(p1);
		sensitive << clk.pos();
	}
};

    void t_ff_comp::p1()
    {
	    Qtmp.write(t.read());
	    Qbartmp.write(!(t.read()));	
	}
#endif