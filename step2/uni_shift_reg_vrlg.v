module uni_shift_reg_v
  ( input [3:0] in,
    input [2:0] Sel,
    input load,
    input clk, rst,
    output reg [3:0] result);

  reg [3:0] tmp;

  always @ (posedge clk or posedge rst)
  begin
    if(rst)
       result = 0;
    else
      case(load)
        1'b1:
          begin
            tmp = in;
          end
        1'b0:
          case(Sel)
            3'b000: result = tmp >> 3;
            3'b001: result = tmp << 2;
            3'b010: result = {tmp[0], tmp[3:1]};
            3'b011: result = result;
            3'b100: result = 0;
            3'b101: result = ~tmp;
            3'b110: result = tmp;
            3'b111: result = {tmp[1:0], tmp[3:2]};
          endcase
      endcase
    end
endmodule
