//双向链表

template<typename T>
struct rlist_i
{
	T val;
	rlist_i<T>* prev;
	rlist_i<T>* next;
};

template<typename T>
struct rlist
{
	rlist_i<T>* m_front;
	rlist_i<T>* m_rear;
	int m_count;

	~rlist<T>()
	{
		clear();
	}

	rlist<T>()
	{
		init();
	}
	
	rlist<T>(rlist<T>& a)
	{
		init();
		for p=a.begin;p!=a.end;p=a.next(p)
			this.push(*p)
	}
	
	operator=(rlist<T>& a)
	{
		clear();
		for p=a.begin;p!=a.end;p=a.next(p)
			this.push(*p)
	}
	
	T& operator[](int n)
	{
		T* p=index(n);
		return *p;
	}

	void init()
	{
		m_front=NULL;
		m_rear=NULL;
		m_count=0;
	}

	void clear()
	{
		while(m_front)
		{
			m_rear=m_front->next;
			r_delete<rlist_i<T>>m_front;
			m_front=m_rear;
		}
		init();
	}

	rbool empty()
	{
		return m_count==0;
	}

	int count()
	{
		return m_count;
	}

	void push(const T& a)
	{
		rlist_i<T>* p=r_new<rlist_i<T>>1;
		p->val=a;
		p->next=NULL;
		p->prev=m_rear;
		if (empty())
		{
			m_front=p;
			m_rear=p;
		}
		else
		{
			m_rear->next=p;
			m_rear=p;
		}
		m_count++;
	}
	
	void push(T a)
	{
		rlist_i<T>* p=r_new<rlist_i<T>>1;
		p->val=a;
		p->next=NULL;
		p->prev=m_rear;
		if (empty())
		{
			m_front=p;
			m_rear=p;
		}
		else
		{
			m_rear->next=p;
			m_rear=p;
		}
		m_count++;
	}

	T pop()
	{
		m_count--;
		rlist_i<T>* p=m_rear;
		T ret=p->val;
		m_rear=p->prev;
		if (m_rear)
		{
			m_rear->next=NULL;
		}
		if (empty())
		{
			m_front=NULL;
		}
		r_delete<rlist_i<T>>p;
		return ret;
	}

	void push_front(const T& a)
	{
		rlist_i<T>* p=r_new<rlist_i<T>>1;
		p->val=a;
		p->next=m_front;
		p->prev=NULL;
		if (empty())
		{
			m_front=p;
			m_rear=p;
		}
		else
		{
			m_front->prev=p;
			m_front=p;
		}
		m_count++;
	}
	
	void push_front(T a)
	{
		rlist_i<T>* p=r_new<rlist_i<T>>1;
		p->val=a;
		p->next=m_front;
		p->prev=NULL;
		if (empty())
		{
			m_front=p;
			m_rear=p;
		}
		else
		{
			m_front->prev=p;
			m_front=p;
		}
		m_count++;
	}

	T pop_front()
	{
		m_count--;
		rlist_i<T>* p=m_front;
		T ret=p->val;
		m_front=p->next;
		if (m_front)
		{
			m_front->prev=NULL;
		}
		if (empty())
		{
			m_rear=NULL;
		}
		r_delete<rlist_i<T>>p;
		return ret;
	}
	
	//前插
	void insert(T* pos,const T& a)
	{
		if (pos==NULL)
		{
			push(a);
			return;
		}
		rlist_i<T>* cur=r_to_p<rlist_i<T>*>pos;
		rlist_i<T>* p=r_new<rlist_i<T>>1;
		p->val=a;
		p->next=cur;
		p->prev=cur->prev;
		if (cur->prev)
		{
			cur->prev->next=p;
		}
		cur->prev=p;
		if (p->prev==NULL)
		{
			m_front=p;
		}
		if (p->next==NULL)
		{
			m_rear=p;
		}
		m_count++;
	}

	void insert(int pos,const T& a)
	{
		insert(index(pos),a);
	}

	void erase(T* pos)
	{
		if (pos==NULL)
		{
			return;
		}
		rlist_i<T>* cur=r_to_p<rlist_i<T>*>pos;
		if (cur->prev==NULL)
		{
			m_front=cur->next;
		}
		if (cur->next==NULL)
		{
			m_rear=cur->prev;
		}
		if (cur->prev)
		{
			cur->prev->next=cur->next;
		}
		if (cur->next)
		{
			cur->next->prev=cur->prev;
		}
		r_delete<rlist_i<T>>cur;
		m_count--;
	}

	void erase(int pos)
	{
		erase(index(pos));
	}

	T* index(int n)
	{
		rlist_i<T>* p=m_front;
		for (;n;n--)
		{
			if (p==NULL)
			{
				return null;
			}
			p=p->next;
		}
		return r_to_p<T*>p;
	}

	T* begin()
	{
		return r_to_p<T*>m_front;
	}

	T* end()
	{
		return null;
	}

	T* next(void* p)
	{
		q=r_to_p<rlist_i<T>*>(p)->next
		return r_to_p<T*>q
	}

	T* prev(void* p)
	{
		q=r_to_p<rlist_i<T>*>(p)->prev
		return r_to_p<T*>q
	}
};
