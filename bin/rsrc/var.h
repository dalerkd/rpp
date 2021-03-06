
import varf.h

class var
{
	void* m_p
	
	~var()
	{
		clear
	}
	
	var()
	{
		m_p=null
	}
	
	var(var& a)
	{
		m_p=null
		set_var(a)
	}
	
	var(int a)
	{
		set_int(a)
	}
	
	var(double a)
	{
		set_double(a)
	}
	
	var(void* a)
	{
		set_func(a)
	}
	
	var(rstr& a)
	{
		set_rstr(a)
	}
	
	void clear()
	{
		if m_p==null
			return
		varf.delete(m_p)
		m_p=null
	}
	
	int toint()
	{
		return varf.toint(m_p)
	}
	
	double todouble()
	{
	}
	
	void* tofunc()
	{
		return varf.toint(m_p).to<void*>
	}
	
	rstr torstr()
	{
		rstr buf
		buf.set_size(varf.get_rstr(m_p,null))
		varf.get_rstr(m_p,buf.begin)
		return buf
	}
	
	set_int(int a)
	{
		if m_p==null
			m_p=varf.new
		varf.set_int(m_p,a)
	}
	
	set_double(double a)
	{
		if m_p==null
			m_p=varf.new
		varf.set_double(m_p,a)
	}
	
	set_func(void* a)
	{
		if m_p==null
			m_p=varf.new
		varf.set_func(m_p,a)
	}
	
	set_var(var& a)
	{
		if m_p==null
			m_p=varf.new
		varf.set_var(m_p,a.m_p)
	}
	
	set_rstr(rstr& a)
	{
		if m_p==null
			m_p=varf.new
		varf.set_rstr(m_p,a.begin,a.size)
	}
	
	operator=(void* a)
	{
		set_func(a)
	}
	
	operator=(int a)
	{
		set_int(a)
	}
	
	operator=(double a)
	{
		set_double(a)
	}
	
	operator=(rstr& a)
	{
		set_rstr(a)
	}
	
	operator=(var& a)
	{
		set_var(a)
	}
	
	operator+=(var& a)
	{
		this=this+a
	}
	
	operator-=(var& a)
	{
		this=this-a
	}
	
	operator*=(var& a)
	{
		this=this*a
	}
	
	operator/=(var& a)
	{
		this=this/a
	}
	
	operator%=(var& a)
	{
		this=this%a
	}
	
	operator++()
	{
		set_int(this.toint()+1)
	}
	
	operator--()
	{
		set_int(this.toint()-1)
	}
	
	friend var operator+(var& a,var& b)
	{
		s_ret.m_p=varf.add(a.m_p,b.m_p)
	}
	
	friend var operator-(var& a,var& b)
	{
		s_ret.m_p=varf.minus(a.m_p,b.m_p)
	}
	
	friend var operator*(var& a,var& b)
	{
		s_ret.m_p=varf.star(a.m_p,b.m_p)
	}
	
	friend var operator/(var& a,var& b)
	{
		s_ret.m_p=varf.divide(a.m_p,b.m_p)
	}
	
	friend var operator%(var& a,var& b)
	{
		s_ret.m_p=varf.modulo(a.m_p,b.m_p)
	}
	
	var sub(int begin,int end=count)
	{
		s_ret.m_p=varf.sub(m_p,begin,end)
	}
	
	int count()
	{
		return varf.count(m_p)
	}
	
	//json序列化
	var stringify()
	{
		s_ret.m_p=varf.stringify(this.m_p)
	}
	
	var parse()
	{
		s='friend var _SELF(){a='+torstr+';return a}'
		f=s.cstr
		void* temp
		sub esp,4
		mov ebx,f
		calle rf.c_eval_txt
		mov temp,[esp]
		add esp,4
		s_ret.m_p=temp
	}
	
	//返回bool效率更高，返回var通用性更好
	friend bool operator==(var& a,void* b)
	{
		return varf.equal(a.m_p,b)
	}
	
	friend bool operator==(void* a,var& b)
	{
		return varf.equal(a,b.m_p)
	}
	
	friend bool operator==(var& a,var& b)
	{
		return varf.equal(a.m_p,b.m_p)
	}
	
	friend bool operator!=(var& a,void* b)
	{
		return !varf.equal(a.m_p,b)
	}
	
	friend bool operator!=(void* a,var& b)
	{
		return !varf.equal(a,b.m_p)
	}
	
	friend bool operator!=(var& a,var& b)
	{
		return !varf.equal(a.m_p,b.m_p)
	}
	
	friend bool operator<(var& a,var& b)
	{
		return varf.less(a.m_p,b.m_p)
	}
	
	friend bool operator>(var& a,var& b)
	{
		return varf.less(b.m_p,a.m_p)
	}
	
	friend bool operator<=(var& a,var& b)
	{
		return !(a>b)
	}
	
	friend bool operator>=(var& a,var& b)
	{
		return !(a<b)
	}
	
	var& operator[](char* name)
	{
		return varf.quote_attr(this.m_p,name)
	}
	
	var& operator[](rstr& name)
	{
		return varf.quote_attr(this.m_p,name.cstr)
	}
	
	void print()
	{
		torstr.print
	}
	
	void printl()
	{
		torstr.printl
	}
	
	bool have(rstr& name)
	{
		return varf.have(this.m_p,name.cstr)
	}
	
	int type()
	{
		int* p=m_p
		return *(p+1)
	}
	
	rstr typestr()
	{
		int a=type
		if(a==varf.c_void)
		{
			return 'void';
		}
		elif(a==varf.c_int)
		{
			return 'int';
		}
		elif(a==varf.c_double)
		{
			return 'double';
		}
		elif(a==varf.c_rstr)
		{
			return 'rstr';
		}
		elif(a==varf.c_dic)
		{
			return 'dic';
		}
		elif(a==varf.c_func)
		{
			return 'function';
		}
		else
		{
			return 'error';
		}
	}
}

/*class rt
{
	int m_type
	void* m_p

	enum
	{
		c_null
		c_int
		c_rstr
	}

	~rt
	{
		if(m_p!=null)
		{
			if(m_type==c_int)
			{
				r_delete<int> m_p
			}
			elif(m_type==c_rstr)
			{
				r_delete<rstr> m_p
			}
			m_p=null
		}
		m_type=c_null
	}

	rt
	{
		m_type=c_null
		m_p=null
	}

	rt(int a)
	{
		m_p=r_new<int>1
		*m_p.to<int*> =a
		m_type=c_int
	}

	rt(rstr& a)
	{
		m_p=r_new<rstr>1
		*m_p.to<rstr*> =a
		m_type=c_rstr
	}

	rt(rt& a)
	{
		if(a.m_type==c_int)
		{
			rt.rt(this,a.toint)
		}
		elif(a.m_type==c_rstr)
		{
			rt.rt(this,a.torstr)
		}
	}

	operator=(rt& a)
	{
		rt.~rt(this)
		if(a.m_type==c_int)
		{
			this.rt(a.toint)
		}
		elif(a.m_type==c_rstr)
		{
			rt.rt(this,a.torstr)
		}
	}

	operator=(int a)
	{
		this.~rt()
		this.rt(a)
	}

	operator=(rstr a)
	{
		this.~rt()
		this.rt(a)
	}

	int toint()
	{
		int ret=0
		if(m_type==c_int)
		{
			ret=*m_p.to<int*>
		}
		return ret;
	}

	rstr torstr()
	{
		rstr ret
		if(m_type==c_rstr)
		{
			ret=*m_p.to<rstr*>
		}
		return ret;
	}

	friend rt operator+(rt& a,rt& b)
	{
		rt ret;
		if(a.m_type!=b.m_type)
		{
			return ret;
		}
		if(c_int==a.m_type)
		{
			ret.~rt()
			ret.rt(a.toint+b.toint)
		}
		elif(c_rstr==a.m_type)
		{
			ret.~rt()
			ret.rt(a.torstr+b.torstr)
		}
		return ret
	}
}*/