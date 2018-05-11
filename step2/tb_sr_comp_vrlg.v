`timescale 1ms/1ms

module tb_sr_comp_v;

  parameter t_c = 50;

  wire Q, Qbar;

  reg S, R;
  reg clk, rst;


  task apply_test ( input S_test, input R_test, input rst_test);
    begin
      
      S = S_test;
      R = R_test;
      rst = rst_test;
      @(posedge clk);
    end
  endtask

  sr_ff_v duv ( .S(S), .R(R), .clk(clk), .rst(rst), .Q(Q), .Qbar(Qbar) );

  always begin
    #(t_c/2)        clk = 1'b1;
    #(t_c - t_c/2)  clk = 1'b0;
  end

  initial begin
    @(posedge clk)
    apply_test(1'b1, 1'b0, 1'b1);
    apply_test(1'b0, 1'b0, 1'b0);
    apply_test(1'b0, 1'b1, 1'b0);
    apply_test(1'b1, 1'b0, 1'b0);
    apply_test(1'b1, 1'b1, 1'b0);
    apply_test(1'b0, 1'b0, 1'b0);
    apply_test(1'b0, 1'b1, 1'b0);
    apply_test(1'b1, 1'b0, 1'b0);
    apply_test(1'b1, 1'b1, 1'b0);
    apply_test(1'b0, 1'b0, 1'b0);
    apply_test(1'b0, 1'b1, 1'b0);
    apply_test(1'b1, 1'b0, 1'b0);
    apply_test(1'b1, 1'b1, 1'b0);  
    $wait;
  end
endmodule
 