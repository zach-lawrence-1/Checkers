#include<iostream>
#include<vector>

int win = 0;
int turn = 2;

//two extra rows for dead pieces
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

class whiteCheckers {
public:
	int valid = 0;
	int x = 1;
	int y = 0;
	std::string piece = "w";
	std::string kingPiece = "W";
	int death = 0;
	int king = 0;

};
whiteCheckers cw1, cw2, cw3, cw4, cw5, cw6, cw7, cw8, cw9, cw10, cw11, cw12;

std::vector<whiteCheckers*> wCheckers;

class blackCheckers {
public:
	int valid = 0;
	int x = 0;
	int y = 7;
	std::string piece = "b";
	std::string kingPiece = "B";
	int death = 0;
	int king = 0;
};
blackCheckers cb1, cb2, cb3, cb4, cb5, cb6, cb7, cb8, cb9, cb10, cb11, cb12;

std::vector<blackCheckers*> bCheckers;

void defaultLocations()
{
	//white checker objects pushed into vector container
	wCheckers.push_back(&cw1);
	wCheckers.push_back(&cw2);
	wCheckers.push_back(&cw3);
	wCheckers.push_back(&cw4);
	wCheckers.push_back(&cw5);
	wCheckers.push_back(&cw6);
	wCheckers.push_back(&cw7);
	wCheckers.push_back(&cw8);
	wCheckers.push_back(&cw9);
	wCheckers.push_back(&cw10);
	wCheckers.push_back(&cw11);
	wCheckers.push_back(&cw12);

	//black checker objects pushed into vector container
	bCheckers.push_back(&cb1);
	bCheckers.push_back(&cb2);
	bCheckers.push_back(&cb3);
	bCheckers.push_back(&cb4);
	bCheckers.push_back(&cb5);
	bCheckers.push_back(&cb6);
	bCheckers.push_back(&cb7);
	bCheckers.push_back(&cb8);
	bCheckers.push_back(&cb9);
	bCheckers.push_back(&cb10);
	bCheckers.push_back(&cb11);
	bCheckers.push_back(&cb12);

	int a = 1;
	int c = 0;
	//auto white piece placement
	for (auto& w : wCheckers) {
		w->x = a;
		a += 2;
		c++;

		if (c == 4)
		{
			a = 0;
		}

		if (c == 8)
		{
			a = 1;
		}

		if (c > 4 && c < 9)
		{
			w->y = 1;
		}

		if (c > 8)
		{
			w->y = 2;
		}
		board[w->y][w->x] = w->piece;
	}

	a = 0;
	c = 0;
	//auto black piece placement
	for (auto& b : bCheckers) {
		b->x = a;
		a += 2;
		c++;

		if (c == 4)
		{
			a = 1;
		}

		if (c == 8)
		{
			a = 0;
		}

		if (c > 4 && c < 9)
		{
			b->y = 6;
		}

		if (c > 8)
		{
			b->y = 5;
		}
		board[b->y][b->x] = b->piece;
	}
}

void drawBoard()
{
	system("cls");

	//your board
	std::cout << "      0     1     2     3     4     5     6     7" << std::endl;
	std::cout << "    " << "_______________________________________________" << std::endl;
	std::cout << "   |     " << "|   " << "  |   " << "  |  " << "   |   " << "  |  " << "   |  " << "   |  " << "   |" << std::endl;
	std::cout <<" 0 " << "|  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "  |  " << board[0][6] << "  |  " << board[0][7] << "  |" << std::endl;
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

void doubleJumpB(int a, int selectx, int selecty);

void bSelection()
{
	if (win == 0)
	{
		int currx = 0;
		int curry = 0;
		int selectx = 0;
		int selecty = 0;
		int same = 0;
		turn = 1;
		int jump = 0;
		int a = 0;
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
		same = 0;

		for (auto& b : bCheckers)
		{
			if (selectx == b->x && selecty == b->y)
			{
				b->valid = 0;
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
				//same location
				if (currx == selectx && curry == selecty)
				{
					b->valid = 0;
				}

				//you can move 1 forward and 1 right if its in bounds of the board
				if ((currx == (selectx + 1) && (curry == (selecty - 1)) || (curry == (selecty + 1) && b->king == 1)))
				{
					b->valid = 1;
					//move is out of bounds
					if (currx > 7 || curry > 7)
					{
						b->valid = 0;
					}

					//move is the same as another piece of the same kind
					for (auto& b : bCheckers)
					{
						if (currx == b->x && curry == b->y)
						{
							same = 1;
						}
					}

					if (curry == selecty + 1 && b->king == 0)
					{
						b->valid = 0;
					}

					if (same == 1)
					{
						b->valid = 0;
					}
				}

				//you can move 1 forward and 1 left if its in bounds of the board
				if ((currx == (selectx - 1)) && (curry == (selecty - 1) || (curry == (selecty + 1) && b->king == 1)))
				{
					b->valid = 1;
					//move is out of bounds
					if (currx > 7 || curry > 7)
					{
						b->valid = 0;
					}

					//move is the same as another piece of the same kind
					for (auto& b : bCheckers)
					{
						if (currx == b->x && curry == b->y)
						{
							same = 1;
						}
					}

					if (curry == selecty + 1 && b->king == 0)
					{
						b->valid = 0;
					}

					if (same == 1)
					{
						b->valid = 0;
					}
				}

				same = 0;
				//checks if black is trying to move into white piece
				for (auto& w : wCheckers)
				{
					for (auto& w : wCheckers)
					{
						if (w->x == currx && w->y == curry)
						{
							if (w->death == 0)
							{
								same = 1;
							}
							if (w->death == 1)
							{
								b->valid = 1;
							}
						}
					}

					if (same == 0)
					{
						//right jump
						if ((currx == selectx + 2) && curry == selecty - 2)
						{
							if ((w->x == selectx + 1) && w->y == selecty - 1)
							{
								if (w->death == 1)
								{
									b->valid = 0;
								}
								if (w->death == 0)
								{
									b->valid = 1;
									w->death = 1;
									jump = 1;
								}
							}
						}

						//left jump
						if ((currx == selectx - 2) && curry == selecty - 2)
						{
							if ((w->x == selectx - 1) && w->y == selecty - 1)
							{
								if (w->death == 1)
								{
									b->valid = 0;
								}
								if (w->death == 0)
								{
									b->valid = 1;
									w->death = 1;
									jump = 1;
								}
							}
						}

						//king right jump
						if ((currx == selectx + 2) && (curry == selecty + 2 && b->king == 1))
						{
							if ((w->x == selectx + 1) && w->y == selecty + 1)
							{
								if (w->death == 1)
								{
									b->valid = 0;
								}
								if (w->death == 0)
								{
									b->valid = 1;
									w->death = 1;
									jump = 1;
								}
							}
						}

						//king left jump
						if ((currx == selectx - 2) && (curry == selecty + 2 && b->king == 1))
						{
							if ((w->x == selectx - 1) && w->y == selecty + 1)
							{
								if (w->death == 1)
								{
									b->valid = 0;
								}
								if (w->death == 0)
								{
									b->valid = 1;
									w->death = 1;
									jump = 1;
								}
							}
						}
					}

					if (same == 1)
					{
						b->valid = 0;
					}
				}

				//prevents piece from moving solely across x axis
				if ((currx >= selectx || currx <= selectx) && curry == selecty)
				{
					b->valid = 0;
				}
				
				//deals with dead pieces
				for (auto w : wCheckers)
				{
					if (w->death == 1)
					{
						a++;
						board[w->y][w->x] = " ";
						w->x = 0;
						w->y = 0;
					}
					if (w->death == 0)
					{
						if (w->king == 0)
						{
							board[w->y][w->x] = w->piece;
						}
						if (w->king == 1)
						{
							board[w->y][w->x] = w->kingPiece;
						}
					}
				}
				
				//deals with valid or invalid cases
				if (b->valid == 0)
				{
					if (b->king == 0)
					{
						board[b->y][b->x] = b->piece;
					}
					if (b->king == 1)
					{
						board[b->y][b->x] = b->kingPiece;
					}
					drawBoard();
					std::cout << "invalid move " << std::endl;
					bSelection();
				}

				if (b->valid == 1)
				{
					if (curry == 0)
					{
						b->king = 1;
					}
					board[b->y][b->x] = " ";
					b->x = currx;
					b->y = curry;
					b->valid = 0;
					if (b->king == 0)
					{
						board[b->y][b->x] = b->piece;
					}
					if (b->king == 1)
					{
						board[b->y][b->x] = b->kingPiece;
					}
					if (jump == 1)
					{
						drawBoard();
						std::cout << std::endl << "Can you jump another piece with the same piece? Y or N";
						std::string select;
						std::cin >> select;
						if (select == "y" || select == "Y")
						{
							doubleJumpB(a, currx, curry);
						}
					}
				}

				//checks if all opposite pieces are dead
				if (a == 12)
				{
					win += 1;
					std::cout << win;
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

void doubleJumpB(int a, int selectx, int selecty)
{
	int currx = 0;
	int curry = 0;
	int same = 0;
	same = 0;
	turn = 1;
	for (auto& b : bCheckers)
	{
		if (selectx == b->x && selecty == b->y)
		{
			b->valid = 0;
			std::cout << "now select a second jump ";
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
			//same location
			if (b->x == currx && b->y == curry)
			{
				b->valid = 0;
			}

			//trying to move into a white piece
			for (auto& w : wCheckers)
			{
				for (auto& w : wCheckers)
				{
					if (w->x == currx && w->y == curry)
					{
						if (w->death == 0)
						{
							same = 1;
						}
						if (w->death == 1)
						{
							same = 0;
						}
					}
				}

				if (same == 0)
				{
					//jump right
					if ((currx == selectx + 2) && curry == selecty - 2)
					{
						if ((w->x == selectx + 1) && w->y == selecty - 1)
						{
							if (w->death == 1)
							{
								b->valid = 0;
							}
							if (w->death == 0)
							{
								b->valid = 1;
								w->death = 1;
							}
						}
					}

					//jump left
					if ((currx == selectx - 2) && curry == selecty - 2)
					{
						if ((w->x == selectx - 1) && w->y == selecty - 1)
						{
							if (w->death == 1)
							{
								b->valid = 0;
							}
							if (w->death == 0)
							{
								b->valid = 1;
								w->death = 1;
							}
						}
					}

					//king right jump
					if ((currx == selectx + 2) && (curry == selecty + 2 && b->king == 1))
					{
						if ((w->x == selectx + 1) && w->y == selecty + 1)
						{
							if (w->death == 1)
							{
								b->valid = 0;
							}
							if (w->death == 0)
							{
								b->valid = 1;
								w->death = 1;
							}
						}
					}
					
					//king left jump
					if ((currx == selectx - 2) && (curry == selecty + 2 && b->king == 1))
					{
						if ((w->x == selectx - 1) && w->y == selecty + 1)
						{
							if (w->death == 1)
							{
								b->valid = 0;
							}
							if (w->death == 0)
							{
								b->valid = 1;
								w->death = 1;
							}
						}
					}
				}

				if (same == 1)
				{
					b->valid = 0;
				}
			}

			//prevents piece from moving solely across x axis
			if ((currx >= selectx || currx <= selectx) && curry == selecty)
			{
				b->valid = 0;
			}

			//deals with dead pieces
			for (auto w : wCheckers)
			{
				if (w->death == 1)
				{
					a++;
					board[w->y][w->x] = " ";
					w->x = 0;
					w->y = 0;
				}
				if (w->death == 0)
				{
					if (w->king == 0)
					{
						board[w->y][w->x] = w->piece;
					}
					if (w->king == 1)
					{
						board[w->y][w->x] = w->kingPiece;
					}
				}
			}

			//deals with valid or invalid pieces
			if (b->valid == 0)
			{
				if (b->king == 0)
				{
					board[b->y][b->x] = b->piece;
				}
				if (b->king == 1)
				{
					board[b->y][b->x] = b->kingPiece;
				}
			}

			if (b->valid == 1)
			{
				if (curry == 0)
				{
					b->king = 1;
				}
				board[b->y][b->x] = " ";
				b->x = currx;
				b->y = curry;
				b->valid = 0;
				if (b->king == 0)
				{
					board[b->y][b->x] = b->piece;
				}
				if (b->king == 1)
				{
					board[b->y][b->x] = b->kingPiece;
				}
				drawBoard();
				std::cout << std::endl << "Can you jump another piece with the same piece? Y or N";
				std::string select;
				std::cin >> select;
				if (select == "y" || select == "Y")
				{
					doubleJumpB(a, currx, curry);
				}
			}

			//checks if all opposite pieces are dead
			if (a == 12)
			{
				win += 1;
				std::cout << win;
			}
		}
	}
}

void doubleJumpA(int a, int selectx, int selecty);

void wSelection()
{
	if (win == 0)
	{
		turn = 2;
		int currx = 0;
		int curry = 0;
		int selectx = 0;
		int selecty = 0;
		int same = 0;
		int jump = 0;
		int a = 0;
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
		same = 0;
		
		for (auto& w : wCheckers)
		{
			if (selectx == w->x && selecty == w->y)
			{
				w->valid = 0;
				//verifies successfull selection
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
				//same location
				if (currx == selectx && curry == selecty)
				{
					w->valid = 0;
				}

				//you can move 1 forward and 1 right if its in bounds of the board
				if ((currx == (selectx + 1)) && (curry == (selecty + 1) || (curry == (selecty - 1) && w->king == 1)))
				{
					w->valid = 1;
					//move is out of bounds
					if (currx > 7 || curry > 7)
					{
						w->valid = 0;
					}

					//move is the same as another piece of the same kind for in bounds
					for (auto& w : wCheckers)
					{
						if (currx == w->x && curry == w->y)
						{
							same = 1;
						}
					}

					if (curry == selecty - 1 && w->king == 0)
					{
						w->valid = 0;
					}

					if (same == 1)
					{
						w->valid = 0;
					}
				}


				//move 1 forward, 1 left
				if ((currx == (selectx - 1)) && (curry == (selecty + 1) || (curry == (selecty - 1) && w->king == 1)))
				{
					w->valid = 1;
					//move is out of bounds
					if (currx > 7 || curry > 7)
					{
						w->valid = 0;
					}

					//move is the same as another piece of the same kind for in bounds
					for (auto& w : wCheckers)
					{
						if (currx == w->x && curry == w->y)
						{
							same = 1;
						}
					}

					if (curry == selecty - 1 && w->king == 0)
					{
						w->valid = 0;
					}

					if (same == 1)
					{
						w->valid = 0;
					}
				}

				same = 0;
				//checks if white is trying to move into black piece 
				for (auto& b : bCheckers)
				{
					for (auto& b : bCheckers)
					{
						if (b->x == currx && b->y == curry)
						{
							if (b->death == 0)
							{
								same = 1;
							}
							if (b->death == 1)
							{
								same = 0;
							}
						}
					}

					if (same == 0)
					{
						//right jump
						if ((currx == selectx + 2) && curry == selecty + 2)
						{
							if ((b->x == selectx + 1) && b->y == selecty + 1)
							{
								if (b->death == 1)
								{
									w->valid = 0;
								}
								if (b->death == 0)
								{
									w->valid = 1;
									b->death = 1;
									jump = 1;
								}
							}
						}

						//left jump
						if ((currx == selectx - 2) && curry == selecty + 2)
						{
							if ((b->x == selectx - 1) && b->y == selecty + 1)
							{
								if (b->death == 1)
								{
									w->valid = 0;
								}
								if (b->death == 0)
								{
									w->valid = 1;
									b->death = 1;
									jump = 1;
								}
							}
						}

						//right king jump
						if ((currx == selectx + 2) && (curry == selecty - 2 && w->king == 1))
						{
							if ((b->x == selectx + 1) && b->y == selecty - 1)
							{
								if (b->death == 1)
								{
									w->valid = 0;
								}
								if (b->death == 0)
								{
									w->valid = 1;
									b->death = 1;
									jump = 1;
								}
							}
						}

						//left king jump
						if ((currx == selectx - 2) && (curry == selecty - 2 && w->king == 1))
						{
							if ((b->x == selectx - 1) && b->y == selecty - 1)
							{
								if (b->death == 1)
								{
									w->valid = 0;
								}
								if (b->death == 0)
								{
									w->valid = 1;
									b->death = 1;
									jump = 1;
								}
							}
						}
					}

					if (same == 1)
					{
						w->valid = 0;
					}
				}
				
				//prevents piece from moving solely across x axis
				if ((currx >= selectx || currx <= selectx) && curry == selecty)
				{
					w->valid = 0;
				}

				//deals with dead pieces
				for (auto b : bCheckers)
				{
					if (b->death == 1)
					{
						a++;
						board[b->y][b->x] = " ";
						b->x = 0;
						b->y = 0;
					}
					if (b->death == 0)
					{
						if (b->king == 0)
						{
							board[b->y][b->x] = b->piece;
						}
						if (b->king == 1)
						{
							board[b->y][b->x] = b->kingPiece;
						}
					}
				}

				//deals with valid or invalid cases
				if (w->valid == 0)
				{
					//add king piece
					if (w->king == 0)
					{
						board[w->y][w->x] = w->piece;
					}
					if (w->king == 1)
					{
						board[w->y][w->x] = w->kingPiece;
					}
					drawBoard();
					std::cout << "invalid move " << std::endl;
					wSelection();
				}

				if (w->valid == 1)
				{
					if (curry == 7)
					{
						w->king = 1;
					}
					board[w->y][w->x] = " ";
					w->x = currx;
					w->y = curry;
					w->valid = 0;
					if (w->king == 0)
					{
						board[w->y][w->x] = w->piece;
					}
					if (w->king == 1)
					{
						board[w->y][w->x] = w->kingPiece;
					}
					if (jump == 1)
					{
						drawBoard();
						std::cout << std::endl << "Can you jump another piece with the same piece? Y or N";
						std::string select;
						std::cin >> select;
						if (select == "y" || select == "Y")
						{
							doubleJumpA(a, currx, curry);
						}
					}
				}
				
				//checks if all opposite pieces are dead
				if (a == 12)
				{
					win += 2;
					std::cout << win;
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

void doubleJumpA(int a, int selectx, int selecty)
{
	int currx = 0;
	int curry = 0;
	int same = 0;
	turn = 2;
	same = 0;
	for (auto& w : wCheckers)
	{
		if (selectx == w->x && selecty == w->y)
		{
			w->valid = 0;
			std::cout << "now select a second jump ";
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
			//same location
			if (w->x == currx && w->y == curry)
			{
				w->valid = 0;
			}

			same = 0;
			//checks if white is trying to move into black piece
			for (auto& b : bCheckers)
			{
				for (auto& b : bCheckers)
				{
					if (b->x == currx && b->y == curry)
					{
						if (b->death == 0)
						{
							same = 1;
						}
						if (b->death == 1)
						{
							same = 0;
						}
					}
				}

				if (same == 0)
				{
					//right jump
					if ((currx == selectx + 2) && curry == selecty + 2)
					{
						if ((b->x == selectx + 1) && b->y == selecty + 1)
						{
							if (b->death == 1)
							{
								w->valid = 0;
							}
							if (b->death == 0)
							{
								w->valid = 1;
								b->death = 1;
							}
						}
					}

					//left jump
					if ((currx == selectx - 2) && curry == selecty + 2)
					{
						if ((b->x == selectx - 1) && b->y == selecty + 1)
						{
							if (b->death == 1)
							{
								w->valid = 0;
							}
							if (b->death == 0)
							{
								w->valid = 1;
								b->death = 1;
							}
						}
					}

					//right king jump
					if ((currx == selectx + 2) && (curry == selecty - 2 && w->king == 1))
					{
						if ((b->x == selectx + 1) && b->y == selecty - 1)
						{
							if (b->death == 1)
							{
								w->valid = 0;
							}
							if (b->death == 0)
							{
								w->valid = 1;
								b->death = 1;
							}
						}
					}

					//left king jump
					if ((currx == selectx - 2) && (curry == selecty - 2 && w->king == 1))
					{
						if ((b->x == selectx - 1) && b->y == selecty - 1)
						{
							if (b->death == 1)
							{
								w->valid = 0;
							}
							if (b->death == 0)
							{
								w->valid = 1;
								b->death = 1;
							}
						}
					}
				}

				if (same == 1)
				{
					w->valid = 0;
				}
			}

			//prevents piece from moving solely across x axis
			if ((currx >= selectx || currx <= selectx) && curry == selecty)
			{
				w->valid = 0;
			}

			//deals withd dead pieces
			for (auto b : bCheckers)
			{
				if (b->death == 1)
				{
					a++;
					board[b->y][b->x] = " ";
					b->x = 0;
					b->y = 0;
				}
				if (b->death == 0)
				{
					if (b->king == 0)
					{
						board[b->y][b->x] = b->piece;
					}
					if (b->king == 1)
					{
						board[b->y][b->x] = b->kingPiece;
					}
				}
			}

			//deals with valid or invalid cases
			if (w->valid == 0)
			{
				//add king piece
				if (w->king == 0)
				{
					board[w->y][w->x] = w->piece;
				}
				if (w->king == 1)
				{
					board[w->y][w->x] = w->kingPiece;
				}
			}

			if (w->valid == 1)
			{
				if (curry == 7)
				{
					w->king = 1;
				}
				board[w->y][w->x] = " ";
				w->x = currx;
				w->y = curry;
				w->valid = 0;
				if (w->king == 0)
				{
					board[w->y][w->x] = w->piece;
				}
				if (w->king == 1)
				{
					board[w->y][w->x] = w->kingPiece;
				}

				drawBoard();
				std::cout << std::endl << "Can you jump another piece with the same piece? Y or N";
				std::string select;
				std::cin >> select;
				if (select == "y" || select == "Y")
				{
					doubleJumpA(a, currx, curry);
				}
			}

			//checks if all opposite pieces are dead
			if (a == 12)
			{
				win += 2;
				std::cout << win;
			}
		}
	}
}

//check if unable to jump on edges at x=1 and x=6
void tieGame()
{
	if (win == 0)
	{
		int selectx = 0;
		int selecty = 0;
		int black = 0;
		int white = 0;
		int drawCount = 0;
		int validCount = 0;

		//checks if white can't move
		if (turn == 1)
		{
			for (auto& w : wCheckers)
			{
				auto cw = w;
				cw->valid = 1;
				selectx = w->x;
				selecty = w->y;
				validCount = 0;

				if (selectx == 0 && selecty == 0)
				{
					validCount = 40;
				}

				if (validCount != 40)
				{
					if (cw->king == 1)
					{
						if (selecty == 0 || selecty == 7)
						{
							validCount = 4;
						}

						std::cout << validCount;
					}

					//try to do valid count and if its a certain value, it breaks the for loop
					for (auto& w : wCheckers)
					{
						if (cw->king == 0)
						{
							//move right invalid
							if ((selectx + 1 == w->x && selecty + 1 == w->y))
							{
								validCount += 2;
							}

							//move left invalid
							if ((selectx - 1 == w->x && selecty + 1 == w->y))
							{
								validCount += 2;
							}

							// left edge
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							if (validCount == 4)
							{
								cw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}

						if (cw->king == 1)
						{
							//move right invalid
							if ((selectx + 1 == w->x && selecty + 1 == w->y))
							{
								validCount += 2;
							}

							//move left invalid
							if ((selectx - 1 == w->x && selecty + 1 == w->y))
							{
								validCount += 2;
							}

							//move right behind invalid
							if ((selectx + 1 == w->x && selecty - 1 == w->y))
							{
								validCount += 2;
							}

							//move left behind invalid
							if ((selectx - 1 == w->x && selecty - 1 == w->y))
							{
								validCount += 2;
							}

							// left edge in front
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							//left edge behind
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							//right edge front
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							//right edge behind
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							if (validCount == 8)
							{
								cw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}
					}

					//checks if white has a black piece in any of its forward and backward moves
					for (auto& b : bCheckers)
					{
						if (cw->king == 0)
						{
							//white cant jump out of bounds left edge
							if (selectx == 1 && selectx - 1 == b->x && selecty + 1 == b->y)
							{
								validCount++;
							}

							//white cant jump out of bounds right edge
							if (selectx == 6 && selectx + 1 == b->x && selecty + 1 == b->y)
							{
								validCount++;
							}

							//white cant jump out of bounds on bottom edge
							if (selecty == 6)
							{
								if (selectx + 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
								if (selectx - 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
							}

							//move right invalid
							if ((selectx + 1 == b->x && selecty + 1 == b->y))
							{
								validCount++;
								black = 1;
							}

							//move right jump invalid
							if (black == 1)
							{
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							//move left invalid
							if ((selectx - 1 == b->x && selecty + 1 == b->y))
							{
								validCount++;
								black = 2;
							}

							if (black == 2)
							{
								//move left jump invalid
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							// left edge
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							if (validCount == 4)
							{
								cw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}

						if (cw->king == 1)
						{
							//white king cant jump out of bounds left edge
							if (selectx == 1)
							{
								if (selectx - 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
								if (selectx - 1 == b->x && selecty - 1 == b->y)
								{
									validCount++;
								}
							}

							//white king cant jump out of bounds right edge
							if (selectx == 6)
							{
								if (selectx + 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
								if (selectx + 1 == b->x && selecty - 1 == b->y)
								{
									validCount++;
								}
							}

							//white king cant jump out of bounds bottom edge
							if (selecty == 6)
							{
								if (selectx + 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
								if (selectx - 1 == b->x && selecty + 1 == b->y)
								{
									validCount++;
								}
							}

							//white king cant jump out of bounds top edge
							if (selecty == 1)
							{
								if (selectx + 1 == b->x && selecty - 1 == b->y)
								{
									validCount++;
								}
								if (selectx - 1 == b->x && selecty - 1 == b->y)
								{
									validCount++;
								}
							}

							//move right invalid
							if ((selectx + 1 == b->x && selecty + 1 == b->y))
							{
								validCount++;
								black = 1;
							}

							//move right jump invalid
							if (black == 1)
							{
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							//move left invalid
							if ((selectx - 1 == b->x && selecty + 1 == b->y))
							{
								validCount++;
								black = 2;
							}

							if (black == 2)
							{
								//move left jump invalid
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							//move right backward invalid
							if ((selectx + 1 == b->x && selecty - 1 == b->y))
							{
								validCount++;
								black = 3;
							}

							//move right backward jump invalid
							if (black == 3)
							{
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							//move left backward invalid
							if ((selectx - 1 == b->x && selecty - 1 == b->y))
							{
								validCount++;
								black = 4;
							}

							//move left backward jump invalid
							if (black == 4)
							{
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										black = 0;
									}
								}
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										black = 0;
									}
								}
							}

							// left edge
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							// left backward edge
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							//right backward edge
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							if (validCount == 8)
							{
								cw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}
					}
				}

				if (validCount == 40)
				{
					drawCount++;
					cw->valid = 0;
				}
			}

			if (drawCount == 12)
			{
				win += 3;
			}
		}

		//checks if black can't move
		if (turn == 2)
		{
			for (auto& b : bCheckers)
			{
				auto bw = b;
				bw->valid = 1;
				selectx = b->x;
				selecty = b->y;
				validCount = 0;

				if (selectx == 0 && selecty == 0)
				{
					validCount = 40;
				}

				if (validCount != 40)
				{
					if (bw->king == 1)
					{
						if (selecty == 0 || selecty == 7)
						{
							validCount = 4;
						}
					}

					//try to do valid count and if its a certain value, it breaks the for loop
					for (auto& b : bCheckers)
					{
						if (bw->king == 0)
						{
							//move right invalid
							if ((selectx + 1 == b->x && selecty - 1 == b->y))
							{
								validCount += 2;
							}

							//move left invalid
							if ((selectx - 1 == b->x && selecty - 1 == b->y))
							{
								validCount += 2;
							}

							// left edge
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							if (validCount == 4)
							{
								bw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}

						if (bw->king == 1)
						{
							//move right invalid
							if ((selectx + 1 == b->x && selecty - 1 == b->y))
							{
								validCount += 2;
							}

							//move left invalid
							if ((selectx - 1 == b->x && selecty - 1 == b->y))
							{
								validCount += 2;
							}

							//move right behind invalid
							if ((selectx + 1 == b->x && selecty + 1 == b->y))
							{
								validCount += 2;
							}

							//move left behind invalid
							if ((selectx - 1 == b->x && selecty + 1 == b->y))
							{
								validCount += 2;
							}

							// left edge in front
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							//left edge behind
							if (selectx == 0 && b->x == selectx + 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							//right edge front
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty - 1)
							{
								validCount += 2;
							}

							//right edge behind
							if (selectx == 7 && b->x == selectx - 1 && b->y == selecty + 1)
							{
								validCount += 2;
							}

							if (validCount == 8)
							{
								bw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}
					}

					//checks if black has a white piece in any of its forward and backward moves
					for (auto& w : wCheckers)
					{
						if (bw->king == 0)
						{
							//black cant jump out of bounds left edge
							if (selectx == 1 && selectx - 1 == w->x && selecty - 1 == w->y)
							{
								validCount++;
							}

							//black cant jump out of bounds right edge
							if (selectx == 6 && selectx + 1 == w->x && selecty - 1 == w->y)
							{
								validCount++;
							}

							//black cant jump out of bounds top edge
							if (selecty == 1)
							{
								if (selectx + 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
								if (selectx - 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
							}

							//move right invalid
							if ((selectx + 1 == w->x && selecty - 1 == w->y))
							{
								validCount++;
								white = 1;
							}

							//move right jump invalid
							if (white == 1)
							{
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							//move left invalid
							if ((selectx - 1 == w->x && selecty - 1 == w->y))
							{
								validCount++;
								white = 2;
							}

							if (white == 2)
							{
								//move left jump invalid
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							// left edge
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							if (validCount == 4)
							{
								bw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}

						if (bw->king == 1)
						{
							//black king cant jump out of bounds left edge
							if (selectx == 1)
							{
								if (selectx - 1 == w->x && selecty + 1 == w->y)
								{
									validCount++;
								}
								if (selectx - 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
							}

							//black king cant jump out of bounds right edge
							if (selectx == 6)
							{
								if (selectx + 1 == w->x && selecty + 1 == w->y)
								{
									validCount++;
								}
								if (selectx + 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
							}

							//black king cant jump out of bounds top edge
							if (selecty == 1)
							{
								if (selectx + 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
								if (selectx - 1 == w->x && selecty - 1 == w->y)
								{
									validCount++;
								}
							}

							//black king cant jump out of bounds bottom edge
							if (selecty == 6)
							{
								if (selectx + 1 == w->x && selecty + 1 == w->y)
								{
									validCount++;
								}
								if (selectx - 1 == w->x && selecty + 1 == w->y)
								{
									validCount++;
								}
							}

							//move right invalid
							if ((selectx + 1 == w->x && selecty - 1 == w->y))
							{
								validCount++;
								white = 1;
							}

							//move right jump invalid
							if (white == 1)
							{
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							//move left invalid
							if ((selectx - 1 == w->x && selecty - 1 == w->y))
							{
								validCount++;
								white = 2;
							}

							if (white == 2)
							{
								//move left jump invalid
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty - 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty - 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							//move right backward invalid
							if ((selectx + 1 == w->x && selecty + 1 == w->y))
							{
								validCount++;
								white = 3;
							}

							//move right backward jump invalid
							if (white == 3)
							{
								for (auto& w : wCheckers)
								{
									if ((selectx + 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx + 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							//move left backward invalid
							if ((selectx - 1 == w->x && selecty + 1 == w->y))
							{
								validCount++;
								white = 4;
							}

							//move left backward jump invalid
							if (white == 4)
							{
								for (auto& w : wCheckers)
								{
									if ((selectx - 2 == w->x && selecty + 2 == w->y))
									{
										validCount++;
										white = 0;
									}
								}
								for (auto& b : bCheckers)
								{
									if ((selectx - 2 == b->x && selecty + 2 == b->y))
									{
										validCount++;
										white = 0;
									}
								}
							}

							// left edge
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							// left backward edge
							if (selectx == 0 && w->x == selectx + 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							//right edge
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty - 1)
							{
								validCount += 2;
							}

							//right backward edge
							if (selectx == 7 && w->x == selectx - 1 && w->y == selecty + 1)
							{
								validCount += 2;
							}

							if (validCount == 8)
							{
								bw->valid = 0;
								validCount = 0;
								drawCount++;
								break;
							}
						}
					}
				}

				if (validCount == 40)
				{
					drawCount++;
					bw->valid = 0;
				}
			}

			if (drawCount == 12)
			{
				win += 4;
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
	
	while(true)
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
				drawBoard();
				std::cout << "black wins" << std::endl;
				return 0;
			case 2:
				drawBoard();
				std::cout << "white wins" << std::endl;
				return 0;
			case 3:
				drawBoard();
				std::cout << "draw white can't move" << std::endl;
				return 0;
			case 4:
				drawBoard();
				std::cout << "draw black can't move" << std::endl;
				return 0;
		}
}
