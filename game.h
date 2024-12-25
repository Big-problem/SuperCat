#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>

#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

enum dir{up,down,Left,Right};
extern bool adir[4];
extern bool render;
extern int col;
extern bool done;
extern bool menu_done;
extern bool setting_done;
extern bool level_done;
extern float fps;
extern int stage_played;
extern int god_time;
extern int god_start;

extern ALLEGRO_FONT *font18 ;
extern ALLEGRO_SAMPLE *menu_music;
extern ALLEGRO_SAMPLE_INSTANCE *menu_song_instance;
extern ALLEGRO_SAMPLE *music ;
extern ALLEGRO_SAMPLE_INSTANCE *song_instance ;
extern ALLEGRO_SAMPLE *coin_music;
extern ALLEGRO_SAMPLE_INSTANCE *coin_song_instance ;
extern ALLEGRO_SAMPLE *dead_music ;
extern ALLEGRO_SAMPLE_INSTANCE *dead_music_instance ;
extern ALLEGRO_SAMPLE *win_music ;
extern ALLEGRO_SAMPLE_INSTANCE *win_music_instance ;
extern ALLEGRO_SAMPLE *break_music ;
extern ALLEGRO_SAMPLE_INSTANCE *break_song_instance ;
extern ALLEGRO_SAMPLE *god_music ;
extern ALLEGRO_SAMPLE_INSTANCE *god_song_instance ;
extern ALLEGRO_SAMPLE *powerup_music ;
extern ALLEGRO_SAMPLE_INSTANCE *powerup_song_instance ;
extern ALLEGRO_SAMPLE *dokan_music ;
extern ALLEGRO_SAMPLE_INSTANCE *dokan_song_instance ;
extern ALLEGRO_TIMER *menu_timer;
extern ALLEGRO_EVENT_QUEUE *menu_event_queue;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT ev;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_TIMER *trap_timer;
extern ALLEGRO_TIMER *trap_timer2;
extern ALLEGRO_TIMER *trap_timer3;
extern ALLEGRO_TIMER *trap_timer4;
extern ALLEGRO_TIMER *trap_timer5;
extern ALLEGRO_TIMER *trap_timer6;
extern ALLEGRO_TIMER *trap_timer7;

void menu_init();
int menu_start();
void menu_destroy();
void setting_start();
int level_start();

void game_init();
int game_start();
void game_destroy();
bool to_close();
void keyboard_input();
void status_update();

void set_trap_timer();
void catch_process();
void timer_update();
void timer_update2();
void timer_update3();
void timer_update4();
void timer_update5();
void timer_update6();
void timer_update7();
void dead_detect();
void reset(int);


