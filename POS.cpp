/*
	POS.cpp
	created : 2022. 3. 28
	Author : 임이랑
*/

#include <iostream>
#include <cstring>
#include<vector>
#include<Windows.h>
using namespace std;

class Product {
private:
	int num;	//배열의 순번을 입력받아 저장.
	int price;	//가격
	string description;	//종류
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
	string title;	//제목
	string writer;	//작가
	string publisher;	//출판사
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
class CD : public Product {
private :
	string title;	//제목
	string singer;	//가수
public:
	CD(int idx, string ct, string cs, int money, string des) : Product(idx, money, des)
	{
		title = ct;
		singer = cs;
	}
	void ShowData() const {
		Product::ShowData();
		cout << "제목 : " << title << endl;
		cout << "작가 : " << singer << endl;
	}
};
/*******************************************************************/
int choose_num()		//항목선택함수
{
	int choose;			//번호 선택
	cout << "1. Book " << endl;
	cout << "2. CD" << endl;
	cout << "선택 : ";
	cin >> choose;
	return choose;
}
/*******************************************************************/
int main() {	
	Product* pobj[100];
	static int idx = 0;	//배열 번호 0~

	vector<int> book;	//책 정보 vector
	vector<int> cd;		//cd 정보 vector

	string title, writer, publisher, decription;
	int price;
	int choose;		//번호 선택
	static int num=0;	//삭제 시 번호 선택

	while (1) {
		system("cls");
		cout << " 1. 상품추가 " << endl;
		cout << " 2. 상품조회 " << endl;
		cout << " 3. 상품삭제 " << endl;
		cout << " 4. 종    료 " << endl;
		cout << "선택 : ";
		cin >> choose;

		if (choose == 1) {					//1. 상품추가
			system("cls");
			choose = choose_num();			//상세 품목 선택 함수
			system("cls");

			if (choose == 1)	//1-1 Book 추가
			{	//내용 입력
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
				//pobj[idx] 동적할당
				book.push_back(idx);
				//book 정보를 가지고 있는 배열의 번호를 입력
			}

			if (choose == 2)	//1-2 cd 추가							
			{
				decription = "CD";
				cout << "종류 : " << decription << endl;
				cout << "제목 : ";
				cin >> title;
				cout << "가수 : ";
				cin >> writer;
				cout << "가격 : ";
				cin >> price;

				pobj[idx] = new CD(idx, title, writer, price, decription);
				cd.push_back(idx);
				//cd 정보를 가지고 있는 배열의 번호를 입력
			}
			idx++;		//배열 번호 ++
			system("pause");	//잠시 멈추기 위한 용도
		}

		else if (choose == 2) {					//2. 상품조회
			system("cls");
			choose = choose_num();
			system("cls");

			vector<int>::iterator iter;

			if (choose == 1)		//1.Book 조회
			{
				for (iter = book.begin(); iter != book.end(); iter++)
					//book vector 의 시작점~끝까지 조회
					pobj[*iter]->ShowData();
			}
			else if (choose == 2)	//2.CD 조회
			{
				for (iter = cd.begin(); iter != cd.end(); iter++)
					//cd vector 의 시작점~끝까지 조회
					pobj[*iter]->ShowData();
			}
			else cout << "다시 입력해 주세요." << endl;
			system("pause");  //잠시 멈추기 위한 용도
		}
		

		else if (choose == 3)			//3. 상품삭제
		{
			system("cls");
			vector<int>::iterator iter;
			choose = choose_num();
			system("cls");
			if (choose == 1) {			//3-1. 책 삭제
				for (iter = book.begin(); iter != book.end(); iter++)
				{  //book vector 의 시작점~끝까지 조회
					num++;       //순번++ (1~ )
					cout << num << "> ";  //순번 출력
					pobj[*iter]->ShowData();
				}
				cout << "삭제할 책 번호를 입력해 주세요" << endl << ">> " << endl;
				cin >> num;
				book.erase(book.begin() + (num - 1));	//book vector의 시작점에서 +(순번-1) 위치의 vector 삭제
			}
			if (choose == 2) {			//3-2. cd 삭제
				for (iter = cd.begin(); iter != cd.end(); iter++)
				{  //cd vector 의 시작점~끝까지 조회
					num++;
					cout << num << "> ";
					pobj[*iter]->ShowData();
				}
				cout << "삭제할 책 번호를 입력해 주세요" << endl << ">> " << endl;
				cin >> num;
				cd.erase(book.begin() + (num - 1)); //cd vector의 시작점에서 +(순번-1) 위치의 vector 삭제
			}
		}
		else if (choose == 4) break;						//4. 종료
		else cout << "다시 입력해 주세요." << endl;
	}
	return 0;
}