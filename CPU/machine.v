module machine(inc_pc,load_acc,load_pc,rd,wr,load_ir,datactl_ena,clk,zero,ena,optcode)
output inc_pc,load_acc,load_pc,rd,wr,load_ir;
output datactl_ena;
input clk,zero,ena;
input[4:0]optcode;
reg inc_pc,load_acc,load_ir,load_pc,rd,wr;
reg datactl_ena;
reg [2:0]state;
parameter add = 5'b00001;
parameter sub = 5'b00010;
parameter andd = 5'b00011;
parameter orr = 5'b00100;
parameter lda = 5'b00101;
parameter sto = 5'b00110;
parameter jmp = 5'b00111;
parameter xorr = 5'b01000;
always @(negedge clk) begin
  if(!ena) begin
    state <= 3'b000;
    {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
    {wr,load_ir,datactl_ena} <= 3'b000;
  end
  else begin
    ctl_cycle;
  end
end
//-------------ctl_cycle---------------------
task ctl_cycle;
begin
  case (state)
    3'b000: begin
      {inc_pc,load_acc,load_pc,rd} <= 4'b0001;
      {wr,load_ir,datactl_ena} <= 3'b010;
      state <= 3'b001;
    end 
    3'b001: begin
      {inc_pc,load_acc,load_pc,rd} <= 4'b1001;
      {wr,load_ir,datactl_ena} <= 3'b010;
      state <= 3'b010;
    end
    3'b010: begin
      {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
      {wr,load_ir,datactl_ena} <= 3'b000;
      state <= 3'b011;
    end
    3'b011: begin
      if(optcode == jmp) begin
      {inc_pc,load_acc,load_pc,rd} <= 4'b0010;
      {wr,load_ir,datactl_ena} <= 3'b000;
      end
      else
        if(optcode == add||optcode == andd || optcode == xorr || optcode == lda || optcode == sub || optcode == orr)
        begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0001;
        {wr,load_ir,datactl_ena} <= 3'b000;
        end
        else 
          if(optcode == sto) begin
            {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
            {wr,load_ir,datactl_ena} <= 3'b001;
          end
        else begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
        {wr,load_ir,datactl_ena} <= 3'b000;
        end
        state <= 3'b100;
    end
    3'b100: begin
      if(optcode == add || optcode == andd || optcode == xorr || optcode == lda || optcode == orr) begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0101;
        {wr,load_ir,datactl_ena} <= 3'b000;
      end
      else
      if(optcode == jmp) begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b1010;
        {wr,load_ir,datactl_ena} <= 3'b001;
      end
      else
      if(optcode == sto) begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
         {wr,load_ir,datactl_ena} <= 3'b101;
      end
      else begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
        {wr,load_ir,datactl_ena} <= 3'b000;
      end
      state <= 3'b101;
    end
    3'b101: begin
      if(optcode == sto) begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
        {wr,load_ir,datactl_ena} <= 3'b001;
      end
      else
      if(optcode == add || optcode == andd || optcode == xorr || optcode == lda || optcode == orr) begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0001;
        {wr,load_ir,datactl_ena} <= 3'b000;
      end
      else begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000;
        {wr,load_ir,datactl_ena} <= 3'b000;
      end
      state <= 3'b110
    end
    3'b110: begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000
        {wr,load_ir,datactl_ena} <= 3'b000;
    end
    state <= 3'b000;
    default: begin
        {inc_pc,load_acc,load_pc,rd} <= 4'b0000
        {wr,load_ir,datactl_ena} <= 3'b000;
        state <= 3'b000;
    end
  endcase
end
endtask
//----------end task ctl_cycle----------
endmodule