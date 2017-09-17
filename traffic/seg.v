module seg(clk_divide,enable,rst_n,data,data2,seg,seg2,seg3,seg4);
input clk_divide,rst_n;
input [7:0]data;
input [7:0]data2;
input enable;
output [6:0]seg;
output [6:0]seg2;
output [6:0]seg3;
output [6:0]seg4;
reg [6:0]seg;
reg [6:0]seg2;
reg [6:0]seg3;
reg [6:0]seg4;
reg [3:0]seg_reg;
reg [3:0]seg_reg2;
reg [3:0]seg_reg3;
reg [3:0]seg_reg4;
reg [27:0]TCnt;
always@(data2)
	begin
		if(data2 > 9)
			begin
				case (data2)
					10:
						begin
							seg_reg3 <= 0;
							seg_reg4 <= 1;
						end
					11:
						begin
							seg_reg3 <= 1;
							seg_reg4 <= 1;
						end
					12:
						begin
							seg_reg3 <= 2;
							seg_reg4 <= 1;
						end
					13:
						begin
							seg_reg3 <= 3;
							seg_reg4 <= 1;
						end
					14:
						begin
							seg_reg3 <= 4;
							seg_reg4 <= 1;
						end
					15:
						begin
							seg_reg3 <= 5;
							seg_reg4 <= 1;
						end
					16:
						begin
							seg_reg3 <= 6;
							seg_reg4 <= 1;
						end
					17:
						begin
							seg_reg3 <= 7;
							seg_reg4 <= 1;
						end
					18:
						begin
							seg_reg3 <= 8;
							seg_reg4 <= 1;
						end
					19:
						begin
							seg_reg3 <= 9;
							seg_reg4 <= 1;
						end
					20:
						begin
							seg_reg3 <= 0;
							seg_reg4 <= 2;
						end
					21:
						begin
							seg_reg3 <= 1;
							seg_reg4 <= 2;
						end
					22:
						begin
							seg_reg3 <= 2;
							seg_reg4 <= 2;
						end
					23:
						begin
							seg_reg3 <= 3;
							seg_reg4 <= 2;
						end
					24:
						begin
							seg_reg3 <= 4;
							seg_reg4 <= 2;
						end
					25:
						begin
							seg_reg3 <= 5;
							seg_reg4 <= 2;
						end
					26:
						begin
							seg_reg3 <= 6;
							seg_reg4 <= 2;
						end
					27:
						begin
							seg_reg3 <= 7;
							seg_reg4 <= 2;
						end
					28:
						begin
							seg_reg3 <= 8;
							seg_reg4 <= 2;
						end
					29:
						begin
							seg_reg3 <= 9;
							seg_reg4 <= 2;
						end
					30:
						begin
							seg_reg3 <= 0;
							seg_reg4 <= 3;
						end
					98:
						begin
							seg_reg3 <= 8;
							seg_reg4 <= 9;
						end
					98:
						begin
							seg_reg3 <= 9;
							seg_reg4 <= 9;
						end
				endcase
			end
		else
			begin
				seg_reg4 <= 0;
				seg_reg3 <= data2;
			end
	end
always@(data)
	begin
		if(data > 9)
			begin
				case (data)
					10:
						begin
							seg_reg <= 0;
							seg_reg2<= 1;
						end
					11:
						begin
							seg_reg <= 1;
							seg_reg2 <= 1;
						end
					12:
						begin
							seg_reg <= 2;
							seg_reg2 <= 1;
						end
					13:
						begin
							seg_reg <= 3;
							seg_reg2 <= 1;
						end
					14:
						begin
							seg_reg <= 4;
							seg_reg2 <= 1;
						end
					15:
						begin
							seg_reg <= 5;
							seg_reg2 <= 1;
						end
					16:
						begin
							seg_reg <= 6;
							seg_reg2 <= 1;
						end
					17:
						begin
							seg_reg <= 7;
							seg_reg2 <= 1;
						end
					18:
						begin
							seg_reg <= 8;
							seg_reg2 <= 1;
						end
					19:
						begin
							seg_reg <= 9;
							seg_reg2 <= 1;
						end
					20:
						begin
							seg_reg <= 0;
							seg_reg2 <= 2;
						end
					21:
						begin
							seg_reg <= 1;
							seg_reg2 <= 2;
						end
					22:
						begin
							seg_reg <= 2;
							seg_reg2 <= 2;
						end
					23:
						begin
							seg_reg <= 3;
							seg_reg2 <= 2;
						end
					24:
						begin
							seg_reg <= 4;
							seg_reg2 <= 2;
						end
					25:
						begin
							seg_reg <= 5;
							seg_reg2 <= 2;
						end
					26:
						begin
							seg_reg <= 6;
							seg_reg2 <= 2;
						end
					27:
						begin
							seg_reg <= 7;
							seg_reg2 <= 2;
						end
					28:
						begin
							seg_reg <= 8;
							seg_reg2 <= 2;
						end
					29:
						begin
							seg_reg <= 9;
							seg_reg2 <= 2;
						end
					30:
						begin
							seg_reg <= 0;
							seg_reg2 <= 3;
						end
					98:
						begin
							seg_reg <= 8;
							seg_reg2 <= 9;
						end
					99:
						begin
							seg_reg <= 9;
							seg_reg2 <= 9;
						end
				endcase
			end
		else
			begin
				seg_reg2 <= 0;
				seg_reg <= data;
			end
	end
always@(posedge clk_divide or posedge rst_n or negedge enable)
	begin
		if(rst_n == 1)
			begin
				seg<=7'b1111111;
				seg2<=7'b1111111;
				seg3<=7'b1111111;
				seg4<=7'b1111111;
				
			end
		else
			begin
				if(enable == 0)
					begin
						seg <= 7'b0000000;
						seg2 <= 7'b0000000;
						seg3 <= 7'b0000000;
						seg4 <= 7'b0000000;
					end
				else 
					begin
						case(seg_reg)
							0:seg=7'b0000001;
							1:seg=7'b1001111;
							2:seg=7'b0010010;
							3:seg=7'b0000110;
							4:seg=7'b1001100;
							5:seg=7'b0100100;
							6:seg=7'b0100000;
							7:seg=7'b0001111;
							8:seg=7'b0000000;
							9:seg=7'b0000100;
							default:seg<=7'b1111111;
						endcase
						case(seg_reg2)
							0:seg2=7'b0000001;
							1:seg2=7'b1001111;
							2:seg2=7'b0010010;
							3:seg2=7'b0000110;
							4:seg2=7'b1001100;
							5:seg2=7'b0100100;
							6:seg2=7'b0100000;
							7:seg2=7'b0001111;
							8:seg2=7'b0000000;
							9:seg2=7'b0000100;
							default:seg2<=7'b1111111;
						endcase
						case(seg_reg3)
							0:seg3=7'b0000001;
							1:seg3=7'b1001111;
							2:seg3=7'b0010010;
							3:seg3=7'b0000110;
							4:seg3=7'b1001100;
							5:seg3=7'b0100100;
							6:seg3=7'b0100000;
							7:seg3=7'b0001111;
							8:seg3=7'b0000000;
							9:seg3=7'b0000100;
							default:seg3<=7'b1111111;
						endcase
						case(seg_reg4)
							0:seg4=7'b0000001;
							1:seg4=7'b1001111;
							2:seg4=7'b0010010;
							3:seg4=7'b0000110;
							4:seg4=7'b1001100;
							5:seg4=7'b0100100;
							6:seg4=7'b0100000;
							7:seg4=7'b0001111;
							8:seg4=7'b0000000;
							9:seg4=7'b0000100;
							default:seg4<=7'b1111111;
						endcase
					end
			end
	end
endmodule