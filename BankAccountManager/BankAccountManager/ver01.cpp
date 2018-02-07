#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();//메뉴출력
void MakeAccount();//계좌생성
void Deposit();//입금
void Withdraw();//출금
void ShowAllAccInfo();

enum {
	MAKE = 1, DEPOSIT, WITHDRAW, INQUIRY, EXIT
};

typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LEN];
}Account;

Account accArr[100];
int accNum = 0;

int main() {
	ShowMenu();
}

void ShowMenu() {
	int exit = 0;
	int inputNumber;

	while (1) {
		if (exit == -1)
			break;

		cout << "-----Menu-----" << endl << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌정보 전체 출력" << endl << "5. 프로그램종료" << endl << "선택:";
		cin >> inputNumber;
		switch (inputNumber)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case INQUIRY:
			ShowAllAccInfo();
			break;
		case EXIT:
			exit = -1;
			break;
		default:
			cout << "번호 선택이 잘못되었습니다. 다시 선택해주세요." << endl;
			break;
		}
	}

}

void MakeAccount() {
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: " << accNum << endl;
	accArr[accNum].accID = accNum;
	accNum++;
	cout << "이 름: ";
	cin >> accArr[accNum].cusName;
	cout << "입금액: ";
	cin >> accArr[accNum].balance;

}

void Deposit() {
	int id;
	int money;
	cout << "[입  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	accArr[id].balance += money;
	cout << "입금완료" << endl;
}

void Withdraw() {
	int id;
	int money;
	cout << "[출  금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	accArr[id].balance -= money;
	cout << "출금완료" << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++) {
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이름: " << accArr[i].cusName << endl;
		cout << "잔액: " << accArr[i].balance << endl;
	}
}