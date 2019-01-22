#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <utility>

using namespace std;

vector<vector<int>> getInput()
{
    string line;
    getline(cin, line);

    string token;

    int rowNum=0;
    int colNum=0;
    int size=0;
    int currSize = 0;

    int test;


    //get size
    stringstream lineStream(line);
    while(lineStream >> token)
    {
        size++;
    }

    //initialize 2D vector
    vector<vector<int>> numbers(size, vector<int>(size, 0));

    //read lines

    for (int k = 0; k<size-1; k++)
    {

        stringstream lineStream2(line);
        currSize = 0;
        while(lineStream2 >> token)
        {

            test = stoi(token);
            numbers[rowNum][currSize] = test;
            currSize++;
        }
        rowNum++;
        getline(cin, line);

    }
    //do the last line
    stringstream lineStream2(line);
    currSize = 0;
    while(lineStream2 >> token)
    {

        test = stoi(token);
        numbers[rowNum][currSize] = test;
        currSize++;
    }

    return numbers;
}

void solveMaze(vector<vector<int>> maze, int x, int y)
{
    stack< pair<int,int> > currentLocationStack;
    stack< pair<int,int> > reverseStack;

    bool done = false;
    int currRow = 0;
    int currColumn = 0;


    currentLocationStack.push(make_pair(0,0)); //creates the first stack pair at (0,0) which is always the beginning



    while(!done)
    {
        if(currRow == x && currColumn == y)
        {
            done = true;
            while(!currentLocationStack.empty())
            {
                reverseStack.push(currentLocationStack.top());
                currentLocationStack.pop();
            }

            while(!reverseStack.empty())
            {
                if(reverseStack.size() == 1)
                {
                    cout << "(" << reverseStack.top().first << ", " << reverseStack.top().second << ")";
                }
                else
                {
                    cout << "(" << reverseStack.top().first << ", " << reverseStack.top().second << ") -> ";
                }
                reverseStack.pop();
            }

            break;

        }


        if(((currRow+1) >= 0 && (currRow+1) < maze.size() && currColumn >= 0 && currColumn < maze.size())) //CHECKS SOUTH
        {
            if(maze[currRow + 1][currColumn] == 1)
            {
                maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED
                currentLocationStack.push(make_pair(currentLocationStack.top().first + 1, currentLocationStack.top().second));
                currRow = currentLocationStack.top().first;
                currColumn = currentLocationStack.top().second;
                continue;
            }
        }

        if((currRow >= 0 && currRow < maze.size() && (currColumn+1) >= 0 && (currColumn+1) < maze.size()))//CHECKS EAST
        {
            if(maze[currRow][currColumn + 1] == 1)
            {
                maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED
                currentLocationStack.push(make_pair(currentLocationStack.top().first, currentLocationStack.top().second + 1));
                currRow = currentLocationStack.top().first;
                currColumn = currentLocationStack.top().second;
                continue;
            }
        }

        if(((currRow-1) >= 0 && (currRow-1) < maze.size()) && (currColumn >= 0 && currColumn < maze.size()))//CHECKS NORTH
        {
            if(maze[currRow - 1][currColumn] == 1)
            {
                maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED
                currentLocationStack.push(make_pair(currentLocationStack.top().first - 1, currentLocationStack.top().second));
                currRow = currentLocationStack.top().first;
                currColumn = currentLocationStack.top().second;
                continue;
            }
        }
        if((currRow >= 0 && currRow < maze.size()) && ((currColumn-1) >= 0 && (currColumn-1) < maze.size()))//CHECKS WEST
        {
            if(maze[currRow][currColumn - 1] == 1)
            {
                maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED
                currentLocationStack.push(make_pair(currentLocationStack.top().first, currentLocationStack.top().second - 1));
                currRow = currentLocationStack.top().first;
                currColumn = currentLocationStack.top().second;
                continue;
            }
        }

        //NEED TO SET LOCATION AS "VISITED"
        maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED

        //NEED TO MOVE BACK TO PREVIOUS SPOT aka pop
        currentLocationStack.pop();
        currRow = currentLocationStack.top().first;
        currColumn = currentLocationStack.top().second;


    }//end while



} //end solveMaze

int main()
{
    vector<vector<int>> maze;
    maze = getInput();
    int x;
    cin >> x;
    int y;
    cin >> y;

    solveMaze(maze, x, y);

    return 0;
}