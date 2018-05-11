#ifndef uni_shift_H
#define uni_shift_H

#include "systemc.h"

SC_MODULE(uni_shift)
{
    sc_in <sc_int <4> > in;
    sc_in <sc_lv <3> > Sel;
	sc_in <bool> load;
	sc_in <bool> clk, rst;
	sc_out <sc_int <4> > result;
	
	sc_signal <sc_int <4> > tmp;
	
	void p1()
	{
	    if(rst.read())
		    result.write("0b0000");
	    else
		    if(load.read())
			    tmp.write(in.read());
		    else
			    if(Sel.read() == "000")
				    result.write(in.read() >> 3);
			    else if(Sel.read() == "001")
				    result.write(in.read() << 2);
			    else if(Sel.read() == "010")
				    result.write((in.read() >> 1) |(in.read() << 3));
			    else if(Sel.read() == "011")
				    result.write(result.read());
			    else if(Sel.read() == "100")
				    result.write("0b0000");
			    else if(Sel.read() == "101")
				    result.write(!(in.read()));
			    else if(Sel.read() == "110")
				    result.write(in.read());
			    else if(Sel.read() == "111")
				    result.write((in.read() << 2) | (in.read() >> 2));	
	} 
	
	SC_CTOR(uni_shift)
	{
	    SC_METHOD(p1);
	    sensitive << clk.pos();	
	}
};
#endif