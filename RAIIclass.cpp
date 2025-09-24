#include<iostream>

using namespace std;

class Wrapper {
private:
	int* mem;

public:
	Wrapper(int* a) : mem(a) {
		cout << "inside ctor\n";
	}

	~Wrapper() {
		cout << "dtor\n";
		delete mem;
	}
};

/*

int main()
{
	// raw pointer 
	int *a = new int(10);
	return 0;

	// calls constructor and when obj gets out of scope destructor is called! Memory is getting free [Wrapper obj is in the stack memory]
	Wrappper obj(new int(10));
	return 0; 

}



*/