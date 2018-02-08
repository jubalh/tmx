#include <tmx.h>
#include <raylib.h>

const int screenWidth = 800;
const int screenHeight = 450;


//----------------------------------------------------------------------------------
// TMX functions
//----------------------------------------------------------------------------------
void draw_objects(tmx_object_group *objgr)
{
	Color color = GetColor(objgr->color);
    tmx_object *head = objgr->head;
	while (head) {
		if (head->visible) {
			if (head->shape == S_SQUARE) {
				DrawRectangle(head->x, head->y, head->x+head->width, head->y+head->height, color);
			} else if (head->shape  == S_POLYGON) {
//				draw_polygone(head->points, head->x, head->y, head->points_len, color);
			} else if (head->shape == S_POLYLINE) {
//				draw_polyline(head->points, head->x, head->y, head->points_len, color);
			} else if (head->shape == S_ELLIPSE) {
//				al_draw_ellipse(head->x + head->width/2.0, head->y + head->height/2.0, head->width/2.0, head->height/2.0, color, LINE_THICKNESS);
			}
		}
		head = head->next;
	}
}

//----------------------------------------------------------------------------------
// Game functions
//----------------------------------------------------------------------------------
void Update(void)
{
}

void Draw(void)
{
	DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
//	DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
}

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
	// Initialization
	//---------------------------------------------------------
	const char windowTitle[30] = "<game name goes here>";

    InitWindow(screenWidth, screenHeight, windowTitle);

	SetTargetFPS(60);
	//----------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
		Update();
        
        // Draw
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
			Draw();
            DrawFPS(screenWidth - 100, 20);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
	
    return 0;
}
