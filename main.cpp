#include <iostream>
#include "C:\Users\Cas\Docs\C++\MazeTutorial\olcPixelGameEngine\olcPixelGameEngine.h"
#include <stack>

using namespace std;

class OneLoneCoder_Maze : public olc::PixelGameEngine {
    public:

        OneLoneCoder_Maze() {
            sAppName = "MAZE";
        }

    protected:

        virtual bool OnUserCreate() {

            m_nMazeHeight = 25;
            m_nMazeWidth = 40;

            m_maze = new int[m_nMazeWidth * m_nMazeHeight];
            memset(m_maze, 0x00, m_nMazeWidth * m_nMazeWidth * sizeof(int));

            m_stack.push(make_pair(0, 0));
            m_maze[0] = CELL_VISITED;
            m_nVisitedCells = 1;

            return true;
        }

        virtual bool OnUserUpdate(float fElapsedTime) {

            FillRect(0, 0, ScreenWidth, ScreenHeight);

            return true;
        }

    private:

        int32_t m_nMazeWidth;
        int32_t m_nMazeHeight;
        int *m_maze;

        enum {
            CELL_PATH_N = 0x01,
            CELL_PATH_E = 0x02,
            CELL_PATH_S = 0x04,
            CELL_PATH_W = 0x08,
            CELL_VISITED = 0x10,
        };

        int m_nVisitedCells;

        stack<pair<int, int>> m_stack;

};

int main() {
    OneLoneCoder_Maze game;
    game.Construct(160, 100, 8, 8);
    game.Start();
   
   return 0;
}