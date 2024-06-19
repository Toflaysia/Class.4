#include <iostream>

using namespace std;

class Color {
public:
	int r;
	int g;
	int b;

	Color() {
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	Color(int r, int g, int b) {
		check(r, g, b);
		this->r = r;
		this->g = g;
		this->b = b;
	}
	void check(int& r, int& g, int& b) {
		while (r <0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
			if (r > 255) {
				cout << "Некорректный ввод числа. Перезапишите число r от 0 до 255" << endl;
				cin >> r;
			}
			if (r < 0) {
				cout << "Некорректный ввод числа. Перезапишите число r от 0 до 255" << endl;
				cin >> r;
			}
			if (g > 255) {
				cout << "Некорректный ввод числа. Перезапишите число g от 0 до 255" << endl;
				cin >> g;
			}
			if (g < 0) {
				cout << "Некорректный ввод числа. Перезапишите число g от 0 до 255" << endl;
				cin >> g;
			}
			if (b > 255) {
				cout << "Некорректный ввод числа. Перезапишите число b от 0 до 255" << endl;
				cin >> b;
			}
			if (b < 0) {
				cout << "Некорректный ввод числа. Перезапишите число b от 0 до 255" << endl;
				cin >> b;
			}
		}
	}
	friend ostream& operator << (ostream& stream, const Color& a) {        //перегрузка оператора вывода
		stream << a.r << "," << a.g << "," << a.b;

		return stream;
	}

	friend istream& operator >> (istream& in, Color& a) {                  //перегрузка оператора ввода
		int r;
		int g;
		int b;
		in >> r >> g >> b;
		a.check(r, g, b);
		a.r = r;
		a.g = g;
		a.b = b;
		return in;
	}
	bool operator == (const Color& a) {
		if (this->r == a.r && this->g == a.g && this ->b == a.b) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator != (const Color& a) {
		if (this->r != a.r || this->g != a.g || this->b != a.b) {
			return true;
		}
		else {
			return false;
		}
	}
};






int main()
{	
	setlocale(LC_ALL, "ru");
	Color a;
	Color b;
	cout << "Введите первое число в RGB " << endl;
	cin >> a; 
	cout << a << endl;
	cout << "Введите второе число в RGB " << endl;
	cin >> b;
	cout << b << endl;
	cout << (a != b) << endl;
	cout << (a == b) << endl;
	



	return 0;
}
