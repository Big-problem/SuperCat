#include"main.h"
#include"object.h"
#include"game.h"
#include"display.h"
#include"pp.h"

#include<vector>

int display_width,display_height;
bool trap_arr[20];
ALLEGRO_DISPLAY *display;
maps Map;



void display_update()
{
    int stay_time=0;
    while(syobon.x>=Map.pos_x+400.0)
    {
        if(syobon.x+400>6000.0)
        {
            Map.pos_x=5200.0;
            break;
        }
        else
        {
            if(Map.pos_x+syobon.velx>Map.pos_x) Map.pos_x+=syobon.velx;
            if(syobon.velx==0) break;
            if(stay_time>1) break;
        }
        stay_time++;
    }
    if(!syobon.control&&!syobon.dead) Map.pos_x+=syobon.velx;
    draw_map(stage_played);
}

void obj_update(int stage_played)
{
    if(stage_played==1)
    {
        for(int i = 500; i < V.size(); ++i)
        {
            V[i]->update();
            if(V[i]->visible) al_draw_bitmap_region(V[i]->img, 0, 0, V[i]->sx, V[i]->sy, V[i]->x, V[i]->y, V[i]->flag);
        }
        for(int i = 0; i < 500; ++i)
        {
            V[i]->update();
            if(V[i]->visible) al_draw_bitmap_region(V[i]->img, 0, 0, V[i]->sx, V[i]->sy, V[i]->x, V[i]->y, V[i]->flag);
        }
    }
    else if(stage_played==2)
    {
        V[1393]->update();
        if(V[1393]->visible) al_draw_bitmap_region(V[1393]->img,0,0,V[1393]->sx,V[1393]->sy,V[1393]->x,V[1393]->y,V[1393]->flag);
        for(int i=0;i<V.size();i++)
        {
            if(i==1393||(i>=1378&&i<=1380)) continue;
            V[i]->update();
            if(V[i]->visible) al_draw_bitmap_region(V[i]->img,0,0,V[i]->sx,V[i]->sy,V[i]->x,V[i]->y,V[i]->flag);
        }
    }
    else
    {
        for(auto &i:V)
        {
            i->update();
            if(i->visible) al_draw_bitmap_region(i->img,0,0,i->sx,i->sy,i->x,i->y,i->flag);
        }
    }

}

void draw_map(int stage_played)
{
    if(stage_played==1||stage_played==3)
    {
        al_clear_to_color(al_map_rgb(160,180,249));
    }
    else
    {
        al_clear_to_color(al_map_rgb(0,0,0));
    }
    al_destroy_bitmap(Map.img);
    Map.img=al_create_bitmap(6000,600);
    al_set_target_bitmap(Map.img);
    obj_update(stage_played);
    player_update();
    if(stage_played==2)
    {
        for(int i=1378;i<=1380;i++)
        {
            V[i]->update();
            if(V[i]->visible) al_draw_bitmap_region(V[i]->img,0,0,V[i]->sx,V[i]->sy,V[i]->x,V[i]->y,V[i]->flag);
        }
    }
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap_region(Map.img,Map.pos_x,Map.pos_y,800,600,0,0,0);
    al_flip_display();
}

void map_init(int stage_played)
{
    al_set_new_display_option(ALLEGRO_VSYNC,true,ALLEGRO_REQUIRE);
    player_init(stage_played);
    object_init();
    display_width=800,display_height=600;
    display=al_create_display(display_width,display_height);
    Map.pos_x=0,Map.pos_y=0;
    Map.img=al_create_bitmap(6000,600);
    al_set_target_bitmap(Map.img);
    if(stage_played==1)
    {
        for(int i=0; i<20; i++) trap_arr[i]=true;
        al_clear_to_color(al_map_rgb(160,180,249));
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
        al_clear_to_color(al_map_rgb(0,0,0));
        java_init_2();
        ground_init_2();
        brick_init_2();
        stair_init_2();
        others_init_2();
        VB_init2();
    }
    else
    {
        al_clear_to_color(al_map_rgb(160,180,249));
        final_init();
    }
    obj_update(stage_played);
    player_update();
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap_region(Map.img,0,0,800,600,0,0,0);
    al_flip_display();
}

void menuu_init()
{
    display_width=800,display_height=600;
    menu_display=al_create_display(display_width,display_height);
    menuu = al_load_bitmap("./res/menu.png");
    setting = al_load_bitmap("./res/setting.png");
    level = al_load_bitmap("./res/s3/level.png");
    al_draw_bitmap(menuu, 0, 0, 0);
    al_flip_display();
}

void trap_detect(int stage_played)
{
    if(stage_played==1)
    {
        if(trap_arr[0]&&syobon.x>=1934)   //天花板掉下來
        {
            trap_arr[0]=false;
            for(int j=381; j<393; j++)
            {
                V[j]->vel_y = 8.0;
                V[j]->acc_y = 9.8/60;
            }
        }
        else if(trap_arr[1]&&syobon.x>=415&&syobon.x<=425+6*28&&!syobon.in_air)  //一開始地板掉下去
        {
            trap_arr[1]=false;
            for(int i=14; i<20; i++)
            {
                V[i]->vel_y = 0.5;
                V[i]->acc_y = 9.8/60;
            }
            for(int i=191; i<197; i++)
            {
                V[i]->vel_y = 0.5;
                V[i]->acc_y = 9.8/60;
            }
        }
        else if(trap_arr[2]&&!syobon.in_air&&syobon.x>=3548&&syobon.x<=3614)  //Record地板掉下來
        {
            for(int i=100; i<103; i++)
            {
                V[i]->vel_y = 2.5;
                V[i]->acc_y = 9.8/60;
            }
            for(int i=277; i<280; i++)
            {
                V[i]->vel_y = 2.5;
                V[i]->acc_y = 9.8/60;
            }
        }
        else if(trap_arr[3]&&syobon.x>=4700+4*38.0)
        {
            trap_arr[3]=false;
            Monster::set_att(4700+4*38.0, -20.0, true, true, 30, 25, monster, "./res/monster.png", 0, 0, 5, 0, 9.8/60, true);

            Monster::set_att(4700+5*38.0, -40.0, true, true, 30, 25, monster, "./res/monster.png", 0, 0, 5, 0, 9.8/60, true);


            Monster::set_att(4700+6*38.0, -60.0, true, true, 30, 25, monster, "./res/monster.png", 0, 0, 5, 0, 9.8/60, true);

            Monster::set_att(4700+7*38.0, -80.0, true, true, 30, 25, monster, "./res/monster.png", 0, 0, 5, 0, 9.8/60, true);
            al_play_sample_instance(god_song_instance);
            god_start=1;
        }
        else if(trap_arr[4]&&syobon.x>=775.0)
        {
            trap_arr[4]=false;
            Monster::set_att(790.0, 430.0, true, true, 29, 42, monster, "./res/sea.png", 0, 0, -7, 0, 0, true);
        }
        else if(trap_arr[5]&&syobon.x>=2440.0)
        {
            trap_arr[5]=false;
            Monster::set_att(2476.0, 400.5, true, true, 31, 52, monster, "./res/big_boss.png", 0, -5, -16, 0, 9.8/30, true);
        }
        else if(trap_arr[6]&&syobon.x>=1015+29*32)  //地板掉下來
        {
            trap_arr[6]=false;
            for(int i=54; i<67; i++)
            {
                V[i]->vel_y = 0.5;
                V[i]->acc_y = 9.8/60;
            }
            for(int i=231; i<244; i++)
            {
                V[i]->vel_y = 0.5;
                V[i]->acc_y = 9.8/60;
            }
        }
        else if(trap_arr[7] && !V[495]->visible)
        {
            trap_arr[7]=false;
            Monster::set_att(4161+43, 361.5, true, true, 32, 33, monster, "./res/ouch.png", 0, 8, -8, 0, 9.8/45, true);
            Monster::set_att(4161+43+60, 600-58.5-38, true, true, 30, 38, monster, "./res/turtle.png", 1, 5, 0, 0, 0, true);
            Monster::set_att(4161+43+60+500, -30, true, true, 30, 38, monster, "./res/turtle.png", 0, -8, 6, 0, 9.8/45, true);
        }
    }
    else if(stage_played==2)
    {
        if(trap_arr[0]&&syobon.x>200&&start_point!=1)
        {
            trap_arr[0]=false;
            V[1385]->vel_y=18;
        }
        else if(trap_arr[1]&&syobon.x>2040&&start_point!=1)
        {
            trap_arr[1]=false;
            for(int i=242;i<=258;i++)
            {
                V[i]->vel_y=1;
                V[i]->acc_y=9.8/55;
            }
            for(int i=387;i<=403;i++)
            {
                V[i]->vel_y=1;
                V[i]->acc_y=9.8/55;
            }
            for(int i=532;i<=548;i++)
            {
                V[i]->vel_y=1;
                V[i]->acc_y=9.8/55;
            }
        }
        else if(trap_arr[2]&&syobon.x>3015)
        {
            trap_arr[2]=false;
        }
        else if(trap_arr[3]&&syobon.x>3650)
        {
            trap_arr[3]=false;
        }
        else if(trap_arr[4]&&syobon.x>5575)
        {
            trap_arr[4]=false;
        }
        else if(trap_arr[5]&&syobon.x>1090&&syobon.y>275&&syobon.y<600-10*28&&syobon.x<1130)
        {
            trap_arr[5]=false;
            for(int i=1242;i<=1243;i++) V[i]->x-=20;
            for(int i=1244;i<=1245;i++) V[i]->x+=20;
        }
        else if(trap_arr[6]&&syobon.x>2550)
        {
            trap_arr[6]=false;
            for(int i=0;i<6;i++)
            {
                for(int j=660+i*98;j<=663+i*98;j++)
                {
                    V[j]->vel_y=0.2;
                    V[j]->acc_y=9.8/70;
                }
            }
        }
        else if(trap_arr[7]&&syobon.x>2690)
        {
            trap_arr[7]=false;
            for(int i=0;i<6;i++)
            {
                for(int j=664+i*98;j<=666+i*98;j++)
                {
                    V[j]->vel_y=0.2;
                    V[j]->acc_y=9.8/70;
                }
            }
        }
        else if(trap_arr[8]&&syobon.x>2780)
        {
            trap_arr[8]=false;
            for(int i=0;i<6;i++)
            {
                for(int j=667+i*98;j<=670+i*98;j++)
                {
                    V[j]->vel_y=0.2;
                    V[j]->acc_y=9.8/70;
                }
            }
        }
        else if(trap_arr[9]&&syobon.x>2870)
        {
            trap_arr[9]=false;
            for(int i=0;i<6;i++)
            {
                for(int j=671+i*98;j<=673+i*98;j++)
                {
                    V[j]->vel_y=0.2;
                    V[j]->acc_y=9.8/70;
                }
            }
        }
        else if(trap_arr[10]&&syobon.x>2955)
        {
            trap_arr[10]=false;
            for(int i=0;i<6;i++)
            {
                for(int j=674+i*98;j<=675+i*98;j++)
                {
                    V[j]->vel_y=0.2;
                    V[j]->acc_y=9.8/70;
                }
            }
        }
    }
}
