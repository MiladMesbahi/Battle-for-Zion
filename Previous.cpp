#include "Previous.h"
#include "globals.h"
#include <iostream>

using namespace std;

// Constructor for Previous class. Initializes a Previous object that corresponds 
// to an Arena with nRows rows and nCols columns.
Previous::Previous(int nRows, int nCols)
    : m_rows(nRows), m_cols(nCols)
{
    // Initialize all grid points to 0
    for (int r = 0; r < nRows; r++)
        for (int c = 0; c < nCols; c++)
            m_previous[r][c] = 0;
}

// The dropACrumb function is called to notify the Previous object that the player has
// arrived at or stayed at a grid point. The function returns false if row r, column c 
// is not within bounds; otherwise, it returns true after recording the move.
bool Previous::dropACrumb(int r, int c)
{
    if (r < 1 || r > m_rows || c < 1 || c > m_cols)
        return false;
    m_previous[r - 1][c - 1]++;
    return true;
}

// The showPreviousMoves function clears the screen and displays the grid of what has
// happened previously. 
void Previous::showPreviousMoves() const
{
    clearScreen();
    for (int r = 0; r < m_rows; r++)
    {
        for (int c = 0; c < m_cols; c++)
        {
            if (m_previous[r][c] == 0) // dot means 0
                cout << ".";
            else if (m_previous[r][c] >= 1 && m_previous[r][c] <= 25) // a letter character A through Y means 1 through 25 times
                cout << char(m_previous[r][c] + 'A' - 1);
            else // Z means 26 or more times.
                cout << "Z";
        }
        cout << endl;
    }
    cout << endl;
}
