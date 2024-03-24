// ReversiDLL.cpp
// Defines the exported functions for the DLL application.
// Programmed by Jonathan Feucht, 2015

#include "stdafx.h"
#include "ReversiDLL.h"
#include <stdexcept>
#include "../ReversiGameEngine/ReversiGameEngine.h"

using namespace std;

ReversiGameEngine myGame;

void NewGame() {
	myGame = ReversiGameEngine();
}

void throwInvalidArgumentError(const char* text) {
	throw invalid_argument(text);
}

int GetSquare(int x, int y) {
	if ((x > 7) || (y > 7) || (x < 0) || (y < 0)) {
		throwInvalidArgumentError("Position does not exist");
	}

	return (myGame.board[x][y]);
}

int IsValidMove(int x, int y) {
	if ((x > 7) || (y > 7) || (x < 0) || (y < 0)) {
		throwInvalidArgumentError("Position does not exist");
	}

	return (myGame.isValidMove(ReversiGameEngine::reversiGameCoord(x, y)));
}

int IsBlackTurn() {
	return (myGame.thisPlayer == ReversiGameEngine::player::blackPlayer);
}

void Play(int x, int y) {
	if ((x > 7) || (y > 7) || (x < 0) || (y < 0)) {
		throwInvalidArgumentError("Position does not exist");
	}

	myGame.Play(ReversiGameEngine::reversiGameCoord(x, y));
}

int IsGameOver() {
	return (myGame.isGameOver());
}

int Winner() {
	return ((int)myGame.findWinner());
}

int GetNumPlays() {
	return (myGame.numPlays());
}


void ComputerPlay() {
	// Computer makes a move
	myGame.computerPlay();
}
