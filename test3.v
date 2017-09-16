module test3(clk,set,cs,mr,my,mg,cr,cy,cg,count,segout,segout2,clk_divide,count_c,segout3,segout4,Em,Ec);
input clk,set,cs;		  //cs乡村,c表示乡村车(1/0)
input Em,Ec;
output mr,my,mg,cr,cy,cg;
output[7:0] count;
output[7:0] count_c;
output[6:0] segout;
output[6:0] segout2;
output[6:0] segout3;
output[6:0] segout4;
output clk_divide;
reg mr;
reg my;
reg mg;
reg cr;
reg cy;
reg cg;
reg[2:0] state;
reg[7:0] count;		  //max256秒
reg[7:0] count_c;
reg[2:0] m;
reg[2:0] c;
wire clk_divide;
parameter mgcr = 3'd0,
		  mycr = 3'd1,
		  mrcg = 3'd2,
		  mrcy = 3'd3,
		  NOC  = 3'd4;
always @(posedge clk_divide or posedge set)
	begin					  //每秒测试一次(clk每秒)
		if(set)              //reset信号
			begin
				m <= 3'b001;         //123位分别是RYG
				c <= 3'b100;
				count <= 8'd25;          //计数 
				count_c <= 8'd30;
				state <= mgcr;		  //计数显示程序留作function
			end
		else
			if(Em == 1 || Ec == 1)
				begin
					if(Em == 1)
						begin
							count <= 0;
							count_c <= 99;
							mr <= 1'b0;
							my <= 1'b0;
							mg <= 1'b1;
							cr <= 1'b1;
							cy <= 1'b0;
							cg <= 1'b0;
						end
					else
						begin
							count <= 99;
							count_c <= 0;
							mr <= 1'b1;
							my <= 1'b0;
							mg <= 1'b1;
							cr <= 1'b0;
							cy <= 1'b0;
							cg <= 1'b1;
						end
				end
			else
					begin
						case(state)
							mgcr:
							begin
								if(cs == 0)
									begin
										if(count == 1)
											begin
												state <= NOC;
												count_c <= 8'd99;
												count <= 8'd99;
											end
										else
											begin
												count <= count - 1'b1;
												count_c	<= count_c - 1'b1;
												state <= mgcr;
												m <= 3'b001;
												c <= 3'b100;
												mr <= 1'b0;
												my <= 1'b0;
												mg <= 1'b1;
												cr <= 1'b1;
												cy <= 1'b0;
												cg <= 1'b0;
											end
									end
								if(count == 1)
									begin
										state <= mycr;
										count <= 8'd5;
										count_c <= 8'd5;
									end
								else
									begin
										count <= count - 1'b1;
										count_c <= count_c - 1'b1;
										m <= 3'b001;
	 									c <= 3'b100;
	 									mr <= 1'b0;
	 									my <= 1'b0;
	 									mg <= 1'b1;
	 									cr <= 1'b1;
	 									cy <= 1'b0;
	 									cg <= 1'b0;
										state <= mgcr;
	 								end
							end
							mycr:
							begin
								if(cs == 0)
									begin
										if(count_c == 1)
											begin
												state <= NOC;
												count_c <= 8'd99;
												count <= 8'd99;
											end
										else
											begin
												count <= count - 1'b1;
												count_c	<= count_c - 1'b1;
												state <= mycr;
												m <= 3'b010;
												c <= 3'b100;
												mr <= 1'b0;
												my <= 1'b1;
												mg <= 1'b0;
												cy <= 1'b0;
												cr <= 1'b1;
												cg <= 1'b0;
											end
									end
	 							if(count_c == 1)
	 								begin
	 									state <= mrcg;
	 									count <= 8'd21;
	 									count_c <= 8'd16;
									end
								else
									begin
	 									count <= count - 1'b1;
	 									count_c <= count_c - 1'b1;
	 									m <= 3'b010;
	 									c <= 3'b100;
	 									mr <= 1'b0;
	 									my <= 1'b1;
	 									mg <= 1'b0;
	 									cy <= 1'b0;
										cr <= 1'b1;
 										cg <= 1'b0;
	 									state <= mycr;
	 								end 
							end
							mrcg:
							begin
								if(cs == 0)
									begin
										if(count_c == 1)
											begin
												state <= NOC;
												count_c <= 8'd99;
												count <= 8'd99;
											end
										else
											begin
												count <= count - 1'b1;
												count_c	<= count_c - 1'b1;
												m <= 3'b100;
												c <= 3'b001;
												mr <= 1'b1;
												my <= 1'b0;
												mg <= 1'b0;
												cy <= 1'b0;
												cr <= 1'b0;
												cg <= 1'b1;
												state <= mrcg;
											end
									end
	 							if(count_c == 1)
	 								begin
	 									state <= mrcy;
	 									count_c <= 8'd5;
										count <= 8'd5;
	 								end
	 							else
									begin
	 									count <= count - 1'b1;
	 									count_c <= count_c - 1'b1;
	 									m <= 3'b100;
	 									c <= 3'b001;
	 									mr <= 1'b1;
	 									my <= 1'b0;
	 									mg <= 1'b0;
	 									cy <= 1'b0;
	 									cr <= 1'b0;
	 									cg <= 1'b1;
										state <= mrcg;
	 								end
							end
							mrcy:
							begin
								if(cs == 0)
									begin
										if(count_c == 1)
											begin
												state <= NOC;
												count_c <= 8'd99;
												count <= 8'd99;
											end
										else
											begin
												count <= count - 1'b1;
												count_c	<= count_c - 1'b1;
												m <= 3'b100;
												c <= 3'b010;
												mr <= 1'b1;
												my <= 1'b0;
												mg <= 1'b0;
												cy <= 1'b1;
												cr <= 1'b0;
												cg <= 1'b0; 
												state <= mrcy;
											end
									end
	 							if(count == 1)
	 								begin
	 									state <= mgcr;
	 									count <= 8'd25;
	 									count_c <= 8'd30;
									end
 								else
	 								begin
	 									count <= count - 1'b1;
	 									count_c <= count_c - 1'b1;
	 									m <= 3'b100;
	 									c <= 3'b010;
										mr <= 1'b1;
										my <= 1'b0;
	 									mg <= 1'b0;
	 									cy <= 1'b1;
	 									cr <= 1'b0;
	 									cg <= 1'b0; 
	 									state <= mrcy;
	 							    end
							end
							NOC:
							begin
								if(cs == 1)
									begin
										state <= mgcr;
										count <= 8'd25;
	 									count_c <= 8'd30;
									end
								else
									begin
										m <= 3'b000;
	 									c <= 3'b000;
										mr <= 1'b0;
										my <= 1'b0;
	 									mg <= 1'b1;
	 									cy <= 1'b0;
	 									cr <= 1'b1;
	 									cg <= 1'b0;
										count <= 99;
										count_c <= 99;
										state <= NOC;
									end
							end 
						endcase
					end
	end
show   		st(.clk(clk_divide),.rst_n(set),.data(count),.data2(count_c),.seg(segout),.seg2(segout2),.seg3(segout3),.seg4(segout4));
divide 	    d1(.clk(clk),.rst_n(set),.clk_divide(clk_divide));
endmodule 
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
module seg(clk_divide,rst_n,data,data2,seg,seg2,seg3,seg4);
input clk_divide,rst_n;
input [7:0]data;
input [7:0]data2;
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
always@(posedge clk_divide or posedge rst_n)
	begin
		if(rst_n)
			begin
				seg<=7'b1111111;
				seg2<=7'b1111111;
				seg3<=7'b1111111;
				seg4<=7'b1111111;
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
endmodule
module show(clk,rst_n,data,data2,seg,seg2,seg3,seg4);
input clk,rst_n;
input [7:0]data;
input [7:0]data2;
output [6:0]seg;
output [6:0]seg2;
output [6:0]seg3;
output [6:0]seg4;
wire [6:0]seg;
wire [6:0]seg2;
wire [6:0]seg3;
wire [6:0]seg4;
seg 	    sg(.clk_divide(clk),.rst_n(rst_n),.data2(data2),.data(data),.seg(seg),.seg2(seg2),.seg3(seg3),.seg4(seg4));
endmodule
	 