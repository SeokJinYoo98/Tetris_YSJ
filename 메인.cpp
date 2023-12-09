#include <iostream>
#include <conio.h>
#include <chrono>

#include "Table.h"
#include "global.h"
#include "MainGame.h"

int Min{ };
int Sec{ };



// ���� 
// 1. ������ �����̼� �ȵǴ°�
// 2. �ٿ��϶��� �ױ� - �ذ�
// 3. ���̺� ����
void Time() {

	if (Sec == 60) {
		++Min;
		Sec = 0;
	}
	std::cout << "����ð�: " << Min << "�� " << Sec << "�� ";
}

int main()
{
	MainGame M;

	M.Init();
	M.MenuDraw();

	if (!M.GetStart())
		return 0;

	Table* Tp = new Table(MAX_X, MAX_Y);

	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
	while (M.GetStart()) {
		std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
		std::chrono::milliseconds elapsedtime = duration_cast<std::chrono::milliseconds>(endTime - startTime);

		if (elapsedtime.count() % 1000 == 0) {
			++Sec;
			Tp->BMove(DOWN);
			M.gotoxy(0, 0);
			Tp->DrawT();
			M.gotoxy(27, 20);
			Time();
			M.gotoxy(27, 18);
			std::cout << "Score - " << M.GetScore();
			
		}

		if (_kbhit()) {
			Tp->BMove(M.KIn());
			M.gotoxy(0, 0);
			Tp->DrawT();
		}
		
		if (Tp->GetIsDead()) {	
			M.EndGame();
			delete Tp;
			return 0;
		}
	
		M.SetScore(Tp->IsGetScore());
	}
	
}
