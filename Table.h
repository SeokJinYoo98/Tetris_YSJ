#include <vector>
#include <iostream>
#include "Block.h"

#pragma once

class Table {
	int Tx{ };
	int Ty{ };
	bool fdraw{ true };
	Blocks* Bp{ nullptr };
	int* tp{ nullptr };
	bool isdead{ false };
	

	std::vector<std::vector<int>> table;
public:
	Table(int x, int y);
	~Table();

	void DrawT();
	void CreateBlock();
	void BMove(int key);

	void Build();
	int IsCollision();

	void SaveBlock();
	void RemoveBlock();

	void IsFullTable();
	void IsDead();
	bool GetIsDead() const;
	int IsGetScore();
};