#include "raylib.h"
#include <math.h>
#define BACKGROUND_COLOUR RAYWHITE
#define FRACTAL_COLOUR BLACK
#define WIDTH 1500
#define HEIGHT 1500
#define BASE_LENGTH 200
#define BASE_THICKNESS 5
#define REDUCTION_FACTOR 0.9
#define BASE_ANGLE 0
#define PI 3.141592653589793
#define ANGLE_INCREASE_FACTOR 0.2
#define MAX_GENERATIONS 8


void DrawBranch(Vector2 startV, float length, float thickness, float angle, int generation)
{
    if (generation > MAX_GENERATIONS)
        return;

    Vector2 endV = {
        startV.x + length * sinf(angle),
        startV.y - length * cosf(angle)
    };

    DrawLineEx(startV, endV, thickness, FRACTAL_COLOUR);

    float newLength = length * REDUCTION_FACTOR;
    float newThickness = thickness * REDUCTION_FACTOR;

    DrawBranch(endV, newLength, newThickness, angle - ANGLE_INCREASE_FACTOR, generation + 1);

    DrawBranch(endV, newLength, newThickness, angle + ANGLE_INCREASE_FACTOR, generation + 1);
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
        DrawBranch((Vector2){WIDTH/2, HEIGHT-100}, BASE_LENGTH, BASE_THICKNESS, BASE_ANGLE, 0);

        EndDrawing();
    }


    CloseWindow();


    return 0;
}