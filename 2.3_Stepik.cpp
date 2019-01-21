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
    stack<pair<int, int>> currentLocationStack;
    bool done = false;
    
    //myStack.push(make_pair(myString, myInt)); just used for reference
    
    while(!done)
    {
        if(rowStack.top() == 2 && colStack.top() == 3)
        {
            done = true;
            cout << "(" << rowStack.top() << ", " << colStack.top();
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