`timescale 1ms/1ms

module tb_X_system_v;

  wire [21:0] Z;

  reg [4:0] X;
  reg [1:0] Sel;
  reg type;

  task apply_test ( input [4:0] X_test, input [1:0] Sel_test, input type_test);
    begin
      X    = X_test;
      Sel  = Sel_test;
      type = type_test;
      #1000;
    end
  endtask

  X_system_v duv ( .X(X), .Sel(Sel), .type(type), .Z(Z) );
  
  initial begin
    apply_test( 5'b11111, 2'b00, 1'b1);
    apply_test( 5'b00001, 2'b00, 1'b1);
    apply_test( 5'b00000, 2'b00, 1'b1);
    apply_test( 5'b01001, 2'b00, 1'b1);
    apply_test( 5'b01111, 2'b00, 1'b1);
    apply_test( 5'b11111, 2'b00, 1'b0);
    apply_test( 5'b00001, 2'b00, 1'b0);
    apply_test( 5'b00000, 2'b00, 1'b0);
    apply_test( 5'b01001, 2'b00, 1'b0);
    apply_test( 5'b01111, 2'b00, 1'b0);
    //2nd Function
    apply_test( 5'b11111, 2'b01, 1'b1);
    apply_test( 5'b00001, 2'b01, 1'b1);
    apply_test( 5'b00000, 2'b01, 1'b1);
    apply_test( 5'b01001, 2'b01, 1'b1);
    apply_test( 5'b01111, 2'b01, 1'b1);
    apply_test( 5'b11111, 2'b01, 1'b0);
    apply_test( 5'b00001, 2'b01, 1'b0);
    apply_test( 5'b00000, 2'b01, 1'b0);
    apply_test( 5'b01001, 2'b01, 1'b0);
    apply_test( 5'b01111, 2'b01, 1'b0);
    //3rd Function
    apply_test( 5'b11111, 2'b10, 1'b1);
    apply_test( 5'b00001, 2'b10, 1'b1);
    apply_test( 5'b00000, 2'b10, 1'b1);
    apply_test( 5'b01001, 2'b10, 1'b1);
    apply_test( 5'b01111, 2'b10, 1'b1);
    apply_test( 5'b11111, 2'b10, 1'b0);
    apply_test( 5'b00001, 2'b10, 1'b0);
    apply_test( 5'b00000, 2'b10, 1'b0);
    apply_test( 5'b01001, 2'b10, 1'b0);
    apply_test( 5'b01111, 2'b10, 1'b0);
    //4th Function
    apply_test( 5'b11111, 2'b11, 1'b1);
    apply_test( 5'b00001, 2'b11, 1'b1);
    apply_test( 5'b00000, 2'b11, 1'b1);
    apply_test( 5'b01001, 2'b11, 1'b1);
    apply_test( 5'b01111, 2'b11, 1'b1);
    apply_test( 5'b11111, 2'b11, 1'b0);
    apply_test( 5'b00001, 2'b11, 1'b0);
    apply_test( 5'b00000, 2'b11, 1'b0);
    apply_test( 5'b01001, 2'b11, 1'b0);
    apply_test( 5'b01111, 2'b11, 1'b0);
    $wait;
  end
endmodule 