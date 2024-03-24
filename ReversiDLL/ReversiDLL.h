// ReversiDll.h
// Defines the external interface to the Reversi game engine DLL
// Programmed by Jonathan Feucht, 2015

#pragma once

#ifdef REVERSIDLL_EXPORTS
#define REVERSIDLL_API __declspec(dllexport) 
#else
#define REVERSIDLL_API __declspec(dllimport) 
#endif

extern "C" {
	// Start a new game
	REVERSIDLL_API void NewGame();

	// Get character representing game board position
	REVERSIDLL_API int GetSquare(int x, int y);

	// Return if the player can move at a specified location
	REVERSIDLL_API int IsValidMove(int x, int y);

	// Return whether or not it is the computer's turn
	REVERSIDLL_API int IsBlackTurn();

	// Call to make a human move
	REVERSIDLL_API void Play(int x, int y);

	// Indicates that the game is over
	REVERSIDLL_API int IsGameOver();

	// Indicates that the game is over
	REVERSIDLL_API int Winner();

	// Returns the number of plays that have been made
	REVERSIDLL_API int GetNumPlays();

	// Calls on the computer to make a move
	REVERSIDLL_API void ComputerPlay();
}
