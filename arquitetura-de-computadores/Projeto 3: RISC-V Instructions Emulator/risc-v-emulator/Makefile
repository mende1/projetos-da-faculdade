SOURCES := utils.c part1.c part2.c riscv.c
HEADERS := types.h utils.h riscv.h

ASM_TESTS := simple multiply random

all: riscv part1 part2
	@echo "=============All tests finished============="

.PHONY: part1 part2 %_disasm %_execute

riscv: $(SOURCES) $(HEADERS) out
	gcc -g -Wpedantic -Wall -Wextra -Werror -std=c99 -o $@ $(SOURCES)

out:
	@mkdir -p ./riscvcode/out

# Part 1 Tests

part1: riscv $(addsuffix _disasm, $(ASM_TESTS))
	@echo "---------Disassembly Tests Complete---------"

%_disasm: riscvcode/code/%.input riscvcode/ref/%.solution riscv
	@./riscv -d $< > riscvcode/out/test.dump
	@diff $(word 2, $^) riscvcode/out/test.dump && echo "$@ TEST PASSED!" || echo "$@ TEST FAILED!"

# Part 2 Tests

part2: riscv $(addsuffix _execute, $(ASM_TESTS))
	@echo "-----------Execute Tests Complete-----------"

%_execute: riscvcode/code/%.input riscvcode/ref/%.trace riscv
	@./riscv -r $< > riscvcode/out/test.trace
	@diff $(word 2, $^) riscvcode/out/test.trace && echo "$@ TEST PASSED!" || echo "$@ TEST FAILED!"

clean:
	rm -f riscv
	rm -rf riscvcode/out
