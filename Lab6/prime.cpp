#include "array.cpp"

int main()
{
	int uv;
	cin >> uv;
	
	prime *p = new prime(uv);
	p->LoadArrayWithPrimes();
	p->print();
	cout << endl;
	
	system("pause");
	return 0;
}


