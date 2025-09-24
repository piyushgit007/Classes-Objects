#include<iostream>
using namespace std;

class Car {
	private:
		string brand;
		int year;

	public:

		//default constructor

		Car()
		{
			brand = "";
			year = 2025;
		}

		Car(string brand, int year)
		{
			this->brand = brand;
			this->year = year;
		}
		
		Car(const Car& obj)
		{
			brand = obj.brand;
			year = obj.year;
		}

		Car& operator=(const Car& obj)
		{
			if (this == &obj)
			{
				return *this;
			}

			brand = obj.brand;
			year = obj.year;

			return *this;
		}

};