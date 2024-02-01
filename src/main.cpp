
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
    raylib_namespace::SetTargetFPS(60); // Set our game to run at 10 frames-per-second
    
    Gui_Namespace::Ausgabe_feld ausgabe_feld_obj (400,40, 200, 200, "Ausgabe");
    Gui_Namespace::Ausgabe_knopf ausgabe_knopf_obj (200, 40, 1500, 200, "Aus DB lesen");
    Gui_Namespace::Eingabe_feld eingabe_feld_obj (400, 40, 200, 800, "Eingabe");
    Gui_Namespace::Speicher_knopf speicher_knopf_obj(200, 40, 1500, 800,
        "Speichern in DB" );
    
    std::string simulierte_DB = "";
    std::string* prt_to_sim_DB = &simulierte_DB;
    
    //der String wird aus der Database geladen
    std::string filename = "peristenter_speicher.txt";
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string data;

        // Read up to 9 characters
        char c;
        int count = 0;
        while (file.get(c) && count < 9 && c != '\n') {
            data += c;
            count++;
        }

        file.close();
        simulierte_DB = data;
    }
    else
    {
        printf("Error couldnt save!"); return 1;
    }


    // Main game loop
    while (!raylib_namespace::WindowShouldClose())    // Detect window close button or ESC key
    {
        //Zuerst werden die Objekte geupdatet
        /*Update des Ausgabefeldes, durch drücken des Ausgabeknopfes, wird das
        Ausgabefeld mit dem Wert des DataBase string neu beschrieben*/
        if(ausgabe_knopf_obj.isClicked_m()){
           ausgabe_feld_obj.update_m(ausgabe_knopf_obj.aus_DB_lesen_m(prt_to_sim_DB));        
        }
        /*Update des Eingabefeldes, neue Benutzereingaben werden dem eingabefeld hinzugefügt,
        aber noch nicht angezeigt, das passiert in draw*/
        eingabe_feld_obj.update_m();

        /*Durch drücken des Eingabeknopfes werden Werte von Eingabefeld in DataBase über-
        tragen */
        if(speicher_knopf_obj.isClicked_m()){
            speicher_knopf_obj.in_DB_schreiben_m(
                eingabe_feld_obj.get_eingabe_m(),prt_to_sim_DB);
        }


        //jetzt werden die Objekte gerendert
        raylib_namespace::BeginDrawing();
            raylib_namespace::ClearBackground(raylib_namespace::RAYWHITE);

            //Alle Objekte werden gerendert
            eingabe_feld_obj.draw();
            speicher_knopf_obj.draw_m();
            ausgabe_knopf_obj.draw_m();
            ausgabe_feld_obj.draw();
        
            
        raylib_namespace::EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    raylib_namespace::CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

   
    std::ofstream file2(filename);
    if(file2.is_open()){
        file2 << simulierte_DB;
        file2.close();
    }
    else
    {
        printf("Error couldnt save!"); return 1;
    }

    return 0;
}

