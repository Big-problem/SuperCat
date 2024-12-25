#include"main.h"
#include"object.h"
#include"game.h"
#include"display.h"
#include"pp.h"

int invincible_time=0;

void player_init(int stage_played)
{
    if(stage_played==1)
    {
        syobon.x=100.0;
        syobon.y=600.0-93;
    }
    else if(stage_played==2)
    {
        syobon.x=88;
        syobon.y=600-6*28-35;
    }
    else
    {
        syobon.x=58;
        syobon.y=600-59-123-30;
    }
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
    syobon.control=true;
    syobon.goal=false;
    syobon.air_jump=true;
    syobon.visible=true;
    syobon.velx=0.0;
    syobon.vely=0.0;
    syobon.img[0][0]=al_load_bitmap("./res/frame1.png");
    syobon.img[0][1]=al_load_bitmap("./res/frame2.png");
    syobon.img[0][2]=al_load_bitmap("./res/frame3.png");
    syobon.img[0][3]=al_load_bitmap("./res/frame4.png");
    syobon.img[1][0]=al_load_bitmap("./res/s3/fire_cat1.png");
    syobon.img[1][1]=al_load_bitmap("./res/s3/fire_cat2.png");
    syobon.img[1][2]=al_load_bitmap("./res/s3/fire_cat3.png");
    syobon.img[1][3]=al_load_bitmap("./res/s3/fire_cat4.png");
    syobon.sx=al_get_bitmap_width(syobon.img[0][2]);
    syobon.sy=al_get_bitmap_height(syobon.img[0][2]);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            al_convert_mask_to_alpha(syobon.img[i][j],al_map_rgb(153,255,255));
        }
    }
    syobon.live=3;
    syobon.deadtime=0;
    syobon.boundx=25;
    syobon.boundy=35;
    syobon.passtime=0;
}

void draw_player()
{
    if(!syobon.dead) syobon.x+=syobon.velx;
    if(!Catch) syobon.y+=syobon.vely;
    if(syobon.control || tube_fly2 == 1) syobon.velx+=syobon.accx;
    syobon.vely+=syobon.accy;
}

void player_update()
{
    if(!syobon.visible) return;
    al_draw_bitmap_region(syobon.img[syobon.state][syobon.curframe],0,0,syobon.sx,syobon.sy,syobon.x,syobon.y,syobon.flag);
}
