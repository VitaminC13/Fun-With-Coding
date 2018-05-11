`timescale 1ms/1ms

module tb_uni_shift_reg_v;

 parameter t_c = 50;

  wire [3:0] result;

  reg [3:0] in;
  reg [2:0] Sel;
  reg load;
  reg clk, rst;

  task apply_test ( input [3:0] in_test, input [2:0] Sel_test, input load_test, input rst_test);
    begin
      in   = in_test;
      Sel  = Sel_test;
      load = load_test;
      rst  = rst_test;
      @(negedge clk);
    end
  endtask

  uni_shift_reg_v duv ( .in(in), .Sel(Sel), .load(load), .clk(clk), .rst(rst), .result(result) );

  always begin
    #(t_c/2)        clk = 1'b1;
    #(t_c - t_c/2)  clk = 1'b0;
  end

  initial begin
    @(negedge clk)
    apply_test( 4'b1010, 3'b110, 1'b1, 1'b1);
    apply_test( 4'b1010, 3'b110, 1'b1, 1'b0);
    apply_test( 4'b1010, 3'b110, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b000, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b001, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b010, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b011, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b100, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b101, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b111, 1'b0, 1'b0);
    apply_test( 4'b1010, 3'b110, 1'b0, 1'b1);
    $wait;
  end
endmodule
