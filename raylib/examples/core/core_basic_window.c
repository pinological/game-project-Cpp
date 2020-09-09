
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct collison
//{
//    int topco;
//    int downco;
//    int frontco;
//    int backco;
//};

void record(int score){
    char value[10];
    snprintf(value, sizeof(value), "%d\n", score);
    FILE *fptr;
    fptr = fopen("score.txt", "a+");
    fprintf(fptr,value);
    fclose(fptr);
    
}


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "The word");
    
    
    Texture2D bus = LoadTexture("resources/bus.png");
    Texture2D story1 = LoadTexture("resources/main.png");
    Texture2D story2 = LoadTexture("resources/after.png");
    Texture2D story3 = LoadTexture("resources/after2.png");
    Texture2D story4 = LoadTexture("resources/after3.png");
    Texture2D story5 = LoadTexture("resources/after4.png");
    Texture2D enemy = LoadTexture("resources/ene.png");
    Texture2D fuel = LoadTexture("resources/fule.png");
    Texture2D background = LoadTexture("resources/back.png");
    //for music 
      InitAudioDevice();    
      Music music = LoadMusicStream("resources/main.mp3");
      PlayMusicStream(music);
      
    
    
    int posy = screenHeight/2,posx = screenWidth/2;
    int storyline = 0;
    int storytext = 0;
    int score = 0;
    int level1 = 2,level2=4;
     bool pause = false;
    int randomx = 592,randomy;
    int counter = 0;  
     int mover = 0;   
     
     //health
     int health = 1;
     int trigger = 1;
    //colider
    //struct collison busPlayer;
    //struct collison astroEne;
    
    char name[10];
    Rectangle textbox = {200,(screenHeight/2)+40,60,20};
    bool co = false;
    
    SetTargetFPS(60);           
       while (!WindowShouldClose())   
    {

        counter +=1;
        //spwaner
        
        if(IsKeyPressed(KEY_M)){
            health = 1;
            trigger = 1;
            
            score = 0;
             randomx = screenWidth;
        }
        if(IsKeyPressed(KEY_H)){
            record(score);
        }
        
        UpdateMusicStream(music);
        //spwaner 
        
        if(trigger == 1){
        if(counter >= 160){
        
        randomy = rand()%363;
        counter = 0;
        randomx = screenWidth;
        score += 1;
        
        }
        }
        
         randomx -= 5;
        
        //music 
         if (IsKeyPressed(KEY_P))
        {
            pause = !pause;

            if (pause) PauseMusicStream(music);
            else ResumeMusicStream(music);
        }
       //border define            
       
        if(posx <= 0){
            posx = 5;
        }
        if(posx >= 592){
            posx = 587;
        }
        if(posy <= 0){
            posy = 3;
        }
        if(posy >= 363){
            posy = 360;
        }
        //here end border
        
        
       
       //levelup
       
       
       
        
        if(IsKeyDown(KEY_R)){
            storyline =1;
            printf("R is done");
        }
        if(IsKeyPressed(KEY_SPACE)){
          
            storytext += 1;
        }
        if(IsKeyPressed(KEY_S)){
            storytext = 60;
           
            
        }
        //controler
        if(IsKeyDown(KEY_UP)){
            posy -= level1;
        }
        if(IsKeyDown(KEY_DOWN)){
            posy += level1;
        }
        if(IsKeyDown(KEY_RIGHT)){
            posx += level1;
        }
        if(IsKeyDown(KEY_LEFT)){
            posx -= level1;
        }
        
        //collison
      // busPlayer.frontco = (posx + 207);
      // busPlayer.topco = (posy + 87);
      // busPlayer.backco = posx;
      // busPlayer.downco = posy;
        
      // astroEne.frontco = (randomx + 83);
      // astroEne.topco = (randomy + 83);
      // astroEne.backco = randomx;
      // astroEne.downco = randomy;
       
     Rectangle collp = {posx,posy,bus.width,bus.height};
     Rectangle colle = {randomx,randomy,enemy.width,enemy.height};
    
       
        //death 
       
       co = CheckCollisionRecs(collp,colle);
       
       if(co){
           health = 2;
       }
       
        //if(busPlayer.backco)
        
        
       
        
        
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
                if(storytext >= 60){
                    
                    // main game here 
                    if(health == 1){
                    DrawTexture(background,0,0,RAYWHITE);
                    DrawTexture(bus,posx,posy,RAYWHITE);
                    DrawText(TextFormat("X pos :%d",posx),0,0,20,RED);
                    DrawText(TextFormat("Y pos :%d",posy),0,20,20,RED);
                    DrawText(TextFormat("Score :%d",score),650,0,30,GREEN);
                    DrawText(TextFormat("X astro :%d",randomx),0,410,20,RED);
                    DrawText(TextFormat("Y astor :%d",randomy),0,430,20,RED);
                    //debug 
                    
                    //DrawText(TextFormat("Bus Width :%d",bus.width),100,100,20,BLUE);
                    //DrawText(TextFormat("Bus height :%d",bus.height),100,120,20,BLUE);
                    //DrawText(TextFormat("Astro Width :%d",enemy.width),100,140,20,BLUE);
                    DrawText(TextFormat("collison :%s",co?"true":"false"),650,430,20,PINK);
                    
                    //end here
                    DrawTexture(bus,posx,posy,RAYWHITE);
                    DrawTexture(enemy,randomx,randomy,RAYWHITE);
                    }
                    else{
                        trigger = 0; //Stop astro generator
                         DrawTexture(background,0,0,RAYWHITE);
                         DrawText(TextFormat("You Die your Score :%d",score),200,(screenHeight/2)+20,30,RED);
                         // DrawRectangleRec(textbox, LIGHTGRAY);
                         
                         DrawText("Press M to restart and H to save Record",200,(screenHeight/2)+70,20,GREEN);
                    }
                    
                    
                    // main game end here
                }
              
             // DrawTexture(story1,0,0,RAYWHITE);
              if(storyline == 0){
              DrawTexture(story1,0,0,RAYWHITE);
              DrawText("Press R to start",280,400,30,RAYWHITE);
              }
              if(storyline == 1){
                  
                  if(storytext == 0){
                      DrawTexture(story2,0,0,RAYWHITE);
                      DrawText("Hello Welcome to the world where you are \n a highschool student",200,350,20,RAYWHITE);
                     DrawText("Press Space",250,410,30,RED);

                  }
                  if(storytext == 1){
                      DrawTexture(story3,0,0,RAYWHITE);
                      DrawText("You are in a school bus trip\n and suddenly, the bus stop",200,350,20,RAYWHITE);
                     DrawText("Press Space",250,410,30,RED);

                  }
                  if(storytext == 2){
                      DrawTexture(story4,0,0,RAYWHITE);
                      DrawText("suddenly a portal open before the bus \n and bus travel to the another dimension",200,350,20,RAYWHITE);
                     DrawText("Press Space",250,410,30,RED);

                  }
                   if(storytext == 3){
                      DrawTexture(story5,0,0,RAYWHITE);
                      DrawText("the bus is travelling in a space now and everyone \n is unconscious so you have to control the bus now  ",200,350,20,RAYWHITE);
                     DrawText("Press S to start",250,410,30,GREEN);
                     

                  }
                  if(storytext >= 4 &&storytext <=59){
                       DrawTexture(background,0,0,RAYWHITE);
                      DrawText("Press S to play game",200,350,20,RAYWHITE);
                  }
                  
                 
                  
              }
             
              
              
              
              
             
        EndDrawing();
        
    }
    
    UnloadMusicStream(music);   // Unload music stream buffers from RAM

    CloseAudioDevice(); 

   
    CloseWindow();      
   
    return 0;
}