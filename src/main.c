#include "raylib.h"
#define BACKGROUND_COLOUR RAYWHITE
#define FRACTAL_COLOUR BLACK
#define WIDTH 1500
#define HEIGHT 1500
#define BASE_LENGTH 250
#define BASE_THICKNESS 25
#define BASE_ANGLE 0

void DrawBranch(float x, float y, float length, float thickness, float angle) {
    // DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
    DrawLineEx((Vector2){x, y}, (Vector2){x, y-length}, thickness, FRACTAL_COLOUR);

}


int main(void)
{


    InitWindow(WIDTH, HEIGHT, "Fractal Window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BACKGROUND_COLOUR);

        // all logic
        DrawBranch(WIDTH/2, HEIGHT, BASE_LENGTH, BASE_THICKNESS, BASE_ANGLE);

        EndDrawing();
    }


    CloseWindow();


    return 0;
}