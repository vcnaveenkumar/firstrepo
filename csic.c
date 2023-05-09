#include <stdint.h>

uint8_t memory[32768];

struct registers {
	uint32_t A : 24;
	uint32_t X : 24;
	uint32_t L : 24;
	uint32_t PC : 24;
	uint32_t SW : 24;
} regs;


struct instruction {
	uint8_t opcode;
	uint16_t index : 1;
	uint16_t address : 15;
};

uint16_t get_indirect_address(uint16_t address) {
	return regs.X + address;
}

void LDA(uint32_t val) {
	regs.A = val;
}
void LDX(uint32_t val) {
	regs.X = val;
}
void LDL(uint32_t val) {
	regs.L = val;
}


uint32_t STA() {
	return regs.A;
}
uint32_t STX() {
	return regs.X;
}
uint32_t STL() {
	return regs.L;
}

void ADD(uint32_t val) {
	regs.A += val;
}
void SUB(uint32_t val) {
	regs.A -= val;
}
void MUL(uint32_t val) {
	regs.A *= val;
}
void DIV(uint32_t val) {
	regs.A /= val;
}

enum comparison {
	comparison_less,
	comparison_equal,
	comparison_greater,
};

void COMP(uint32_t val) {
	if(regs.A < val) {
		regs.SW = comparison_less;
	} else if(regs.A == val) {
		regs.SW = comparison_equal;
	} else {
		regs.SW = comparison_greater;
	}
}


int main()
{
	return 0;
}