#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int xfirst1 = 194, yfisrt1 = 490;
int xfirst2 = 194, yfisrt2 = 490;
int xsecond1 = 572, ysecond1 = 114;
int xsecond2 = 572, ysecond2 = 114;

int x_tas = 371;
int y_tas = 29;

int tas() {
    int arr[6], T;
    for (int i = 0; i < 3; i++) {
        arr[i] = -3 + i;
    }
    for (int i = 3; i < 6; i++) {
        arr[i] = -2 + i;
    }
    /*for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }*/
    srand(time(0));
    T = rand();
    return arr[T % 6];
}

int main() {
    const int windowwidth = 800;
    const int windowheight = 600;
    
    InitWindow(windowwidth, windowheight, "my game");
    SetTargetFPS(60);
    
    Texture2D board = LoadTexture("resources/final_board.png"); 

    Texture2D first1 = LoadTexture("resources/rsz_sefid.png"); 
    Texture2D first2 = LoadTexture("resources/rsz_sefid.png"); 
    Texture2D second1 = LoadTexture("resources/rsz_siah.png"); 
    Texture2D second2 = LoadTexture("resources/rsz_siah.png"); 

    int TAS = 0, turn = 1;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE); //color(245, 245, 245, 255)
        DrawTexture(board, windowwidth/2 - board.width/2, windowheight/2 - board.height/2, WHITE);
        
        DrawTexture(first1, xfirst1, yfisrt1, WHITE);
        DrawTexture(first2, xfirst2, yfisrt2, WHITE);
        DrawTexture(second1, xsecond1, ysecond1, WHITE);
        DrawTexture(second2, xsecond2, ysecond2, WHITE);

        if (GetMouseX() < 431 && GetMouseX() > 368 &&GetMouseY() < 90 && GetMouseY() > 27 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (tas() == -3) {
                TAS = tas();
            }
            if (tas() == -2) {
                TAS = tas();
            }
            if (tas() == -1) {
                TAS = tas();
            }
            if (tas() == 1) {
                TAS = tas();
            }
            if (tas() == 2) {
                TAS = tas();
            }
            if (tas() == 3) {
                TAS = tas();
            }
            turn *= -1;
        }
        if (turn == 1) {
            DrawText("WHITE :", 81, 48, 30, MAROON);
        }
        else {
            DrawText("BLACK :", 81, 48, 30, MAROON);
        }
        DrawText(TextFormat("%i", TAS), 387, 37, 40, BLACK);
        EndDrawing();
    }
    UnloadTexture(board);
    UnloadTexture(first1);
    UnloadTexture(first2);
    UnloadTexture(second1);
    UnloadTexture(second2);
    CloseWindow();
    return 0; 
}
