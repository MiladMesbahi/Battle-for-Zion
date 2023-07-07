#ifndef PREVIOUS_H
#define PREVIOUS_H

#include "globals.h"

// The Previous class keeps track of all previous positions of the player on the grid. 
// It provides functionality to drop a "crumb" when the player moves to a grid point, 
// and to show a display of all previous moves.
class Previous
{
public:
    // Constructor for Previous class. Initializes a Previous object that corresponds 
    // to an Arena with nRows rows and nCols columns.
    Previous(int nRows, int nCols);

    // The dropACrumb function is called to notify the Previous object that the player has
    // arrived at or stayed at a grid point. The function returns false if row r, column c 
    // is not within bounds; otherwise, it returns true after recording the move.
    bool dropACrumb(int r, int c);

    // The showPreviousMoves function clears the screen and displays the grid of what has
    // happened previously. 
    void showPreviousMoves() const;

private:
    int m_rows;
    int m_cols;
    int m_previous[MAXROWS][MAXCOLS]; // Stores the number of visits to each grid point
};

#endif // PREVIOUS_H
