#include "../inc/audio.h"

int audio_processing(void)
{
    int i = 0;
    int total_samples = DURATION * SAMPLES_PER_SECOND;
    short int sample;

    float time = 0;
    float angle;

    FILE *file = fopen("sine.raw", "wb");
    if (file == NULL) {
        printf("Could not open file\n");
        return -1;
    }

    while (i < total_samples) {
        time = i * (1/SAMPLES_PER_SECOND);
        angle = 2 * PI * TONE_FREQ * time;
        sample = MAX_VALUE_ENCODING * sin(angle);
        
        fwrite(&sample, 2, 1, file);
        i++;
    }
    fclose(file);
    return 0;
}

int main(void) 
{
    audio_processing();
    return 0;
}