
namespace rf
{
	mac max(a,b) r_cond(a>b,a,b)
	mac min(a,b) r_cond(a>b,b,a)
	mac abs(a) r_cond(a<0,neg a,a)

	void* find_func(rstr& s)
	{
		return find_func(s.cstr)
	}

	void* find_func(char* p)
	{
		return null
	}

	void* find_dll(char* p)
	{
		return null
	}

	void* get_vclass()
	{
		return null
	}
	
	int lstrlenW(wchar* p)
	{
		push p
		rn invoke lstrlenW
		mov s_ret,eax
	}
	
	FindClose(int handle)
	{
		push handle
		rn invoke FindClose
	}
	
	int FindNextFileW(int handle,void* p)
	{
		push p
		push handle
		rn invoke FindNextFileW
		mov s_ret,eax
	}
	
	int FindFirstFileW(wchar* dir,void* p)
	{
		push p
		push dir
		rn invoke FindFirstFileW
		mov s_ret,eax
	}
	
	int _beginthreadex(void* _Security,int _StackSize,
		void* start,void* _ArgList,int _InitFlag,void* addr)
	{
		push addr
		push _InitFlag
		push _ArgList
		push start
		push _StackSize
		push _Security
		rn invoke _beginthreadex
		add esp,24
		mov s_ret,eax
	}
	
	WaitForSingleObject(int handle,int milliseconds)
	{
		push milliseconds
		push handle
		rn invoke WaitForSingleObject
	}

	bool CloseHandle(void* handle)
	{
		push handle
		rn invoke CloseHandle
		mov s_ret,eax
	}

	void* create_thr(void* start,void* param=null)
	{
		int ret=_beginthreadex(null,0,start,param,0,null)
		if(ret==0||ret==1)
			return null
		return ret.to<void*>
	}
	
	wait_thr(void* addr)
	{
		WaitForSingleObject(addr.toint,0xFFFFFFFF)
	}
	
	int cmd(rstr s)
	{
		return cmd(s.cstr)
	}

	int cmd(char* p)
	{
		push p
		rn invoke system
		add esp,4
		mov s_ret,eax
	}

	srand(int param)
	{
		push param
		rn invoke srand
		add esp,4
	}
	
	int8 time(void* p)
	{
		push p
		rn invoke _time32
		mov s_ret,eax
		mov [ebp+(s_off s_ret+4)],edx
		add esp,4
	}
	
	srand()
	{
		srand(time(null).toint)
	}
	
	int rand()
	{
		rn invoke rand
		mov s_ret,eax
	}
	
	int tick()
	{
		rn invoke GetTickCount
		mov s_ret,eax
	}
	
	sleep(int a)
	{
		push a
		rn invoke Sleep
	}

	print(char* p)
	{
		push p
		rn invoke printf
		add esp,4
	}

	print_l(char* p,int len)
	{
		print(rstr(p,len).cstr)
	}

	int getch()
	{
		rn invoke _getch
		mov s_ret,eax
	}
	
	void* getstdin()
	{
		rn invoke __iob_func
		mov s_ret,eax
	}

	void* getstdout()
	{
		rn invoke __iob_func
		add eax,32
		mov s_ret,eax
	}
	
	//似乎是golink的bug,命令行没有传入正确的参数
	/*int get_argc()
	{
		mov s_ret,[_ARGC]
	}
	
	int* get_argv()
	{
		mov s_ret,[_ARGV]
	}
	
	rbuf<rstr> get_param()
	{
		int argc=get_argc
		int* p=get_argv
		rbuf<rstr> ret
		for i=0;i<argc;i++
			ret.push(rstr((*(p+i)).to<char*>))
		return ret
	}*/
	
	sprintf(char* dst,char* format,int n)
	{
		push n
		push format
		push dst
		rn invoke sprintf
		add esp,12
	}

	sprintf(char* dst,char* format,uint n)
	{
		push n
		push format
		push dst
		rn invoke sprintf
		add esp,12
	}
	
	sprintf8(char* dst,char* format,int8 n)
	{
		lea esi,[ebp+s_off n]
		push [esi+4]
		push [esi]
		push format
		push dst
		rn invoke sprintf
		add esp,16
	}

	sprintf8(char* dst,char* format,double n)
	{
		lea esi,[ebp+s_off n]
		push [esi+4]
		push [esi]
		push format
		push dst
		rn invoke sprintf
		add esp,16
	}

	sscanf(char* src,char* format,void* n)
	{
		push n
		push format
		push src
		rn invoke sscanf
		add esp,12
	}

	char* malloc(int size)
	{
		push size
		rn invoke malloc
		add esp,4
		mov s_ret,eax
	}

	mfree(char* p)
	{
		push p
		rn invoke free
		add esp,4
	}
	
	memset(char* begin,int val,int size)
	{
		push size
		push val
		push begin
		rn invoke memset
		add esp,12
	}
	
	memcpy(char* dst,char* src,int size)
	{
		push size
		push src
		push dst
		rn invoke memcpy
		add esp,12
	}

	strcpy(char* dst,char* src)
	{
		push src
		push dst
		rn invoke strcpy
		add esp,8
	}

	int strcmp(char* a,char* b)
	{
		push b
		push a
		rn invoke strcmp
		add esp,8
		mov s_ret,eax
	}

	int strlen(char* p)
	{
		push p
		rn invoke strlen
		add esp,4
		mov s_ret,eax
	}

	bool is_number(char ch)
	{
		int t=ch.toint
		return t>=`0&&t<=`9
	}
	
	exit(int a)
	{
		push a
		rn invoke exit
		add esp,4
	}
	
	error(char* p="")
	{
		print p
		print "\nerror\n"
		exit(0)
	}

	rstr scanl()
	{
		rstr result
		result.clear();
		char c;
		void* fp=getstdin
		while(1==rff.fread(&c,1,1,fp))
		{
			if(13==c.toint||10==c.toint)
			{
				if(0==result.count())
				{
					continue;
				}
				else
				{
					return result
				}
			}
			result+=c;
		}
		return result;
	}
	
	print(rstr& s)
	{
		print_l s.begin,s.count
	}

	print(uint a)
	{
		print rstr(a).cstr
	}

	print(int a)
	{
		print rstr(a).cstr
	}
	
	print(int8 a)
	{
		print rstr(a).cstr
	}
	
	print(double a)
	{
		print rstr(a).cstr
	}

	printl(rstr& s)
	{
		print_l s.begin,s.count
		print "\n"
	}

	printl(char* p="")
	{
		print p
		print "\n"
	}

	printl(int a)
	{
		print a
		printl
	}

	printl(uint a)
	{
		print a
		printl
	}
	
	printl(int8 a)
	{
		print a
		printl
	}
	
	printl(double a)
	{
		print a
		printl
	}

	enum
	{
		c_call_js,
		c_cp_txt,
		c_find_meta,
		c_find_func,
		c_find_dll,
		c_stdcall_func,
		c_cdecl_func,
		c_get_vclass,

		c_thr_create,
		c_thr_wait,

		c_mu_init,
		c_mu_del,
		c_mu_enter,
		c_mu_leave,

		c_execmd,
		c_srand,
		c_rand,
		c_gettick,
		c_sleep,

		c_puts,
		c_puts_l,
		c_getch,
		c_getstdin,
		c_getstdout,
		c_get_argc,
		c_get_argv,

		c_sprintf,
		c_sprintf8,
		c_sscanf,

		c_malloc,
		c_mfree,
		c_memset,
		c_memcpy,
		
		c_strcpy,
		c_strcmp,
		c_strlen,
		
		c_fopen_w,
		c_fopen,
		c_fclose,
		c_fread,
		c_fwrite,
		c_fseek,
		c_fseek8,
		c_ftell,
		c_ftell8,

		c_s_socket,
		c_s_connect,
		c_s_close,
		c_s_send,
		c_s_recv,
		c_s_bind,
		c_s_listen,
		c_s_accept,
		
		c_gbk_to_utf8,
		c_gbk_to_utf16,
		c_utf8_to_gbk,
		c_utf8_to_utf16,
		c_utf16_to_gbk,
		c_utf16_to_utf8,
		
		c_CloseHandle,
		c_MessageBoxA,
		c_itof8,
	};
}