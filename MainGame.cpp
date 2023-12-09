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
			std::cout << "입력 키 값: ▲";
			break;
		case DOWN:
			gotoxy(40, 25);
			std::cout << "입력 키 값: ▼";
			break;
		case LEFT:
			gotoxy(40, 25);
			std::cout << "입력 키 값: ◀";
			break;
		case RIGHT:
			gotoxy(40, 25);
			std::cout << "입력 키 값: ▶";
			break;
		case ENTER:
			gotoxy(40, 25);
			std::cout << "입력 키 값: E";
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
	std::cout << "\t\t"; std::cout << "ㅁㅁㅁㅁㅁ ㅁㅁㅁㅁ ㅁㅁㅁㅁㅁ  ㅁㅁㅁㅁㅁ  ㅁㅁㅁ  ㅁㅁㅁㅁㅁ   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ㅁ     ㅁ           ㅁ      ㅁ      ㅁ    ㅁ    ㅁ           \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ㅁ     ㅁㅁㅁㅁ     ㅁ      ㅁㅁㅁㅁㅁ    ㅁ      ㅁㅁㅁㅁ   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ㅁ     ㅁ           ㅁ      ㅁ    ㅁ      ㅁ             ㅁ  \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    ㅁ     ㅁㅁㅁㅁ     ㅁ      ㅁ      ㅁ  ㅁㅁㅁ  ㅁㅁㅁㅁㅁ   \n";

}

void MainGame::MenuDraw()
{
	int x{ 40 }, y{ 11 };
	gotoxy(x - 2, y);
	std::cout << "> 게 임 시 작" << '\n';
	gotoxy(x, y + 2);
	std::cout << "종       료" << '\n';
	gotoxy(x - 10, y + 4);
	std::cout << "(원하는 메뉴를 선택후 엔터키 입력)" << '\n';
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
				std::cout << "종료합니다." << '\n';
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
	std::cout << "이름을 입력하세요: ";
	std::cin >> name;
	std::ofstream rank("Ranking.txt");
	rank << Score << " " << name;



}

int MainGame::GetScore() const
{
	return Score;
}
