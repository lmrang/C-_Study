#include <iostream>
#include <cstring>
using namespace std;

class Product {
private:
	int price;
	string description;
public:
	Product(int money, string des) : price(money)
	{
		description = des;
	}

	virtual void ShowData()
	{
		cout << "가격 : " << price << endl;
		cout << "종류 : " << description << endl;
	}
	void getProduct()
	{

	}
};
/******************************************************************/
class Book : public Product {
private:
	string title;
	string writer;
	string publisher;
public:
	Book(string bt, string bw, string bp, int money, string des)
	: Product(money, des)
	{
		title = bt;
		writer = bw;
		publisher = bp;
	}
	void ShowData()
	{
		cout << "제목 : " << title << endl;
		cout << "작가 : " << writer << endl;
		cout << "출판사 : " << publisher << endl;
		Product::ShowData();
	}
	void getProduct()
	{

	}
};
/*******************************************************************/
class ProductHandler {
private:
	Product* pobj[100];
	static int idx=0;
public:
	ProductHandler() {}
	void AddProduct(Product* id)
	{
		pobj[idx++]=id;
	}
	void ShowData() {
		for (int i = 0; i < idx; i++)
		{
			pobj[i]->ShowData();
			
		}
	}
};
/******************************************************************/

void Plus() {
	//Product* pobj[100];
	static int idx = 0;

	ProductHandler Handler;

	int choose;
	string title, writer, publisher, decription;
	int price;

	cout << "1. Book " << endl;
	cout << "2. CD" << endl;
	cout << "3. cellphone" << endl;
	cin >> choose;

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
		
		Handler.AddProduct(new Book(title, writer, decription, price, decription));
		cout << endl << endl;
		Handler.ShowData();
	}

	//idx++;
}
/******************************************************************/

int main() {
	int choose;
	while (1) {
		cout << " 1. 상품추가 " << endl;
		cout << " 2. 상품조회 " << endl;
		cout << " 3. 종    료 " << endl;
		cin >> choose;

		if (choose == 1) Plus();
		else if (choose == 2);
		else break;
	}
	return 0;
}