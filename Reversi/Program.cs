// Program.cs
// Defines the entry point for the Reversi application, and the interface to the game engine dll
// Programmed by Jonathan Feucht, 2015

using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Reversi {
	internal static class Program {
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		private static void Main() {
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new FrmReversi());
		}
	}

	internal static class GameEngine {
		public enum BoardSquareTypes {
			Blank = 0,
			Black = 1,
			White = -1
		}

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void NewGame();

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern BoardSquareTypes GetSquare(Int32 x, Int32 y);

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Int32 IsValidMove(Int32 x, Int32 y);

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Int32 IsBlackTurn();

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void Play(Int32 x, Int32 y);

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Int32 IsGameOver();

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Int32 Winner();

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Int32 GetNumPlays();

		[DllImport("ReversiDLL.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void ComputerPlay();

		public static new String ToString() {
			String retStr = "------------------\n";

			for (Int32 y = 0; y < 8; y++) {
				for (Int32 x = 0; x < 8; x++) {
					Char thisSquare = '.';

					switch (GetSquare(x, y)) {
						case BoardSquareTypes.White:
							thisSquare = 'O';
							break;
						case BoardSquareTypes.Black:
							thisSquare = 'X';
							break;
					}

					retStr += thisSquare;
				}
				retStr += "\n";
			}

			return retStr;
		}
	}
}