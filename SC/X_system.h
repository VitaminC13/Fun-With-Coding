#ifndef X_system_H
#define X_system_H

#include "systemc.h"

SC_MODULE(X_system)
{
    sc_in <sc_uint <5> > X;
	sc_in <sc_lv <2> > Sel;
	sc_in <bool> type;
	sc_out <sc_int <22> > Z;
	
	void p1()
	{
		if(type)
	        if(Sel.read() == "00")
		        Z.write(X.read() * X.read() * X.read() * X.read());
	        else if(Sel.read() == "01")
		  	    Z.write(100 - X.read());
            else if(Sel.read() == "10")
	            Z.write(!(X.read() * X.read() * X.read()));
            else if(Sel.read() == "11")
	            Z.write(X.read() + 250);
	    else
	        if(Sel.read() == "00")
		        Z.write(X.read() * X.read() * X.read() * X.read());
	        else if(Sel.read() == "01")
		  	    Z.write(100 - X.read());
            else if(Sel.read() == "10")
	            Z.write(!(X.read() * X.read() * X.read()));
            else if(Sel.read() == "11")
	            Z.write(X.read() + 250);		
	}
	
	SC_CTOR(X_system)
	{
	    SC_METHOD(p1);
		sensitive << X;
	}
};
#endif