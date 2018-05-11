module jk_ff
  ( input J, K,
    input clk,
    output reg Q,
    output reg Qbar );

  initial begin
  Q = 1'b0;
  Qbar = 1'b1;
  end

  always @(negedge clk)
  begin
    if( J == 1'b0 && K == 1'b0)
    begin
      assign Q =  Q;
      assign Qbar = Qbar;
    end
    else if( J == 1'b0 && K == 1'b1)
    begin
      assign Q = 1'b0;
      assign Qbar = 1'b1;
    end
    else if( J == 1'b1 && K == 1'b0)
    begin
      assign Q = 1'b1;
      assign Qbar = 1'b0;
    end
    else
    begin
      assign Q = ~Q;
      assign Qbar = ~Qbar;
    end
  end
endmodule
