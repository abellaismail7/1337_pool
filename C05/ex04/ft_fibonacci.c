
int ft_fibonacci(int index)
{
	if(index < 0)
		return -1;
	if(index == 0)
		return 0;

	return ft_fibonacci(index -1);
}

int main()
{
	return ft_fibonacci(7);


}
