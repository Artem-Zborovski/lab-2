#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stdio.h>
using namespace std;
void printMultimap(const multimap<double, int>& m) {
	double currentKey;
	bool first = true;
	for (const auto& pair : m) {
		if (first || pair.first != currentKey) {
			currentKey = pair.first;
			first = false;
			cout << "\nЦена: " << currentKey << "\n";
		}
		cout << "Количество: " << pair.second << "\n";
	}
}
void add(multimap<double, int>& m, const vector<pair<double, int>>& v, int start, int end) {
	if (start < 0 || end > v.size() || start > end) {
		throw out_of_range("Invalid range");
	}

	for (int i = start; i < end; ++i) {
		m.insert(v[i]);
	}
}
void remove1(multimap<double, int>& m, const double price, const int value) {
	for (auto it = m.begin(); it != m.end(); ) {
		if (it->second == value && it->first == price) {
			it = m.erase(it);
		}
		else {
			++it;
		}
	}
}
void counter(multimap<double, int>& a, double price) {
	int c = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == price) {
			c++;
		}
	}
	cout << "Количество элементов с ключом " << price << " = " << c << endl;
}
void changEl(multimap<double, int>& a, double price, int val) {
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == price && it->second == val) {
			double newprice;
			cout << "Ведите новую цену:" << endl;
			cin >> newprice;
			int newval;
			cout << "Введите новое количество:" << endl;
			cin >> newval;
			a.erase(it);
			a.insert({ newprice, newval });
			break;
		}
	}
}
void comp1(multimap<double, int>& a, double a1, double a2, int v1, int v2) {
	int c = 0, d = 0;


	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == a1 && it->second == v1) {
			auto t1 = it;
			c++;
		}
		if (it->first == a2 && it->second == v2) {
			auto t2 = it;
			d++;
		}
	}
	if (c == 0 || d == 0) {
		cout << "Таких товаров нет в списке" << endl;
	}
	else {
		if (a1 > a2) {
			cout << "1 товар дороже 2" << endl;
		}
		if (a1 < a2) {
			cout << "2 товар дороже 1" << endl;
		}
		if (a1 == a2) {
			cout << "Они стоят одинаково" << endl;
		}
	}
}
void change1(multimap<double, int>& a, double a1, double a2, int v1, int v2) {
	int c = 0, d = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == a1 && it->second == v1) {
			a.erase(it);
			a.insert({ a2,v1 });
			c++;
			break;
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == a2 && it->second == v2) {
			a.erase(it);
			a.insert({ a1,v2 });
			d++;
			break;
		}
	}
	if (c == 0 || d == 0) {
		cout << "Таких товаров нет в списке" << endl;
	}

}
void change2(multimap<double, int>& a, double a1, double a2, int v1, int v2) {
	int c = 0, d = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == a1 && it->second == v1) {
			a.erase(it);
			a.insert({ a1,v2 });
			c++;
			break;
		}
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it->first == a2 && it->second == v2) {
			a.erase(it);
			a.insert({ a2,v1 });
			d++;
			break;
		}
	}
	if (c == 0 || d == 0) {
		cout << "Таких товаров нет в списке" << endl;
	}

}
int main() {
	setlocale(LC_ALL, "rus");
	cout << "1.Добавить элементы из заданного диапазона \n"
		<< "2.Удалить элемент\n" << "3.Поиск  количества элементов, ключи которых равны К\n"
		<< "4.Обменивает  значения двух объектов\n"
		<< "5.Замена значения элемента\n" 
		<< "6.Сравнение  отображений\n"
		<< "7.Выход из программы\n";
	vector<pair<double, int>>th2 = { {11.7,12},{23.9,1},{66.6,11},{56.99,9},{44,1},{66,10},{101.01,45},{18.8,91} };
	multimap<double, int>things;
	char op;
	int op2;
	int val;
	int val2;
	int val3;
	int val4;
	int val5;
	int val6;
	cin >> op;
	while (true) {
		switch (op) {
		case '1':cout << "Выберите позицию:" << endl;
			int pos;
			cin >> pos;
			cout << "Выберите количество:" << endl;
			int amount;
			cin >> amount;
			add(things, th2, pos, pos + amount);
			printMultimap(things);
			break;
		case '2':cout << "Введите цену:" << endl;
			double price;
			cin >> price;
			cout << "Введите количество:" << endl;
			cin >> val;
			remove1(things, price, val);
			printMultimap(things);
			break;
		case '3':cout << "Введите цену:" << endl;
			double price2;
			cin >> price2;
			counter(things, price2);
			break;
		case '4':cout << "Введите цену 1 товара:" << endl;
			double price6;
			cin >> price6;
			cout << "Введите цену 2 товара:" << endl;
			double price7;
			cin >> price7;
			cout << "Введите количество 1 товара:" << endl;
			cin >> val5;
			cout << "Введите количество 2 товара:" << endl;
			cin >> val6;
			cout << "Поменять цену (1) или количество (2):" << endl;
			cin >> op2;
			if (op2 == 1) {
				change1(things, price6, price7, val5, val6);
				printMultimap(things);
			}
			if (op2 == 2) {
				change2(things, price6, price7, val5, val6);
				printMultimap(things);
			}
			if (op2 != 1 && op2 != 2) {
				cout << "Некорректный ввод, введите заново:" << endl;
				cin >> op2;
			} break;
		case '5':cout << "Введите цену:" << endl;
			double price3;
			cin >> price3;
			cout << "Введите количество:" << endl;
			cin >> val2; changEl(things, price3, val2);
			printMultimap(things); break;
		case '6':cout << "Введите цену 1 товара:" << endl;
			double price4;
			cin >> price4;
			cout << "Введите цену 2 товара:" << endl;
			double price5;
			cin >> price5;
			cout << "Введите количество 1 товара:" << endl;
			cin >> val3;
			cout << "Введите количество 2 товара:" << endl;
			cin >> val4;
			comp1(things, price4, price5, val3, val4);
			break;
		case '7':cout << "Конец программы";
			exit(EXIT_SUCCESS); 
			break;
		default:
			cout << "Ошибка" << endl;
		}
		cout << "Выберите операцию:" << endl;
		cin >> op;
	}
	return 0;
}