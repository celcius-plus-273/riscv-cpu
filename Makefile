files = src/testbench.v src/register.v
output = target/verilog_output_file

all: run

sim: $(files)
	echo "running iverilog..."
	iverilog -o $(output) $(files) 

run: sim
	vvp $(output)

clean:
	rm -rf ./target/*