#include <iostream>
#include <raylib.h>

using namespace std;

class Ball {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update() {
        x += speed_x;
        y += speed_y;
    }
};

Ball ball;

int main () {

    cout << "Starting the game" << endl;
    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "PONG");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while(WindowShouldClose() == false) {

        BeginDrawing();

        ball.Update();
        
        if ((ball.x >= screen_width - ball.radius) || (ball.x <= ball.radius)) {
            ball.speed_x = -1 * ball.speed_x;
        }

        if ((ball.y >= screen_height - ball.radius) || (ball.y <= 0)) {
            ball.speed_y = -1 * ball.speed_y;
        }

        ClearBackground(BLACK);
        // Draw ball in the middle of the screen
        ball.Draw();
        DrawRectangle(10, screen_height/2 - 60, 25, 120, WHITE);
        DrawRectangle(screen_width - (10 + 25), screen_height/2 - 60, 25, 120, WHITE);
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        EndDrawing();

    }

    CloseWindow();
    return 0;
}