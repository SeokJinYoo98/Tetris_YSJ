#include <string>
#pragma once


class MainGame
{
	std::string name{ };
	int key{ };
	bool startgame = false;
	int Score{ };
	int elapsedtime{ };
public:
	void gotoxy(int x, int y); 
	int KIn(); 
	void Init();
	void MenuDraw();
	bool GetStart() const;
	void SetStart(bool);
	void EndGame();
	int GetScore() const;

	inline void SetScore(int score) { Score += score; };
};

