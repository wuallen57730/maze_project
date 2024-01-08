# Maze Project

## 中文版
這是一個簡單的迷宮尋找程式，使用**深度優先搜尋算法**來尋找從起點到終點的路徑。
程式會讀取一個迷宮地圖，其中0代表可通行的空格，1代表牆壁。程式會將找到的路徑以"*"標記，並輸出最終的迷宮地圖。

程式碼中定義了一個point結構，表示迷宮中的一個座標點，包含x座標、y座標和目前的方向。
程式使用一個堆疊（stack）來保存已經走過的路徑，並使用一個二維陣列visited來標記已經訪問過的格子。

在solve函數中，使用迴圈不斷將下一個可能的座標加入堆疊，直到找到終點或者堆疊為空。
在每一個座標點，根據目前的方向嘗試向上、下、左、右四個方向移動，
並檢查新的座標是否符合以下條件：
1. 在迷宮內
2. 非牆壁
3. 沒有走過

如果符合條件，將新的座標加入堆疊和標記為已訪問。程式讀取迷宮地圖的部分從一個檔案中讀取，檔案名稱為"maze.txt"。迷宮地圖的大小為N*N，並根據地圖中的數字輸出對應的符號：0為空格，1為牆壁。

程式執行後，會輸出原始的迷宮地圖，並在找到路徑後，輸出標記了路徑的最終迷宮地圖。如果找不到從起點到終點的路徑，則輸出相應的訊息
## English Version
This is a simple maze-solving program that uses the **depth-first search algorithm** to find a path from the start point to the end point.
The program reads a maze map where 0 represents a passable space and 1 represents a wall. The program marks the found path with "*" and outputs the final maze map.

The code defines a point structure that represents a coordinate in the maze, including the x and y coordinates and the current direction.
The program uses a stack to keep track of the visited paths and a 2D array visited to mark the visited cells.

In the solve function, a loop is used to continuously add the next possible coordinates to the stack until the end point is found or the stack is empty.
At each coordinate, the program tries to move in the four directions: up, down, left, and right, based on the current direction.
It checks if the new coordinate meets the following conditions:
1. within the maze
2. not a wall
3. not visited.
   
If the conditions are met, the new coordinate is added to the stack and marked as visited.
The program reads the maze map from a file named "maze.txt". The size of the maze map is N*N, and the corresponding symbols are output based on the numbers in the map: 0 for an empty space and 1 for a wall.

After execution, the program outputs the original maze map and, if a path is found, the final maze map with the path marked. If a path from the start point to the end point cannot be found, the program outputs the corresponding message.
