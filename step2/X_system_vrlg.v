module X_system_v
  ( input [4:0] X,
    input [1:0] Sel,
    input type,
    output reg [21:0] Z );

  //wire [21:0] tmp;

  always @ (Sel)
    if(type)
      begin
        if (Sel == 2'b00)
          begin
            assign Z = (X ** 4);
          end
        else if (Sel == 2'b01)
          begin
            assign Z = (100 - X);
          end
        else if (Sel == 2'b10)
          begin
            assign Z = (~(X ** 3));
          end
        else if (Sel == 2'b11)
          begin
            assign Z = (X + 250);
          end
      end
    else
      begin
        if(Sel == 2'b00)
          begin
            assign Z = $signed(X ** 4);
          end
        else if(Sel == 2'b01)
          begin
            assign Z = $signed(100 - X);
          end
        else if(Sel == 2'b10)
          begin
            assign Z = $signed(~(X ** 3));
          end
        else if(Sel == 2'b11)
          begin
            assign Z = $signed(X + 250);
          end
      end  
endmodule   
