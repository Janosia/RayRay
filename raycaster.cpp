#include <iostream>
#include "quickcg.h"
// using namespace QuickCG;
using namespace std;
using QuickCG::screen;
using std::cout;
using std::endl;
#define map_width 24
#define map_ht 24
#define screen_width 640
#define screen_ht 480

int worldMap[map_width][map_ht]={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

strawberry = rgb(247, 44, 91), unripe_strawberry =rgb(255, 116, 139), leaf = rgb(167, 212, 119), pale_leaf = rgb(228, 241, 172);

int main(int /*argc*/, char */*argv*/ []){
    double posX =22, posY =12;

    double dirX =-1, dirY =0;

    double planeX =0, planeY =0.66;

    double time =0, old_time 0;

    screen(screen_width, screen_ht, 0, "Raycaster");
    bool done = false;
    while(!done){
        for(int x =0; x<w; x++){
            double cameraX =2*x / double(w) -1;
            double rayDirX = dirX+planeX*cameraX, rayDirY = dirY+palneY*cameraX;
        }
        int mapX = int(posX), mapY = int(posY);
        double sideDistX, sideDistY;
        double deltaDistX = rayDirX == 0 ? 1e30 : abs(1 / rayDirX);
        double deltaDistY = rayDirY == 0 ? 1e30 : abs(1 / rayDirY);

        double perpWallDist;

        int stepX, stepY, side, hit =0;

        if(rayDirX < 0){
            stepX =-1;
            sideDistX = (posX-mapX) * deltaDistX;
        }else{
            stepX=1;
            sideDistX = (mapX +1.0 -posX)* deltaDistX;
        }
        if(rayDirY <0){
            stepY=-1;
            sideDistY = (posY-mapY) *deltaDistY;
        }else{
            stepY=1;
            sideDistY = (mapY +1.0 -posY)*deltaDistY;
        }

        while(hit == 0){
            if(sideDistX < sideDistY){
                sideDistX +=deltaDistY;
                mapX+=stepX;
                side =0;
            }
            else{
                sideDistY+=deltaDistY;
                mapY+=stepY;
                side =1;
            }
            if(worldMap[mapX][mapY] == 1) hit =1;
        }
        
        if(side == 0) perpWallDist = (sideDistX -deltaDistX);
        else perpWallDist = (sideDistY -deltaDistY);

        int lineHeight = (int) (h/perpWallDist), drawStart = -lineHieght/2 +h/2, drawEnd = lineHeight/2 +h/2;;

        if(drawStart<0) =-lineHeight/2+h/2;
        if(drawEnd >=h) drawEnd = h-1;
        
        switch(worldMap[mapX][mapY])
        {
            case 1:  color = strawberry;  break; 
            case 2:  color = unripe_strawberry;  break; 
            case 3:  color = pale_leaf;   break; 
            case 4:  color = leaf;  break; 
            default: color = RGB_Yellow; break; 
        }

        if (side == 1) {color = color / 2;}

        verLine(x, drawStart, drawEnd, color);
    }
    old_time =time;
    time = getTicks();
    
    double frame_time =(time -old_time)/1000.0
    
    cout << 1.0/frameTime << endl;
    redraw();
    cls();

    double move_speed = frame_time * 5.0, rot_Speed = frame_time * 3.0;

    if(key_down(SDLK_UP)){
        if(worldMap[(int) posX +dirX *move_speed][(int) posY] == false){
            posX +=dirX *move_speed;
        }
        if(worldMap[(int)posX][(int) posY+dirY *move_speed] == false){
            posY+=dirY*move_speed;
        }
    }
    else if (key_down(SDLK_DOWN)){
        if(worldMap[(int)posX-dirX *move_speed][(int)posY]  == false){
            posX -=dirX*move_speed;
        }
        if(worldMap[(int)posX][(int) posY-dirY*move_speed] ==  false){
            posY -=dirY*move_speed;
        }
    }
    else if (key_down(SDLK_RIGHT)){
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    else if (key_down(SDLK_LEFT)){
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
    return 0;
}