module cpu_ir(opcode,obj,clk,rst_clk,);
input [4:0]opcode;
input [10:0]obj;
input clk;
input rst_clk;
reg [7:0]R1;
reg [7:0]R2;
parameter plda = 00001;
parameter padd = 00010;
parameter pout= 00011;
parameter pstr = 00100;
parameter psub = 00101;
parameter pjmp = 00110;
parameter pswap = 00111;
parameter psdl = 01000;
parameter psdh = 01001;
reg lad,add,out,str,sub,jmp,swap,sdh,sdl;
reg [4:0]optcode;
reg [3:0]jp;
reg [10:0] mar;
assign optcode = opcode;
always @(posedge clk)
begin
  if(rst_clk == 1)
  begin
    optcode <= 0;
    jp <= 0;
  end
  case (jp)
    begin
      0:
      begin
        jp <= 1;
      end
      1:
      begin
        case (optcode)
          plda: lda <= 1; 
          padd: add <= 1;
          pout: out <= 1;
          pstr: str <= 1;
          psub: sub <= 1;
          pjmp: jmp <= 1;
          pswap: swap <= 1;
          psdl: sdl <= 1;
          psdh: sdh <= 1;
          default: jp <= 0;
        endcase
        jp <= 2;
      end
      2:
      case (optcode)
      begin
        
      end
    end
    default: 
  endcase
end
