#include"main.h"
#include"object.h"
#include"game.h"
#include"display.h"
#include"pp.h"

#include<bits/stdc++.h>

float fps;
bool done;
bool coin_on;
bool adir[4];
int stage_played;
int tube_fly1;
int tube_fly2;
int tube_fly3;
int start_point;
bool render;
int tt=0; //計算水管動畫時間
bool level_done;
bool setting_done;
bool menu_done;
int god_time=0;
int god_start=0;

ALLEGRO_BITMAP *level;
ALLEGRO_BITMAP *setting;
ALLEGRO_BITMAP *menuu;
ALLEGRO_DISPLAY *menu_display;

ALLEGRO_SAMPLE *menu_music;
ALLEGRO_SAMPLE_INSTANCE *menu_song_instance;

ALLEGRO_SAMPLE *win_music ;
ALLEGRO_SAMPLE_INSTANCE *win_music_instance ;

ALLEGRO_SAMPLE *dead_music ;
ALLEGRO_SAMPLE_INSTANCE *dead_music_instance ;

ALLEGRO_SAMPLE *god_music ;
ALLEGRO_SAMPLE_INSTANCE *god_song_instance ;

ALLEGRO_SAMPLE *music ;
ALLEGRO_SAMPLE_INSTANCE *song_instance ;

ALLEGRO_SAMPLE *powerup_music;
ALLEGRO_SAMPLE_INSTANCE *powerup_song_instance;

ALLEGRO_SAMPLE *dokan_music;
ALLEGRO_SAMPLE_INSTANCE *dokan_song_instance;

ALLEGRO_SAMPLE *break_music ;
ALLEGRO_SAMPLE_INSTANCE *break_song_instance ;

ALLEGRO_SAMPLE *coin_music ;
ALLEGRO_SAMPLE_INSTANCE *coin_song_instance ;

ALLEGRO_TIMER *timer;
ALLEGRO_TIMER *trap_timer;
ALLEGRO_TIMER *trap_timer2;
ALLEGRO_TIMER *trap_timer3;
ALLEGRO_TIMER *trap_timer4;
ALLEGRO_TIMER *trap_timer5;
ALLEGRO_TIMER *trap_timer6;
ALLEGRO_TIMER *trap_timer7;

ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER *menu_timer;
ALLEGRO_EVENT_QUEUE *menu_event_queue;
ALLEGRO_FONT *font18 ;

void menu_init()
{
    menu_done=false;
    level_done=false;
    setting_done = false;
    al_init();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();
    font18 = al_load_ttf_font("./font/pirulen.ttf",30,0);
    for(int i=0; i<4; i++) adir[i]=false;
    for(int i=0; i<4; i++) adir[i]=false;
    syobon.maxvelx = 3;
    syobon.maxvely = -7;
    menuu_init();
    menu_event_queue=al_create_event_queue();
    fps=1/60.0;
    menu_timer=al_create_timer(fps);
    al_register_event_source(menu_event_queue,al_get_display_event_source(menu_display));
    al_register_event_source(menu_event_queue,al_get_timer_event_source(menu_timer));
    al_register_event_source(menu_event_queue,al_get_keyboard_event_source());
    al_start_timer(menu_timer);
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(10);
    menu_music=al_load_sample("./BGM/field.ogg");
    menu_song_instance=al_create_sample_instance(menu_music);
    al_set_sample_instance_playmode(menu_song_instance,ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(menu_song_instance,al_get_default_mixer());
}

int menu_start()
{
    al_play_sample_instance(menu_song_instance);
    int ret = 0;
    while(!menu_done)
    {
        al_wait_for_event(menu_event_queue,&ev);
        if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_S)
        {
            setting_start();
            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(menuu,0,0,0);
            al_flip_display();
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_SPACE)
        {
            int choose = level_start();
            if(choose == 0)
            {
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(menuu,0,0,0);
                al_flip_display();
            }
            else if(choose == 1)
            {
                ret = 1;
                menu_done = true;
            }
            else if(choose==2)
            {
                ret = 2;
                menu_done = true;
            }
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
        {
            ret = 0;
            menu_done = true;
        }
    }
    al_stop_sample_instance(menu_song_instance);
    menu_destroy();
    return ret;
}

void setting_start()
{
    setting_done = false;
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(setting,0,0,0);
    al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 210, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvelx);
    al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 350, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvely);
    al_flip_display();
    while(!setting_done)
    {
        al_wait_for_event(menu_event_queue,&ev);
        if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_RIGHT)
        {
            if(syobon.maxvelx < 3.5)
            {
                syobon.maxvelx += 0.5;
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(setting,0,0,0);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 210, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvelx);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 350, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvely);
                al_flip_display();
            }
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_LEFT)
        {
            if(syobon.maxvelx > 2.5)
            {
                syobon.maxvelx -= 0.5;
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(setting,0,0,0);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 210, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvelx);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 350, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvely);
                al_flip_display();
            }
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_UP)
        {
            if(syobon.maxvely > -8)
            {
                syobon.maxvely -= (1);
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(setting,0,0,0);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 210, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvelx);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 350, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvely);
                al_flip_display();
            }
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_DOWN)
        {
            if(syobon.maxvely < -6)
            {
                syobon.maxvely += (1);
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_bitmap(setting,0,0,0);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 210, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvelx);
                al_draw_textf(font18, al_map_rgb(0, 225, 225), 400, 350, ALLEGRO_ALIGN_CENTRE, "%f", syobon.maxvely);
                al_flip_display();
            }
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_SPACE)
        {
            setting_done = true;
        }
    }
}


int level_start()
{
    level_done = false;
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(level,0,0,0);
    al_flip_display();
    while(!level_done)
    {
        al_wait_for_event(menu_event_queue,&ev);
        if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_1)  // choose level 1
        {
            return 1;
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_2)  // Choose level 2
        {
            return 2;
        }
        else if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_SPACE)  // Back to menu
        {
            level_done = true;
        }
    }
    return 0;
}

void menu_destroy()
{
    al_destroy_sample_instance(menu_song_instance);
    al_destroy_sample(menu_music);
    al_destroy_display(menu_display);
    al_destroy_timer(menu_timer);
    al_destroy_event_queue(menu_event_queue);
    al_destroy_bitmap(menuu);
    al_destroy_bitmap(setting);
    al_destroy_bitmap(level);
}

void set_trap_timer()
{
    trap_timer=al_create_timer(1/0.5);
    trap_timer2=al_create_timer(1/0.7);
    trap_timer3=al_create_timer(1/0.9);
    trap_timer4=al_create_timer(1/1.1);
    trap_timer5=al_create_timer(1/1.3);
    trap_timer6=al_create_timer(1.5);
    trap_timer7=al_create_timer(1.7);
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer2));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer3));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer4));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer5));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer6));
    al_register_event_source(event_queue,al_get_timer_event_source(trap_timer7));
    al_start_timer(trap_timer);
    al_start_timer(trap_timer2);
    al_start_timer(trap_timer3);
    al_start_timer(trap_timer4);
    al_start_timer(trap_timer5);
    al_start_timer(trap_timer6);
    al_start_timer(trap_timer7);
}

void timer_update()
{
    if(V[1356]->visible)
    {
        V[1356]->visible=false;
        V[1356]->collision=false;
        V[1366]->visible=false;
        V[1366]->collision=false;
    }
    else
    {
        V[1356]->visible=true;
        V[1356]->collision=true;
        V[1366]->visible=true;
        V[1366]->collision=true;
    }
}
void timer_update2()
{
    if(V[1358]->visible)
    {
        V[1358]->visible=false;
        V[1358]->collision=false;
        V[1364]->visible=false;
        V[1364]->collision=false;
    }
    else
    {
        V[1358]->visible=true;
        V[1358]->collision=true;
        V[1364]->visible=true;
        V[1364]->collision=true;
    }
}
void timer_update3()
{
    if(V[1363]->visible)
    {
        V[1363]->visible=false;
        V[1363]->collision=false;
    }
    else
    {
        V[1363]->visible=true;
        V[1363]->collision=true;
    }
}
void timer_update4()
{
    if(V[1357]->visible)
    {
        V[1357]->visible=false;
        V[1357]->collision=false;
        V[1365]->visible=false;
        V[1365]->collision=false;
    }
    else
    {
        V[1357]->visible=true;
        V[1357]->collision=true;
        V[1365]->visible=true;
        V[1365]->collision=true;
    }
}
void timer_update5()
{
    if(V[1359]->visible)
    {
        V[1359]->visible=false;
        V[1359]->collision=false;
        V[1367]->visible=false;
        V[1367]->collision=false;
    }
    else
    {
        V[1359]->visible=true;
        V[1359]->collision=true;
        V[1367]->visible=true;
        V[1367]->collision=true;
    }
}
void timer_update6()
{
    if(V[1360]->visible)
    {
        V[1360]->visible=false;
        V[1360]->collision=false;
        V[1362]->visible=false;
        V[1362]->collision=false;
    }
    else
    {
        V[1360]->visible=true;
        V[1360]->collision=true;
        V[1362]->visible=true;
        V[1362]->collision=true;
    }
}

void timer_update7()
{
    if(V[1361]->visible)
    {
        V[1361]->visible=false;
        V[1361]->collision=false;
    }
    else
    {
        V[1361]->visible=true;
        V[1361]->collision=true;
    }
}

void catch_process()
{
    ALLEGRO_BITMAP *tmp=V[1388]->img;
    V[1388]->img=al_load_bitmap("./res/s3/ally.png");
    al_convert_mask_to_alpha(V[1388]->img,al_map_rgb(0,0,0));
    al_convert_mask_to_alpha(V[1388]->img,al_map_rgb(153,255,255));
    al_destroy_bitmap(tmp);
    Catch=false;
    if(V[1388]->flag==0)
    {
        syobon.velx=-10;
        syobon.vely=-5;
        syobon.accy=9.8/20;
    }
    else
    {
        syobon.velx=10;
        syobon.vely=-5;
        syobon.accy=9.8/30;
    }
    V[1388]->vel_x=V[1388]->flag==1?3:-3;
}

void game_init()
{
    render=false;
    tt=tube_fly1=tube_fly2=tube_fly3=0;
    coin_on=false;
    done=false;
    al_init();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    for(int i=0; i<4; i++) adir[i]=false;
    map_init(stage_played);
    event_queue=al_create_event_queue();
    fps=1/60.0;
    timer=al_create_timer(fps);
    if(stage_played!=1) set_trap_timer();
    al_register_event_source(event_queue,al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_start_timer(timer);
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(10);
    music = al_load_sample("./BGM/dungeon.ogg");
    coin_music = al_load_sample("./SE/coin.ogg");
    dead_music = al_load_sample("./SE/death.ogg");
    win_music = al_load_sample("./SE/goal.ogg");
    break_music=al_load_sample("./SE/brockbreak.ogg");
    break_song_instance=al_create_sample_instance(break_music);
    song_instance = al_create_sample_instance(NULL);
    al_set_sample(song_instance,music);
    coin_song_instance = al_create_sample_instance(coin_music);
    god_music=al_load_sample("./SE/god.ogg");
    dead_music_instance = al_create_sample_instance(dead_music);
    win_music_instance = al_create_sample_instance(win_music);
    god_song_instance=al_create_sample_instance(god_music);
    al_set_sample_instance_playmode(god_song_instance,ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(god_song_instance,al_get_default_mixer());
    al_set_sample_instance_playmode(break_song_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(break_song_instance, al_get_default_mixer());
//    al_set_sample_instance_playmode(song_instance, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(coin_song_instance, ALLEGRO_PLAYMODE_ONCE);
  //  al_attach_sample_instance_to_mixer(song_instance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(coin_song_instance, al_get_default_mixer());
    al_set_sample_instance_playmode(dead_music_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(dead_music_instance, al_get_default_mixer());
    al_set_sample_instance_playmode(win_music_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(win_music_instance, al_get_default_mixer());
    powerup_music = al_load_sample("./SE/powerup.ogg");
    dokan_music = al_load_sample("./SE/dokan.ogg");
    powerup_song_instance = al_create_sample_instance(powerup_music);
    dokan_song_instance = al_create_sample_instance(dokan_music);
    al_set_sample_instance_playmode(powerup_song_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(powerup_song_instance, al_get_default_mixer());
    al_set_sample_instance_playmode(dokan_song_instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(dokan_song_instance, al_get_default_mixer());
    al_set_sample_instance_gain(break_song_instance, 7);
    al_set_sample_instance_gain(dokan_song_instance, 7);
}

int game_start()
{
    while(!done)
    {
//        al_play_sample_instance(song_instance);
        if(coin_on)
        {
            al_play_sample_instance(coin_song_instance);
            coin_on = false;
        }
        al_wait_for_event(event_queue,&ev);
        if(to_close())
        {
            done=true;
            game_destroy();
            return 0;
        }
        if(tube_fly1 == 1)
        {
            syobon.curframe = 0;
            if(ev.type==ALLEGRO_EVENT_TIMER)
            {
                render=true;
                if(syobon.visible)
                {
                    syobon.velx = 0;
                    syobon.vely = 0.5;
                    syobon.accx =0;
                    syobon.accy = 0;
                    syobon.x = 5940;
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    if(syobon.y > 350)
                    {
                        syobon.vely = 0;
                        syobon.visible = 0;
                    }
                }
                else if(V[1378]->y >= -400)
                {
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    tt++;
                    if(tt < 150)
                    {
                        if(V[1378]->x >= 5919)
                        {
                            V[1378]->vel_x = -2;
                            V[1379]->vel_x = -2;
                        }
                        if(V[1378]->x <= 5909)
                        {
                            V[1378]->vel_x = 2;
                            V[1379]->vel_x = 2;
                        }
                        V[1378]->x += V[1378]->vel_x;
                        V[1379]->x += V[1379]->vel_x;
                    }
                    else
                    {
                        V[1378]->x = 5919;
                        V[1379]->x = 5823;
                        V[1378]->acc_y = -9.8/30;
                    }
                }
                else
                {
                    al_stop_sample_instance(song_instance);
                    al_stop_sample_instance(coin_song_instance);
                    al_play_sample_instance(dead_music_instance);
                    al_rest(3);
                    syobon.live--;
                    font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                    al_draw_textf(font18, al_map_rgb(255, 225, 225), 420, 289, ALLEGRO_ALIGN_CENTRE, "X %d", syobon.live);
                    al_flip_display();
                    al_rest(2);
                    al_stop_sample_instance(dead_music_instance);
                    reset(stage_played);
                    continue;
                }
            }
        }
        else if(tube_fly2 == 1)
        {
            syobon.control = 0;
            syobon.curframe = 0;
            if(ev.type==ALLEGRO_EVENT_TIMER)
            {
                render=true;
                if(syobon.visible && syobon.flag == 0)
                {
                    syobon.velx = 0.5;
                    syobon.vely = 0;
                    syobon.accx =0;
                    syobon.accy = 0;
                    syobon.y = 390;
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    if(syobon.x > 5854)
                    {
                        syobon.velx = 0;
                        syobon.visible = 0;
                        syobon.flag = 1;
                    }
                }
                else if(syobon.x >= 5326 || syobon.y < 600)
                {
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    tt++;
                    if(tt < 150)
                    {
                        if(V[1378]->x >= 5910)
                        {
                            V[1378]->vel_x = -2;
                            V[1379]->vel_x = -2;
                        }
                        if(V[1378]->x <= 5900)
                        {
                            V[1378]->vel_x = 2;
                            V[1379]->vel_x = 2;
                        }
                        V[1378]->x += V[1378]->vel_x;
                        V[1379]->x += V[1379]->vel_x;
                    }
                    else if(syobon.x >= 5326)
                    {
                        V[1378]->x = 5910;
                        V[1379]->x = 5823;
                        syobon.visible = 1;
                        syobon.velx = -20;
                        syobon.accx = 0.3;
                    }
                    else
                    {
                        syobon.accy = 9.8/55;
                    }
                }
                else
                {
                    al_stop_sample_instance(song_instance);
                    al_stop_sample_instance(coin_song_instance);
                    al_play_sample_instance(dead_music_instance);
                    al_rest(3);
                    syobon.live--;
                    font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                    al_draw_textf(font18, al_map_rgb(255, 225, 225), 420, 289, ALLEGRO_ALIGN_CENTRE, "X %d", syobon.live);
                    al_flip_display();
                    al_rest(2);
                    al_stop_sample_instance(dead_music_instance);
                    reset(stage_played);
                    continue;
                }
            }
        }
        else if(tube_fly3 == 1)
        {
            syobon.control = 0;
            syobon.curframe = 0;
            if(ev.type==ALLEGRO_EVENT_TIMER)
            {
                render=true;
                if(syobon.visible)
                {
                    syobon.velx = 0;
                    syobon.vely = -0.5;
                    syobon.accx =0;
                    syobon.accy = 0;
                    syobon.x = 5490;
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    if(syobon.y < 130)
                    {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                        al_flip_display();
                        al_rest(3);
                        al_stop_sample_instance(song_instance);
                        game_destroy();
                        return stage_played;
                    }
                }
            }
        }
        else if(!syobon.dead && !syobon.goal)
        {
            if(!syobon.goal)
            {
                keyboard_input();
                status_update();
            }
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer)
            {
                timer_update();
                if(Catch) catch_process();
            }
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer2) timer_update2();
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer3) timer_update3();
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer4) timer_update4();
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer5) timer_update5();
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer6) timer_update6();
            if(ev.type==ALLEGRO_EVENT_TIMER&&ev.timer.source==trap_timer7) timer_update7();
            if(render&&al_is_event_queue_empty(event_queue))
            {
                collision_process2();
                render=false;
                trap_detect(stage_played);
                draw_player();
                dead_detect();
                display_update();
            }
        }
        else if(syobon.goal)
        {
            al_stop_sample_instance(song_instance);
            al_stop_sample_instance(coin_song_instance);
            al_play_sample_instance(win_music_instance);
            if(stage_played==1)
            {
                if(ev.type==ALLEGRO_EVENT_TIMER)
                {
                    render = true;
                    while(syobon.y <= 500)
                    {
                        syobon.flag = 0;
                        syobon.x=5261-syobon.sx+25;
                        syobon.vely=3.0;
                        syobon.velx=0.0;
                        syobon.accx=0.0;
                        syobon.accy=0.0;
                        syobon.curframe = 2;
                        draw_player();
                        display_update();
                    }
                    syobon.vely = 0;
                    if(!V[495]->visible)
                    {
                        while(syobon.x <= 5660)
                        {
                            syobon.velx = 2;
                            syobon.curframe = 0;
                            syobon.flag = 0;
                            syobon.x += syobon.velx;
                            display_update();
                        }
                        font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                        al_draw_textf(font18, al_map_rgb(255, 225, 225), 420, 289, ALLEGRO_ALIGN_CENTRE, "PASS!!");
                        al_flip_display();
                        al_rest(3);
                        syobon.goal = false;
                        al_stop_sample_instance(win_music_instance);
                        game_destroy();
                        return stage_played;
                    }
                    else
                    {
                        while(syobon.x <= 5500)
                        {
                            syobon.velx = 2;
                            syobon.curframe = 0;
                            syobon.flag = 0;
                            syobon.x += syobon.velx;
                            display_update();
                        }
                        while(syobon.x <= 5918)
                        {
                            syobon.velx = 2;
                            syobon.curframe = 0;
                            syobon.flag = 0;
                            syobon.x += syobon.velx;
                            V[497]->x += syobon.velx;
                            display_update();
                        }
                        al_stop_sample_instance(win_music_instance);
                        al_play_sample_instance(dead_music_instance);
                        while(syobon.y <= 610)
                        {
                            syobon.vely = 3;
                            syobon.curframe = 3;
                            syobon.flag = 0;
                            syobon.y += syobon.vely;
                            display_update();
                        }
                        syobon.live--;
                        font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                        al_draw_textf(font18, al_map_rgb(255, 225, 225), 420, 289, ALLEGRO_ALIGN_CENTRE, "X %d", syobon.live);
                        al_flip_display();
                        al_rest(3);
                        syobon.goal = false;
                        al_stop_sample_instance(dead_music_instance);
                        reset(stage_played);
                        continue;
                    }
                }
            }
            else if(stage_played==3)
            {
                if(ev.type==ALLEGRO_EVENT_TIMER)
                {
                    render = true;
                    while(syobon.y <= 500)
                    {
                        syobon.flag = 0;
                        syobon.x=791-syobon.sx+25;
                        syobon.vely=3.0;
                        syobon.velx=0.0;
                        syobon.accx=0.0;
                        syobon.accy=0.0;
                        syobon.curframe = 2;
                        draw_player();
                        display_update();
                    }
                    syobon.vely = 0;
                    while(syobon.x <= 1162)
                    {
                        syobon.velx = 2;
                        syobon.curframe = 0;
                        syobon.flag = 0;
                        syobon.x += syobon.velx;
                        display_update();
                    }
                    font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(syobon.img[0][0], 350, 270, 0);
                    al_draw_textf(font18, al_map_rgb(255, 225, 225), 365, 310, ALLEGRO_ALIGN_CENTRE, "All Clear!!");
                    al_flip_display();
                    al_rest(3);
                    syobon.goal = false;
                    al_stop_sample_instance(win_music_instance);
                    game_destroy();
                    return stage_played;
                }
            }
        }
        else
        {
            al_stop_sample_instance(song_instance);
            al_stop_sample_instance(coin_song_instance);
            al_play_sample_instance(dead_music_instance);
            syobon.curframe = 3;
            if(ev.type==ALLEGRO_EVENT_TIMER)
            {
                render=true;
                if(syobon.deadtime <= 130)
                {
                    if(render&&al_is_event_queue_empty(event_queue))
                    {
                        draw_player();
                        display_update();
                    }
                    syobon.deadtime++;
                    if(syobon.deadtime < 25)
                    {
                        syobon.vely = 0;
                        syobon.accy = 0;
                    }
                    if(syobon.deadtime >= 25 && syobon.deadtime < 75)
                    {
                        syobon.y -= 3.0;
                        syobon.vely=0;
                        syobon.accy = 0;
                    }
                    else syobon.accy=9.8/40;
                }
                else
                {
                    while(syobon.y<610)
                    {
                        draw_player();
                        display_update();
                    }
                    syobon.live--;
                    font18 = al_load_ttf_font("./font/pirulen.ttf",20,0);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_draw_bitmap(syobon.img[0][0], 350, 283, 0);
                    al_draw_textf(font18, al_map_rgb(255, 225, 225), 420, 289, ALLEGRO_ALIGN_CENTRE, "X %d", syobon.live);
                    al_flip_display();
                    al_rest(2);
                    al_stop_sample_instance(dead_music_instance);
                    reset(stage_played);
                    continue;
                }
            }
        }
    }
}

void reset(int stage_played)
{
    al_flush_event_queue(event_queue);
    for(auto &i:V) al_destroy_bitmap(i->img);
    V.clear();
    VB.clear();
    VP.clear();
    VB.clear();
    syobon.control=true;
    syobon.state = 0;
    syobon.invincible = 0;
    syobon.get_hit = 0;
    syobon.visible=true;
    tt=tube_fly1=tube_fly2=tube_fly3=0;
    god_start=god_time=0;
    if(!start_point)
    {
        ss = 1;
        if(stage_played==1)
        {
            for(int i=0; i<20; i++) trap_arr[i]=true;
            syobon.x=100.0;
            syobon.y=600.0-93;
            ground1_init();
            base1_init();
            brick_init();
            base_init();
            quest_init();
            stage_init();
            coin_init();
            others_init();
            monster_init();
            mushroom_init();
            flower_init();
            star_init();
            ball_init();
        }
        else if(stage_played==2)
        {
            for(int i=0; i<20; i++) trap_arr[i]=true;
            syobon.x=88;
            syobon.y=600-6*28-35;
            java_init_2();
            ground_init_2();
            brick_init_2();
            stair_init_2();
            others_init_2();
            VB_init2();
        }
        else
        {
            syobon.x=55;
            syobon.y=600-59-123-35;
            final_init();
        }
        for(int i=0; i<4; i++) adir[i]=false;
        Map.pos_x=0.0;
        Map.pos_y=0.0;
        syobon.accx=0.0;
        syobon.accy=0.0;
        syobon.flag=0;
        syobon.curframe=0;
        syobon.switch_delay=1;
        syobon.up_time=1;
        syobon.move_time=1;
        syobon.in_air=false;
        syobon.dead=false;
        syobon.moving=false;
        syobon.velx=0.0;
        syobon.vely=0.0;
        syobon.deadtime=0;

    }
    else
    {
        ss = 1;
        if(stage_played==1)
        {
            for(int i=0; i<20; i++) trap_arr[i]=true;
            syobon.x=3614.0;
            syobon.y=600.0-93;
            ground1_init();
            base1_init();
            brick_init();
            base_init();
            quest_init();
            stage_init();
            coin_init();
            others_init();
            monster_init();
            mushroom_init();
            flower_init();
            star_init();
            ball_init();
        }
        else
        {
            for(int i=0; i<20; i++) trap_arr[i]=true;
            syobon.x=3540;
            syobon.y=175;
            java_init_2();
            ground_init_2();
            brick_init_2();
            stair_init_2();
            others_init_2();
            VB_init2();
        }
        for(int i=0; i<4; i++) adir[i]=false;
        Map.pos_x=3614-400.0;
        Map.pos_y=0.0;
        syobon.accx=0.0;
        syobon.accy=0.0;
        syobon.flag=0;
        syobon.curframe=0;
        syobon.switch_delay=1;
        syobon.up_time=1;
        syobon.move_time=1;
        syobon.in_air=false;
        syobon.dead=false;
        syobon.moving=false;
        syobon.velx=0.0;
        syobon.vely=0.0;
        syobon.deadtime=0;
    }
}

void dead_detect()
{
    if(syobon.y>610||syobon.y<-100)
    {
        syobon.dead=true;
        syobon.live--;
        syobon.vely=0.0;
        syobon.velx=0.0;
    }
}

void status_update()
{
    if(ev.type==ALLEGRO_EVENT_TIMER)
    {
        render=true;
        if(god_start)
        {
            god_time++;
            if(god_time>=240) al_stop_sample_instance(god_song_instance);
        }

        if(syobon.get_hit == 1)
        {
            syobon.invincible = 1;
            invincible_time++;
            if(invincible_time >= 180)
            {
                syobon.invincible = 0;
                invincible_time = 0;
                syobon.get_hit = 0;
            }
        }
        if(syobon.in_air)
        {
            syobon.accy=9.8/55;
            syobon.accx=0;
            syobon.curframe=2;
        }
        if(!syobon.in_air&&syobon.moving)
        {
            syobon.air_jump=true;
            syobon.accy=0;
            syobon.switch_delay++;
            if(syobon.switch_delay>20) syobon.switch_delay=1;
            if(syobon.switch_delay<10) syobon.curframe=0;
            else syobon.curframe=1;
        }
        else if(!syobon.in_air&&!syobon.moving)
        {
            syobon.air_jump=true;
            syobon.curframe=0;
            syobon.accy=0;
        }
        if(adir[up])
        {
            if(!syobon.in_air)
            {
                syobon.air_jump=false;
                syobon.in_air=true;
                syobon.vely = syobon.maxvely;
            }
            else if(syobon.air_jump)
            {
                syobon.in_air=true;
                syobon.vely = -9.8/1.35;
                syobon.air_jump=false;
            }
            syobon.up_time++;
            if(syobon.up_time>15)
            {
                syobon.up_time=1;
                syobon.vely -= 0.6;
                syobon.accy+=0.6/5;
            }
        }
        else syobon.up_time=1;

        if(adir[Right])
        {
            syobon.flag=0;
            if(!syobon.moving)
            {
                syobon.moving=true;
                syobon.velx=0.5;
            }
            syobon.move_time++;
            if(syobon.move_time>10)
            {
                syobon.velx=syobon.maxvelx;
            }
        }
        else if(adir[Left])
        {
            syobon.flag=1;
            if(!syobon.moving)
            {
                syobon.moving=true;
                syobon.velx = -0.5;
            }
            syobon.move_time++;
            if(syobon.move_time>10)
            {
                syobon.velx = -syobon.maxvelx;
            }
        }
        else if(!adir[Right]&&syobon.velx>0)
        {
            syobon.accx=-syobon.velx/7.5;
            if(syobon.velx+syobon.accx<0)
            {
                syobon.velx=0;
                syobon.accx=0;
            }
            syobon.moving=false;
            syobon.move_time=1;
        }
        else
        {
            syobon.accx=-syobon.velx/7.5;
            if(syobon.velx+syobon.accx>0)
            {
                syobon.velx=0;
                syobon.accx=0;
            }
            syobon.moving=false;
            syobon.move_time=1;
        }
        if(adir[down])
        {

        }
        if(adir[Left]&&adir[Right])
        {
            syobon.velx=0;
            syobon.accx=0;
        }
    }

}

void keyboard_input()
{
    if(syobon.dead||!syobon.control)
    {
        for(int i=0; i<4; i++) adir[i]=false;
        return;
    }
    if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_UP:
            adir[up]=true;
            break;
        case ALLEGRO_KEY_DOWN:
            adir[down]=true;
            break;
        case ALLEGRO_KEY_LEFT:
            adir[Left]=true;
            if(!syobon.in_air) syobon.curframe=1;
            syobon.flag=1;
            break;
        case ALLEGRO_KEY_RIGHT:
            adir[Right]=true;
            if(!syobon.in_air) syobon.curframe=1;
            syobon.flag=0;
            break;
        case ALLEGRO_KEY_W:
            adir[up]=true;
            break;
        case ALLEGRO_KEY_S:
            adir[down]=true;
            break;
        case ALLEGRO_KEY_A:
            adir[Left]=true;
            if(!syobon.in_air) syobon.curframe=1;
            syobon.flag=1;
            break;
        case ALLEGRO_KEY_D:
            adir[Right]=true;
            if(!syobon.in_air) syobon.curframe=1;
            syobon.flag=0;
            break;
        case ALLEGRO_KEY_5:
            if(stage_played == 1 && syobon.state == 1 && V[505]->visible  == false)
            {
                V[505]->visible=true;
                V[505]->collision = true;
                if(syobon.flag)
                {
                    V[505]->x=syobon.x-10;
                    V[505]->y=syobon.y+4;
                    V[505]->vel_x = -7;
                    V[505]->flag = 1;
                }
                else
                {
                    V[505]->x=syobon.x+20;
                    V[505]->y=syobon.y+4;
                    V[505]->vel_x = 7;
                    V[505]->flag = 0;
                }
            }
            if(stage_played == 2 && syobon.state == 1 && V[1394]->visible  == false)
            {
                V[1394]->visible=true;
                V[1394]->collision = true;
                if(syobon.flag)
                {
                    V[1394]->x=syobon.x-10;
                    V[1394]->y=syobon.y+4;
                    V[1394]->vel_x = -7;
                    V[1394]->flag = 1;
                }
                else
                {
                    V[1394]->x=syobon.x+20;
                    V[1394]->y=syobon.y+4;
                    V[1394]->vel_x = 7;
                    V[1394]->flag = 0;
                }
            }
            if(stage_played == 3 && syobon.state == 1 && V[146]->visible  == false)
            {
                V[146]->visible=true;
                V[146]->collision = true;
                if(syobon.flag)
                {
                    V[146]->x=syobon.x-10;
                    V[146]->y=syobon.y+4;
                    V[146]->vel_x = -7;
                    V[146]->flag = 1;
                }
                else
                {
                    V[146]->x=syobon.x+20;
                    V[146]->y=syobon.y+4;
                    V[146]->vel_x = 7;
                    V[146]->flag = 0;
                }
            }
        default:
            break;
        }
    }
    if(ev.type==ALLEGRO_EVENT_KEY_UP)
    {
        switch(ev.keyboard.keycode)
        {
        case ALLEGRO_KEY_UP:
            adir[up]=false;
            break;
        case ALLEGRO_KEY_DOWN:
            adir[down]=false;
            break;
        case ALLEGRO_KEY_LEFT:
            adir[Left]=false;
            break;
        case ALLEGRO_KEY_RIGHT:
            adir[Right]=false;
            break;
        case ALLEGRO_KEY_W:
            adir[up]=false;
            break;
        case ALLEGRO_KEY_S:
            adir[down]=false;
            break;
        case ALLEGRO_KEY_A:
            adir[Left]=false;
            break;
        case ALLEGRO_KEY_D:
            adir[Right]=false;
            break;
        default:
            break;
        }
    }
}

bool to_close()
{
    if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE) return true;
    if(ev.type==ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE) return true;
    return false;
}

void game_destroy()
{
    render=false;
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(Map.img);
    al_destroy_font(font18);
    al_destroy_sample(music);
    al_destroy_sample_instance(song_instance);
    al_destroy_sample(coin_music);
    al_destroy_sample_instance(coin_song_instance);
    al_destroy_sample(dead_music);
    al_destroy_sample_instance(dead_music_instance);
    al_destroy_sample(win_music);
    al_destroy_sample_instance(win_music_instance);
    al_destroy_sample(break_music);
    al_destroy_sample_instance(break_song_instance);
    al_destroy_sample(god_music);
    al_destroy_sample_instance(god_song_instance);
    al_destroy_sample(powerup_music);
    al_destroy_sample_instance(powerup_song_instance);
    al_destroy_sample(dokan_music);
    al_destroy_sample_instance(dokan_song_instance);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            al_destroy_bitmap(syobon.img[i][j]);
        }
    }
    for(auto &i : V) al_destroy_bitmap(i->img);
    V.clear();
    VP.clear();
    VB.clear();
    VB2.clear();
}
