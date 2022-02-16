#include <iostream>

using namespace std;

template <typename T>
class dynamicArray
{
	public:
	
	T* array = new T[1];
	int size;
	int capacity = 1;
	dynamicArray() : size(0) {}
	dynamicArray(int capacity) : size(0) {resize(capacity);}
	~dynamicArray<T>(){
		delete[] array;
	}		
	void resize(int newCapacity)
	{
		T* newArray = new T[newCapacity];
		
		for(int i=0;i<size;++i)
			newArray[i] = array[i];
		
		if(array)
			delete[] array;
		
		array = newArray;
		capacity = newCapacity;
	}
	
	void append(T value)
	{
		if(size == capacity)
			resize(2*capacity);
		
		array[size++] = value;
	}
	
	void print_array()
	{
		cout <<"[";
		for(int i=0;i<size;++i)	
		{
			cout << array[i];
			if(i != size -1) cout << ", ";
		}
		cout <<"]\n";
	}
};
	

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dynamicArray<int> da;
	
	//append testCase
	da.append(1);
	da.append(2);
	da.append(5);
	da.append(4);
	
	
	//print testCase
	da.print_array();
	
}