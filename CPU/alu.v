module alu(accmu,data,optcode,zero,ena);
input[7:0] accmu;
input[7:0] data;
input clk,rst_clk;
input[4:0] optcode;
input ena;
output[7:0]alu_out;
output zero;
reg[7:0]alu_out;
reg zero;
parameter add = 5'b00001;
parameter sub = 5'b00010;
parameter andd = 5'b00011;
parameter orr = 5'b00100;
parameter lda = 5'b00101;
parameter sto = 5'b00110;
parameter jmp = 5'b00111;
parameter xorr = 5'b01000;
assign zero = !accmu;
always @(posedge clk) begin
  if (rst_clk == 1) begin
    alu_out <= 8'b0000000;
    zero <= 1;
  end
  else
  begin
    case (optcode)
      add: alu_out <= data+accmu;
      andd:alu_out <= data&accmu;
      xorr:alu_out <= data^accmu;
      lda:alu_out <= data;
      sub:alu_out <= data-accmu;
      orr:alu_out <= data|accmu;
      jmp:alu_out <= accmu;
      sto:alu_out <= accmu;
      default: alu_out <= 8'b0000000;
    endcase
  end
end
endmodule