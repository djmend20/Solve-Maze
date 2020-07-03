//************************************************************
// solveMaze.cpp
//   Author:   David Mendoza
//   Date:     November 2, 2018
//   Class:    CSCI132, Professor Kadady
//   Purpose:  Solve any maze.  
//   Implemented: solveMaze, isWallAbove, isWallBelow,
//                isWalltoLeft, isWalltoRight
//              
//************************************************************
 
#include "maze.h"

bool solve(Maze &, int, int);
bool isWallAbove(Maze &, int, int);
bool isWallBelow(Maze &, int, int);
bool isWalltoLeft(Maze &, int, int);
bool isWalltoRight(Maze &, int, int);

int main()  {
	int width, height;
	char answer;
	
	cout << "Do you want me to solve a maze (y/n)? ";
	cin >> answer;

	while (answer == 'y') {
		cout << "Enter number for width of maze: " ;
		cin >> width;
		cout  << "Enter number for height of maze: ";
		cin >> height;

		Maze myMaze(width, height);
        
		cout << "Maze to be solved: " << endl;
		myMaze.print_maze();
		if (!solve(myMaze, 0, 0)) {
			cout << "Couldn't solve this maze!" << endl;
		} 
		cout << "Do you want me to solve another maze (y/n)? ";
		cin >> answer;
        cout << answer << endl;
	} // while solving another maze
		
	return 0;
} //end main program

bool solve(Maze &theMaze, int x, int y) {
    // Pre-Condition: provides the maze and coordinates
    // Post-condition: prints the solved maze and returns true 
    
    if (theMaze.get_position(x, y) == 2) { // base case when solved
        theMaze.print_maze();
        return true;
    } else if (theMaze.get_position(x, y) == 1) { // base case for dead end
        return false;
    } else {  // looking ahead to solve the maze 
        bool is_solved = false;
        theMaze.set_position(x, y, 1);
        if (!(isWallAbove(theMaze, x, y))) {
            is_solved = solve(theMaze, x, y-1);
        }
        if (!is_solved && !(isWallBelow(theMaze, x, y))) {
            is_solved = solve(theMaze, x, y+1);
        }
        if (!is_solved && !(isWalltoLeft(theMaze, x, y))) {
            is_solved = solve(theMaze, x-1, y);
        }
        if (!is_solved && !(isWalltoRight(theMaze, x, y))) { 
            is_solved = solve(theMaze, x+1, y);
        }
        
        theMaze.set_position(x, y, 0);
            
        return is_solved;
    }
} //end solve

bool isWallAbove(Maze &theMaze, int x, int y) {
    // Pre-condition: provides the maze and coordinates
    // Post-condition: returns true if a wall
    // is found above else false 
    if (!(theMaze.is_horizontal_wall(x,y))) {
        return false;
    } else {
        return true;
    }
} //end isWallAbove

bool isWallBelow(Maze &theMaze, int x, int y) {
    // Pre-condition: provides the maze and position
    // Post-condition: returns true if a wall
    // is found below else false
    if (!(theMaze.is_horizontal_wall(x, y+1))) {
        return false;
    } else {
        return true;
    }
} //end isWallBelow

bool isWalltoLeft(Maze &theMaze, int x, int y) {
    // Pre-condition: provides the maze and coordinates
    // Post-condition: returns true if a wall
    // is found to the left  else false
    if (!(theMaze.is_vertical_wall(x,y))) {
        return false;
    } else {
        return true;
    }
} //end isWalltoLeft

bool isWalltoRight(Maze &theMaze, int x, int y) {
    // Pre-condition: provides the maze and coordinates
    // Post-condition: returns true if a wall
    // is found to the right else false
    if (!(theMaze.is_vertical_wall(x+1,y))) {
        return false;
    } else {
        return true;
    }
} //end isWalltoRight
