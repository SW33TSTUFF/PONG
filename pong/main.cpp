#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    cout << "Starting the game" << endl;
    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "PONG");
    SetTargetFPS(60);

    while(WindowShouldClose() == false) {
        BeginDrawing();

        // Draw ball in the middle of the screen
        DrawCircle(screen_width/2, screen_height/2, 20, WHITE);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}