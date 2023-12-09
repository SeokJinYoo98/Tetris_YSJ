#include "Table.h"
#include "global.h"
#include <random>
#include <Windows.h>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution uid{ 1, 7 };


Table::Table(int x, int y)
	: Tx{ x }, Ty{ y }, fdraw{true}, isdead{false}
{
	for (int i = 0; i < Ty; ++i) {
		std::vector<int> temp;
		for (int j = 0; j < Tx; ++j) {
				temp.push_back(0);
		}
		table.push_back(temp);
	}
	int tempy = Ty - 1;
	int tempx = Tx - 1;

	for (int i = 0; i < Ty; ++ i)
		for (int j = 0; j < Tx; ++j) {
			table[0][j] = 1; // 위
			table[tempy][j] = 3; // 아래
			table[i][0] = 1; // 왼쪽
			table[i][tempx] = 1; // 오른쪽
		}
		DrawT();
		CreateBlock();
}
Table::~Table() {

	if (Bp != nullptr)
		delete Bp;
}
void Table::DrawT()
{
	
	for (int y = 0; y < Ty; ++y) {
		for (int x = 0; x < Tx; ++x) {
			if (table[y][x] == 0)
				std::cout << "  ";
			if (table[y][x] == 1 || table[y][x] == 3)
				std::cout << "■";
			if (table[y][x] == 2)
				std::cout << "□";
			if (table[y][x] == 4)
				std::cout << "▦";
		}
		std::cout << '\n';
		if (fdraw)
			Sleep(50);
	}
	
	fdraw = false;
};

void Table::CreateBlock()
{
	if (Bp != NULL)
		delete Bp;
	Bp = new Blocks(uid(dre));
	IsDead();
	if (!isdead) {
		SaveBlock();
	}
};

void Table::BMove(int key)
{
	Blocks Temp(8);
	Temp.SetBx(Bp->GetBx());
	Temp.SetBy(Bp->GetBy());
	Temp.SetRCnt(Bp->GetRotationCnt());

	RemoveBlock();

	if (key == 72) {
		Bp->BRotate();
	}
	if (key == 80) {
		Bp->BMoveD();
	}
	else if (key == 77) {
		Bp->BMoveR();
	}
	else if (key == 75) {
		Bp->BMoveL();
	}

	int colltype = IsCollision();

	if (colltype == BUILD) {
		Bp->SetBx(Temp.GetBx());
		Bp->SetBy(Temp.GetBy());
		Bp->SetRCnt(Temp.GetRotationCnt());

		if (key == DOWN) {
			Build();
			if(!isdead)
			CreateBlock();
		}
	}
	if (colltype == DONTMOVE) {
		Bp->SetBx(Temp.GetBx());
		Bp->SetBy(Temp.GetBy());
		Bp->SetRCnt(Temp.GetRotationCnt());
	}

	SaveBlock();
}


void Table::Build()
{
	int By, Bx, BValue = 0;

	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			BValue = Bp->GetShape(x, y);

			if (BValue == 2) {
				Bx = Bp->GetBx() + x;
				By = Bp->GetBy() + y;
				table[By][Bx] = 4;
			}
		}
	}
}

int Table::IsCollision()
{

	int BRCnt = Bp->GetRotationCnt();
	int Bx, By, BValue;

	for (int y = 3; y >= 0; --y) {
		for (int x = 0; x < 4; ++x) {
			BValue = Bp->GetShape(x, y);

			if (BValue == 2) {
				Bx = Bp->GetBx() + x;
				By = Bp->GetBy() + y;
	
				if (table[By][Bx] == 3 || table[By][Bx] == 4)
					return BUILD;
				if (table[By][Bx] == 1)
					return DONTMOVE;
			}
		}
	}
	return 0;

}

void Table::SaveBlock()
{
	int Bx, By, BValue = 0;
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			BValue = Bp->GetShape(x, y);
			if (BValue == 2) {
				By = Bp->GetBy() + y;
				Bx = Bp->GetBx() + x;
				table[By][Bx] = BValue;
			}
		}
	}
}

void Table::RemoveBlock()
{
	int Bx, By, BValue = 0;

	for (int y = 0; y < 4; ++y) {
		By = Bp->GetBy() + y;
		for (int x = 0; x < 4; ++x) {
			Bx = Bp->GetBx() + x;
			BValue = Bp->GetShape(x, y);
			if (BValue == 2)
				table[By][Bx] = 0;
		}
	}
}

void Table::IsFullTable()
{
	//int isfull{ };
	//for(int y = Ty - 1; y > 0; --y)
	//	for (int x = 1; x < Tx - 1; ++x) {
	//		isfull += table[y][x];
	//		for (int x = 1; x < Tx - 1; ++x)
	//	}
}

void Table::IsDead()
{
	int Bx, By, BValue = 0;
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			BValue = Bp->GetShape(x, y);
			if (BValue == 2) {
				By = Bp->GetBy() + y;
				Bx = Bp->GetBx() + x;
				if (table[By][Bx] == 4)
					isdead = true;
			}
		}
	}
}

bool Table::GetIsDead() const
{
	return isdead;
}

int Table::IsGetScore()
{
	int cnt{ };
	int TValue[MAX_Y]{ };

	for (int y = 0; y < Ty; ++y) {
		for (int x = 0; x < Tx; ++x) {
			TValue[y] += table[y][x];
		}
	}

	for (int i = 0; i < Ty; ++i) {
		if (TValue[i] == 46) {
			++cnt;
			for (int x = 0; x < Tx; ++x) {
				if (table[i][x] != 1) {
					table[i][x] = 0;
				}
			
			}
		}
	}
	
	for (int i = 0; i < Ty; ++i) {
		if (TValue[i] == 46) {
			int tempT[MAX_X]{ };
			for (int j = i; j > 2; --j) {
				for (int x = 0; x < Tx; ++x) {
					tempT[x] = table[j - 1][x];
					table[j][x] = tempT[x];
				}
			}
		}
	}
	
	
	return 100 * cnt;
}
