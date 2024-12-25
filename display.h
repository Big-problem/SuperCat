#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>

#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

struct maps
{
    ALLEGRO_BITMAP *img;
    float pos_x;
    float pos_y;
};

extern maps Map;
extern int display_width;
extern int display_height;
extern bool trap_arr[20];

extern ALLEGRO_BITMAP *menuu;
extern ALLEGRO_BITMAP *setting;
extern ALLEGRO_BITMAP *level;
extern ALLEGRO_DISPLAY *menu_display;
extern ALLEGRO_DISPLAY *display;

void menuu_init();
void map_init(int);
void display_update();
void draw_map(int);
void obj_update(int);
void trap_detect(int);
