#include "MainGame.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>

#include "global.h"

void MainGame::gotoxy(int x, int y)
{
	short X = static_cast<short>(x);
	short Y = static_cast<short>(y);

	COORD pos{ X, Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int MainGame::KIn()
{
	if (_kbhit()) {

		key = _getch();

		if (key == KBHIT)
			key = _getch();
		
		
		switch (key) {
			
		case UP:
			gotoxy(40, 25);
			std::cout << "�Է� Ű ��: ��";
			break;
		case DOWN:
			gotoxy(40, 25);
			std::cout << "�Է� Ű ��: ��";
			break;
		case LEFT:
			gotoxy(40, 25);
			std::cout << "�Է� Ű ��: ��";
			break;
		case RIGHT:
			gotoxy(40, 25);
			std::cout << "�Է� Ű ��: ��";
			break;
		case ENTER:
			gotoxy(40, 25);
			std::cout << "�Է� Ű ��: E";
			break;
		default:
			break;
		}
		return key;
	}
	return 0;
}

void MainGame::Init()
{
	system("mode con: cols=100 lines=30");
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	
	std::cout << "\a\n\n\n\n";
	std::cout << "\t\t"; std::cout << "���������� �������� ����������  ����������  ������  ����������   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ��     ��           ��      ��      ��    ��    ��           \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ��     ��������     ��      ����������    ��      ��������   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ��     ��           ��      ��    ��      ��             ��  \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ��     ��������     ��      ��      ��  ������  ����������   \n";

}

void MainGame::MenuDraw()
{
	int x{ 40 }, y{ 11 };
	gotoxy(x - 2, y);
	std::cout << "> �� �� �� ��" << '\n';
	gotoxy(x, y + 2);
	std::cout << "��       ��" << '\n';
	gotoxy(x - 10, y + 4);
	std::cout << "(���ϴ� �޴��� ������ ����Ű �Է�)" << '\n';
	int n{ };
	while (n != ENTER) {
		n = KIn();
		switch (n)
		case UP: {
			if (y > 11) {
				y -= 2;
				gotoxy(x - 2, y + 2);
				std::cout << " ";
				gotoxy(x - 2, y);
				std::cout << ">";
			}
			break;

		case DOWN:
			if (y < 13) {
				y += 2;
				gotoxy(x - 2, y - 2);
				std::cout << " ";

				gotoxy(x - 2, y);
				std::cout << ">";
			}
			break;
		case ENTER:
			if (y == 13) {
				system("cls");
				std::cout << "�����մϴ�." << '\n';
				startgame = false;
				break;
			}
			else if (y == 11) {
				system("cls");
				startgame = true;
				break;
			}
		default: break;
		}
	}

}

bool MainGame::GetStart() const
{
	return startgame;
}

void MainGame::SetStart(bool type)
{
	Sleep(100);
	startgame = type;
}

void MainGame::EndGame()
{

	system("cls");
	std::cout << "T.T GAME OVER T.T" << '\n';
	std::cout << "�̸��� �Է��ϼ���: ";
	std::cin >> name;
	std::ofstream rank("Ranking.txt");
	rank << Score << " " << name;



}

int MainGame::GetScore() const
{
	return Score;
}
