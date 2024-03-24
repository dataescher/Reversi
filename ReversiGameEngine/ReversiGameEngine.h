// ReversiGameEngine.h
// Defines the interface to the Reversi game engine
// Programmed by Jonathan Feucht, 2015

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <random>
#include <iterator>
#include <list>
using namespace std;


#define BLANK 0
#define BLACK 1
#define WHITE -1

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8


class ReversiGameEngine {
public:
	enum player {
		blackPlayer = BLACK,
		whitePlayer = WHITE
	};

	enum boardSquare {
		blankSquare = BLANK,
		blackSquare = BLACK,
		whiteSquare = WHITE
	};

	enum winner {
		tie = BLANK,
		blackWins = BLACK,
		whiteWins = WHITE
	};

	struct reversiGameCoord {
		int x;
		int y;

		reversiGameCoord();
		reversiGameCoord(int x, int y);
		bool operator==(const reversiGameCoord& other);
	};

	struct availableMove {
		reversiGameCoord location;
		list<reversiGameCoord> reversedSquares;
		availableMove();
		availableMove(const availableMove& copyavailableMove);
	};

	list<availableMove> availableMoves;

	winner thisWinner;
	player thisPlayer;
	boardSquare board[8][8];

	ReversiGameEngine();
	bool isValidMove(reversiGameCoord move);
	void ReversiGameEngine::Play(reversiGameCoord loc);
	bool isGameOver();
	winner findWinner();
	void computerPlay();
	void printBoard();
	int numPlays();
	void getAsciiBoard(char* boardData);
	int boardScore();

private:
	availableMove* findMove(reversiGameCoord move);
	bool gameOver;
	ReversiGameEngine(const ReversiGameEngine& copyGameData);
	void findAvailableMoves();
	void findReversedSquares(availableMove* thisMove);
	char tileToChar(boardSquare thisTile);
	unsigned int plays;

	// AI routines
	static const signed int tileWeights[BOARD_WIDTH][BOARD_HEIGHT];
	float boardWeight();
	signed int recurseLevels(unsigned int numLevels);
	reversiGameCoord computer_AI(unsigned int numLevels);
};
