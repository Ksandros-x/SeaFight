#include "Board.h"
#include <string>
#include <iostream>
using namespace std;

void Board::createBoard(std::istream& in)
{
	string line;
	while (getline(in, line)) {
		vector<shared_ptr<Cell>> row;
		for (auto c : line) {
			shared_ptr<Cell> cell;
			if (c == WATER) {
				cell = make_shared<Water>(WATER);
			}
			else if (c == SHIP) {
				cell = make_shared<ShipPart>(SHIP);
			}
			row.push_back(cell);
		}
	}
}

bool Board::isBoardCorrect() const
{
	return true;
}

void Board::createShips()
{

}