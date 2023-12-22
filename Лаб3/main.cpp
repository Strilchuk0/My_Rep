#include <iostream>
#include <fstream>
#include <string>  
using namespace std;


int mas[6][6];
string connections[10];

int connectionCount = 0;
int enterPoint = 0;
int leavePoint = 0;
string graph = "graph.txt";


void fileRead(string fileToRead);
void showAndAdd();
void showConnections(int arrayToShow[]);
void findPath(int pathFrom, int pathTo);


void fileRead(string fileToRead)
{
    ifstream file;
    file.open(fileToRead);

    // reading txt into mas
    for (int i = 0; i < 6; i++)
    {
        for (int y = 0; y < 6; y++)
        {
            file >> mas[y][i];
        }
    }
}

void showAndAdd()
{
    // showing mas and adding connections to the "connections" array
    cout << "\nGraph: " << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int y = 0; y < 6; y++)
        {
            cout << mas[i][y] << " ";
            if (mas[i][y] == 1)
            {
                connections[connectionCount] = (to_string(i + 1) + " - " + to_string(y + 1));
                connectionCount++;
            }
        }
        cout << endl;
    }
    connectionCount = 0;
}

void showConnections(string arrayToShow[])
{
    // showing connections
    cout << "\nConnections: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arrayToShow[i] << "\t";
    }

    cout << endl;
}

void pointInit()
{
    cout << "\nPath search: \nEnter first point: ";
    cin >> enterPoint;
    cout << "Enter second point: ";
    cin >> leavePoint;
}

void findPath(int pathFrom, int pathTo)
{
    // find path
    cout << "\nFinding path from " << pathFrom << " to " << pathTo << endl;
    int tempFirst = 0;
    int tempSecond = 0;
    int counter = 0;
    while (tempSecond != pathTo)
    {
        string tempStr = connections[counter];
        int firstNum = stoi(tempStr.substr(0, tempStr.find('-')));
        int secondNum = stoi(tempStr.substr(tempStr.find('-') + 1));

        if (tempFirst != secondNum && tempSecond == firstNum || tempFirst == 0 && firstNum == pathFrom)
        {
            cout << firstNum << " - " << secondNum << endl;
            tempFirst = firstNum;
            tempSecond = secondNum;
        }
        counter++;
        if (counter == 10) counter = 0;
    }
    cout << "\nPath founded!" << endl;
}

int main()
{
    // read info from file
    fileRead(graph);
    // showing info from mas[][] and adding connections to "connections" array
    showAndAdd();
    // showing graph connections
    showConnections(connections);
    // initialization of first and last searching points
    pointInit();
    // finding path from first to last point
    findPath(enterPoint, leavePoint);
}


