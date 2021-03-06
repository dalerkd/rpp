
class int
{
	rd4 m_in;

	enum
	{
		c_min=4294967295,
		c_max=0x7fffffff
	}

	~int()
	{
	}

	int()
	{
	}

	int(int a)
	{
		mov esi,[esp+4]
		mov [esi],[esp+8]
		//mov esi,this
		//mov [esi],a
	}

	int(int& a)
	{
		mov edi,[esp+4]
		mov esi,[esp+8]
		mov [edi],[esi]
		//mov edi,this
		//mov esi,a
		//mov [edi],[esi]
	}

	int(char a)
	{
		mov edi,this
		mov [edi],0
		mov1 [edi],a
	}

	int(ushort a)
	{
		mov edi,this
		mov [edi],0
		mov1 [edi],a
		mov1 [edi+1],[ebp+(s_off a+1)]
	}

	TYPE to<TYPE>()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	ushort toushort()
	{
		mov esi,this
		mov1 s_ret,[esi]
		mov1 [ebp+(s_off s_ret+1)],[esi+1]
	}

	int toint()
	{
		mov esi,this
		mov s_ret,[esi]
	}

	uint touint()
	{
		mov esi,this
		mov s_ret,[esi]
	}
	
	int8 toint8()
	{
		int8 ret(this)
		return ret
	}
	
	double todouble()
	{
		double ret(this)
		return ret
	}

	rstr torstr()
	{
		rstr ret(this)
		return ret
	}
	
	char tochar()
	{
		mov esi,this
		mov1 s_ret,[esi]
	}

	operator=(int a)
	{
		mov esi,[esp+4]
		mov [esi],[esp+8]
		//mov esi,this
		//mov [esi],a
	}

	operator=(int& a)
	{
		mov edi,[esp+4]
		mov esi,[esp+8]
		mov [edi],[esi]
		//mov edi,this
		//mov esi,a
		//mov [edi],[esi]
	}

	operator=(uint a)
	{
		mov esi,this
		mov [esi],a
	}

	friend operator<->(int& a,int& b)
	{
		c=a
		a=b
		b=c
	}

	friend int& operator=>(int a,int& this)
	{
		mov esi,this
		mov [esi],a
		return this
	}

	operator+=(int a)
	{
		mov esi,[esp+4]
		add [esi],[esp+8]
		//mov esi,this
		//add [esi],a
	}

	operator-=(int a)
	{
		mov esi,[esp+4]
		sub [esi],[esp+8]
		//mov esi,this
		//sub [esi],a
	}

	operator*=(int a)
	{
		mov esi,[esp+4]
		imul [esi],[esp+8]
		//mov esi,this
		//imul [esi],a
	}
	
	operator/=(int a)
	{
		mov esi,[esp+4]
		idiv [esi],[esp+8]
		//mov esi,this
		//idiv [esi],a
	}
	
	operator%=(int a)
	{
		mov esi,[esp+4]
		imod [esi],[esp+8]
		//mov esi,this
		//imod [esi],a
	}

	friend int operator neg(int a)
	{
		mov esi,0
		sub esi,[esp+4]
		mov [esp+8],esi
		//mov esi,0
		//sub esi,a
		//mov s_ret,esi
		//mov esi,a
		//bnot esi
		//add esi,1
		//mov s_ret,esi
	}

	operator++()
	{
		mov esi,[esp+4]
		add [esi],1
		//mov esi,this
		//add [esi],1
	}

	operator--()
	{
		mov esi,[esp+4]
		sub [esi],1
		//mov esi,this
		//sub [esi],1
	}

	friend int operator+(int a,int b) 
	{
		add [esp+4],[esp+8]
		mov [esp+12],[esp+4]
		//add a,b
		//mov s_ret,a
	}

	friend int operator-(int a,int b)
	{
		sub [esp+4],[esp+8]
		mov [esp+12],[esp+4]
		//sub a,b
		//mov s_ret,a
	}

	friend int operator*(int a,int b)
	{
		imul [esp+4],[esp+8]
		mov [esp+12],[esp+4]
		//imul a,b
		//mov s_ret,a
	}

	friend int operator/(int a,int b)
	{
		idiv [esp+4],[esp+8]
		mov [esp+12],[esp+4]
		//idiv a,b
		//mov s_ret,a
	}

	friend int operator%(int a,int b)
	{
		imod [esp+4],[esp+8]
		mov [esp+12],[esp+4]
		//imod a,b
		//mov s_ret,a
	}

	friend bool operator<(int a,int b)
	{
		clsb [esp+4],[esp+8]
		mov [esp+12],ebx
		//clsb a,b
		//mov s_ret,ebx
	}

	friend bool operator<=(int a,int b)
	{
		clesb [esp+4],[esp+8]
		mov [esp+12],ebx
		//clesb a,b
		//mov s_ret,ebx
	}

	friend bool operator==(int a,int b)
	{
		cesb [esp+4],[esp+8]
		mov [esp+12],ebx
		//cesb a,b
		//mov s_ret,ebx
	}

	friend bool operator!=(int a,int b)
	{
		cnesb [esp+4],[esp+8]
		mov [esp+12],ebx
		//cnesb a,b
		//mov s_ret,ebx
	}

	friend bool operator>(int a,int b)
	{
		clsb [esp+8],[esp+4]
		mov [esp+12],ebx
		//clsb b,a
		//mov s_ret,ebx
		//return b<a;
	}

	friend bool operator>=(int a,int b)
	{
		clesb [esp+8],[esp+4]
		mov [esp+12],ebx
		//clesb b,a
		//mov s_ret,ebx
		//return b<=a;
	}

	friend bool operator!(int a)
	{
		cesb [esp+4],0
		mov [esp+8],ebx
		//cesb a,0
		//mov s_ret,ebx
	}

	friend bool operator&&(int a,int b)
	{
		cesb [esp+4],0
		jebxz next
		mov [esp+12],0
		reti 8
next:
		cnesb [esp+8],0
		mov [esp+12],ebx
		/*cesb a,0
		jebxz next
		mov s_ret,0
		pop ebp
		reti 8
next:
		cnesb b,0
		mov s_ret,ebx*/
		/*if(!a)
		{
			return false;
		}
		elif(!b)
		{
			return false;
		}
		return true;*/
	}

	friend bool operator||(int a,int b)
	{
		cesb [esp+4],0
		jebxnz next
		mov [esp+12],1
		reti 8
next:
		cnesb [esp+8],0
		mov [esp+12],ebx
		/*cesb a,0
		jebxnz next
		mov s_ret,1
		pop ebp
		reti 8
next:
		cnesb b,0
		mov s_ret,ebx*/
		/*if(a)
		{
			return true;
		}
		elif(b)
		{
			return true;
		}
		return false;*/
	}
	
	int abs()
	{
		if this<0
			return -this
		return this
	}

	set(int a)
	{
		mov esi,this
		mov [esi],a
	}

	clear()
	{
		mov esi,this
		mov [esi],0
	}

	bool empty()
	{
		return 0==this
	}

	print()
	{
		rf.print this
	}

	printl()
	{
		rf.printl this
	}
};