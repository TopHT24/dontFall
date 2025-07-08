#ifndef SOUND_H
#define SOUND_H

#include "raylib.h"
enum Sound_E{
    SOUND_WIN,
    SOUND_GAMEOVER,
   
    SOUND_TOTAL 
};

void Load_Sound();
void Play_Sound(Sound_E id);
void Unload_Sound();

#endif