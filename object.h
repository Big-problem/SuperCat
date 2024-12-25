#include<allegro5/allegro_image.h>
#include<allegro5/allegro.h>

#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>

#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

class Object
{
public:
    virtual void collide() = 0;
    virtual void update() = 0;
    float x;
    float y;
    bool visible;
    bool collision;
    int boundx;
    int boundy;
    int type;
    int sx;
    int sy;
    ALLEGRO_BITMAP *img;
    int flag;
    int number;
    float vel_x;
    float vel_y;
    float acc_x;
    float acc_y;
    bool in_air;
};

class Monster : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
                        float _acc_x, float _acc_y, bool _in_air);
    Monster(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
            float _acc_x, float _acc_y, bool _in_air);
};

class Coin : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Coin(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Base : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Base(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Brick : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Brick(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Quest : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Quest(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Tube : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Tube(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Cloud : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Cloud(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Record : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Record(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Trap : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Trap(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Pole : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Pole(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Spring : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Spring(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Mushroom : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Mushroom(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    float original_x;
    float original_y;
};

class Flower : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Flower(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    float original_x;
    float original_y;
};

class Star : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Star(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    float original_x;
    float original_y;
};

class Ball : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Ball(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Untouchable : public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Untouchable(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class B1_G1_S : public Object  // base1, ground1, stage
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    B1_G1_S(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Platform:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Platform(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Torch:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Torch(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    float original_x,original_y;
};

class Switch:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Switch(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Ton:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
    Ton(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag);
};

class Fly:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
    Fly(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
};

class Ally:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
    Ally(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
};

class Fire:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
    Fire(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
};

class Cat:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
    Cat(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
};

class Boss:public Object
{
public:
    void collide() override;
    void update() override;
    static void set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
    Boss(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air);
};

extern vector<Object*> V;
extern vector<Platform*> VP;
extern vector<Base*> VB;
extern vector<Base*> VB2;

enum obj_type {ground1,base,base1,brick,question,stage,coin,stube,tube,spring,monster,bloom,trap,record,pole, mushroom, flower, star, ball, none};
extern float set_x,set_y;
extern bool coin_on;
extern int start_point;
extern int ss; //判斷第一關星星的狀態
extern bool Catch;
extern int invincible_time;
extern int tube_fly1;
extern int tube_fly2;
extern int tube_fly3;

void player_dead();
void object_init();
void base1_init();
void ground1_init();
void base_init();
void base_init();
void brick_init();
void quest_init();
void stage_init();
void coin_init();
void others_init();
void monster_init();
void mushroom_init();
void flower_init();
void star_init();
void ball_init();
void collision_process2();

//關卡2
void ground_init_2();
void brick_init_2();
void stair_init_2();
void others_init_2();
void java_init_2();
void VB_init2();
void final_init(); //關卡二的第二場景
