#include"main.h"
#include"object.h"
#include"game.h"
#include"display.h"
#include"pp.h"

#include<bits/stdc++.h>
#include<string>
#include<vector>

player syobon;

int main()
{
    syobon.gold = 110;
    stage_played = 1;
    int game_return;
    while(stage_played)
    {
        menu_init();
        stage_played = menu_start();
        syobon.state=0;
        if(stage_played)
        {
            game_init();
            game_return=game_start();
        }
        if(game_return==1)
        {
            stage_played=2;
            game_init();
            game_return=game_start();
        }
        if(game_return==2)
        {
            stage_played=3;
            game_init();
            game_return=game_start();
        }
    }
    return 0;
}
