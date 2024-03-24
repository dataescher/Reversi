// ReversiGameEngine.cpp
// Defines the implementation of the Reversi game engine
// Programmed by Jonathan Feucht, 2015

#include "ReversiGameEngine.h"
#include <Windows.h>
#include <stdio.h>

// Table which indicates tile values early on in the game
const int ReversiGameEngine::tileWeights[BOARD_WIDTH][BOARD_HEIGHT] = {
	{ 50,  -5,   1,   1,   1,   1,  -5,  50},
	{ -5,  -10,  1,   1,   1,   1, -10,  -5},
	{  1,   1,   1,   1,   1,   1,   1,   1},
	{  1,   1,   1,   1,   1,   1,   1,   1},
	{  1,   1,   1,   1,   1,   1,   1,   1},
	{  1,   1,   1,   1,   1,   1,   1,   1},
	{ -5, -10,   1,   1,   1,   1, -10,  -5},
	{ 50,  -5,   1,   1,   1,   1,  -5,  50}
};

char ReversiGameEngine::tileToChar(ReversiGameEngine::boardSquare thisTile) {
	char thisChar;

	switch (thisTile) {
		case boardSquare::blankSquare:
			thisChar = '.';
			break;
		case boardSquare::blackSquare:
			thisChar = 'X';
			break;
		case boardSquare::whiteSquare:
			thisChar = 'O';
			break;
	}

	return thisChar;
}

ReversiGameEngine::reversiGameCoord::reversiGameCoord(int x, int y) {
	this->x = x;
	this->y = y;
}

ReversiGameEngine::reversiGameCoord::reversiGameCoord() {
	this->x = 0;
	this->y = 0;
}

inline bool ReversiGameEngine::reversiGameCoord::operator==(const reversiGameCoord& other) {
	return ((x == other.x) && (y == other.y));
}

bool ReversiGameEngine::isGameOver() {
	return gameOver;
}

ReversiGameEngine::availableMove::availableMove() {}

ReversiGameEngine::availableMove::availableMove(const ReversiGameEngine::availableMove& copyavailableMove) {
	location = copyavailableMove.location;
	reversedSquares = copyavailableMove.reversedSquares;
}

void ReversiGameEngine::Play(reversiGameCoord loc) {
	if (!gameOver) {
		availableMove* thisMove = findMove(loc);

		if (thisMove != NULL) {
			plays++;

			board[thisMove->location.x][thisMove->location.y] = (boardSquare)thisPlayer;
			for (list<reversiGameCoord>::iterator it = thisMove->reversedSquares.begin(); it != thisMove->reversedSquares.end(); it++) {
				board[it->x][it->y] = (boardSquare)thisPlayer;
			}

			thisPlayer = (player)(-thisPlayer);

			findAvailableMoves();
			if (availableMoves.size() == 0) {
				thisPlayer = (player)(-thisPlayer);

				findAvailableMoves();

				if (availableMoves.size() == 0) {
					// Find out who the winner is
					int winVal = boardScore();

					if (winVal > 0) {
						thisWinner = winner::blackWins;
					} else if (winVal < 0) {
						thisWinner = winner::whiteWins;
					} else {
						thisWinner = winner::tie;
					}

					gameOver = true;
				}
			}
		}
	}
}


void ReversiGameEngine::printBoard() {
	FILE* myFile = fopen("C:\\Users\\Jonathan Feucht\\Documents\\Visual Studio 2012\\Projects\\Reversi\\Debug\\output.log", "a");
	if (myFile) {
		fprintf(myFile, "-----------------------\n");
		for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
			for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
				fprintf(myFile, "%c ", tileToChar(board[x][y]));
			}
			fprintf(myFile, "\n");
		}
		fprintf(myFile, "-----------------------\n");
	}
	fclose(myFile);

	return;
}

ReversiGameEngine::availableMove* ReversiGameEngine::findMove(reversiGameCoord move) {
	for (list<availableMove>::iterator it = availableMoves.begin(); it != availableMoves.end(); it++) {
		if (it->location == move) {
			return &(*it);
		}
	}

	return NULL;
}

bool ReversiGameEngine::isValidMove(reversiGameCoord move) {
	for (list<availableMove>::iterator it = availableMoves.begin(); it != availableMoves.end(); it++) {
		if (it->location == move) {
			return true;
		}
	}

	return false;
}

// Finds all the available plays
void ReversiGameEngine::findAvailableMoves() {
	availableMove thisAvailableMove;
	availableMoves.clear();
	int retVal = 0;
	for (thisAvailableMove.location.y = 0; thisAvailableMove.location.y < BOARD_HEIGHT; thisAvailableMove.location.y++) {
		for (thisAvailableMove.location.x = 0; thisAvailableMove.location.x < BOARD_WIDTH; thisAvailableMove.location.x++) {
			if (board[thisAvailableMove.location.x][thisAvailableMove.location.y] == boardSquare::blankSquare) {
				findReversedSquares(&thisAvailableMove);

				if (thisAvailableMove.reversedSquares.size() > 0) {
					availableMoves.push_back(thisAvailableMove);
					thisAvailableMove.reversedSquares.clear();
				}
			}
		}
	}
}

// Helper function to findNextPlayer
// Finds the squares which are flipped due to a game play
inline void ReversiGameEngine::findReversedSquares(availableMove* thisMove) {
	reversiGameCoord endPos;
	reversiGameCoord startPos = thisMove->location;
	list<reversiGameCoord> _reversedSquares;

	// Check x+ direction
	if (startPos.x < (BOARD_WIDTH - 2)) {
		if (board[startPos.x + 1][startPos.y] == -thisPlayer) {
			_reversedSquares.clear();
			_reversedSquares.push_back(reversiGameCoord(startPos.x + 1, startPos.y));
			endPos.y = startPos.y;
			for (endPos.x = startPos.x + 2; endPos.x < BOARD_WIDTH; endPos.x++) {
				if (board[endPos.x][endPos.y] == thisPlayer) {
					// Add square
					thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
					break;
				} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
					break;
				}

				_reversedSquares.push_back(endPos);
			}
		}
		// Check x+y+ direction
		if (startPos.y < (BOARD_HEIGHT - 2)) {
			if (board[startPos.x + 1][startPos.y + 1] == -thisPlayer) {
				_reversedSquares.clear();
				_reversedSquares.push_back(reversiGameCoord(startPos.x + 1, startPos.y + 1));
				for (endPos.x = startPos.x + 2, endPos.y = startPos.y + 2; (endPos.x < BOARD_WIDTH) && (endPos.y < BOARD_HEIGHT); endPos.x++, endPos.y++) {
					if (board[endPos.x][endPos.y] == thisPlayer) {
						// Add square
						thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
						break;
					} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
						break;
					}
					_reversedSquares.push_back(endPos);
				}
			}
		}
		// Check x+y- direction
		if (startPos.y > 1) {
			if (board[startPos.x + 1][startPos.y - 1] == -thisPlayer) {
				_reversedSquares.clear();
				_reversedSquares.push_back(reversiGameCoord(startPos.x + 1, startPos.y - 1));
				for (endPos.x = startPos.x + 2, endPos.y = startPos.y - 2; (endPos.x < BOARD_WIDTH) && (endPos.y >= 0); endPos.x++, endPos.y--) {
					if (board[endPos.x][endPos.y] == thisPlayer) {
						// Add square
						thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
						break;
					} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
						break;
					}
					_reversedSquares.push_back(endPos);
				}
			}
		}
	}
	// Check x- direction
	if (startPos.x > 1) {
		if (board[startPos.x - 1][startPos.y] == -thisPlayer) {
			_reversedSquares.clear();
			_reversedSquares.push_back(reversiGameCoord(startPos.x - 1, startPos.y));
			endPos.y = startPos.y;
			for (endPos.x = startPos.x - 2; endPos.x >= 0; endPos.x--) {
				if (board[endPos.x][endPos.y] == thisPlayer) {
					// Add square
					thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
					break;
				} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
					break;
				}
				_reversedSquares.push_back(endPos);
			}
		}
		// Check x-y+ direction
		if (startPos.y < (BOARD_HEIGHT - 2)) {
			if (board[startPos.x - 1][startPos.y + 1] == -thisPlayer) {
				_reversedSquares.clear();
				_reversedSquares.push_back(reversiGameCoord(startPos.x - 1, startPos.y + 1));
				for (endPos.x = startPos.x - 2, endPos.y = startPos.y + 2; (endPos.x >= 0) && (endPos.y < BOARD_HEIGHT); endPos.x--, endPos.y++) {
					if (board[endPos.x][endPos.y] == thisPlayer) {
						// Add square
						thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
						break;
					} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
						break;
					}
					_reversedSquares.push_back(endPos);
				}
			}
		}
		// Check x-y- direction
		if (startPos.y > 1) {
			if (board[startPos.x - 1][startPos.y - 1] == -thisPlayer) {
				_reversedSquares.clear();
				_reversedSquares.push_back(reversiGameCoord(startPos.x - 1, startPos.y - 1));
				for (endPos.x = startPos.x - 2, endPos.y = startPos.y - 2; (endPos.x >= 0) && (endPos.y >= 0); endPos.x--, endPos.y--) {
					if (board[endPos.x][endPos.y] == thisPlayer) {
						// Add square
						thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
						break;
					} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
						break;
					}
					_reversedSquares.push_back(endPos);
				}
			}
		}
	}
	// Check y+ direction
	if (startPos.y < (BOARD_HEIGHT - 2)) {
		if (board[startPos.x][startPos.y + 1] == -thisPlayer) {
			_reversedSquares.clear();
			_reversedSquares.push_back(reversiGameCoord(startPos.x, startPos.y + 1));
			endPos.x = startPos.x;
			for (endPos.y = startPos.y + 2; endPos.y < BOARD_HEIGHT; endPos.y++) {
				if (board[endPos.x][endPos.y] == thisPlayer) {
					// Add square
					thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
					break;
				} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
					break;
				}
				_reversedSquares.push_back(endPos);
			}
		}
	}
	// Check y- direction
	if (startPos.y > 1) {
		if (board[startPos.x][startPos.y - 1] == -thisPlayer) {
			_reversedSquares.clear();
			_reversedSquares.push_back(reversiGameCoord(startPos.x, startPos.y - 1));
			endPos.x = startPos.x;
			for (endPos.y = startPos.y - 2; endPos.y >= 0; endPos.y--) {
				if (board[endPos.x][endPos.y] == thisPlayer) {
					// Add square
					thisMove->reversedSquares.splice(thisMove->reversedSquares.begin(), _reversedSquares);
					break;
				} else if (board[endPos.x][endPos.y] == boardSquare::blankSquare) {
					break;
				}
				_reversedSquares.push_back(endPos);
			}
		}
	}
}

ReversiGameEngine::winner ReversiGameEngine::findWinner() {
	int winIdx = boardScore();
	winner retVal;

	if (winIdx > 0) {
		retVal = winner::blackWins;
	} else if (winIdx < 0) {
		retVal = winner::whiteWins;
	} else {
		retVal = winner::tie;
	}

	return retVal;
}


int ReversiGameEngine::numPlays() {
	return plays;
}

int ReversiGameEngine::boardScore() {
	int winIdx = 0;

	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			winIdx += board[x][y];
		}
	}

	return winIdx;
}

ReversiGameEngine::ReversiGameEngine() {
	// Create a new board
	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			board[y][x] = boardSquare::blankSquare;
		}
	}

	board[(BOARD_WIDTH / 2) - 1][(BOARD_HEIGHT / 2) - 1] = boardSquare::blackSquare;
	board[BOARD_WIDTH / 2][BOARD_HEIGHT / 2] = boardSquare::blackSquare;
	board[(BOARD_WIDTH / 2) - 1][BOARD_HEIGHT / 2] = boardSquare::whiteSquare;
	board[BOARD_WIDTH / 2][(BOARD_HEIGHT / 2) - 1] = boardSquare::whiteSquare;

	plays = 0;

	thisWinner = winner::tie;
	thisPlayer = player::blackPlayer;
	gameOver = false;
	findAvailableMoves();

	return;
}

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
	std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

ReversiGameEngine::ReversiGameEngine(const ReversiGameEngine& copyGameData) {
	// Copy the board
	for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
		for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
			board[x][y] = copyGameData.board[x][y];
		}
	}

	thisPlayer = copyGameData.thisPlayer;
	gameOver = copyGameData.gameOver;
	availableMoves = copyGameData.availableMoves;
	thisWinner = copyGameData.thisWinner;
	plays = copyGameData.plays;
}

signed int ReversiGameEngine::recurseLevels(unsigned int numLevels) {
	signed int totalStats = 0;

	if (!gameOver && (numLevels > 0)) {
		list<availableMove> bestMoves;
		signed int bestStat = 0;
		bool bestStatUninitialized = true;

		for (list<availableMove>::iterator it = availableMoves.begin(); it != availableMoves.end(); it++) {

			//signed int thisTileWeight = (signed int)thisPlayer * tileWeights[it->location.x][it->location.y];
			ReversiGameEngine nextGame = *this;
			nextGame.Play(it->location);
			signed int thisStat = nextGame.recurseLevels(numLevels - 1) * (nextGame.thisPlayer * thisPlayer);
			totalStats += thisStat;
		}

		// Return the best board stat
		return (totalStats / (signed int)availableMoves.size());
	} else {

		// Get the stats for the current board
		for (unsigned int y = 0; y < BOARD_HEIGHT; y++) {
			for (unsigned int x = 0; x < BOARD_WIDTH; x++) {
				totalStats += (signed int)thisPlayer * (signed int)board[x][y] * tileWeights[x][y];
			}
		}

		// Add the accumulative weight of all the best moves
		for (list<availableMove>::iterator it = availableMoves.begin(); it != availableMoves.end(); it++) {
			totalStats += (signed int)thisPlayer * tileWeights[it->location.x][it->location.y];
		}

		return totalStats;
	}
}

inline ReversiGameEngine::reversiGameCoord ReversiGameEngine::computer_AI(unsigned int numLevels) {
	bool bestStatsUninitialized = true;
	signed int bestStats = 0;
	reversiGameCoord bestMove;

	for (list<availableMove>::iterator it = availableMoves.begin(); it != availableMoves.end(); it++) {
		// Copy the current class
		ReversiGameEngine nextGame = *this;
		nextGame.Play(it->location);

		// Recurse multiple levels
		signed int theseStats = (nextGame.thisPlayer * thisPlayer) * nextGame.recurseLevels(numLevels);

		if ((theseStats > bestStats) || bestStatsUninitialized) {
			bestStats = theseStats;
			bestMove = (it->location);
			bestStatsUninitialized = false;
		}
	}

	return bestMove;
}

void ReversiGameEngine::computerPlay() {
	// Select the best move
	Play(computer_AI(3));

	return;
}
