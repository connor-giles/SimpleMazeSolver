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
            currentLocationStack.push(make_pair(currentLocationStack.top().first + 1, currentLocationStack.top().second)); 
            currLoc = currentLocationStack.top();
        }
        else if(maze[currentLocationStack.top().first][currentLocationStack.top().second + 1] == 1) //CHECKS EAST
        {
            currentLocationStack.push(make_pair(currentLocationStack.top().first, currentLocationStack.top().second + 1)); 
            currLoc = currentLocationStack.top();
        }
        else if(maze[currentLocationStack.top().first - 1][currentLocationStack.top().second] == 1) //CHECKS NORTH
        {
            currentLocationStack.push(make_pair(currentLocationStack.top().first - 1, currentLocationStack.top().second)); 
            currLoc = currentLocationStack.top();
        }
        else if(maze[currentLocationStack.top().first][currentLocationStack.top().second - 1] == 1) //CHECKS WEST
        {
            currentLocationStack.push(make_pair(currentLocationStack.top().first, currentLocationStack.top().second - 1)); 
            currLoc = currentLocationStack.top();
        }
        else if(!currentLocationStack.empty())//ASSUMES NONE OF THE WAYS ARE VIABLE AND NOT FIRST ENTRY, NEED TO MOVE BACK
        { 
            //NEED TO SET LOCATION AS "VISITED"
            maze[currentLocationStack.top().first][currentLocationStack.top().second] = 0; //THIS SHOULD MARK IT AS VISITED 
            
            //NEED TO MOVE BACK TO PREVIOUS SPOT aka pop
            currentLocationStack.pop();
        }
        else
        {
            cout << "Something went wrong and no other case evauluated" << endl;    
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