/*
指针和引用
*/

void main()
{
	a=2
	int& b
	lea b,[ebp+s_off a]

	a.print
	b.print
	
	func(a)
	a.print

	a=3
	p=&a
	a.print
	p->print

	a=4
	p=&a
	int** pp=&p
	puts *(*pp)

	rp<rp<rp<int>>> ppp=&pp
	puts *(*(*ppp))
}

void func(int& n)
{
	n=5
}