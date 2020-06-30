#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "TUM_Draw.h"
#include "main.h"




void vDownMenuSelection(SelectedMenuOption_t* CurrentSelect)
{
    switch(*CurrentSelect){
        case SinglePlayer:
        case MultiPlayer:
        case Quit:
            (*CurrentSelect)++;
            break;
        case Pause:
           (*CurrentSelect) = SinglePlayer;
    }
}

void vUpMenuSelection(SelectedMenuOption_t* CurrentSelect)
{
    switch(*CurrentSelect){
        case Pause:        
        case Quit:
        case MultiPlayer:
            (*CurrentSelect)--;
            break;
        case SinglePlayer:
           (*CurrentSelect) = Pause;
    }
}

unsigned int xWhichColorAmI(SelectedMenuOption_t CurrentSelect, SelectedMenuOption_t ConsideredOption)
{
    if(ConsideredOption == CurrentSelect)
        return Green;
    else 
        return White;
}
