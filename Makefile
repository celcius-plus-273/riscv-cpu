# define the design source files
decode = src/decode/decode.sv src/decode/register.sv
execute = src/execute/execute.sv src/execute/alu.sv
fetch = src/fetch/fetch.sv src/fetch/i_register.sv
writeback = src/writeback/writeback.sv

# datapath test files
datapath = test/datapath_test.sv $(decode) $(execute) $(fetch) $(writeback)
output = target/test

all: run

cpu: $(datapath)
	echo "running iverilog..."
	iverilog -o $(output) $(datapath) 

run: cpu
	vvp $(output)

clean:
	rm -rf ./target/*

alu_files = src/alu.v test/alu_test.v
alu_output = target/iverilog/alu_test
alu:
	iverilog -o $(alu_output) $(alu_files)

register_files = test/register_test.v src/register.v
register_output = target/iverilog/reg_test
reg:
	iverilog -o $(register_output) $(register_files)