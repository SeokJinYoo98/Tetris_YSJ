#include "Block.h"
#include "global.h"
#include <iostream>

Blocks::Blocks(int num)
	:Bx{ MAX_X / 2 - 2 }, By{ 1 }, RotationCnt{ 0 }
{
	{
		if (관찰)
			std::cout << "블록 생성자 호출" << '\n';
		switch (num) {
		case 1:
			memcpy(shape, block1, sizeof(block1));
			break;
		case 2:
			memcpy(shape, block2, sizeof(block2));
			break;
		case 3:
			memcpy(shape, block3, sizeof(block3));
			break;
		case 4:
			memcpy(shape, block4, sizeof(block4));
			break;
		case 5:
			memcpy(shape, block5, sizeof(block5));
			break;
		case 6:
			memcpy(shape, block6, sizeof(block6));
			break;
		case 7:
			memcpy(shape, block7, sizeof(block7));
			break;
		case 8:
			memcpy(shape, block8, sizeof(block8));
			break;
		default:
			break;
		};
	};
}

Blocks::~Blocks()
{
	if(관찰)
		std::cout << "블록 소멸자 호출" << '\n';
}

