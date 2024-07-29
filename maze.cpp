#include <iostream>
#include <queue>
#include <vector>
#include <utility> // for std::pair
#include <algorithm> // for std::reverse

using namespace std;

// Global variables for start and end points
pair<int, int> start, endPoint;

// Function prototypes
void generateUserMaze(int rows, int cols);
bool isValid(int row, int col, vector<vector<bool>>& visited);
void BFS(pair<int, int> start, pair<int, int> endPoint, int rows, int cols);
void printMazeWithPath(vector<pair<int, int>> path = {}, int rows = 0, int cols = 0);

vector<vector<int>> maze;

int main() {
    int rows, cols;

    // Get the maze dimensions from the user
    cout << "Enter the number of rows in the maze: ";
    cin >> rows;
    cout << "Enter the number of columns in the maze: ";
    cin >> cols;

    // Generate a user-defined maze
    generateUserMaze(rows, cols);

    // Display the maze
    printMazeWithPath({}, rows, cols);

    // Get user input for start and end points with validation
    while (true) {
        cout << "Enter the start point (row and column): ";
        cin >> start.first >> start.second;
        cout << "Enter the end point (row and column): ";
        cin >> endPoint.first >> endPoint.second;

        // Validate input
        if (start.first >= 0 && start.first < rows && start.second >= 0 && start.second < cols &&
            endPoint.first >= 0 && endPoint.first < rows && endPoint.second >= 0 && endPoint.second < cols &&
            maze[start.first][start.second] == 0 && maze[endPoint.first][endPoint.second] == 0) {
            break;
        } else {
            cout << "Invalid start or end point. Please make sure they are within bounds and not walls." << endl;
        }
    }

    // Solve the maze and display the path
    BFS(start, endPoint, rows, cols);

    return 0;
}

// Function to generate a user-defined maze
void generateUserMaze(int rows, int cols) {
    maze.resize(rows, vector<int>(cols));
    cout << "Enter the maze row by row (0 for path, 1 for wall):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> maze[i][j];
        }
    }
}

// Function to check if a cell is valid for movement
bool isValid(int row, int col, vector<vector<bool>>& visited) {
    return (row >= 0 && row < visited.size() && col >= 0 && col < visited[0].size() &&
            maze[row][col] == 0 && !visited[row][col]);
}

// BFS to find the shortest path in the maze
void BFS(pair<int, int> start, pair<int, int> endPoint, int rows, int cols) {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols));
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;

    // Directions for moving in the maze: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        // Check if we have reached the end
        if (current == endPoint) {
            vector<pair<int, int>> path;
            while (current != start) {
                path.push_back(current);
                current = parent[current.first][current.second];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());

            // Print the maze with the path
            printMazeWithPath(path, rows, cols);

            return;
        }

        // Explore the neighbors
        for (auto dir : directions) {
            int newRow = current.first + dir.first;
            int newCol = current.second + dir.second;

            if (isValid(newRow, newCol, visited)) {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
                q.push({newRow, newCol});
            }
        }
    }

    cout << "No path found." << endl;
}

// Function to print the maze with different symbols
void printMazeWithPath(vector<pair<int, int>> path, int rows, int cols) {
    cout << "Maze size: " << rows << " x " << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (make_pair(i, j) == start) {
                cout << "S ";
            } else if (make_pair(i, j) == endPoint) {
                cout << "E ";
            } else if (find(path.begin(), path.end(), make_pair(i, j)) != path.end()) {
                cout << "* ";
            } else if (maze[i][j] == 1) {
                cout << "# ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}
