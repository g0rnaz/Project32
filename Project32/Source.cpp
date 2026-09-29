#include <iostream>
using namespace std;
template<class T>
class matrix
{
	T** p;
	int row, col;
public:
	matrix() // конструктор по умолчанию 
	{
		row = 0;
		col = 0;
		p = new T*[row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
	}
	matrix(int r, int c) // конструктор с параметрами 
	{
		row = r;
		col = c;
		p = new T*[row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
	}
	matrix(const matrix& obj) // конструктор копирования 
	{
		row = obj.row;
		col = obj.col;
		p = new T*[row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = obj.p[i][j];
			}
		}
	}
	matrix(matrix&& obj) // конструктор переноса 
	{
		row = obj.row;
		col = obj.col;
		obj.row = 0;
		obj.col = 0;
		p = obj.p;
		obj.p = nullptr;
	}
	~matrix() // деструктор 
	{
		for (int i = 0; i < row; i++)
		{
			delete[] p[i];
		}
		delete[]p;
	}
		matrix& operator = (const matrix& obj) {

	}
	// присваивания с копированием 
	matrix& operator = (matrix&& obj) // перегруженный оператор  
	{
		if (p != nullptr) {
			for (int i = 0; i < row; i++)
			{
				delete[] p[i];
			}
			delete[]p;
		}
		row = obj.row;
		col = obj.col;
		p = new T *[row];
		for (int i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = obj.p[i][j];
			}
		}
		return *this;
	}
	// присваивания с переносом 
	// увеличение на 1 каждого элемента матрицы 
	matrix& operator ++() // префиксный инкремент 
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j]++;
			}
		}
		return *this;
	}
	matrix operator ++(int) // постфиксный инкремент 
	{
		matrix temp = p;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j]++;
			}
		}
		return temp;
	}
	// уменьшение на 1 каждого элемента матрицы 
	matrix& operator --() // префиксный декремент 
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j]--;
			}
		}
		return *this;
	}
	matrix operator --(int) // постфиксный декремент 
	{
		matrix temp = p;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j]--;
			}
		}
		return temp;
	}
	matrix& operator+(matrix& obj) // сложение матриц 
	{
		if (row == obj.row && col == obj.col)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					p[i][j] += obj.p[i][j];
				}
			}
		}
		return *this;
	}
	matrix operator*(matrix& obj) // умножение матриц 
	{
		if (col == obj.row) {
			matrix temp;
			temp.row = row;
			temp.col = obj.col;
			temp.p = new T * [row];
			for (int i = 0; i < row; i++)
				temp.p[i] = new T[obj.col];
			for (int i = 0; i < row; i++)
			{
				for (int k = 0; k < obj.col; k++)
				{
					int temp1 = 0;
					for (int j = 0; j < col; j++)
					{
						temp1 += p[i][j] * obj.p[j][k];
					}
					temp.p[i][k] = temp1;
				}
			}
			cout << temp;
			return temp;
		}
		else {
			matrix t = *this;
			return t;
		}
		//return *this;
	}
	T& operator()(int r, int c) // установка / получение значения  
	{
		if (r >= 0 && r < row && c >= 0 && c < col) {
			cout << p[r][c] << endl;
			cin >> p[r][c];
		}
	}
	// элемента матрицы 
	friend ostream& operator << (ostream& os, matrix& obj)
	{
		for (int i = 0; i < obj.row; i++)
		{
			for (int j = 0; j < obj.col; j++)
			{
				os << obj.p[i][j] << "\t";
			}
			os << endl;
		}
		os << endl;
		return os;
	}
	// печать матрицы 
	friend istream& operator >> (istream& is, matrix& obj)
	{
		for (int i = 0; i < obj.row; i++)
		{
			for (int j = 0; j < obj.col; j++)
			{
				is >> obj.p[i][j];
			}
		}
		return is;
	}
	// ввод данных в матрицу 
	void init() {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = rand()%10;
			}
		}
	}
};
int main() {
	srand(time(0));
	matrix<int>obj(1, 2);
	obj.init();
	cout << obj;
	matrix<int>obj1(2,1);
	obj1.init();
	cout << obj1;
	obj = obj * obj1;
	cout << obj;
}
