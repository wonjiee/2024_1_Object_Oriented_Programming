#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, size = 0;
	int* arr = nullptr;

	void resize(int new_capacity) {
		int* new_arr = new int[new_capacity];
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[] arr;
		arr = new_arr;
		capacity = new_capacity;

	}
public:
	void insert(int k) {
		if (capacity == size) {
			if (capacity > 0) {
				resize(capacity * 2);
				arr[size] = k;
				size++;

			}
			else {
				resize(1);
				arr[0] = k;
				size = 1;
			}
		}
		else {
			arr[size] = k;
			size++;
		}
		for (int i = 0; i < size; i++)
			for (int j = i + 1; j < size; j++)
				if (arr[j] < arr[i]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
	}

	int getsize() {
		return size;
	}

	int &operator[](int a){
		return arr[a];
	}

	bool remove_by_val(int a) {
		int i = 0;
		for (i = 0; i < size; i++)
			if (arr[i] == a)
				break;
		if (i < size) {
			for (int j = i; j < size - 1; j++)
				arr[j] = arr[j + 1];
			size--;
			return true;

		}
		return false;
	}
	bool remove_by_index(int a) {
		if (a >= 0 && a < size) {
			for (a; a < size - 1; a++)
				arr[a] = arr[a + 1];
			size--;
			return true;
		}
		else
			return false;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	OrderedVecInt vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = rand() % 1000;
		vec.insert(k); 
	}
	
	for (int i = 0; i < vec.getsize(); i++)
		cout << vec[i] << " "; 
	cout << endl;

	if (vec.remove_by_val(vec[2]))
		cout << "Remove done" << endl;
	else
		cout << "Remove failed" << endl;
	if (vec.remove_by_index(4))
		cout << "RemoveIndex done" << endl;
	else
		cout<< "RemoveIndex failed" << endl;
	for(int i =0; i < vec.getsize(); i++)
		vec[i] -=10;
	for (int i =0; i < vec.getsize(); i++)
		cout << vec[i] <<" ";
	cout << endl;
	return 0;
}