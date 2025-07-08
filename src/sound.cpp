#include "sound.h"

static Sound sound_E[SOUND_TOTAL];

void Load_Sound(){
    InitAudioDevice();

    
    sound_E[SOUND_WIN] = LoadSound("assets/win.wav");
    sound_E[SOUND_GAMEOVER] = LoadSound("assets/over.wav");
}

void Play_Sound(Sound_E id){
    if(id>=0 && id< SOUND_TOTAL ){
        PlaySound(sound_E[id]);
    }
}

void Unload_Sound(){
    for(int i=0; i<=SOUND_TOTAL;i++){
        UnloadSound(sound_E[i]);
    }
}