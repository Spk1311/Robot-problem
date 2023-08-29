#include <bits/stdc++.h>
using namespace std;

vector<string> direction = {"NORTH", "EAST", "SOUTH", "WEST","UP","DOWN"};

// Move the robot in the specified direction.
void move(int &x, int &y,int& z, int &dir)
{
    switch (dir)
    {
    case 0: //north
        y++;
        break;
    case 1: //east
        x++;
        break;
    case 2: //south
        y--;
        break;
    case 3: //west
        x--;
        break;
    case 4: //up
        z++;
        break;
    case 5: // down
        z--;
        break;
    }
}


// Turn the robot 90 degrees to the right.
void turnRight(int &dir)
{
    dir = (dir + 1) % 6;
}

// Turn the robot 90 degrees to the left.
void turnLeft(int &dir)
{
    dir = (dir - 1 + 6) % 6;
}

int main()
{
    // Initialize the robot's position and direction.
    int x = 0;
    int y = 0;
    int z = 0;
    int dir = 0;

    // Read the commands.
    string commands;
    cin >> commands;

    // Move the robot according to the commands.
    for (char command : commands)
    {
        if (command == 'f' || command == 'b')
        {
            move(x, y,z, dir);
        }
        else if(command == 'u'){ //up
            z++;
        }
        else if(command == 'd'){ //down
            z--;
        }
        else if (command == 'r')
        {
            turnRight(dir);
        }
        else if (command == 'l')
        {
            turnLeft(dir);
        }
    }

    // Print the final position and direction.
    cout << "Final position: (" << x << ", " << y << ", " << z << ")" << endl;
    cout << "Final direction: " << direction[dir] << endl;

    return 0;
}