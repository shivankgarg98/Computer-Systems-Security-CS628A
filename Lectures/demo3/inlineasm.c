unsigned char code[] = 
	"\x48" "\x31" "\xc0"             	
	"\xb0" "\x02"                	
	"\x48" "\x89" "\xc7"             	
	"\xb0" "\x0e"                	
	"\x48" "\x89" "\xc2"             	
	"\x48" "\x8d" "\x05" "\x19" "\x01" "\x01" "\x01" 	
	"\x48" "\x89" "\xc6"             	
	"\x48" "\x31" "\xc0"             	
	"\xb8" "\x01" "\x01" "\x01" "\x01"       	
	"\x30" "\xc0"                	
	"\x48" "\x29" "\xc6"             	
	"\x48" "\x31" "\xc0"             	
	"\xb0" "\x01"                	
	"\x0f" "\x05" 
	"\xeb" "\x0e"           
	"\x68" "\x65" "\x6c" "\x6c" "\x6f"       	
	"\x20" "\x77" "\x6f"             	
	"\x72" "\x6c"                	
	"\x64" "\x21" "\x0a"             	
	"\x00"
;

int main()
{
	void (*f)() = code;
	const char* string = "hello, world!\n";
	asm volatile(
		"movq $1, %%rax\n"
		"movq $2, %%rdi\n"
		"movq %0, %%rsi\n"
		"movq $14, %%rdx\n"
		"syscall\n"
		: 
		: "r"(string)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
	asm volatile(
		"xor %%rax, %%rax\n"
		"movb $2, %%al\n"
		"movq %%rax, %%rdi\n"
		"movb $14, %%al\n"
		"movq %%rax, %%rdx\n"
		"movb $1, %%al\n"
		"movq %0, %%rsi\n"
		"syscall\n"
		"nop\n"
		"nop\n"
		"nop\n"
		: 
		: "r"(string)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
	asm volatile(
		"xor %%rax, %%rax\n"
		"movb $2, %%al\n"
		"movq %%rax, %%rdi\n"
		"movb $14, %%al\n"
		"movq %%rax, %%rdx\n"
		"lea 0x01010119(%%rip), %%rax\n"
		"movq %%rax, %%rsi\n"
		"xor %%rax, %%rax\n"
		"mov $0x1010101, %%eax\n"
		"xor %%al, %%al\n"
		"subq %%rax, %%rsi\n"
		"xor %%rax, %%rax\n"
		"movb $1, %%al\n"
		"syscall\n"
		"jmp end;\n"
		".byte 0x68\n" 
		".byte 0x65\n" 
		".byte 0x6c\n" 
		".byte 0x6c\n" 
		".byte 0x6f\n" 
		".byte 0x20\n" 
		".byte 0x77\n" 
		".byte 0x6f\n" 
		".byte 0x72\n" 
		".byte 0x6c\n" 
		".byte 0x64\n" 
		".byte 0x21\n" 
		".byte 0x0a\n" 
		".byte 0x00\n"
		"end: \n"
		: 
		: "r"(string)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
	f();
	return 0;
}
