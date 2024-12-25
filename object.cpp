#include"main.h"
#include"object.h"
#include"game.h"
#include"display.h"
#include"pp.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<Object*> V;
vector<Platform*> VP;
vector<Base*> VB,VB2;

bool Catch;

void object_init()
{
    start_point=0;
}

int stand;
int ss= 1;

void collision_process2()
{
    stand = 0;
    for(auto &i : V)
    {
        if(!i->visible && !i->collision) continue;
        i->collide();
    }
    if(!stand) syobon.in_air=true;
}

void player_dead()
{
    if(syobon.deadtime <= 130)
    {
        syobon.curframe = 3;
        display_update();
        syobon.deadtime++;
        if(syobon.deadtime >= 25 && syobon.deadtime < 50) syobon.y -= 3;
        if(syobon.deadtime >= 50) syobon.y += 3;
    }
}

void monster_init()
{
    Monster::set_att(490, 454, 1, 1, 30, 25, monster, "./res/monster.png", 0, -0.5, 0, 0, 0, 0);
}

void coin_init()
{
    float set_x=1824.0,set_y=44.0;
    for(int i=0; i<11; i++)
    {
        if(4<=i&&i<=6)
        {
            set_x+=43.0;
            continue;
        }
        Coin::set_att(set_x, set_y, true, true, 35, 46, coin, "./res/coin.png", 0);

        set_x+=43.0;
    }
    set_x=355.0,set_y=495.0;
    for(int i=0; i<7; i++)
    {
        Coin::set_att(set_x, set_y, true, true, 35, 46, coin, "./res/coin.png", 0);

        set_x+=43.0;
    }
}

void base1_init()
{
    float set_x=0.0,set_y=600-30-28.5;
    while(set_x<=6000.0)
    {
        if(set_x>=1000&&set_x<1050)
        {
            for(int i=0; i<10; i++) set_x+=29.0;
        }
        if(set_x>=3000&&set_x<3030)
        {
            for(int i=0; i<12; i++) set_x+=29.0;
        }
        if(set_x>=3700&&set_x<3730)
        {
            for(int i=0; i<6; i++) set_x+=29.0;
        }
        if(set_x>=4130&&set_x<4160) set_x+=29.0;
        if(set_x>=5900&&set_x<5930) set_x+=29.0;

        B1_G1_S::set_att(set_x, set_y, true, true, 32, 30, base1, "./res/base1.jpg", 0);

        set_x+=29.0;
    }
}

void ground1_init()
{
    float set_x=0.0,set_y=600-30;
    while(set_x<=6000.0)
    {
        if(set_x>=1000&&set_x<1050)
        {
            for(int i=0; i<10; i++) set_x+=29.0;
        }
        if(set_x>=3000&&set_x<3030)
        {
            for(int i=0; i<12; i++) set_x+=29.0;
        }
        if(set_x>=3700&&set_x<3730)
        {
            for(int i=0; i<6; i++) set_x+=29.0;
        }
        if(set_x>=4130&&set_x<4160) set_x+=29.0;
        if(set_x>=5900&&set_x<5930) set_x+=29.0;

        B1_G1_S::set_att(set_x, set_y, true, true, 32, 30, ground1, "./res/ground1.jpg", 0);

        set_x+=29.0;
    }
}

void base_init()
{
    float set_x=4141.0,set_y=421.5;
    for(int i=0; i<7; i++)
    {
        Base::set_att(set_x, set_y, false, true, 31, 30, base, "./res/base_cut.jpg", 0);

        set_x-=29;
    }
    set_x=1021.0,set_y=425.0;

    Base::set_att(set_x, set_y, false, true, 31, 30, base, "./res/base_cut.jpg", 0);

    set_x=1646.0,set_y=220.0;

    Base::set_att(set_x, set_y, false, true, 31, 30, base, "./res/base_cut.jpg", 0);

    set_x=2038.0,set_y=425.0;

    Base::set_att(set_x, set_y, false, true, 31, 30, base, "./res/base_cut.jpg", 0);
}

void brick_init()
{
    float set_x=3124.0,set_y=395.5;
    for(int i=0; i<5; i++)
    {
        Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        set_x+=29.0;
    }
    set_x=3589.0,set_y=395.5;
    for(int i=0; i<3; i++)
    {
        Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        set_x+=29.0;
    }
    set_x=429.0,set_y=350.0;
    for(int i=0; i<5; i++)
    {
        if(i!=2)
        {
            Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        }
        set_x+=29;
    }
    set_x=749.0,set_y=115.0;
    for(int i=0; i<7; i++)
    {
        Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        set_x+=29;
    }
    set_x=1500.0,set_y=350.0;
    for(int i=0; i<4; i++)
    {
        Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        set_x+=29;
    }
    set_x=1766.0,set_y=90.0;
    for(int i=0; i<20; i++)
    {
        Brick::set_att(set_x, set_y, true, true, 32, 30, brick, "./res/brick.jpg", 0);

        set_x+=29;
    }
}

void quest_init()
{

    Quest::set_att(400.0, 350.0, true, true, 33, 30, question, "./res/question.jpg", 0);

    Quest::set_att(486.0, 350.0, true, true, 33, 30, question, "./res/question.jpg", 0);

    Quest::set_att(486.0, 225.0, true, true, 33, 30, question, "./res/question.jpg", 0);

    Quest::set_att(574.0, 350.0, true, true, 33, 30, question, "./res/question.jpg", 0);

    Quest::set_att(4445.0, 300.0, true, true, 33, 30, question, "./res/question.jpg", 0);

    float set_x=4325.0,set_y=420.0;
    for(int i=0; i<3; i++)
    {
        Quest::set_att(set_x, set_y, true, true, 33, 30, question, "./res/question.jpg", 0);

        set_x+=120.0;
    }
}

void stage_init()
{
    float set_x=3479.0,set_y=503.5,tmpx;
    for(int i=0; i<7; i++)
    {
        B1_G1_S::set_att(set_x, set_y, true, true, 38, 38, stage, "./res/stage.jpg", 0);

        set_y-=36.5;
    }
    set_x=3886.0,set_y=503.5,tmpx=set_x;
    for(int i=0; i<3; i++)
    {
        set_x=tmpx;
        for(int j=0; j<3-i; j++)
        {
            B1_G1_S::set_att(set_x, set_y, true, true, 38, 38, stage, "./res/stage.jpg", 0);

            set_x+=38.0;
        }
        set_y-=36.5;
    }
    set_y=503.5;
    for(int i=0; i<8; i++)
    {
        set_x=4700.0+i*38;
        for(int j=0; j<9-i; j++)
        {
            B1_G1_S::set_att(set_x, set_y, true, true, 38, 38, stage, "./res/stage.jpg", 0);

            set_x+=38.0;
        }
        set_y-=36.5;
    }
    B1_G1_S::set_att(5270.0, 503.0, true, true, 38, 38, stage, "./res/stage.jpg", 0);

}

void others_init()
{
    Untouchable::set_att(100.0, 440.0, true, false, 0, 0, none, "./res/hill.png", 0);

    Tube::set_att(775.0, 418.5, true, true, 85, 123, tube, "./res/stube.png", 0);

    Tube::set_att(4161.5, 381.5, true, true, 86, 160, tube, "./res/tube.png", 0);

    Tube::set_att(2446.0, 380.5, true, true, 86, 160, tube, "./res/tube.png", 0);

    Cloud::set_att(1081.0, 0, true, true, 95, 56, bloom, "./res/bloom.png", 0);

    Cloud::set_att(1998.0, 15.0, true, true, 95, 56, bloom, "./res/bloom.png", 0);

    Record::set_att(3614.0, 461.0, true, true, 57, 80, record, "./res/record.png", 0);

    Trap::set_att(4443.0, 261.0, true, true, 35, 37, trap, "./res/trap.png", 0);

    Pole::set_att(5261.0, 121.0, true, true, 30, 374, pole, "./res/pole.png", 0);

    Untouchable::set_att(5600.0, 420.5, true, true, 0, 0, none, "./res/dest.png", 0);

    Spring::set_att(1365.0, 508.0, true, true, 31, 34, spring, "./res/spring.png", 0);
}

void flower_init()
{
    Flower::set_att(490.0, 225.0, false, false, 23, 27, flower, "./res/flower.png", 0);
}

void mushroom_init()
{
    Mushroom::set_att(4445.0, 420.0, false, false, 29, 25, mushroom, "./res/mushroom.png", 0);

    Mushroom::set_att(574.0, 350.0, false, false, 29, 25, mushroom, "./res/mushroom.png", 0);

    Mushroom::set_att(4565.0, 420.0, false, false, 29, 25, mushroom, "./res/mushroom2.png", 0);
}

void star_init()
{
    Star::set_att(4325.0, 388.0, false, false, 28, 28, star, "./res/star.png", 0);
}

void ball_init()
{
    Ball::set_att(syobon.x+20, syobon.y+4, false, false, 29, 26, ball, "./res/ball.png", 0);
}

// Monster
Monster::Monster(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
                 float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}
void Monster::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
                      float _acc_x, float _acc_y, bool _in_air)
{
    Monster *monster = new Monster(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag, _vel_x, _vel_y, _acc_x, _acc_y, _in_air);
    al_convert_mask_to_alpha(monster->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(monster->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(monster->img,al_map_rgb(160,180,250));
    V.push_back(monster);
}
void Monster::collide()
{
    if(visible)
    {
        if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y && !syobon.invincible)  // While colliding
        {
            if(syobon.y+syobon.boundy <= y+11 && syobon.vely >= 0)
            {
                if(syobon.x>=760&&syobon.x<=860)   //Sea
                {
                    syobon.dead=true;
                    return;
                }
                else if(syobon.x>=2231.0&&syobon.x<=2546.0)   //Big boss
                {
                    syobon.dead=true;
                    return;
                }
                // ½ò©ÇÃ~
                visible = false;
                syobon.vely = -9.8/2;
            }
            else if(syobon.state == 1)  // From fire state to normal state
            {

                al_set_sample_instance_gain(dokan_song_instance, 5);
                al_play_sample_instance(dokan_song_instance);
                al_rest(1.2);
                syobon.get_hit = 1;
                syobon.state = 0;
                return;
            }
            else
            {
                syobon.dead=true;
            }
        }

        if(V[505]->x+V[505]->boundx >= x && V[505]->x <= x+boundx &&
                V[505]->y <= y+boundy && V[505]->y+V[505]->boundy >= y && V[505]->visible)  // Fire ball
        {
            V[505]->visible = false;
            visible = false;
            collision = false;
        }
    }
}
void Monster::update()
{
    if(stage_played==1)
    {
        if((number == 509||number == 513) &&  sy == 38)  // Turtle
        {
            if(x >= 4161+500)
            {
                flag = (flag+1)%2;
                vel_x = -2;
            }
            else if(x <= 4161+90)
            {
                flag = (flag+1)%2;
                vel_x=2;
            }
        }
    }
    else
    {
        if(trap_arr[3]) return;
        if(y<250&&x+boundx<4005)
        {
            acc_y=9.8/55;
        }
        else if(vel_x>0&&x>4020)
        {
            acc_y=9.8/55;
        }
        else if(y+boundy>600-2*28&&vel_y>0)
        {
            y=600-2*28-boundy;
            vel_y=0;
            acc_y=0;
            vel_x=-0.8;
        }
        else if(x<3930)
        {
            flag=1;
            vel_x*=-1;
        }

    }

    x += vel_x;
    y += vel_y;
    vel_x += acc_x;
    vel_y += acc_y;
}

// Coin
Coin::Coin(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Coin::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Coin *coin = new Coin(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(coin->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(coin->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(coin->img,al_map_rgb(160,180,250));
    V.push_back(coin);
}
void Coin::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&
            syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)
    {
        syobon.gold++;
        coin_on = true;
        visible = false;
        collision = false;
    }
}
void Coin::update()
{
    return;
}

// Base
Base::Base(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Base::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Base *base = new Base(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(base->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(base->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(base->img,al_map_rgb(160,180,250));
    V.push_back(base);
}
void Base::collide()
{
    if(!trap_arr[1]&&number>=532&&number<=548)
    {
        for(int i=1262; i<=1331; i++)
        {
            if(y<V[i]->y+V[i]->boundy&&y+boundy>V[i]->y)
            {
                al_play_sample_instance(break_song_instance);
                V[i]->visible=false;
                V[i]->collision=false;
            }
        }
    }
    if(syobon.dead) return;
    if(syobon.x+17 >= x && syobon.x+5 <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y && visible) stand = 1;
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if(((syobon.x < x && syobon.velx > 0) || (syobon.x > x && syobon.velx < 0)) && visible)
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx && visible)
        {
            syobon.control=true;
            syobon.y = y-36;
            syobon.vely=0.0;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
        if(!trap_arr[1]&&number>=532&&number<=548)
        {
            if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx)
            {
                syobon.vely = 0;
                visible = true;
                syobon.dead=true;
            }// ¼²¥¦

        }
        else
        {
            if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx && syobon.vely < 0)
            {
                if(x==1021) coin_on=true;
                syobon.vely = 0;
                visible = true;
            }// ¼²¥¦
        }
    }
}
void Base::update()
{
    if(!trap_arr[1]&&syobon.dead) collide();
    y+=vel_y;
    vel_y+=acc_y;
}

// Brick
Brick::Brick(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Brick::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Brick *brick = new Brick(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(brick->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(brick->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(brick->img,al_map_rgb(160,180,250));
    V.push_back(brick);
}
void Brick::collide()
{
    if(syobon.x+17 >= x+1 && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y) stand = 1;
    if(syobon.x+syobon.boundx >= x+1 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if((syobon.x < x+1 && syobon.velx > 0) || (syobon.x > x+1 && syobon.velx < 0))
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx)
        {
            if(stage_played!=1&&number>=1332&&number<=1334)
            {
                al_play_sample_instance(break_song_instance);
                visible=false;
                collision=false;
                return;
            }
            syobon.vely = 0;
            syobon.y = y-36;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
        if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx)
        {
            if(number>=381&&number<393)  // trap 0 (¼²¨ìÁÙ¬O¦º)
            {
                syobon.dead=true;
                return;
            }
            al_play_sample_instance(break_song_instance);
            syobon.vely = 0;
            visible = false;
            collision = false;

        }// ¼²¥¦
    }
}
void Brick::update()
{
    y += vel_y;
    vel_y += acc_y;
}

// Quest
Quest::Quest(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Quest::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Quest *quest = new Quest(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(quest->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(quest->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(quest->img,al_map_rgb(160,180,250));
    V.push_back(quest);
}
void Quest::collide()
{
    if(syobon.x+17 >= x+2 && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y) stand = 1;
    if(syobon.x+syobon.boundx >= x+2 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if((syobon.x < x+2 && syobon.velx > 0) || (syobon.x > x+2 && syobon.velx < 0))
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        } //¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx)
        {
            syobon.vely = 0;
            syobon.y = y-36;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
        if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx && syobon.vely < 0)
        {
            if(stage_played == 1 && number==407)
            {
                y+=syobon.vely;
                return;
            }
            if(stage_played == 1 && collision)
            {
                if(x==4445.0 && y==420.0)
                {
                    V[500]->visible = true;
                    V[500]->collision=false;
                }
                else if(x==574.0)
                {
                    V[501]->visible = true;
                    V[501]->collision=false;
                }
                else if(x==4565.0)
                {
                    V[502]->visible = true;
                    V[502]->collision=false;
                }
                else if(x==486.0 && y == 225.0)
                {
                    V[503]->visible = true;
                    V[503]->collision=false;
                }
                else if(x==4325.0)
                {
                    V[504]->visible = true;
                    V[504]->collision=false;
                }
                collision = false;
                img = al_load_bitmap("./res/base_cut.jpg");
                sx=al_get_bitmap_width(img);
                sy=al_get_bitmap_height(img);
                al_convert_mask_to_alpha(img,al_map_rgb(153,255,255));
            }
            if(stage_played == 2 && collision)
            {
                V[1393]->visible = true;
                V[1393]->collision=false;
                collision = false;
                img = al_load_bitmap("./res/s3/base1.png");
                sx=al_get_bitmap_width(img);
                sy=al_get_bitmap_height(img);
                al_convert_mask_to_alpha(img,al_map_rgb(153,255,255));
            }
            syobon.vely = 0;
        }// ¼²¥¦
    }
}
void Quest::update()
{
    return;
}

// Tube
Tube::Tube(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Tube::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Tube *tube = new Tube(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(tube->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(tube->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(tube->img,al_map_rgb(160,180,250));
    al_convert_mask_to_alpha(tube->img,al_map_rgb(130,146,203));
    al_convert_mask_to_alpha(tube->img,al_map_rgb(120,135,187));
    al_convert_mask_to_alpha(tube->img,al_map_rgb(115,129,179));
    V.push_back(tube);
}
void Tube::collide()
{
    if(number == 1378)
    {
        if(syobon.x+17 >= x && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y) stand = 1;
        if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
        {
            if((syobon.x < x && syobon.velx > 0) || (syobon.x > x+11 && syobon.velx < 0))
            {
                syobon.velx = 0;
                syobon.moving = false;
                syobon.curframe = 0;
            }// ¥ª¥k
            if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx)
            {
                syobon.y = y-37;
                syobon.vely=0.0;
                syobon.accy=0.0;
                syobon.in_air=false;
                syobon.curframe = 0;
            }//½ò¥¦
        }
    }
    if(number == 1379)
    {
        if(syobon.x+17 >= x && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y) stand = 1;
        if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+10)  // While colliding
        {

            if((syobon.x < x && syobon.velx > 0) || (syobon.x > x+boundx-10 && syobon.velx < 0))
            {
                syobon.velx = 0;
                syobon.moving = false;
                syobon.curframe = 0;
            }// ¥ª¥k
            if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx)
            {
                syobon.y = y-34;
                syobon.vely=0.0;
                syobon.accy=0.0;
                syobon.in_air=false;
                syobon.curframe = 0;
            }//½ò¥¦
        }
    }
    else if(number == 1380)
    {
        if(syobon.x+syobon.boundx >= x+1 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+5)  // While colliding
        {
            if((syobon.x < x+1 && syobon.velx > 0) || (syobon.x > x+boundx-10 && syobon.velx < 0))
            {
                syobon.velx = 0;
                syobon.moving = false;
                syobon.curframe = 0;
            }// ¥ª¥k
            if(syobon.y <= y+boundy && syobon.x+17 > x+1 && syobon.x+5 < x+boundx && syobon.vely < 0)
            {
                syobon.vely=0.0;
                if(syobon.x >= 5479 && syobon.x <= 5514 && adir[up])
                {
                }
            }//¼²¥¦
        }
    }
    else
    {
        if(syobon.x+17 >= x+11 && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y+20) stand = 1;
        if(syobon.x+syobon.boundx >= x+11 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+20)  // While colliding
        {
            if((syobon.x < x+11 && syobon.velx > 0) || (syobon.x > x+11 && syobon.velx < 0))
            {
                syobon.velx = 0;
                syobon.moving = false;
                syobon.curframe = 0;
            }// ¥ª¥k
            if(syobon.y < y && syobon.x+17 > x+11 && syobon.x+5 < x+boundx)
            {
                syobon.y = y+20-36;
                syobon.vely=0.0;
                syobon.accy=0.0;
                syobon.in_air=false;
                syobon.curframe = 0;
            }//½ò¥¦
        }
    }
}
void Tube::update()
{
    if(stage_played == 2 && adir[down] && syobon.x >= 5930 && syobon.x <= 5962 && syobon.y <= V[1378]->y+V[1378]->boundy &&
            syobon.y+syobon.boundy+5 >= V[1378]->y)
    {
        if(trap_arr[11])
        {
            trap_arr[11]=false;
            al_play_sample_instance(dokan_song_instance);
        }
        tube_fly1 = 1;
    }
    else if(stage_played == 2 && adir[Right] && syobon.x+syobon.boundx >= V[1379]->x+1 && syobon.y <= V[1379]->y+V[1379]->boundy &&
            syobon.y+syobon.boundy+5 >= V[1379]->y+20 && syobon.y >= 393)
    {
        if(trap_arr[12])
        {
            trap_arr[12]=false;
            al_play_sample_instance(dokan_song_instance);
        }
        tube_fly2 = 1;
    }
    else if(stage_played == 2 && adir[up] && syobon.x >= 5482 && syobon.x <= 5510 &&
            syobon.y <= V[1380]->y+V[1380]->boundy && syobon.y+syobon.boundy >= V[1380]->y+5 && syobon.vely < 0)
    {
        if(trap_arr[13])
        {
            trap_arr[13]=false;
            al_play_sample_instance(dokan_song_instance);
        }
        tube_fly3 = 1;
    }
    y+=vel_y;
    vel_y+=acc_y;
}

// Cloud
Cloud::Cloud(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Cloud::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Cloud *cloud = new Cloud(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(cloud->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(cloud->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(cloud->img,al_map_rgb(160,180,250));
    V.push_back(cloud);
}
void Cloud::collide()
{
    if(syobon.x+syobon.boundx >= x+20 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+20 && !syobon.invincible)  // While colliding
    {
        img=al_load_bitmap("./res/bloom2.png");
        sx=al_get_bitmap_width(img);
        sy=al_get_bitmap_height(img);
        if(syobon.state == 1)  // From fire state to normal state
        {
            al_set_sample_instance_gain(dokan_song_instance, 5);
            al_play_sample_instance(dokan_song_instance);
            al_rest(1.2);
            syobon.get_hit = 1;
            syobon.state = 0;
            return;
        }
        syobon.dead=true;
    }
}
void Cloud::update()
{
    return;
}

//Torch
Torch::Torch(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    original_x=x-10;
    original_y=y-10;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}

void Torch::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Torch *torch=new Torch(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    V.push_back(torch);
}

void Torch::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+20)  // While colliding
    {
        syobon.dead=true;
        img=al_load_bitmap("./res/s3/trap_torch.png");
        sx=al_get_bitmap_width(img);
        sy=al_get_bitmap_height(img);
        x=original_x;
        y=original_y;
    }
}

void Torch::update()
{
    return;
}

//Switch
Switch::Switch(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}

void Switch::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Switch *sw=new Switch(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    V.push_back(sw);
}

void Switch::collide()
{
    if(syobon.x+17 >= x && syobon.x+5 <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y && visible) stand = 1;
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if(((syobon.x < x && syobon.velx > 0) || (syobon.x > x && syobon.velx < 0)) && visible)
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx && visible)
        {
            syobon.y = y-36;
            syobon.vely=0.0;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
        if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx && syobon.vely < 0)
        {
            img=al_load_bitmap("./res/s3/on.png");
            for(auto &i:VP)
            {
                i->visible=true;
                i->collision=true;
            }
            sx=al_get_bitmap_width(img);
            sy=al_get_bitmap_height(img);
            syobon.vely = 0;
        }// ¼²¥¦
    }
}

void Switch::update()
{
    return;
}

//Platform
Platform::Platform(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    if(sy==22) vel_y=0;
    else vel_y=1;
    vel_x = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}

void Platform::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Platform *platform=new Platform(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(platform->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(platform->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(platform->img,al_map_rgb(160,180,250));
    V.push_back(platform);
    VP.push_back(platform);
}

void Platform::collide()
{
    if(syobon.x+17 >= x+2 && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y) stand = 1;
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&
            syobon.y <= y+boundy-5 && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if(((syobon.x < x && syobon.velx > 0) || (syobon.x > x && syobon.velx < 0)) && visible)
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx && visible)
        {
            if(sy==22)
            {
                syobon.control=false;
                syobon.in_air=true;
                syobon.velx=-3;
                syobon.vely=-5;
                syobon.accy=9.8/30;
            }
            else
            {
                for(auto &i:VP)
                {
                    if(i->sy!=22) i->vel_y=3;
                }
                syobon.in_air=false;
                syobon.vely=vel_y;
                syobon.accy=acc_y;
                syobon.curframe = 0;
                syobon.y = y-36;
            }
        }// ½ò¥¦
        if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx && syobon.vely < 0)
        {
            syobon.vely = vel_y;
            syobon.accy=9.8/55;
        }// ¼²¥¦
    }
}

void Platform::update()
{
    y+=vel_y;
    if(y>610) y=-10;
}

// Record
Record::Record(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Record::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Record *record = new Record(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(record->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(record->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(record->img,al_map_rgb(160,180,250));
    V.push_back(record);
}
void Record::collide()
{
    if(syobon.x+syobon.boundx >= x+10 && syobon.x <= x+boundx && syobon.y <= y+30 && syobon.y+syobon.boundy >= y+8)  // While colliding
    {
        visible=false;
        collision=false;
        start_point=1;
    }
}
void Record::update()
{
    return;
}

// Trap
Trap::Trap(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Trap::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Trap *trap = new Trap(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(trap->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(trap->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(trap->img,al_map_rgb(160,180,250));
    al_convert_mask_to_alpha(trap->img,al_map_rgb(0,0,0));
    al_convert_mask_to_alpha(trap->img,al_map_rgb(1,1,1));
    al_convert_mask_to_alpha(trap->img,al_map_rgb(10,10,10));
    V.push_back(trap);
}
void Trap::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        visible=false;
        collision=false;
    }
}
void Trap::update()
{
    return;
}

// Pole
Pole::Pole(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Pole::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Pole *pole = new Pole(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(pole->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(pole->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(pole->img,al_map_rgb(160,180,250));
    V.push_back(pole);
}
void Pole::collide()
{
    if(syobon.x+syobon.boundx >= x+25 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+10)  //while colliding
    {
        syobon.goal = true;
    }
}
void Pole::update()
{
    return;
}

// Spring
Spring::Spring(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Spring::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Spring *spring = new Spring(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(spring->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(spring->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(spring->img,al_map_rgb(160,180,250));
    V.push_back(spring);
}
void Spring::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  //While colliding
    {
        if(syobon.y+syobon.boundy <= y+11 && syobon.vely >= 0) // ½ò¥¦
        {
            syobon.vely = -20;
        }
        else
        {
            if((syobon.x < x && syobon.velx > 0) || (syobon.x > x && syobon.velx < 0))
            {
                syobon.velx = 0;
                syobon.moving = false;
                syobon.curframe = 0;
            } // ¥ª¥k
        }
    }
}
void Spring::update()
{
    return;
}

// Mushroom
Mushroom::Mushroom(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    original_x = _x;
    original_y = _y;
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Mushroom::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Mushroom *mushroom = new Mushroom(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(mushroom->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(mushroom->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(mushroom->img,al_map_rgb(160,180,250));
    V.push_back(mushroom);
}
void Mushroom::collide()
{
    if((number == 500 || number == 501) && visible && original_y-y < 30) vel_y= -2;
    if(original_y-y >= 30)
    {
        vel_y=0;
        collision=true;
    }
    if(number == 502 && visible && x-original_x < 30) vel_x= 2;
    if(x-original_x >= 30)
    {
        vel_x=0;
        collision=true;
    }
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y && collision && !syobon.invincible)  //While colliding
    {
        if(syobon.state == 1)  // From fire state to normal state
        {
            al_set_sample_instance_gain(dokan_song_instance, 5);
            al_play_sample_instance(dokan_song_instance);
            al_rest(1.2);
            syobon.get_hit = 1;
            syobon.state = 0;
            return;
        }
        syobon.dead = true;
    }
}
void Mushroom::update()
{
    x += vel_x;
    y += vel_y;
}

// Flower
Flower::Flower(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    original_x = _x;
    original_y = _y;
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Flower::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Flower *flower = new Flower(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(flower->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(flower->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(flower->img,al_map_rgb(160,180,250));
    V.push_back(flower);
}
void Flower::collide()
{
    if(visible && original_y-y < 30) vel_y= -1;
    if(original_y-y >= 30)
    {
        vel_y=0;
        collision=true;
    }
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y && collision)  // While colliding
    {
        al_set_sample_instance_gain(powerup_song_instance, 7);
        al_play_sample_instance(powerup_song_instance);
        al_rest(1);
        syobon.state = 1;
        visible = 0;
        collision = 0;
    }
}
void Flower::update()
{
    x += vel_x;
    y += vel_y;
}

// Star
Star::Star(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    original_x = _x;
    original_y = _y;
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Star::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Star *star = new Star(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(star->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(star->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(star->img,al_map_rgb(160,180,250));
    V.push_back(star);
}
void Star::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y && collision && !syobon.invincible)  // While colliding
    {
        if(syobon.state == 1)  // From fire state to normal state
        {
            al_set_sample_instance_gain(dokan_song_instance, 5);
            al_play_sample_instance(dokan_song_instance);
            al_rest(1.2);
            syobon.get_hit = 1;
            syobon.state = 0;
            return;
        }
        syobon.dead=true;
    }
}
void Star::update()
{
    if(visible && ss)
    {
        vel_y= -3;
        ss = 0;
    }
    if(vel_y == -3 && original_y-y >= 100)
    {
        vel_y=3;
        collision=true;
        original_y = y;
    }
    if(vel_y==3 && y-original_y >= 100)
    {
        vel_y=-3;
        collision=true;
        original_y = y;
    }
    x += vel_x;
    y += vel_y;
}

// Ball
Ball::Ball(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Ball::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Ball *ball = new Ball(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(ball->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(ball->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(ball->img,al_map_rgb(160,180,250));
    V.push_back(ball);
}
void Ball::collide()
{
    if(visible && (x >= syobon.x+500 || x <= syobon.x-500))
    {
        visible=false;
    }
}
void Ball::update()
{
    x += vel_x;
    y += vel_y;
}

// Untouchable
Untouchable::Untouchable(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void Untouchable::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Untouchable *untouchable = new Untouchable(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(untouchable->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(untouchable->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(untouchable->img,al_map_rgb(160,180,250));
    V.push_back(untouchable);
}
void Untouchable::collide()
{
    return;
}
void Untouchable::update()
{
    return;
}

// B1_G1_S
B1_G1_S::B1_G1_S(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}
void B1_G1_S::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    B1_G1_S *bgs = new B1_G1_S(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    al_convert_mask_to_alpha(bgs->img,al_map_rgb(153,255,255));
    al_convert_mask_to_alpha(bgs->img,al_map_rgb(160,180,249));
    al_convert_mask_to_alpha(bgs->img,al_map_rgb(160,180,250));
    V.push_back(bgs);
}
void B1_G1_S::collide()
{
    if(syobon.x+17 >= x+1 && syobon.x+5 <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y) stand = 1;
    if(syobon.x+syobon.boundx >= x+1 && syobon.x <= x+boundx && syobon.y <= y+boundy && syobon.y+syobon.boundy >= y+2)
    {
        if((syobon.x < x+1 && syobon.velx > 0) || (syobon.x > x+1 && syobon.velx < 0))
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x+1 && syobon.x+5 < x+boundx)
        {
            syobon.y = y-35;
            syobon.vely=0.0;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
    }
}
void B1_G1_S::update()
{
    y += vel_y;
    vel_y += acc_y;
}

// Ton
Ton::Ton(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    al_convert_mask_to_alpha(img,al_map_rgb(10,10,10));
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = 0;
    vel_y = 0;
    acc_x = 0;
    acc_y = 0;
    in_air = 0;
}

void Ton::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag)
{
    Ton *ton=new Ton(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag);
    V.push_back(ton);
}

void Ton::update()
{
    if(y>750) return;
    y+=vel_y;
    vel_y+=acc_y;
    collide();
}

void Ton::collide()
{
    if(syobon.x+17 >= x && syobon.x+5 <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy+5 >= y && visible) stand = 1;
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)  // While colliding
    {
        if(((syobon.x < x && syobon.velx > 0) || (syobon.x > x && syobon.velx < 0)) && visible)
        {
            syobon.velx = 0;
            syobon.moving = false;
            syobon.curframe = 0;
        }// ¥ª¥k
        if(syobon.y < y && syobon.x+17 > x && syobon.x+5 < x+boundx && visible)
        {
            syobon.y = y-36;
            syobon.vely=0.0;
            syobon.accy=0.0;
            syobon.in_air=false;
            syobon.curframe = 0;
        }// ½ò¥¦
        if(syobon.y > y && syobon.x+17 > x && syobon.x+3 < x+boundx)
        {
            syobon.dead=true;
        }// ¼²¥¦
    }
    for(int i=1224; i<=1238; i++)
    {
        if(V[i]->x+V[i]->boundx>=x&&V[i]->x<=x+boundx&&V[i]->y<=y+boundy&&V[i]->y+V[i]->boundy>=y)
        {
            al_play_sample_instance(break_song_instance);
            V[i]->visible=false;
            V[i]->collision=false;
        }
    }
}

void ground_init_2()
{
    float x=0,y=0;
    for(int i=0; i<3; i++)
    {
        x=0;
        while(x<=6000)
        {
            if(x>200&&x<300)
            {
                x+=30;
                continue;
            }
            if(x>930&&x<1650)
            {
                x+=30;
                continue;
            }
            if(x>4560&&x<5330)
            {
                x+=30;
                continue;
            }
            if(x>=5880&&x<=6000)
            {
                x+=30;
                continue;
            }
            Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            x+=30;
        }
        y+=28;
    }

    //¤U­±

    x=0,y=600-6*28;

    for(int i=0; i<6; i++)
    {
        x=0;
        while(x<=6000)
        {
            if(x>=200&&x<480)
            {
                x+=30;
                continue;
            }
            if(x>600&&x<1650)
            {
                x+=30;
                continue;
            }
            if(x>2000&&x<2500)
            {
                x+=30;
                continue;
            }
            if(x>3000&&x<3300)
            {
                x+=30;
                continue;
            }
            if(x>3900&&x<4200)
            {
                x+=30;
                continue;
            }
            if(x>4560&&x<5330)
            {
                x+=30;
                continue;
            }
            Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            x+=30;
        }
        y+=28;
    }

    y=600-5*28;

    for(int i=0; i<5; i++)
    {
        x=210;
        for(int j=0; j<3; j++)
        {
            Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            x+=30;
        }
        y+=28;
    }


    //¶ñ¥R
    y=600-8*28;
    for(int i=0; i<2; i++)
    {
        x=480;
        for(int j=0; j<=i; j++)
        {
            Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            x+=30;
        }
        y+=28;
    }

    x=1050,y=600-10*28;
    for(int i=0; i<4; i++)
    {
        Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
        x+=30;
    }

    x=4005,y=600-2*28;

    Base::set_att(x,250,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+30,250,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+60,250,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+60,220,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+60,190,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+90,190,true,true,30,30,ground1,"./res/s3/ground.png",0);

    x=4140;
    for(int i=0; i<2; i++)
    {
        Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
        x+=30;
    }
    y=600-28*10;
    for(int i=0; i<4; i++)
    {
        Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
        y+=28;
    }

    x=4560,y=600-28*10;
    for(int i=0; i<4; i++)
    {
        Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
        y+=28;
    }

    //µe¾ô

    x=1980,y=600-7*28;
    Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+30,y-28,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+60,y-28*2,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x+90,y-28*3,true,true,30,30,ground1,"./res/s3/ground.png",0);

    for(int i=0; i<11; i++)
    {
        Base::set_att(x+30*4,y-28*3,true,true,30,30,ground1,"./res/s3/ground.png",0);
        x+=30;
    }

    x=1980+30*3,y=600-10*28;
    for(int i=0; i<2; i++)
    {
        y=600-(10-i)*28;
        for(int j=0; j<10; j++)
        {
            Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            y+=28;
        }
        x+=30;
    }


    x=1980+30*4,y=600-11*28;

    for(int i=0; i<11; i++)
    {
        Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
        x+=30;
    }

    x=2520,y=600-7*28;
    Base::set_att(x,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x-30,y-28,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x-60,y-28*2,true,true,30,30,ground1,"./res/s3/ground.png",0);
    Base::set_att(x-90,y-28*3,true,true,30,30,ground1,"./res/s3/ground.png",0);

    for(int i=0; i<2; i++)
    {
        y=600-(10-i)*28;
        for(int j=0; j<10; j++)
        {
            Base::set_att(x-90,y,true,true,30,30,ground1,"./res/s3/ground.png",0);
            y+=28;
        }
        x-=30;
    }

}
void brick_init_2()
{
    float x=3930,y=600-2*28;
    for(int i=0; i<3; i++)
    {
        Brick::set_att(x,y,true,true,29,30,brick,"./res/s3/brick.png",0);
        x+=29;
    }

    x=5390,y=85;
    for(int i=0; i<7; i++)
    {
        Brick::set_att(x,y,true,true,29,30,brick,"./res/s3/brick.png",0);
        y+=29;
    }

    x=5418,y-=29;
    for(int i=0; i<7; i++)
    {
        Brick::set_att(x,y,true,true,29,30,brick,"./res/s3/brick.png",0);
        x+=28;
    }

    x-=28,y=85;
    for(int i=0; i<7; i++)
    {
        Brick::set_att(x,y,true,true,29,30,brick,"./res/s3/brick.png",0);
        y+=29;
    }


}
void stair_init_2()
{
    Base::set_att(690,260,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(790,130,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(790,420,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(920,280,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(960,520,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1035,180,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1110,520,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1110,420,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1260,520,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1260,220,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1410,520,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(1410,220,true,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(4615,180,false,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(3045,300,false,true,29,30,stage,"./res/s3/stair.png",0);
    Base::set_att(3940,300,false,true,29,30,stage,"./res/s3/stair.png",0);

}
void others_init_2()
{
    render=false;
    Untouchable::set_att(20,600-6*28-121,true,false,155,121,none,"./res/s3/dest.png",0);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(160,180,250));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(140,157,218));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(120,135,187));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(110,123,171));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(90,101,140));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(80,90,125));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(150,168,234));
    Record::set_att(3510,175,true,true,57,80,record,"./res/s3/record.png",0);
    Torch::set_att(3500,250,true,true,29,30,none,"./res/s3/torch.png",0);
    Torch::set_att(4095,125,true,true,29,30,none,"./res/s3/torch.png",0);
    Quest::set_att(4170,600-7*28,true,true,33,30,question,"./res/s3/question.jpg",0);
    Switch::set_att(4380,240,true,true,33,30,none,"./res/s3/off.png",0);
    Platform::set_att(4820,300,false,false,115,22,none,"./res/s3/trap_platform.png",0);
    Tube::set_att(6000-90+9,600-6*28-128+20,true,true,86,160,tube,"./res/s3/stube.png",0);
    Tube::set_att(6000-78-110+11,600-6*28-78+12,true,true,100,65,tube,"./res/s3/tube3.png",0);
    Tube::set_att(5467,85,true,true,76,105,tube,"./res/s3/tube.png",2);
    V[V.size()-1]->sy-=20;

    float x=5040,y=-10;
    for(int i=0; i<4; i++)
    {
        Platform::set_att(x,y,false,false,115,22,none,"./res/s3/platform.png",0);
        y+=150;
    }
    Ton::set_att(228,-70,true,true,57,68,none,"./res/s3/ton.png",0);
    Fly::set_att(1305,300,true,true,78,104,monster,"./res/s3/fly.png",0,0,-3,0,9.8/45,true);
    Fly::set_att(1500,100,true,true,78,104,monster,"./res/s3/fly.png",0,0,3,0,9.8/45,true);
    Ally::set_att(1800,600-6*28-48,true,true,34,48,monster,"./res/s3/ally.png",1,3,0,0,0,0);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(0,0,0));
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(153,255,255));
    Fire::set_att(3108,610,false,false,36,42,none,"./res/s3/fire.png",2,0,-14,0,9.8/45,true);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(10,10,10));
    Fire::set_att(3144,610,false,false,36,42,none,"./res/s3/fire.png",2,0,-14,0,9.8/45,true);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(10,10,10));
    Fire::set_att(3180,610,false,false,36,42,none,"./res/s3/fire.png",2,0,-14,0,9.8/45,true);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(10,10,10));
    Monster::set_att(4020,250-27,true,true,30,27,monster,"./res/monster.png",0,-0.8,0,0,0,0);
    al_convert_mask_to_alpha(V[V.size()-1]->img,al_map_rgb(153,255,255));
    Flower::set_att(4174,600-7*28,false,false,23,27,flower,"./res/s3/flower.png",0);
    Ball::set_att(syobon.x+20, syobon.y+4, false, false, 29, 26, ball, "./res/s3/ball.png", 0);
    Cat::set_att(4260,600-6*28-35,true,true,23,33,monster,"./res/s3/mirror.png",0, -4, 0, 0, 9.8/40, 0);
    Boss::set_att(5907,600-6*28-158,false,false,78,158,monster,"./res/s3/gg.png",0,-5,-10,0,9.8/30,true);
    Base::set_att(4035,600-7*28-35,false,true,30,30,base,"./res/s3/stair.png",0);
    Base::set_att(5880,0,true,true,30,30,base,"./res/s3/ground.png",0);
    Base::set_att(5880,28,true,true,30,30,base,"./res/s3/ground.png",0);
    Base::set_att(5880,56,true,true,30,30,base,"./res/s3/ground.png",0);
}

void java_init_2()
{
    float x=0,y=600-29;
    while(x<=6000)
    {
        Untouchable::set_att(x,y,true,false,30,37,none,"./res/s3/java.png",0);
        x+=30;
    }
}

Fly::Fly(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
         float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}
void Fly::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    Fly *f = new Fly(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag, _vel_x, _vel_y, _acc_x, _acc_y, _in_air);
    V.push_back(f);
}
void Fly::collide()
{

    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)
    {
        if(syobon.control) syobon.dead=true;
    }
    if(V[1394]->x+V[1394]->boundx >= x && V[1394]->x <= x+boundx &&V[1394]->y <= y+boundy && V[1394]->y+V[1394]->boundy >= y && V[1394]->visible)  // Fire ball
    {
        V[1394]->visible = false;
    }
}
void Fly::update()
{
    if(y>250)
    {
        vel_y=-3;
        acc_y=-acc_y;
    }
    else if(y<50)
    {
        vel_y=3;
        acc_y=-acc_y;
    }
    y += vel_y;
    vel_y += acc_y;
}

Ally::Ally(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
           float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}
void Ally::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    Ally *ally = new Ally(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag, _vel_x, _vel_y, _acc_x, _acc_y, _in_air);
    Catch=false;
    V.push_back(ally);
}
void Ally::collide()
{
    if(!Catch&&syobon.control&&syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)
    {
        Catch=true;
        syobon.control=false;
        syobon.in_air=false;
        img=al_load_bitmap("./res/s3/ally2.png");
        al_convert_mask_to_alpha(img,al_map_rgb(0,0,0));
        al_convert_mask_to_alpha(img,al_map_rgb(153,255,255));
        vel_x=0;
        syobon.x=x+5;
        syobon.y=y-33;
        syobon.velx=0;
        syobon.vely=0;
        syobon.accx=0;
        syobon.accy=0;
    }
    if(V[1394]->x+V[1394]->boundx >= x && V[1394]->x <= x+boundx &&V[1394]->y <= y+boundy && V[1394]->y+V[1394]->boundy >= y && V[1394]->visible)  // Fire ball
    {
        V[1394]->visible = false;
        visible=false;
        collision=false;
    }
}
void Ally::update()
{
    if(trap_arr[1]&&x+boundx >= V[1262]->x && x <= V[1262]->x+V[1262]->boundx &&y <= V[1262]->y+V[1262]->boundy && y+boundy >= V[1262]->y)  // While colliding
    {
        if(((x < V[1262]->x && vel_x > 0) || (x > V[1262]->x && vel_x < 0)))
        {
            flag=flag==1?0:1;
            vel_x=-vel_x;
        }// ¥ª¥k
    }
    else if(x<1645||x>1980)
    {
        flag=flag==1?0:1;
        vel_x=-vel_x;
    }
    x += vel_x;
}

void Fire::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)
    {
        syobon.dead=true;
    }
}
void Fire::update()
{
    if(!trap_arr[2])
    {
        visible=true;
        collision=true;
    }
    else return;
    if(y>610)
    {
        y=610;
        flag=2;
        vel_y=-14;
    }
    if(vel_y>0)
    {
        flag=0;
    }
    y+=vel_y;
    vel_y+=acc_y;
}
void Fire::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    Fire *f=new Fire(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag, _vel_x, _vel_y, _acc_x, _acc_y, _in_air);
    V.push_back(f);
}
Fire::Fire(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}

Cat::Cat(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,
         float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}
void Cat::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    Cat *cat = new Cat(_x, _y, _visible, _collision, _boundx, _boundy, _type, path, _flag, _vel_x, _vel_y, _acc_x, _acc_y, _in_air);
    V.push_back(cat);
}
void Cat::collide()
{
    if(visible)
    {
        if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y && !syobon.invincible)  // While colliding
        {
            if(syobon.state == 1)  // From fire state to normal state
            {
                al_set_sample_instance_gain(dokan_song_instance, 5);
                al_play_sample_instance(dokan_song_instance);
                al_rest(1.2);
                syobon.get_hit = 1;
                syobon.state = 0;
                return;
            }

            else
            {
                syobon.dead=true;
            }
        }
        if(V[1394]->x+V[1394]->boundx >= x && V[1394]->x <= x+boundx &&
                V[1394]->y <= y+boundy && V[1394]->y+V[1394]->boundy >= y && V[1394]->visible)  // Fire ball
        {
            V[1394]->visible = false;
            img = al_load_bitmap("./res/s3/mirror2.png");
            sx=al_get_bitmap_width(img);
            sy=al_get_bitmap_height(img);
            al_convert_mask_to_alpha(img,al_map_rgb(153,255,255));
        }
    }
}
void Cat::update()
{
    int cat_stand = 0;
    if(y+boundy > 436) y = 395;
    for(auto &i : VB)
    {
        if(x+17 >= i->x && x+5 <= i->x+i->boundx && y <= i->y+i->boundy && y+boundy+5 >= i->y)
        {
            cat_stand = 1;
        }
        if(x+boundx >= i->x && x <= i->x+i->boundx && y <= i->y+i->boundy && y+boundy >= i->y)  // While colliding
        {
            if(((x < i->x && vel_x > 0) || (x > i->x && vel_x < 0)) && y> i->y-5)
            {
                if(vel_x > 0) x = i->x-boundx;
                else x = i->x + i->boundx;
                flag = (flag+1)%2;
                vel_x *= -1;
            }// ¥ª¥k
            if(y < i->y && x+10 > i->x && x+10 < i->x+i->boundx && y+boundy < i->y+10)
            {
                y = i->y-37;
                vel_y=0;
                acc_y=0.0;
                in_air=false;
            }// ½ò¥¦
        }
    }
    if(!cat_stand) acc_y = 9.8/38;
    if(cat_stand && adir[up] && syobon.x > 4226 && syobon.x < 4538) vel_y = -6;
    x += vel_x;
    y += vel_y;
    vel_x += acc_x;
    vel_y += acc_y;
}

Boss::Boss(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    x = _x;
    y = _y;
    visible = _visible;
    collision = _collision;
    boundx = _boundx;
    boundy = _boundy;
    type = _type;
    img = al_load_bitmap(path);
    sx = al_get_bitmap_width(img);
    sy = al_get_bitmap_height(img);
    flag = _flag;
    number = V.size();
    vel_x = _vel_x;
    vel_y = _vel_y;
    acc_x = _acc_x;
    acc_y = _acc_y;
    in_air = _in_air;
}

void Boss::collide()
{
    if(syobon.x+syobon.boundx >= x && syobon.x <= x+boundx &&syobon.y <= y+boundy && syobon.y+syobon.boundy >= y)
    {
        syobon.dead=true;
    }
    for(auto &i:VB2)
    {
        if(i->x+i->boundx>=x&&i->x<=x+boundx&&i->y<=y+boundy&&i->y+i->boundy>=y)
        {
            al_play_sample_instance(break_song_instance);
            i->visible=false;
            i->collision=false;
        }
    }
    if(V[1394]->x+V[1394]->boundx >= x && V[1394]->x <= x+boundx &&V[1394]->y <= y+boundy && V[1394]->y+V[1394]->boundy >= y && V[1394]->visible)  // Fire ball
    {
        V[1394]->visible = false;
    }
}

void Boss::update()
{
    if(y>750||trap_arr[4]) return;
    if(!trap_arr[4])
    {
        visible=true;
        collision=true;
    }
    x+=vel_x;
    y+=vel_y;
    vel_x+=acc_x;
    vel_y+=acc_y;
    collide();
}

void Boss::set_att(float _x, float _y, bool _visible, bool _collision, int _boundx, int _boundy, int _type, char* path, int _flag, float _vel_x, float _vel_y,float _acc_x, float _acc_y, bool _in_air)
{
    Boss *boss=new Boss(_x,_y,_visible,_collision,_boundx,_boundy,_type,path,_flag,_vel_x,_vel_y,_acc_x,_acc_y,_in_air);
    V.push_back(boss);
}

void VB_init2()
{
    for(int i=1254; i<=1261; i++) VB.push_back((Base*)V[i]);
    for(int i=699; i<=709; i++) VB.push_back((Base*)V[i]);
    for(int i=711; i<=733; i++) VB2.push_back((Base*)V[i]);
    for(int i=809; i<=831; i++) VB2.push_back((Base*)V[i]);
    for(int i=907; i<=929; i++) VB2.push_back((Base*)V[i]);
    for(int i=1005; i<=1027; i++) VB2.push_back((Base*)V[i]);
    for(int i=1103; i<=1125; i++) VB2.push_back((Base*)V[i]);
    for(int i=1201; i<=1223; i++) VB2.push_back((Base*)V[i]);
}

void final_init()
{
    render=false;
    float x=0,y=600-59;
    //¦aªO
    for(int i=0; i<2; i++)
    {
        x=0;
        while(x<=1400)
        {
            if(i==0)
            {
                B1_G1_S::set_att(x,y,true,true,30,30,ground1,"./res/ground1.jpg",0);
            }
            else
            {
                B1_G1_S::set_att(x,y,true,true,30,30,ground1,"./res/base1.jpg",0);
            }
            x+=29;
        }
        y+=30;
    }

    //¤ôºÞ

    Tube::set_att(45,600-59-123,true,true,95,123,tube,"./res/stube.png",0);
    //¶¥±è

    y=600-59-38;

    for(int i=0; i<8; i++)
    {
        x=250+37*i;
        for(int j=0; j<9-i; j++)
        {
            B1_G1_S::set_att(x,y,true,true,38,38,stage,"./res/stage.jpg",0);
            x+=37;
        }
        y-=37;
    }


    //ºX¤l+ºX®y
    B1_G1_S::set_att(800,600-59-38,true,true,38,38,stage,"./res/stage.jpg",0);
    Pole::set_att(791,600-59-382-38,true,true,52,382,pole,"./res/pole.png",0);

    //²×ÂI
    Untouchable::set_att(1100,600-59-121,true,false,155,121,none,"./res/dest.png",0);
    Ball::set_att(syobon.x+20, syobon.y+4, false, false, 29, 26, ball, "./res/s3/ball.png", 0);
}
