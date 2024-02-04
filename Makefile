files = src/datapath_test.v src/register.v src/alu.v src/decode.v src/execute.v src/writeback.v
output = target/test

all: run

cpu: $(files)
	echo "running iverilog..."
	iverilog -o $(output) $(files) 

run: cpu
	vvp $(output)

clean:
	rm -rf ./target/*

alu_files = src/alu.v src/alu_test.v
alu_output = target/iverilog/alu_test
alu:
	iverilog -o $(alu_output) $(alu_files)

register_files = src/testbench.v src/register.v
register_output = target/iverilog/reg_test
reg:
	iverilog -o $(register_output) $(register_files)