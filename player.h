#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>

#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

ALLEGRO_FONT *font18 ;
ALLEGRO_SAMPLE *music ;
ALLEGRO_SAMPLE *coin_music ;
ALLEGRO_SAMPLE_INSTANCE *song_instance ;
ALLEGRO_SAMPLE_INSTANCE *coin_song_instance ;
ALLEGRO_SAMPLE *dead_music ;
ALLEGRO_SAMPLE_INSTANCE *dead_music_instance ;
ALLEGRO_SAMPLE *win_music ;
ALLEGRO_SAMPLE_INSTANCE *win_music_instance ;
ALLEGRO_SAMPLE *break_music ;
ALLEGRO_SAMPLE_INSTANCE *break_song_instance ;
ALLEGRO_SAMPLE *god_music ;
ALLEGRO_SAMPLE_INSTANCE *god_song_instance ;
ALLEGRO_SAMPLE *time_music ;
ALLEGRO_SAMPLE_INSTANCE *time_song_instance ;
typedef struct
{
    float x;      //位置
    float y;
    float velx;   //速度
    float vely;
    float accx;   //加速度
    float accy;
    bool moving;
    bool in_air;
    bool dead;
    bool air_jump;
    bool visible;
    bool control;
    bool goal;
    bool ok;
    int flag;
    int curframe; //控制在哪一張圖
    int switch_delay;
    int up_time;
    int move_time;
    int sx;
    int sy;
    ALLEGRO_BITMAP *img[4];
    //#########
    int live;
    int deadtime;
    int boundx;
    int boundy;
    int passtime;
    int gold;
    float maxvelx;
    float maxvely;
    //#########
}player;

player syobon;
void player_init();
void draw_player();
void player_update();

int god_time;
int god_start;

int stop;
int item1;
int item2;
