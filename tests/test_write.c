#include <unistd.h>

int main()
{
	char c = 'c';
	write(1, (void *)c, 1);
}