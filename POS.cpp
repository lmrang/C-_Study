/*
	POS.cpp
	created : 2022. 3. 28
	Author : ���̶�
*/

#include <iostream>
#include <cstring>
#include<vector>
#include<Windows.h>
using namespace std;

class Product {
private:
	int num;	//�迭�� ������ �Է¹޾� ����.
	int price;	//����
	string description;	//����
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
	string title;	//����
	string writer;	//�۰�
	string publisher;	//���ǻ�
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
class CD : public Product {
private :
	string title;	//����
	string singer;	//����
public:
	CD(int idx, string ct, string cs, int money, string des) : Product(idx, money, des)
	{
		title = ct;
		singer = cs;
	}
	void ShowData() const {
		Product::ShowData();
		cout << "���� : " << title << endl;
		cout << "�۰� : " << singer << endl;
	}
};
/*******************************************************************/
int choose_num()		//�׸����Լ�
{
	int choose;			//��ȣ ����
	cout << "1. Book " << endl;
	cout << "2. CD" << endl;
	cout << "���� : ";
	cin >> choose;
	return choose;
}
/*******************************************************************/
int main() {	
	Product* pobj[100];
	static int idx = 0;	//�迭 ��ȣ 0~

	vector<int> book;	//å ���� vector
	vector<int> cd;		//cd ���� vector

	string title, writer, publisher, decription;
	int price;
	int choose;		//��ȣ ����
	static int num=0;	//���� �� ��ȣ ����

	while (1) {
		system("cls");
		cout << " 1. ��ǰ�߰� " << endl;
		cout << " 2. ��ǰ��ȸ " << endl;
		cout << " 3. ��ǰ���� " << endl;
		cout << " 4. ��    �� " << endl;
		cout << "���� : ";
		cin >> choose;

		if (choose == 1) {					//1. ��ǰ�߰�
			system("cls");
			choose = choose_num();			//�� ǰ�� ���� �Լ�
			system("cls");

			if (choose == 1)	//1-1 Book �߰�
			{	//���� �Է�
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
				//pobj[idx] �����Ҵ�
				book.push_back(idx);
				//book ������ ������ �ִ� �迭�� ��ȣ�� �Է�
			}

			if (choose == 2)	//1-2 cd �߰�							
			{
				decription = "CD";
				cout << "���� : " << decription << endl;
				cout << "���� : ";
				cin >> title;
				cout << "���� : ";
				cin >> writer;
				cout << "���� : ";
				cin >> price;

				pobj[idx] = new CD(idx, title, writer, price, decription);
				cd.push_back(idx);
				//cd ������ ������ �ִ� �迭�� ��ȣ�� �Է�
			}
			idx++;		//�迭 ��ȣ ++
			system("pause");	//��� ���߱� ���� �뵵
		}

		else if (choose == 2) {					//2. ��ǰ��ȸ
			system("cls");
			choose = choose_num();
			system("cls");

			vector<int>::iterator iter;

			if (choose == 1)		//1.Book ��ȸ
			{
				for (iter = book.begin(); iter != book.end(); iter++)
					//book vector �� ������~������ ��ȸ
					pobj[*iter]->ShowData();
			}
			else if (choose == 2)	//2.CD ��ȸ
			{
				for (iter = cd.begin(); iter != cd.end(); iter++)
					//cd vector �� ������~������ ��ȸ
					pobj[*iter]->ShowData();
			}
			else cout << "�ٽ� �Է��� �ּ���." << endl;
			system("pause");  //��� ���߱� ���� �뵵
		}
		

		else if (choose == 3)			//3. ��ǰ����
		{
			system("cls");
			vector<int>::iterator iter;
			choose = choose_num();
			system("cls");
			if (choose == 1) {			//3-1. å ����
				for (iter = book.begin(); iter != book.end(); iter++)
				{  //book vector �� ������~������ ��ȸ
					num++;       //����++ (1~ )
					cout << num << "> ";  //���� ���
					pobj[*iter]->ShowData();
				}
				cout << "������ å ��ȣ�� �Է��� �ּ���" << endl << ">> " << endl;
				cin >> num;
				book.erase(book.begin() + (num - 1));	//book vector�� ���������� +(����-1) ��ġ�� vector ����
			}
			if (choose == 2) {			//3-2. cd ����
				for (iter = cd.begin(); iter != cd.end(); iter++)
				{  //cd vector �� ������~������ ��ȸ
					num++;
					cout << num << "> ";
					pobj[*iter]->ShowData();
				}
				cout << "������ å ��ȣ�� �Է��� �ּ���" << endl << ">> " << endl;
				cin >> num;
				cd.erase(book.begin() + (num - 1)); //cd vector�� ���������� +(����-1) ��ġ�� vector ����
			}
		}
		else if (choose == 4) break;						//4. ����
		else cout << "�ٽ� �Է��� �ּ���." << endl;
	}
	return 0;
}