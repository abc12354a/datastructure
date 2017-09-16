module test3(clk,set,cs,mr,my,mg,cr,cy,cg,count,segout,selout);
input clk,set,cs;		  //cs乡村,c表示乡村车(1/0)
output mr,my,mg,cr,cy,cg;
output[7:0] count;
output selout;
output[7:0] segout;
reg mr;
reg my;
reg mg;
reg cr;
reg cy;
reg cg;
reg[1:0] state;
reg[7:0] count;		  //max256秒
reg[2:0] m;
reg[2:0] c;
parameter mgcr = 2'd0,
		  mycr = 2'd1,
		  mrcg = 2'd2,
		  mrcy = 2'd3;
always @(posedge clk)
begin					  //每秒测试一次(clk每秒)
	 if(set)              //reset信号
	 begin
	 m <= 3'b001;         //123位分别是RYG
	 c <= 3'b100;
	 count <= 0;          //计数 
	 state <= mgcr;		  //计数显示程序留作function
	 end
	 else
	 begin
	 if(cs == 0)			  //乡村干道没车
	 begin
	 m <= 3'b001;
	 c <= 3'b100;
	 state <= mgcr;
	 count <= 0;
	 mr <= 1'b0;
	 my <= 1'b0;
	 mg <= 1'b1;
	 cr <= 1'b1;
	 cy <= 1'b0;
	 cg <= 1'b0;
	 end
	 else				  //乡村有车
	 begin
	 case(state)
	mgcr:
	 if(count == 25)
	 begin
	 state <= mycr;
	 count <= 0;
	 end
	 else
	 begin
	 count <= count + 1'b1;
	 m <= 3'b001;
	 c <= 3'b100;
	 mr <= 1'b0;
	 my <= 1'b0;
	 mg <= 1'b1;
	 cr <= 1'b1;
	 cy <= 1'b0;
	 cg <= 1'b0;
	 state <= mgcr;
	 endverilog
	mycr:
	 if(count == 5)
	 begin
	 state <= mrcg;
	 count <= 0;
	 end
	 else
	 begin
	 count <= count + 1'b1;
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
	mrcg:
	 if(count == 16)
	 begin
	 state <= mrcy;
	 count <= 0;
	 end
	 else
	 begin
	 count <= count + 1'b1;
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
	mrcy:
	 if(count == 5)
	 begin
	 state <= mgcr;
	 count <= 0;
	 end
	 else
	 begin
	 count <= count + 1'b1;
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
	endcase
	end
	end
	end
show   st(.clk(clk),.rst_n(set),.data(data),.sel_acture(selout),.seg(segout));
endmodule 
module divide(clk,rst_n,clk_divide);
input clk,rst_n;
output clk_divide;
reg [17:0]cnt;
reg clk_divide;
always@(posedge clk or posedge rst_n )
if(rst_n)                              
	cnt<=0;
else 
	begin
		cnt<=cnt+1'b1;
		//clk_divide<=cnt[17];//cnt[17] under the actual situation.
		clk_divide<=cnt[2];//cnt[2] in the simulation case;
	end
endmodule
module sel(clk_divide,rst_n,sel,sel_acture);
input clk_divide,rst_n;
output sel,sel_acture;
reg sel,sel_acture;
always@(posedge clk_divide or posedge rst_n)
if (rst_n)
	sel<=0;
else
begin
	sel<=sel+1'b1;
	sel_acture<=sel;
end
endmodule
module seg(clk_divide,rst_n,sel,data,seg);
input clk_divide,rst_n;
input sel;
input [7:0]data;
output [7:0]seg;
reg [7:0]seg;
reg [3:0]seg_reg;
always@(posedge clk_divide or posedge rst_n)
if(rst_n)
seg<=8'hFF;
else 
	begin
		case(seg_reg)
			4'h0: seg<=8'hC0;
			4'h1: seg<=8'hF9;
			4'h2: seg<=8'hA4;
			4'h3: seg<=8'hB0;
			4'h4: seg<=8'h99;
			4'h5: seg<=8'h92;
			4'h6: seg<=8'h82;
			4'h7: seg<=8'hF8;
			4'h8: seg<=8'h80;
			4'h9: seg<=8'h90;
			4'hA: seg<=8'h88;
			4'hB: seg<=8'h83;
			4'hC: seg<=8'hC6;
			4'hD: seg<=8'hA1;
			4'hE: seg<=8'h86;
			4'hF: seg<=8'h8E;
			default:seg<=8'hFF;
		endcase
	end
always@(sel,data)
case(sel)
0:begin
			seg_reg=data[7:4];
		end
		
1:begin
			seg_reg=data[3:0];
		end
endcase
endmodule
module show(clk,rst_n,data,sel_acture,seg);
input clk,rst_n;
input [7:0]data;
output sel_acture;
output [7:0]seg;
wire sel_acture;
wire [7:0]seg;
wire clk_divide;
wire sel;
divide 	    d1(.clk(clk),.rst_n(rst_n),.clk_divide(clk_divide));
sel 		sl(.clk_divide(clk_divide),.rst_n(rst_n),.sel(sel),.sel_acture(sel_acture));
seg 	    sg(.clk_divide(clk_divide),.rst_n(rst_n),.sel(sel),.data(data),.seg(seg));
endmodule
	 