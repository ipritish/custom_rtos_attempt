#include<stdint.h>

#define GPIO3DATA 0x50033FFC
#define GPIO3DIR 0x50038000

extern stack_entry;
int main(void);

const void *vectors[128] __attribute__ ((section(".irq_vectors"))) =
{
	&stack_entry,
	main,	
};

int main()
{
	while(1);
	return 0;
}
