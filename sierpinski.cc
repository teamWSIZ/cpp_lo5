#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>

#define ALLEGRO_STATICLINK
#define ScreenWidth 1200
#define ScreenHeight 1200


void dywan(int xa,int ya,int xb,int yb,int lvl)
{
    int c = 255 - (xa + ya)/9;
    al_draw_rectangle(xa,ya,xb,yb,al_map_rgb(0,c,c),1);
    int xab,yab,xba,yba;
    if(lvl>0)
    {
        xab = (2*xa+xb)/3;
        yab = (2*ya+yb)/3;
        xba = (xa+2*xb)/3;
        yba = (ya+2*yb)/3;

        if (rand()%2) xba = xba + xba * 0.015;
        if (rand()%2) yba = yba + yba * 0.015;

        double x[4] = {xa, xab, xba, xb};
        double y[4] = {ya, yab, yba, yb};
    //    al_draw_rectangle(xab,yab,xba,yba,al_map_rgb(0,255,255),10);
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++) {
        if (i==1 && j==1) continue;
        dywan(x[i],y[j],x[i+1],y[j+1],lvl-1);
    }
//        dywan(xa,ya,xab,yab,lvl-1);
//        dywan(xba,ya,xb,yab,lvl-1);
//        dywan(xba,ya,xb,yab,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
//        dywan(xab,yab,xba,yba,lvl-1);
    }
    else
    {
        //al_draw_rectangle(xa,ya,xb,yb,al_map_rgb(255,0,0),10);
    }

}
int main()
{

    if(!al_init_primitives_addon())
    {
        al_show_native_message_box(NULL, NULL, "Error", "shit just got real", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    ALLEGRO_DISPLAY *display;

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, "Error", "Could not initialize Allegro 5", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    display = al_create_display(ScreenWidth, ScreenHeight);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, "Error", "Could not create Allegro 5 display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // You generally want to do this after you check to see if the display was created. If the display wasn't created then there's
    // no point in calling this function
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    al_set_window_position(display, 200, 100);
    al_set_window_title(display, "Kebab");

    ALLEGRO_COLOR electricBlue = al_map_rgb(44, 117, 255);


    float points[8] = { 0, 0, 400, 100, 50, 200, ScreenWidth, ScreenHeight };

    srand(123);

    dywan(10,10,1200,1200,7);

    al_flip_display();
    al_rest(25.0);
    al_destroy_display(display);



    return 0;
}
