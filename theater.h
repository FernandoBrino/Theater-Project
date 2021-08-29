#ifndef THEATER_H_INCLUDED
#define THEATER_H_INCLUDED

//template <typename Tipo>
struct Theater
{
    int size;
    int line, column;
    char *v;

    Theater(int qtLine, int qtColumn)
    {
        line = qtLine;
        column = qtColumn;
        size = line * column;
        v = new char[size];
        for (int i = 0; i < size; i++)
        {
            v[i] = '0';
        }
    }

    ~Theater()
    {
        delete[] v;
    }

    bool isAvaliable(int position)
    {
        if (v[position] == 'X')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void reserveChair(int lin, int col)
    {
        int position = lin * column + col;
        v[position] = 'X';
    }

    void returnChair(int lin, int col)
    {
        int position = lin * column + col;
        v[position] = '0';
    }

    void changeChair(int oldLin, int oldCol, int newLin, int newCol)
    {
        int newPosition = newLin * column + newCol;
        int oldPosition = oldLin * column + oldCol;
        v[newPosition] = 'X';
        v[oldPosition] = '0';
    }
};

#endif