module divide(clk,rst_n,clk_divide);
input clk,rst_n;
output clk_divide;
reg [31:0]cnt;
reg clk_divide;
always@(posedge clk or posedge rst_n)
	begin
		if(rst_n)                              
			cnt<=0;
		else 
			begin
				cnt<=cnt+1'b1;
			//clk_divide<=cnt[17];//cnt[17] under the actual situation.
				clk_divide<=cnt[2];//cnt[2] in the simulation case;
			end
	end
endmodule