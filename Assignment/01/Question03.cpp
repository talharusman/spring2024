#include <iostream>
#include <cmath>
using namespace std;

class ChessPiece
{
private:
    string name;
    string color;
    char symbol;

public:
    ChessPiece(string name = "Pawn", string color = "white", char symbol = 'p')
    {
        this->name = name;
        this->color = color;
        this->symbol = symbol;
    }

    // Setter functions
    void setName(string name)
    {
        this->name = name;
    }

    void setColor(string color)
    {
        this->color = color;
    }

    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }

    // Getter functions
    string getName()
    {
        return name;
    }

    string getColor()
    {
        return color;
    }

    char getSymbol()
    {
        return symbol;
    }
};

class ChessBoard
{
private:
    ChessPiece board[8][8];

public:
    ChessBoard()
    {
        ChessPiece r("Rook", "white", 'r'), n("Knight", "white", 'n'), b("Bishop", "white", 'b'), q("Queen", "white", 'q'), k("King", "white", 'k'),
            p("pawn", "white", 'p'), P("pawn", "black", 'P'),
            R("Rook", "black", 'R'), N("Knight", "black", 'N'), B("Bishop", "black", 'B'), Q("Queen", "black", 'Q'), K("King", "black", 'K');

        board[0][0] = r;
        board[0][1] = n;
        board[0][2] = b;
        board[0][3] = q;
        board[0][4] = k;
        board[0][5] = b;
        board[0][6] = n;
        board[0][7] = r;

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = p;
            board[6][i] = P;
        }

        board[7][0] = R;
        board[7][1] = N;
        board[7][2] = B;
        board[7][3] = Q;
        board[7][4] = K;
        board[7][5] = B;
        board[7][6] = N;
        board[7][7] = R;

        // Initialize other squares to nullptr
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = ChessPiece("", "", '-');
            }
        }
    }

    bool movepiece(string source, string destination)
    {
        int sour_row, sour_col, des_row, des_col;
        sour_col = source[0] - 'a';
        sour_row = source[1] - '1';
        des_col = destination[0] - 'a';
        des_row = destination[1] - '1';

        if (board[sour_row][sour_col].getSymbol() != 'n' && board[sour_row][sour_col].getSymbol() != 'N')
        {
            cout << "on " << source << " no knight piece: " << endl
                 << "Enter the valid parameters:" << endl;
            return false;
        }
        else if (abs(sour_col - des_col) != 1 || abs(sour_row - des_row) != 2)
        {
            cout << "You can't move here:" << endl;
            return false;
        }
        else if (board[des_row][des_col].getSymbol() != '-')
        {
            cout << "you can't move here because there is already a piece:" << endl;
            return false;
        }
        else
        {
            // move the piece
            char tamp = board[sour_row][sour_col].getSymbol();
            board[sour_row][sour_col] = ChessPiece("", "", '-');
            board[des_row][des_col].setSymbol(tamp);
            return true;
        }
    }

    void display()
    {
        cout << "\n\n   a b c d e f g h " << endl;
        cout << " +-----------------+" << endl;
        int count = 8;
        for (int i = 7; i >= 0; i--)
        {
            cout << count << "| ";
            for (int j = 0; j < 8; j++)
            {

                cout << board[i][j].getSymbol() << " ";
            }
            // cout<<endl;
            cout << "|" << count << endl;
            count--;
        }
        cout << " +-----------------+" << endl;
        cout << "   a b c d e f g h " << endl
             << endl;
    }
};

int main()
{
    ChessBoard board;
    board.display();
    cout << "MOVE FOR WHITE PAWN  " << endl
         << endl;
    board.movepiece("b1", "c3");
    board.display();

    cout << "MOVE FOR BLACK KNIGHT  " << endl
         << endl;
    board.movepiece("b8", "c6");
    board.display();

    return 0;
}
