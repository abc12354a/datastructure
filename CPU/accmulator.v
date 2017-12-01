module accmulator(data,ena,clk,rst_clk,accmu);
input [7:0]data;
input ena,clk,rst_clk;
output [7:0]accmu;
reg [7:0]accmu;
always@(clk)
begin
  if(rst_clk == 1)
  begin
    accmu <= 8'b00000000;
  end
  else
  begin
    if(ena)
    begin
      accmu <= data;
    end
  end
end
endmodule