#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

class Product {
private:
	int num;
	int price;
	string description;
public:
	Product(int idx, int money, string des) : num(idx), price(money)
	{
		description = des;
	}

	virtual void ShowData() const
	{
		cout << endl;
		cout << "���� : " << description << endl;
		cout << "���� : " << price << endl;
	}
};
/******************************************************************/
class Book : public Product {
private:
	string title;
	string writer;
	string publisher;
public:
	Book(int idx,  string bt, string bw, string bp, int money, string des)
	: Product(idx, money, des) 
	{
		title = bt;
		writer = bw;
		publisher = bp;
	}
	void ShowData() const
	{
		Product::ShowData();
		cout << "���� : " << title << endl;
		cout << "�۰� : " << writer << endl;
		cout << "���ǻ� : " << publisher << endl << endl;
	}
};
/*******************************************************************/
int choose_num()
{
	int choose;

	cout << "1. Book " << endl;
	cout << "2. CD" << endl;
	cout << "3. cellphone" << endl;
	cin >> choose;

	return choose;
}
/*******************************************************************/
int main() {	
	Product* pobj[100];
	static int idx = 0;

	vector<int> book;

	string title, writer, publisher, decription;
	int price;
	int choose;
	while (1) {
		cout << " 1. ��ǰ�߰� " << endl;
		cout << " 2. ��ǰ��ȸ " << endl;
		cout << " 3. ��    �� " << endl;
		cin >> choose;

		if (choose == 1) {
			choose = choose_num();

			if (choose == 1)
			{
				decription = "Book";
				cout << "���� : " << decription << endl;
				cout << "���� : ";
				cin >> title;
				cout << "�۰� : ";
				cin >> writer;
				cout << "���ǻ� : ";
				cin >> publisher;
				cout << "���� : ";
				cin >> price;

				pobj[idx] = new Book(idx, title, writer, publisher, price, decription);
				book.push_back(idx);
				idx++;

			}
		}
		else if (choose == 2) {
			choose = choose_num();

			if (choose == 1)
			{
				vector<int>::iterator iter;

				for (iter = book.begin(); iter != book.end(); iter++)
					pobj[*iter]->ShowData();
			}

		}
		else if (choose == 3) break;
		else cout << "�ٽ� �Է��� �ּ���." << endl;
	}
	return 0;
}