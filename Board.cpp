#include "Board.h"
#include <string>
#include <iostream>
using namespace std;

void Board::createBoard(std::istream& in)
{
	string line;
	while (getline(in, line)) {
		vector<shared_ptr<Cell>> row;
		row.push_back(make_shared<Water>(WATER));
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
		row.push_back(make_shared<Water>(WATER));
		cells.push_back(row);
	}

	vector<shared_ptr<Cell>> row(cells[0].size(), 
		make_shared<Water>(WATER));//констуктор вектора, количество элементов, элементы
	cells.insert(cells.begin(), row);
	cells.push_back(row);
}

bool Board::isBoardCorrect() const
{
	return true;
}

void Board::createShips()
{

}