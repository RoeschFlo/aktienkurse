#include "global_stuff.h"
#include "drawing.h"
#include "speicher.h"
#include "button.h"

//Database
//#include "../database/include/mysql/jdbc.h"
#include "jdbc.h"

/*
int main(void)
{
    
    int zahl = 0;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    drawing_interface page_1_obj;
    
    Vector2 mouse_position = { -1.0f,-1.0f }; 
    save_button save_button_obj(200, 100, 300, 400, "Speichern");
    
    while (!WindowShouldClose())
    {
        mouse_position = GetMousePosition();
        //page_1.update();
        page_1_obj.draw();
        save_button_obj.draw();
        save_button_obj.update();
    }

    CloseWindow();

    return 0;
}*/
using namespace std;

//for demonstration only. never save your password in the code!
const sql::SQLString  server = "tcp://127.0.0.1:3306";
const  sql::SQLString username = "root";
const  sql::SQLString password = "yourpassword";

int main()
{
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    printf("1");
    driver = sql::mysql::get_mysql_driver_instance();
    printf("2");
    con = driver->connect ("tcp://127.0.0.1:3306", "root", "yourpassword");
    printf("3");

    delete con;
    return 0;
}