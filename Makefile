# define the design source files
decode = src/decode/decode.v src/decode/register.v
execute = src/execute/execute.v src/execute/alu.v
fetch = src/fetch/fetch.v src/fetch/i_register.v
writeback = src/writeback/writeback.v

# datapath test files
datapath = test/datapath_test.v $(decode) $(execute) $(fetch) $(writeback)
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