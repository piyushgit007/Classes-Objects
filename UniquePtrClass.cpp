#include<iostream>

using namespace std;

template<typename T>
class uniqueptr {
private :
	T* res;

public:

	uniqueptr(T* a = nullptr) : res(a)
	{
		cout << "ctor";
	}

	uniqueptr(const uniqueptr<T>& ptr) = delete;
	uniqueptr& operator=(const uniqueptr<T>& ptr) = delete;

	// move copy constructor
	uniqueptr(uniqueptr<T>&& ptr)
	{
		res = ptr.res;
		ptr.res = nullptr; 
	}

	// move copy assignment operator
	uniqueptr& operator=(uniqueptr<T>&& ptr)
	{
		if (this != &ptr)
		{
			if (res)
			{
				delete res;
			}
			res = ptr.res;
			ptr.res = nullptr;
		}
		return *this;
	}
	
	//Think of it as “give me the pointer so I can use -> on it.”
	T* operator->() {
		return res;
	}

	// Think of it as “give me the actual object, not the pointer.”
	T& operator*() {
		return *res;
	}

	T* get()
	{
		return res;
	}

	void reset(T* newres = nullptr)
	{
		if (res)
		{
			delete res;
		}
		res = newres;
	}

	~uniqueptr() {
		if (res)
		{
			delete res;
			res = nullptr;
		}
	}


};

/*


1️) T* operator->()
T* operator->() { return res; }


res is already a pointer to T.

operator->() is used when you want to call members of the object like a pointer:

struct Foo { void func() { std::cout << "Hi"; } };
UniquePtr<Foo> ptr(new Foo);
ptr->func();  // works because operator->() returns a pointer to Foo


Return type: T* (a pointer to the object).

Think of it as “give me the pointer so I can use -> on it.”

2️) T& operator*()
T& operator*() { return *res; }


*res dereferences the pointer → gives the object itself.

Now you have direct access to the object, like this:

struct Foo { void func() { std::cout << "Hi"; } };
UniquePtr<Foo> ptr(new Foo);
(*ptr).func();  // works because operator*() returns a reference to Foo


Return type: T& (reference to the object).

Think of it as “give me the actual object, not the pointer.”


int &y = *a;






int main()
{
	uniqueptr<int> ptr1(new int(2));
	//uniqueptr<int> ptr2(ptr1);    // compilation error
	//uniqueptr<int> ptr3 = ptr1;  // compilation error
	uniqueptr<int> ptr4(new int(500));
	//ptr4 = ptr3; // compilation error
	uniqueptr<int> ptr3 = std::move(ptr1);
	ptr4 = std::move(ptr3);


	//ptr1->func();
	cout << *ptr1;
	ptr1.get();
	ptr1.reset(new int (30));




}*/