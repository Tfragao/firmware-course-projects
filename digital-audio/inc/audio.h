#ifndef AUDIO_H
#define AUDIO_H

#include <stdio.h>
#include <math.h>

const float SAMPLES_PER_SECOND = 44100;
const int DURATION = 2;
const int MAX_VALUE_ENCODING = 32767;
const int TONE_FREQ = 440;
const float PI = 3.1415;

int sample_processing(void);


#endif // AUDIO_H