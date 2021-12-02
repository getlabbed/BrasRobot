//https://github.com/mikyll/SDL2-Controller-Tester

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "ctype.h"
#include "SDL.h"

#define MAX_NUM_JOYSTICKS 4

typedef struct {
    SDL_Joystick *joysticks[MAX_NUM_JOYSTICKS];
    SDL_Haptic *haptics[MAX_NUM_JOYSTICKS];
    int rumble[MAX_NUM_JOYSTICKS]; // 2 -> play rumble
    int connected; // connected joysticks number
} App;


extern void cleanup(void);
extern void initSDL(void);
extern void doInput(void);

App app;
