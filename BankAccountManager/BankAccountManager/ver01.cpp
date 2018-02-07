#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();//�޴����
void MakeAccount();//���»���
void Deposit();//�Ա�
void Withdraw();//���
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

		cout << "-----Menu-----" << endl << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. �������� ��ü ���" << endl << "5. ���α׷�����" << endl << "����:";
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
			cout << "��ȣ ������ �߸��Ǿ����ϴ�. �ٽ� �������ּ���." << endl;
			break;
		}
	}

}

void MakeAccount() {
	cout << "[���°���]" << endl;
	cout << "����ID: " << accNum << endl;
	accArr[accNum].accID = accNum;
	accNum++;
	cout << "�� ��: ";
	cin >> accArr[accNum].cusName;
	cout << "�Աݾ�: ";
	cin >> accArr[accNum].balance;

}

void Deposit() {
	int id;
	int money;
	cout << "[��  ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;
	accArr[id].balance += money;
	cout << "�ԱݿϷ�" << endl;
}

void Withdraw() {
	int id;
	int money;
	cout << "[��  ��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;
	accArr[id].balance -= money;
	cout << "��ݿϷ�" << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�̸�: " << accArr[i].cusName << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl;
	}
}