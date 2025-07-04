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
			std::cout << "脊径 徹 葵: ＜";
			break;
		case DOWN:
			gotoxy(40, 25);
			std::cout << "脊径 徹 葵: ≦";
			break;
		case LEFT:
			gotoxy(40, 25);
			std::cout << "脊径 徹 葵: ��";
			break;
		case RIGHT:
			gotoxy(40, 25);
			std::cout << "脊径 徹 葵: ∈";
			break;
		case ENTER:
			gotoxy(40, 25);
			std::cout << "脊径 徹 葵: E";
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
	std::cout << "\t\t"; std::cout << "けけけけけ けけけけ けけけけけ  けけけけけ  けけけ  けけけけけ   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    け     け           け      け      け    け    け           \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    け     けけけけ     け      けけけけけ    け      けけけけ   \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    け     け           け      け    け      け             け  \n";
	Sleep(100);
	std::cout << "\t\t"; std::cout << "    け     けけけけ     け      け      け  けけけ  けけけけけ   \n";

}

void MainGame::MenuDraw()
{
	int x{ 40 }, y{ 11 };
	gotoxy(x - 2, y);
	std::cout << "> 惟 績 獣 拙" << '\n';
	gotoxy(x, y + 2);
	std::cout << "曽       戟" << '\n';
	gotoxy(x - 10, y + 4);
	std::cout << "(据馬澗 五敢研 識澱板 殖斗徹 脊径)" << '\n';
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
				std::cout << "曽戟杯艦陥." << '\n';
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
	std::cout << "戚硯聖 脊径馬室推: ";
	std::cin >> name;
	std::ofstream rank("Ranking.txt");
	rank << Score << " " << name;



}

int MainGame::GetScore() const
{
	return Score;
}
