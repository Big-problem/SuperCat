#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>

#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

#include<iostream>
#include<bits/stdc++.h>

struct player
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
    int flag;
    int curframe; //控制在哪一張圖
    int switch_delay;
    int up_time;
    int move_time;
    int sx;
    int sy;
    int state;
    int invincible;
    int get_hit;
    ALLEGRO_BITMAP *img[2][4];
    int live;
    int deadtime;
    int boundx;
    int boundy;
    int passtime;
    int gold;
    float maxvelx;
    float maxvely;
};

extern player syobon;
void player_init(int);
void draw_player();
void player_update();
