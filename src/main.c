#include "raylib.h"
#define BACKGROUND_COLOUR RAYWHITE
#define FRACTAL_COLOUR BLACK

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Fractal Window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BACKGROUND_COLOUR);


        EndDrawing();
    }


    CloseWindow();


    return 0;
}