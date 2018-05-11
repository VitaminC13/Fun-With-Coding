#ifndef stimX_H
#define stimX_H

#include "systemc.h"

SC_MODULE(stimX)
{
    sc_out <sc_uint <5> > X;
    sc_out <sc_lv <2> > Sel;
	sc_out <bool> type;
    sc_in <bool> clk;

    void StimGen()
    {
	    X.write("0b11111");
		Sel.write("0b00");
		type.write(true);
		wait();
		X.write("0b00001");
		Sel.write("00");
		type.write(true);
		wait();
		X.write("0b00000");
		Sel.write("00");
		type.write(true);
		wait();
		X.write("0b01001");
		Sel.write("00");
		type.write(true);
		wait();
		X.write("0b01111");
		Sel.write("00");
		type.write(true);
		wait();
		X.write("0b11111");
		Sel.write("0b00");
		type.write(false);
		wait();
		X.write("0b00001");
		Sel.write("00");
		type.write(false);
		wait();
		X.write("0b00000");
		Sel.write("00");
		type.write(false);
		wait();
		X.write("0b01001");
		Sel.write("00");
		type.write(false);
		wait();
		X.write("0b01111");
		Sel.write("00");
		type.write(false);
		wait();
		X.write("0b11111");//2nd Function
		Sel.write("0b01");
		type.write(true);
		wait();
		X.write("0b00001");
		Sel.write("01");
		type.write(true);
		wait();
		X.write("0b00000");
		Sel.write("01");
		type.write(true);
		wait();
		X.write("0b01001");
		Sel.write("01");
		type.write(true);
		wait();
		X.write("0b01111");
		Sel.write("01");
		type.write(true);
		wait();
		Sel.write("0b01");
		type.write(false);
		wait();
		X.write("0b00001");
		Sel.write("01");
		type.write(false);
		wait();
		X.write("0b00000");
		Sel.write("01");
		type.write(false);
		wait();
		X.write("0b01001");
		Sel.write("01");
		type.write(false);
		wait();
		X.write("0b01111");
		Sel.write("01");
		type.write(false);
		wait();
		X.write("0b11111");//3rd Function
		Sel.write("0b10");
		type.write(true);
		wait();
		X.write("0b00001");
		Sel.write("10");
		type.write(true);
		wait();
		X.write("0b00000");
		Sel.write("10");
		type.write(true);
		wait();
		X.write("0b01001");
		Sel.write("10");
		type.write(true);
		wait();
		X.write("0b01111");
		Sel.write("10");
		type.write(true);
		wait();
		X.write("0b11111");//3rd Function
		Sel.write("0b10");
		type.write(false);
		wait();
		X.write("0b00001");
		Sel.write("10");
		type.write(false);
		wait();
		X.write("0b00000");
		Sel.write("10");
		type.write(false);
		wait();
		X.write("0b01001");
		Sel.write("10");
		type.write(false);
		wait();
		X.write("0b01111");
		Sel.write("10");
		type.write(false);
		wait();
		X.write("0b11111");// 4th Function
		Sel.write("0b11");
		type.write(true);
		wait();
		X.write("0b00001");
		Sel.write("11");
		type.write(true);
		wait();
		X.write("0b00000");
		Sel.write("11");
		type.write(true);
		wait();
		X.write("0b01001");
		Sel.write("11");
		type.write(true);
		wait();
		X.write("0b01111");
		Sel.write("11");
		type.write(true);
		wait();
		X.write("0b11111");
		Sel.write("0b11");
		type.write(false);
		wait();
		X.write("0b00001");
		Sel.write("11");
		type.write(false);
		wait();
		X.write("0b00000");
		Sel.write("11");
		type.write(false);
		wait();
		X.write("0b01001");
		Sel.write("11");
		type.write(false);
		wait();
		X.write("0b01111");
		Sel.write("11");
		type.write(false);
		
		sc_stop();
	}
 
    SC_CTOR(stimX)
    {
	    SC_THREAD(StimGen);
		sensitive << clk.pos();
	}
};
#endif