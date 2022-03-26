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
		cout << "종류 : " << description << endl;
		cout << "가격 : " << price << endl;
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
		cout << "제목 : " << title << endl;
		cout << "작가 : " << writer << endl;
		cout << "출판사 : " << publisher << endl << endl;
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
		cout << " 1. 상품추가 " << endl;
		cout << " 2. 상품조회 " << endl;
		cout << " 3. 종    료 " << endl;
		cin >> choose;

		if (choose == 1) {
			choose = choose_num();

			if (choose == 1)
			{
				decription = "Book";
				cout << "종류 : " << decription << endl;
				cout << "제목 : ";
				cin >> title;
				cout << "작가 : ";
				cin >> writer;
				cout << "출판사 : ";
				cin >> publisher;
				cout << "가격 : ";
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
		else cout << "다시 입력해 주세요." << endl;
	}
	return 0;
}