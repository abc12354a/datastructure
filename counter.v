module counter(iraddr,load,clk,rst_clk,pcaddr);
input[15:0] iraddr;
input load,clk,rst_clk;
output[15:0]pcaddr;
reg pcaddr;
always @(posedge clk) begin
  if (rst_clk == 1) begin
    pcaddr <= 16'b0000000000000000;
  end
  else begin
    if (load) begin
      pcaddr <= iraddr;
    end
    else begin
      pcaddr <= pcaddr+1;
    end
  end
end
endmodule