
#include "../include/my_includes.h"
#include "../include/ausgabe_feld.h"
#include "../include/ausgabe_knopf.h"
#include "../include/eingabe_feld.h"
#include "../include/global_defines.h"
#include "../include/knopf.h"
#include "../include/rechteck.h"
#include "../include/speicher_knopf.h"


/*Die Hierachie ist:
Es gibt eine GUI mit einer Seite, welche mehrere Bedienelemente haben können
Mehrer Seiten kommt später noch*/


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib_namespace::InitWindow(2000,1600,"42");
    raylib_namespace::SetTargetFPS(60);               // Set our game to run at 10 frames-per-second
    
    Gui_Namespace::Ausgabe_feld ausgabe_feld_obj (400,40, 200, 200, "Ausgabe");
    Gui_Namespace::Ausgabe_knopf ausgabe_knopf_obj (200, 40, 1500, 200, "Aus DB lesen");
    Gui_Namespace::Eingabe_feld eingabe_feld_obj (400, 40, 200, 800, "Eingabe");
    Gui_Namespace::Speicher_knopf speicher_knopf_obj(200, 40, 1500, 800,
        "Speichern in DB" );

    std::string simulierte_DB = "";
    std::string* prt_to_sim_DB = &simulierte_DB;
    
    
    //--------------------------------------------------------------------------------------
   


    // Main game loop
    while (!raylib_namespace::WindowShouldClose())    // Detect window close button or ESC key
    {
        raylib_namespace::BeginDrawing();
        raylib_namespace::ClearBackground(raylib_namespace::RAYWHITE);

        
        eingabe_feld_obj.update_m();
        speicher_knopf_obj.update_m();
        if(speicher_knopf_obj.isClicked_m()){
            simulierte_DB = eingabe_feld_obj.get_eingabe_m();
        }

        ausgabe_knopf_obj.update_m();
        ausgabe_feld_obj.draw();
        if(ausgabe_knopf_obj.isClicked_m()){
           ausgabe_feld_obj.update_m(ausgabe_knopf_obj.aus_DB_lesen_m(prt_to_sim_DB));
                
        }
        //ausgabe_feld_obj.update_m(prt_to_sim_DB);
            
        raylib_namespace::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    raylib_namespace::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

