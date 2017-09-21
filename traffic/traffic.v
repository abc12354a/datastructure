module traffic(clk,set,cs,mr,my,mg,cr,cy,cg,count,count_c,Em,Ec);
input clk,set,cs;		  //cs乡村,c表示乡村车(1/0)
input Em,Ec;
output mr,my,mg,cr,cy,cg;
output[7:0] count;
output[7:0] count_c;
reg mr;
reg my;
reg mg;
reg cr;
reg cy;
reg cg;
reg[2:0] state;
reg[7:0] count;		  //max128秒
reg[7:0] count_c;   
reg[2:0] m;
reg[2:0] c;
parameter mgcr = 3'd0,
		  mycr = 3'd1,
		  mrcg = 3'd2,
		  mrcy = 3'd3,
		  NOC  = 3'd4;
always @(posedge clk or posedge set)
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
							mr <= 1'b0;
							my <= 1'b0;
							mg <= 1'b1;
							cr <= 1'b1;
							cy <= 1'b0;
							cg <= 1'b0;
						end
					else
						begin
							mr <= 1'b1;
							my <= 1'b0;
							mg <= 1'b0;
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
                                            count_c <= 8'd0;
                                            count <= 8'd0;
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
                            else
                                begin
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
                        end
                        mycr:
                        begin
                            if(cs == 0)
                                begin
                                    if(count_c == 1)
                                        begin
                                            state <= NOC;
                                            count_c <= 8'd0;
                                            count <= 8'd0;
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
                            else
                                begin
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
                        end
                        mrcg:
                        begin
                            if(cs == 0)
                                begin
                                    count <= 8'd25;
                                    count_c <= 8'd30;
                                    state <= mgcr;
                                end
                            else
                                begin
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
                        end
                        mrcy:
                        begin
                            if(cs == 0)
                                begin
                                    if(count_c == 1)
                                        begin
                                            state <= NOC;
                                            count_c <= 8'd0;
                                            count <= 8'd0;
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
                            else
                                begin
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
                        end
                        NOC:
                        begin
                            if(cs == 1)
                                begin
                                    state <= mgcr;
                                    count <= 8'd25;
                                    count_c <= 8'd30;
                                    m <= 3'b001;
                                    c <= 3'b100;
                                    mr <= 1'b0;
                                    my <= 1'b0;
                                    mg <= 1'b1;
                                    cy <= 1'b0;
                                    cr <= 1'b1;
                                    cg <= 1'b0;
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
                                    count <= 0;
                                    count_c <= 99;
                                    state <= NOC;
                                end
                        end 
                    endcase
                end
	end
endmodule 