
#ifndef __creatures_H__
#define __creatures_H__

#include "ship.h"
#include "main.h"

#define CREATURE_X_POS SCREEN_WIDTH*4/8
#define CREATURE_Y_POS SCREEN_HEIGHT*50/100

#define CREATURE_Y_ROW_BEGIN SCREEN_HEIGHT*1/2
#define CREATURE_X_ROW_BEGIN SCREEN_WIDTH*1/6
#define CREATURE_X_DIST_APART 60

#define CREATURE_MIN_DIST_WALL SCREEN_WIDTH - CREATURE_WIDTH/2

#define NUMB_OF_CREATURES 8
#define NUMB_IN_ROW 8
#define NUMB_OF_COLUMNS 8
#define CREATURE_SPEED 1

#define CREATURE_BULLET_SPEED 5
#define CREAT_BULLET_THICKNESS 3

typedef enum creatureIDS_t{
    CreatureONE,
    CreatureTWO,
    CreatureTHREE,
    CreatureFOUR,
    CreatureFIVE,
    CreatureSIX,
    CreatureSEVEN,
    CreatureEIGHT,
    CreatureNINE,
    CreatureTEN,
    CreatureELEVEN,
    CreatureTWELVE,
    CreatureTHIRTEEN,
    CreatureFOURTEEN,
    CreatureFIFTEEN,
    CreatureSIXTEEN,
    CreatureSEVENTEEEN,
    CreatureEIGHTEEN,
    CreatureNINETEEN,
    CreatureTWENTY,
    CreatureTWENTYONE,
    CreatureTWENTYTWO,
    CreatureTWENTYTHREE,
    CreatureTWENTYFOUR,
    CreatureTWENTYFIVE,
    CreatureTWENTYSIX,
    CreatureTWENTYSEVEN,
    CreatureTWENTYEIGHT,
    CreatureTWENTYNINE,
    CreatureTHIRTY,
    CreatureTHIRTYONE,
    CreatureTHIRTYTWO,
    CreatureTHIRTYTHREE,
    CreatureTHIRTYFOUR,
    CreatureTHIRTYFIVE,
    CreatureTHIRTYSIX,
    CreatureTHIRTYSEVEN,
    CreatureTHIRTYEIGHT,
    CreatureTHIRTYNINE,
    CreatureFOURTY
}creatureIDS_t;

typedef enum Position_t{
    Position0,
    Position1
}Position_t;

typedef enum classes_t{
    NONEXISTENT_CLASS,
    EASY,
    MEDIUM,
    HARD
}classes_t;

typedef enum V_Movement_t{
    DOWN,
    UP
}V_Movement_t;

typedef enum H_Movement_t{
    RIGHT,
    LEFT
}H_Movement_t;

typedef struct creature_t{
    classes_t CreatureType;
    creatureIDS_t CreatureID;

    signed short x_pos;
    signed short y_pos;
    signed short speed;
    
    unsigned char Alive;

    Position_t Position;
    bullet_t* bullet;

}creature_t;

creature_t* CreateCreatures();
creature_t CreateSingleCreature(signed short x_pos, signed short y_pos,
                                classes_t CreatureType, creatureIDS_t ID);

void vCreateCreaturesBullet(creature_t* creatures, 
                            bullet_t* CreatureBullets);


void vDrawCreaturesBullet(bullet_t* CreatureBullets);
void vUpdateCreaturesBulletPos(bullet_t* CreaturesBullet);

signed char xCheckCreaturesCollision(creature_t* creatures,
                                     signed short bullet_x,
                                     signed short bullet_y);

signed char xCheckSingleCreatureCollision(signed short bullet_x, signed short bullet_y,
                                          creature_t* creature);

unsigned char xCheckCreaturesBulletCollisonBottomWall(signed short y_pos);


unsigned char xCheckCreaturesBulletShipCollision(signed short x_pos,
                                                 signed short y_pos,
                                                 ship_t* ship);

void vKillCreature(creature_t* creature, unsigned char ID);
void vAlternateAnimation(creature_t* creature);

void vMoveCreaturesHorizontal(creature_t* creature, H_Movement_t* DIRECTION);

unsigned char xFetchCreatureValue(unsigned char creatureclassID);
#endif 

