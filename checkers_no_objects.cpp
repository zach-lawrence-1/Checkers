#include<iostream>
#include<vector>

int win = 0;
int selectx;
int selecty;
int currx;
int curry;
int valid;
int gameOver = 0;
int turn = 1;
int alive = 12;
std::string whitePiece = "w";
std::string whiteKing = "W";
std::string blackPiece = "b";
std::string blackKing = "B";

std::string board[8][8] = {
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 1
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 2
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 3
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 4
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 5
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 6
	{" ", " ", " ", " ", " ", " ", " ", " "},   // row 7
	{" ", " ", " ", " ", " ", " ", " ", " "}	// row 8
};

void defaultLocations()
{
	int x = 1;
	int y = 0;
	//auto white piece placement
	for (int i = 0; i < 12; i++)
	{
		x += 2;
		if (i == 0)
		{
			x = 1;
		}

		if (i == 4)
		{
			y = 1;
			x = 0;
		}

		if (i == 8)
		{
			y = 2;
			x = 1;
		}

		board[y][x] = whitePiece;
	}

	x = 0;
	y = 7;

	//auto black piece placement
	for (int i = 0; i < 12; i++) {
		
		x += 2;

		if (i == 0)
		{
			x = 0;
		}

		if (i == 4)
		{
			x = 1;
			y = 6;
		}

		if (i == 8)
		{
			x = 0;
			y = 5;
		}

		if (i > 4 && i < 9)
		{
			y = 6;
		}

		if (i >= 8)
		{
			y = 5;
		}
		board[y][x] = blackPiece;
	}
}

void drawBoard()
{
	system("cls");

	//your board
	std::cout << "      0     1     2     3     4     5     6     7" << std::endl;
	std::cout << "    " << "_______________________________________________" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 0 " << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "  |  " << board[0][6] << "  |  " << board[0][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 1 " << "|  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << "  |  " << board[1][4] << "  |  " << board[1][5] << "  |  " << board[1][6] << "  |  " << board[1][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 2 " << "|  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << "  |  " << board[2][4] << "  |  " << board[2][5] << "  |  " << board[2][6] << "  |  " << board[2][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 3 " << "|  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << "  |  " << board[3][4] << "  |  " << board[3][5] << "  |  " << board[3][6] << "  |  " << board[3][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 4 " << "|  " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "  |  " << board[4][3] << "  |  " << board[4][4] << "  |  " << board[4][5] << "  |  " << board[4][6] << "  |  " << board[4][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 5 " << "|  " << board[5][0] << "  |  " << board[5][1] << "  |  " << board[5][2] << "  |  " << board[5][3] << "  |  " << board[5][4] << "  |  " << board[5][5] << "  |  " << board[5][6] << "  |  " << board[5][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 6 " << "|  " << board[6][0] << "  |  " << board[6][1] << "  |  " << board[6][2] << "  |  " << board[6][3] << "  |  " << board[6][4] << "  |  " << board[6][5] << "  |  " << board[6][6] << "  |  " << board[6][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout << " 7 " << "|  " << board[7][0] << "  |  " << board[7][1] << "  |  " << board[7][2] << "  |  " << board[7][3] << "  |  " << board[7][4] << "  |  " << board[7][5] << "  |  " << board[7][6] << "  |  " << board[7][7] << "  |" << std::endl;
	std::cout << "   |_____" << "|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|___" << "__|" << std::endl;
}

void deadCount(int c)
{
	//all white piece dead check
	if (turn == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == whitePiece || board[i][j] == whiteKing)
				{
					c++;
				}
			}
		}

		alive = c;

		if (c == 0)
		{
			win = 1;
		}
	}

	//all black piece dead check
	if (turn == 2)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == blackPiece || board[i][j] == blackKing)
				{
					c++;
				}
			}
		}

		alive = c;

		if (c == 0)
		{
			win = 2;
		}
	}
}

void doubleJumpB(int selectx, int selecty);

void bSelection()
{
	if (win == 0)
	{
		int c = 0;
		turn = 1;
		int jump = 0;
		std::cout << "Black's turn: select a piece ";

		//get selection piece
		std::cin >> selectx;
		std::cin >> selecty;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			bSelection();
		}

		//check if selection is a valid for white and restart function if it isn't
		int sNum = 0;
		
		if (board[selecty][selectx] == blackPiece || board[selecty][selectx] == blackKing)
		{
			valid = 0;
			sNum = 1;

			std::cout << "now select a location ";
			std::cin >> currx;
			std::cin >> curry;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				bSelection();
			}

			//you can move 1 forward and 1 right
			if ((currx == selectx + 1 || currx == selectx - 1) && curry == selecty - 1)
			{
				//runs into nothing
				if (board[curry][currx] == " ")
				{
					valid =	1;
				}
			}

			//king can move backward
			if ((currx == selectx + 1 || currx == selectx - 1) && curry == selecty + 1)
			{
				if (board[selecty][selectx] == blackKing)
				{
					//runs into nothing
					if (board[curry][currx] == " ")
					{
						valid = 1;
					}
				}
			}

			//jump white piece to the right
			if (currx == selectx + 2 && curry == selecty - 2)
			{
				if (board[selecty - 1][selectx + 1] == whitePiece || board[selecty - 1][selectx + 1] == whiteKing)
				{
					if (board[selecty - 2][selectx + 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					jump = 1;
					board[selecty - 1][selectx + 1] = " ";
				}
			}

			//jump white piece to the left
			if (currx == selectx - 2 && curry == selecty - 2)
			{
				if (board[selecty - 1][selectx - 1] == whitePiece || board[selecty - 1][selectx - 1] == whiteKing)
				{
					if (board[selecty - 2][selectx - 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					jump = 1;
					board[selecty - 1][selectx - 1] = " ";
				}
			}

			if (board[selecty][selectx] == blackKing)
			{
				//king jump white piece to the right
				if (currx == selectx + 2 && curry == selecty + 2)
				{
					if (board[selecty + 1][selectx + 1] == whitePiece || board[selecty + 1][selectx + 1] == whiteKing)
					{
						if (board[selecty + 2][selectx + 2] == " ")
						{
							valid = 1;
						}
					}

					if (valid == 1)
					{
						jump = 1;
						board[selecty + 1][selectx + 1] = " ";
					}
				}

				//king jump white piece to the left
				if (currx == selectx - 2 && curry == selecty + 2)
				{
					if (board[selecty + 1][selectx - 1] == whitePiece || board[selecty + 1][selectx - 1] == whiteKing)
					{
						if (board[selecty + 2][selectx - 2] == " ")
						{
							valid = 1;
						}
					}

					if (valid == 1)
					{
						jump = 1;
						board[selecty + 1][selectx - 1] = " ";
					}
				}
			}

			if (valid == 0)
			{
				drawBoard();
				std::cout << "invalid move " << std::endl;
				bSelection();
			}

			if (valid == 1)
			{
				if (board[selecty][selectx] == blackKing)
				{
					board[selecty][selectx] = " ";
					board[curry][currx] = blackKing;
				}

				if (board[selecty][selectx] == blackPiece)
				{
					board[selecty][selectx] = " ";
					board[curry][currx] = blackPiece;
				}

				if (curry == 0)
				{
					board[curry][currx] = blackKing;
				}

				deadCount(c);

				if (jump == 1)
				{
					drawBoard();
					std::string s;
					std::cout << "can you jump another piece? y/n" << std::endl;
					std::cin >> s;

					if (s == "y" || s == "Y")
					{
						doubleJumpB(currx, curry);
					}
				}
			}
		}

		if (sNum == 0)
		{
			drawBoard();
			std::cout << "invalid selection" << std::endl;
			bSelection();
		}
	}
}

void doubleJumpB(int selectx, int selecty)
{
	if (win == 0)
	{
		int c = 0;
		turn = 1;
		valid = 0;
		
		std::cout << "jump another piece ";
		std::cin >> currx;
		std::cin >> curry;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			bSelection();
		}

		//jump white piece to the right
		if (currx == selectx + 2 && curry == selecty - 2)
		{
			if (board[selecty - 1][selectx + 1] == whitePiece || board[selecty - 1][selectx + 1] == whiteKing)
			{
				if (board[selecty - 2][selectx + 2] == " ")
				{
					valid = 1;
				}
			}

			if (valid == 1)
			{
				board[selecty - 1][selectx + 1] = " ";
			}
		}

		//jump white piece to the left
		if (currx == selectx - 2 && curry == selecty - 2)
		{
			if (board[selecty - 1][selectx - 1] == whitePiece || board[selecty - 1][selectx - 1] == whiteKing)
			{
				if (board[selecty - 2][selectx - 2] == " ")
				{
					valid = 1;
				}
			}

			if (valid == 1)
			{
				board[selecty - 1][selectx - 1] = " ";
			}
		}

		//king jump white piece to the right
		if (board[selecty][selectx] == blackKing)
		{
			if (currx == selectx + 2 && curry == selecty + 2)
			{
				if (board[selecty + 1][selectx + 1] == whitePiece || board[selecty + 1][selectx + 1] == whiteKing)
				{
					if (board[selecty + 2][selectx + 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					board[selecty + 1][selectx + 1] = " ";
				}
			}

			//king jump white piece to the left
			if (currx == selectx - 2 && curry == selecty + 2)
			{
				if (board[selecty + 1][selectx - 1] == whitePiece || board[selecty + 1][selectx - 1] == whiteKing)
				{
					if (board[selecty + 2][selectx - 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					board[selecty + 1][selectx - 1] = " ";
				}
			}
		}
		
		if (valid == 1)
		{
			if (board[selecty][selectx] == blackKing)
			{
				board[selecty][selectx] = " ";
				board[curry][currx] = blackKing;
			}

			if (board[selecty][selectx] == blackPiece)
			{
				board[selecty][selectx] = " ";
				board[curry][currx] = blackPiece;
			}

			if (curry == 0)
			{
				board[curry][currx] = blackKing;
			}

			deadCount(c);

			drawBoard();
			std::string s;
			std::cout << "can you jump another piece? y/n" << std::endl;
			std::cin >> s;

			if (s == "y" || s == "Y")
			{
				doubleJumpB(currx, curry);
			}
		}
	}
}

void doubleJumpW(int selectx, int selecty);

void wSelection()
{
	if (win == 0)
	{
		int c = 0;
		turn = 2;
		int jump = 0;
		std::cout << "White's turn: select a piece ";

		//get selection piece
		std::cin >> selectx;
		std::cin >> selecty;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			wSelection();
		}

		//check if selection is a valid for white and restart function if it isn't
		int sNum = 0;

		if (board[selecty][selectx] == whitePiece || board[selecty][selectx] == whiteKing)
		{
			valid = 0;
			sNum = 1;

			std::cout << "now select a location ";
			std::cin >> currx;
			std::cin >> curry;

			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				drawBoard();
				std::cout << "cannot enter letter values" << std::endl;
				wSelection();
			}

			//you can move 1 forward and 1 right
			if ((currx == selectx + 1 || currx == selectx - 1) && curry == selecty + 1)
			{
				//runs into any piece
				if (board[curry][currx] == " ")
				{
					valid = 1;
				}
			}

			//king moves backwards
			if ((currx == selectx + 1 || currx == selectx - 1) && curry == selecty - 1)
			{
				//not king
				if (board[selecty][selectx] == whiteKing)
				{
					//runs into any piece
					if (board[curry][currx] == " ")
					{
						valid = 1;
					}
				}
			}

			//jump black piece to the right
			if (currx == selectx + 2 && curry == selecty + 2)
			{
				if (board[selecty + 1][selectx + 1] == blackPiece || board[selecty + 1][selectx + 1] == blackKing)
				{
					if (board[selecty + 2][selectx + 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					jump = 1;
					board[selecty + 1][selectx + 1] = " ";
				}
			}

			//jump black piece to the left
			if (currx == selectx - 2 && curry == selecty + 2)
			{
				if (board[selecty + 1][selectx - 1] == blackPiece || board[selecty + 1][selectx - 1] == blackKing)
				{
					if (board[selecty + 2][selectx - 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					jump = 1;
					board[selecty + 1][selectx - 1] = " ";
				}
			}

			if (board[selecty][selectx] == whiteKing)
			{
				//king jump black piece to the right
				if (currx == selectx + 2 && curry == selecty - 2)
				{
					if (board[selecty - 1][selectx + 1] == blackPiece || board[selecty - 1][selectx + 1] == blackKing)
					{
						if (board[selecty - 2][selectx + 2] == " ")
						{
							valid = 1;
						}
					}

					if (valid == 1)
					{
						jump = 1;
						board[selecty - 1][selectx + 1] = " ";
					}
				}

				//king jump black piece to the left
				if (currx == selectx - 2 && curry == selecty - 2)
				{
					if (board[selecty - 1][selectx - 1] == blackPiece || board[selecty - 1][selectx - 1] == blackKing)
					{
						if (board[selecty - 2][selectx - 2] == " ")
						{
							valid = 1;
						}
					}

					if (valid == 1)
					{
						jump = 1;
						board[selecty - 1][selectx - 1] = " ";
					}
				}
			}

			if (valid == 0)
			{
				drawBoard();
				std::cout << "invalid move " << std::endl;
				wSelection();
			}

			if (valid == 1)
			{
				if (board[selecty][selectx] == whiteKing)
				{
					board[selecty][selectx] = " ";
					board[curry][currx] = whiteKing;
				}

				if (board[selecty][selectx] == whitePiece)
				{
					board[selecty][selectx] = " ";
					board[curry][currx] = whitePiece;
				}

				if (curry == 7)
				{
					board[curry][currx] = whiteKing;
				}

				deadCount(c);

				if (jump == 1)
				{
					drawBoard();
					std::string s;
					std::cout << "can you jump another piece? y/n" << std::endl;
					std::cin >> s;

					if (s == "y" || s == "Y")
					{
						doubleJumpB(currx, curry);
					}
				}
			}
		}

		if (sNum == 0)
		{
			drawBoard();
			std::cout << "invalid selection" << std::endl;
			wSelection();
		}
	}
}

void doubleJumpW(int selectx, int selecty)
{
	if (win == 0)
	{
		int c = 0;
		turn = 2;
		valid = 0;

		std::cout << "jump another piece ";
		std::cin >> currx;
		std::cin >> curry;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			drawBoard();
			std::cout << "cannot enter letter values" << std::endl;
			wSelection();
		}

		//jump black piece to the right
		if (currx == selectx + 2 && curry == selecty + 2)
		{
			if (board[selecty + 1][selectx + 1] == blackPiece || board[selecty + 1][selectx + 1] == blackKing)
			{
				if (board[selecty + 2][selectx + 2] == " ")
				{
					valid = 1;
				}
			}

			if (valid == 1)
			{
				board[selecty + 1][selectx + 1] = " ";
			}
		}

		//jump black piece to the left
		if (currx == selectx - 2 && curry == selecty + 2)
		{
			if (board[selecty + 1][selectx - 1] == blackPiece || board[selecty + 1][selectx - 1] == blackKing)
			{
				if (board[selecty + 2][selectx - 2] == " ")
				{
					valid = 1;
				}
			}

			if (valid == 1)
			{
				board[selecty + 1][selectx - 1] = " ";
			}
		}

		if (board[selecty][selectx] == whiteKing)
		{
			//king jump black piece to the right
			if (currx == selectx + 2 && curry == selecty - 2)
			{
				if (board[selecty - 1][selectx + 1] == blackPiece || board[selecty - 1][selectx + 1] == blackKing)
				{
					if (board[selecty - 2][selectx + 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					board[selecty - 1][selectx + 1] = " ";
				}
			}

			//king jump black piece to the left
			if (currx == selectx - 2 && curry == selecty - 2)
			{
				if (board[selecty - 1][selectx - 1] == blackPiece || board[selecty - 1][selectx - 1] == blackKing)
				{
					if (board[selecty - 2][selectx - 2] == " ")
					{
						valid = 1;
					}
				}

				if (valid == 1)
				{
					board[selecty - 1][selectx - 1] = " ";
				}
			}
		}

		if (valid == 1)
		{
			if (board[selecty][selectx] == whiteKing)
			{
				board[selecty][selectx] = " ";
				board[curry][currx] = whiteKing;
			}

			if (board[selecty][selectx] == whitePiece)
			{
				board[selecty][selectx] = " ";
				board[curry][currx] = whitePiece;
			}

			if (curry == 7)
			{
				board[curry][currx] = whiteKing;
			}

			deadCount(c);

			drawBoard();
			std::string s;
			std::cout << "can you jump another piece? y/n" << std::endl;
			std::cin >> s;

			if (s == "y" || s == "Y")
			{
				doubleJumpW(currx, curry);
			}
		}
	}
}

void tieGame()
{
	if (win == 0)
	{
		int black = 0;
		int white = 0;
		int drawCount = 0;
		int validCount = 0;

		//checks if white can't move
		if (turn == 1)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					validCount = 0;
					
					if (board[i][j] == whitePiece)
					{
						//left edge
						if (j == 0)
						{
							validCount += 2;
						}

						//right edge
						if (j == 7)
						{
							validCount += 2;
						}

						//left side
						if (j == 1 && (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing))
						{
							if (i != 6)
								validCount++;
						}

						//right side
						if (j == 6 && (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing))
						{
							if (i != 6)
								validCount++;
						}

						//bottom edge
						if (i == 6 && (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing))
						{
							validCount++;
						}

						//bottom edge
						if (i == 6 && (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing))
						{
							validCount++;
						}

						//white piece in front right
						if (board[i + 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing)
						{
							validCount += 2;
						}

						//white piece in front left
						if (board[i + 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing)
						{
							validCount += 2;
						}
						
						//black piece in front right
						if (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing)
						{
							validCount++;

							if (board[i + 2][j + 2] == blackPiece || board[i + 2][j + 2] == blackKing || board[i + 2][j + 2] == whitePiece || board[i + 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//black piece in front left
						if (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing)
						{
							validCount++;

							if (board[i + 2][j - 2] == blackPiece || board[i + 2][j - 2] == blackKing || board[i + 2][j - 2] == whitePiece || board[i + 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						//std::cout << validCount;

						if (validCount == 4)
						{
							drawCount++;
						}
					}

					if (board[i][j] == whiteKing)
					{
						//left edge
						if (j == 0)
						{
							validCount += 4;
						}

						//right edge
						if (j == 7)
						{
							validCount += 4;
						}

						//top edge
						if (i == 0)
						{
							validCount += 4;
						}
						

						//bottom edge
						if (i == 7)
						{
							validCount += 4;
						}

						//left bottom corner
						if (i == 7 && j == 0)
						{
							validCount = 6;
						}

						//right top corner
						if (i == 0 && j == 7)
						{
							validCount = 6;
						}

						//left edge in front
						if (j == 1 && (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing))
						{
							validCount++;
						}

						//right edge in front
						if (j == 6 && (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing))
						{
							validCount++;
						}

						//left edge behind
						if (j == 1 && (board[i - 1][j - 1] == blackPiece || board[i - 1][j - 1] == blackKing))
						{
							validCount++;
						}

						//right edge behind
						if (j == 6 && (board[i - 1][j + 1] == blackPiece || board[i - 1][j + 1] == blackKing))
						{
							validCount++;
						}

						//heres issue
						//bottom edge
						if (i == 6 && j != 6 && (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing))
						{
							validCount++;
						}

						//bottom edge
						if (i == 6 && j != 1 && (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing))
						{
							validCount++;
						}

						//top edge
						if (i == 1 && j != 1 && (board[i - 1][j + 1] == blackPiece || board[i - 1][j + 1] == blackKing))
						{
							validCount++;
						}

						//top edge
						if (i == 1 && j != 6 && (board[i - 1][j - 1] == blackPiece || board[i - 1][j - 1] == blackKing))
						{
							validCount++;
						}

						

						//white piece in front right
						if (board[i + 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing)
						{
							validCount += 2;
						}

						//white piece in front left
						if (board[i + 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing)
						{
							validCount += 2;
						}

						//white piece back right
						if (board[i - 1][j + 1] == whitePiece || board[i - 1][j + 1] == whiteKing)
						{
							validCount += 2;
						}

						//white piece back left
						if (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing)
						{
							validCount += 2;
						}

						//black piece in front right
						if (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing)
						{
							validCount++;

							if (board[i + 2][j + 2] == blackPiece || board[i + 2][j + 2] == blackKing || board[i + 2][j + 2] == whitePiece || board[i + 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//black piece in front left
						if (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing)
						{
							validCount++;

							if (board[i + 2][j - 2] == blackPiece || board[i + 2][j - 2] == blackKing || board[i + 2][j - 2] == whitePiece || board[i + 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						//black piece back right
						if (board[i - 1][j + 1] == blackPiece || board[i - 1][j + 1] == blackKing)
						{
							validCount++;

							if (board[i - 2][j + 2] == blackPiece || board[i - 2][j + 2] == blackKing || board[i - 2][j + 2] == whitePiece || board[i - 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//black piece back left
						if (board[i - 1][j - 1] == blackPiece || board[i - 1][j - 1] == blackKing)
						{
							validCount++;

							if (board[i - 2][j - 2] == blackPiece || board[i - 2][j - 2] == blackKing || board[i - 2][j - 2] == whitePiece || board[i - 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						if (validCount == 8)
						{
							drawCount++;
						}
					}
				}
			}
			
			deadCount(0);

			if (drawCount == alive)
			{
				win = 3;
			}
		}

		//checks if black can't move
		if (turn == 2)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					validCount = 0;

					if (board[i][j] == blackPiece)
					{
						//left edge
						if (j == 0)
						{
							validCount += 2;
						}

						//right edge
						if (j == 7)
						{
							validCount += 2;
						}

						//left side
						if (j == 1 && (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing))
						{
							if (i != 1)
								validCount++;
						}

						//right side
						if (j == 6 && (board[i - 1][j + 1] == whitePiece || board[i - 1][j + 1] == whiteKing))
						{
							if (i != 1)
								validCount++;
						}

						//top edge
						if (i == 1 && (board[i - 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing))
						{
							validCount++;
						}

						//top edge
						if (i == 1 && (board[i - 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing))
						{
							validCount++;
						}

						//black piece in front right
						if (board[i - 1][j + 1] == blackPiece || board[i - 1][j + 1] == blackKing)
						{
							validCount += 2;
						}

						//black piece in front left
						if (board[i - 1][j - 1] == blackPiece || board[i - 1][j - 1] == blackKing)
						{
							validCount += 2;
						}

						//white piece in front right
						if (board[i - 1][j + 1] == whitePiece || board[i - 1][j + 1] == whiteKing)
						{
							validCount++;

							if (board[i - 2][j + 2] == blackPiece || board[i - 2][j + 2] == blackKing || board[i - 2][j + 2] == whitePiece || board[i - 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//white piece in front left
						if (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing)
						{
							validCount++;

							if (board[i - 2][j - 2] == blackPiece || board[i - 2][j - 2] == blackKing || board[i - 2][j - 2] == whitePiece || board[i - 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						if (validCount == 4)
						{
							drawCount++;
						}
					}

					if (board[i][j] == blackKing)
					{
						//left edge
						if (j == 0)
						{
							validCount += 4;
						}

						//right edge
						if (j == 7)
						{
							validCount += 4;
						}

						//top edge
						if (i == 0)
						{
							validCount += 4;
						}

						//bottom edge
						if (i == 7)
						{
							validCount += 4;
						}

						//left bottom corner
						if (i == 7 && j == 0)
						{
							validCount = 6;
						}

						//right top corner
						if (i == 0 && j == 7)
						{
							validCount = 6;
						}

						//left edge in front
						if (j == 1 && (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing))
						{
							validCount++;
						}

						//right edge in front
						if (j == 6 && (board[i - 1][j + 1] == whitePiece || board[i - 1][j + 1] == whiteKing))
						{
							validCount++;
						}

						//left edge behind
						if (j == 1 && (board[i + 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing))
						{
							validCount++;
						}

						//right edge behind
						if (j == 6 && (board[i + 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing))
						{
							validCount++;
						}

						//bottom edge
						if (i == 6 && j != 6 && (board[i + 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing))
						{
							validCount++;
						}

						//bottom edge
						if (i == 6 && j != 1 && (board[i + 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing))
						{
							validCount++;
						}

						//top edge
						if (i == 1 && j != 1 && (board[i - 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing))
						{
							validCount++;
						}

						//top edge
						if (i == 1 && j != 6 && (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing))
						{
							validCount++;
						}

						//black piece in front right
						if (board[i - 1][j + 1] == blackPiece || board[i - 1][j + 1] == blackKing)
						{
							validCount += 2;
						}

						//black piece in front left
						if (board[i - 1][j - 1] == blackPiece || board[i - 1][j - 1] == blackKing)
						{
							validCount += 2;
						}

						//black piece back right
						if (board[i + 1][j + 1] == blackPiece || board[i + 1][j + 1] == blackKing)
						{
							validCount += 2;
						}

						//black piece back left
						if (board[i + 1][j - 1] == blackPiece || board[i + 1][j - 1] == blackKing)
						{
							validCount += 2;
						}

						//white piece in front right
						if (board[i - 1][j + 1] == whitePiece || board[i - 1][j + 1] == whiteKing)
						{
							validCount++;

							if (board[i - 2][j + 2] == blackPiece || board[i - 2][j + 2] == blackKing || board[i - 2][j + 2] == whitePiece || board[i - 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//white piece in front left
						if (board[i - 1][j - 1] == whitePiece || board[i - 1][j - 1] == whiteKing)
						{
							validCount++;

							if (board[i - 2][j - 2] == blackPiece || board[i - 2][j - 2] == blackKing || board[i - 2][j - 2] == whitePiece || board[i - 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						//white piece back right
						if (board[i + 1][j + 1] == whitePiece || board[i + 1][j + 1] == whiteKing)
						{
							validCount++;

							if (board[i + 2][j + 2] == blackPiece || board[i + 2][j + 2] == blackKing || board[i + 2][j + 2] == whitePiece || board[i + 2][j + 2] == whiteKing)
							{
								validCount++;
							}
						}

						//white piece back left
						if (board[i + 1][j - 1] == whitePiece || board[i + 1][j - 1] == whiteKing)
						{
							validCount++;

							if (board[i + 2][j - 2] == blackPiece || board[i + 2][j - 2] == blackKing || board[i + 2][j - 2] == whitePiece || board[i + 2][j - 2] == whiteKing)
							{
								validCount++;
							}
						}

						if (validCount == 8)
						{
							drawCount++;
						}
					}
				}
			}

			deadCount(0);

			if (drawCount == alive)
			{
				win = 4;
			}
		}
	}
}

int main()
{
	char s;
	std::cout << "To select a piece, type the x coordinate and hit enter and type the y coordinate and hit enter." << std::endl << "To move, do the same process but for a new position. ";
	std::cout << std::endl << "Valid moves are 1 diagonal left or right and 2 diagonal left or right if you are jumping a piece." << std::endl << "Only the king can move and jump backwards";
	std::cout << std::endl << "Do you understand?";
	std::cin >> s;

	defaultLocations();

	while (gameOver == 0)
		switch (win)
		{
		case 0:
			drawBoard();
			tieGame();
			bSelection();
			drawBoard();
			tieGame();
			wSelection();
			break;
		case 1:
			gameOver = 1;
			drawBoard();
			std::cout << "black wins" << std::endl;
			break;
		case 2:
			gameOver = 1;
			drawBoard();
			std::cout << "white wins" << std::endl;
			break;
		case 3:
			gameOver = 1;
			drawBoard();
			std::cout << "draw white can't move" << std::endl;
			break;
		case 4:
			gameOver = 1;
			drawBoard();
			std::cout << "draw black can't move" << std::endl;
			break;
		}
}
