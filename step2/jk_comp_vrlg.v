module jk_comp_v
  ( input J, K,
    input clk,
    output Q, Qbar);
  
  wire w, x, y, z;
  wire Q_tmp, Qbar_tmp;   

  assign Q_tmp = 1'b0;
  assign Qbar_tmp = 1'b1;
  assign w = Q_tmp;
  assign z = Qbar_tmp;

  nnd3_v nand1 ( z, J, clk, x);
  nnd3_v nand2 ( clk, K, w, y);
  nnd2_v nand3 ( x, z, Q_tmp);
  nnd2_v nand4 ( y, w, Qbar_tmp);

  assign Q = Q_tmp;
  assign Qbar = Qbar_tmp;
endmodule
