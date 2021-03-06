#include <iostream>


template <typename T>
class SmartPointers {
public:
	SmartPointers(T *ptr) {
		this->ptr = ptr;
	}

	~SmartPointers() {
		delete ptr;
	}
	T* operator->() {
		return ptr;
	}
	T& operator* () {
		return *ptr;
	}
private:
	T *ptr;

};

class AnyClass {
public:
	int * arr = new int[size];
	void init() {
		for (int i = 0; i < size; ++i) {
			arr[i] = i;
			std::cout << arr[i] << std::endl;
		}
	}

	~AnyClass() {
		delete[] arr;
	}
private:
	const int size = 10;
};

int main()
{
	SmartPointers<int> pointer = new int(5);
	std::cout << *pointer << std::endl;
	std::cout << std::endl;

	SmartPointers<AnyClass> s_pointer(new AnyClass());
	s_pointer->init();
}



