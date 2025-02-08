/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    DataFile data;
    int currentRecordIdx = 0;

    //we are not trying to load the whole file
    //data.Load("npc_data.dat");

    DataFile::Record* currentRecord = data.GetRecord("npc_data.dat", currentRecordIdx);
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image);


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        //moves the npc data page to the left by one. contains an edge case that keeps the page on the first one if the current page is already the first one
        if (IsKeyPressed(KEY_LEFT))
        {
            currentRecordIdx--;
            //edge case for if the page is attempted to be moved left if the current page is already on the leftmost page
            if (currentRecordIdx < 0)
            {
                currentRecordIdx = 0;
            }
            currentRecord = data.GetRecord("npc_data.dat", currentRecordIdx);
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }

        //moves the npc data page to the right by one
        if (IsKeyPressed(KEY_RIGHT))
        {
            currentRecordIdx++;
            if (currentRecordIdx >= data.GetRecordCount())
            {
                currentRecordIdx = data.GetRecordCount();
            }
            currentRecord = data.GetRecord("npc_data.dat", currentRecordIdx);
            recordTexture = LoadTextureFromImage(currentRecord->image);
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(recordTexture, 300, 50, WHITE);

        DrawText("NAME", 10, 50, 20, LIGHTGRAY);
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY);

        DrawText("AGE", 10, 120, 20, LIGHTGRAY);
        DrawText(to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}