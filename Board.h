#pragma once
#include "Cell.h"
#include <vector>
#include <memory>
#include "Ship.h"
#include <stdexcept>

class Board
{
	std::vector<std::vector<std::shared_ptr<Cell>>> cells;
	std::vector<std::shared_ptr<Ship>> ships;
public:
	Board(std::istream& in) {
		createBoard(in);
		if (!isBoardCorrect()) {
			throw std::invalid_argument("Board is not corrrect");
		}
		createShips();
	}

	enum {WATER = ' ', SHIP = '#' };
private:
	void createBoard(std::istream& in);
	bool isBoardCorrect() const;
	void createShips();

};

