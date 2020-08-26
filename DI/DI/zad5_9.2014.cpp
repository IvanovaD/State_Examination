#include <iostream>
using namespace std;

struct Point{
public : int x, y;
	Point(int i, int j)
	{
		x = i;
		y = j;
	}
	Point()
	{
		x = 0;
		y = 0;
	}
};
class GamePlayer
{
	
    protected: Point position;
    public :
	Point getPosition() const
	{return position;}
	GamePlayer(int i, int j)
	{
		position.x = i;
		position.y = j;
	}
	/*можем да върнем вместо масив std::вектор*/
    virtual Point* allowedMoves(int** GameBoard, int size) const = 0;
	virtual void print() = 0;

	virtual ~GamePlayer() //хубаво е да имаме виртуален деструктор в базовия клас потенциално
	{}
};

class Knight : public GamePlayer
{

public :
	Knight(int i, int j) : GamePlayer(i, j)
	{}
	
	Point* allowedMoves(int *GameBoard[], int size) const
	{
		Point allowedMoves[8];
		int k = 0;
		for (int i = position.x - 1; i < position.x + 2; i++)
		{
			for (int j = position.y - 1; j < position.y + 2; j++)
			{
				if (i > 0 && i < size && j>0 && j< size && (*GameBoard+i)[j] == 0)
				{
					allowedMoves[k]=Point(i,j);
					k++;

				}
			}

		}
		Point* allowed = new Point[k];
		for (int i = 0; i < k; i++)
			allowed[i] = allowedMoves[i];
		return allowedMoves;
	}

	void print()
	{
		cout << "Knight:" << getPosition().x << "," << getPosition().y << ")" << endl;
	}
};


class SeaMonster : public GamePlayer
{public:

	SeaMonster(int i, int j) : GamePlayer(i, j)
	{}
	Point* allowedMoves(int *GameBoard[], int size) const
	{
		Point allowedMoves[8];
		int k = 0;
		for (int i = position.x - 1; i < position.x + 2; i++)
		{
			for (int j = position.y - 1; j < position.y + 2; j++)
			{
				while (i > 0 && i < size && j>0 && j < size && (*GameBoard + i)[j] == 2)
				{

					allowedMoves[k] = Point(i, j);
					
					k++;

				}
			}

		}
		Point* allowed = new Point[k];
		for (int i = 0; i < k; i++)
			allowed[i] = allowedMoves[i];
		return allowedMoves;
	}
	void setPosition(int x, int y)
	{

	}
};

void allMoves(GamePlayer *players[], int length, int* Gameboard[], int size)
{
	for (int i = 0; i < length; i++)
	{
		
		Point* allowedMoves = (*players[i]).allowedMoves(Gameboard, size);
		/**/
	}

}
int main()
{
	int N;
	int** GameBoard = new int*[N];
	for (int i = 0; i < N; i++)
	{
		GameBoard[i] = new int[N];
	}
	Knight knight = Knight(1, 2);
	Point *allowedMoves = knight.allowedMoves(GameBoard, N);
	return 0;

}