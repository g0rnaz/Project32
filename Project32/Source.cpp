#include <iostream>
using namespace std;
class point {
	int x;
	int y;
public:
	point() {
		x = 0;
		y = 0;
	}
	point(int a, int b) {
		x = a;
		y = b;
	}
	point& operator + (point& obj) {
		x += obj.x;
		y += obj.y;
		return *this;
	}
	point& operator - (point& obj) {
		x -= obj.x;
		y -= obj.y;
		return *this;
	}
	point& operator * (point& obj) {
		x *= obj.x;
		y *= obj.y;
		return *this;
	}
	point& operator / (point& obj) {
		x /= obj.x;
		y /= obj.y;
		return *this;
	}
	point& operator += (point& obj) {
		x += obj.x;
		y += obj.y;
		return *this;
	}
	point& operator -= (point& obj) {
		x -= obj.x;
		y -= obj.y;
		return *this;
	}
	point& operator *= (point& obj) {
		x *= obj.x;
		y *= obj.y;
		return *this;
	}
	point& operator /= (point& obj) {
		x /= obj.x;
		y /= obj.y;
		return *this;
	}
	friend istream& operator >> (istream& is, point& obj)
	{
		is >> obj.x >> obj.y;
		return is;
	}
	friend ostream& operator << (ostream& os, point& obj)
	{
		os << obj.x << " " << obj.y;
		return os;
	}
};
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
		matrix& operator = ( matrix& obj) {
			if (p != nullptr) {
				for (int i = 0; i < row; i++)
				{
					delete[] p[i];
				}
				delete[]p;
			}
			row = obj.row;
			col = obj.col;
			p = new T * [row];
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
	matrix& operator*(matrix& obj) // сложение матриц 
	{
		if (row == obj.row && col == obj.col)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					p[i][j] *= obj.p[i][j];
				}
			}
		}
		return *this;
	}
	matrix& operator-(matrix& obj) // сложение матриц 
	{
		if (row == obj.row && col == obj.col)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					p[i][j] -= obj.p[i][j];
				}
			}
		}
		return *this;
	}
	matrix& operator/(matrix& obj) // сложение матриц 
	{
		if (row == obj.row && col == obj.col)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					p[i][j] /= obj.p[i][j];
				}
			}
		}
		return *this;
	}
	T& operator()(int r, int c, point& obj) // установка / получение значения  
	{
		if (r >= 0 && r < row && c >= 0 && c < col) {
			p[r][c] = obj;
			cout << p[r][c] << endl;
			
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
	int max() {
		int max=p[0][0];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (p[i][j] > max)
				{
					max = p[i][j];
				}
			}
		}
		return max;
	}
	int min() {
		int min = p[0][0];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (p[i][j] < min)
				{
					min = p[i][j];
				}
			}
		}
		return min;
	}
	void init(int)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = point(rand() % 10, rand() % 10);
			}
		}
	}
};
int main() {
	srand(time(0));
	matrix<point>obj(1, 2);
	obj.init(1);
	cout << obj;
	matrix<point>obj1 = obj;
	obj = obj1 + obj;
	cout << obj;
}
