
void main()
{
	int a
	int b
	[int = [a 1]]
	[int = [b 2]]
	
	[rf printl [[int + [a b]]]]
	rf.printl(a+b)
	
	[rf printl [[int ! [a]]]]
	
	[main func [2]].printl
}

int func(int a)
{
	return a*2
}