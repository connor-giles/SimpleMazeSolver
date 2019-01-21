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
    bool done = false;
    pair<int,int> currLoc;
    
    //myStack.push(make_pair(myString, myInt)); just used for reference
    
    currentLocationStack.push(make_pair(0,0)); //creates the first stack pair at (0,0) which is always the beginning
    currLoc = currentLocationStack.top();
    
    while(!done)
    {
        if(currentLocationStack.top().first == 2 && currentLocationStack.top().second == 3)
        {
            done = true;
            while(!currentLocationStack.empty())
            {
                cout << "(" << currentLocationStack.top().first << ", " << currentLocationStack.top().second << ")";
            }
            //NEED TO FIGURE OUT A WAY TO PRINT THE CORRECT PATH TAKEN PARTICULARY IN REVERSE ORDER
            
        }
        
        if(maze[currentLocationStack.top().first + 1][currentLocationStack.top().second] == 1) //CHECKS SOUTH
        {
            
        }
        else if(maze[currentLocationStack.top().first][currentLocationStack.top().second + 1] == 1) //CHECKS EAST
        {
            
        }
        else if(maze[currentLocationStack.top().first - 1][currentLocationStack.top().second] == 1) //CHECKS NORTH
        {
            
        }
        else if(maze[currentLocationStack.top().first][currentLocationStack.top().second - 1] == 1) //CHECKS WEST
        {
            
        }
        else //ASSUMES NONE OF THE WAYS ARE VIABLE AND NEED TO MOVE BACK TO PREVIOUS SPOT
        {
            //NEED TO MOVE BACK TO PREVIOUS SPOT 
        }
        
        
    }
    
    
    
}

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