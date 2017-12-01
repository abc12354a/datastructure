module machinecontrol(ena,fetch,rst_clk,clk);
input fetch,rst_clk,clk;
output ena;
reg ena;
reg state;
always @(posedge clk) begin
  if (rst_clk) begin
    ena <= 0;
  end
  else begin
    if(fetch) begin
      ena <= 1;
    end
  end
end
endmodule