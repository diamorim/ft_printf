int ft_printhex(unsigned int n)
{
	int count;

	count = 0;
    if (n >= 16)
        count += ft_printhex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
	count++;
	return count;
}
int ft_print_caphex(unsigned int n)
{
	int count;

	count = 0;
    if (n >= 16)
        count += ft_print_caphex(n / 16);
    write(1, &"0123456789ABCDEF"[n % 16], 1);
	count++;
	return count;
}