#include "soundplayer.h"
#include <portaudio.h>
#include <QDebug>
extern char _binary_00_raw_start[];
extern char _binary_00_raw_end[];

SoundPlayer::SoundPlayer() {

}
bool SoundPlayer::playSoundFile(int fileNumber) {
    //qDebug() << Pa_GetVersionText();
    const int SAMPLE_RATE = 44100;
    const double TRACK_DURATION = 1.5; //duration of the track in seconds.
    const int DURATION_BYTES = (int) (2*SAMPLE_RATE*TRACK_DURATION); //factor 2 is due 16 bit sound.
    int offset = fileNumber*DURATION_BYTES;
    PaError paError = Pa_Initialize();
    PaStream* stream = nullptr;
    PaStreamParameters paStreamParameters;
    paStreamParameters.device = Pa_GetDefaultOutputDevice();
    paStreamParameters.channelCount = 1;
    paStreamParameters.sampleFormat = paInt16;
    paStreamParameters.suggestedLatency = Pa_GetDeviceInfo(paStreamParameters.device)->defaultLowOutputLatency;
    paStreamParameters.hostApiSpecificStreamInfo = nullptr;
    paError = Pa_OpenStream(&stream, nullptr, &paStreamParameters, SAMPLE_RATE, paFramesPerBufferUnspecified, paClipOff, nullptr, nullptr);
    if (paError != paNoError || ! stream) {
        Pa_Terminate();
        return false;
    }
    paError = Pa_StartStream(stream);
    if (paError != paNoError) {
        Pa_Terminate();
        return false;
    }
    const size_t BUFFER_LEN = SAMPLE_RATE/10;
    int16_t data[BUFFER_LEN];
    int index = 0;
    while((_binary_00_raw_start+index+offset) < (_binary_00_raw_start+offset+DURATION_BYTES)) {
        memcpy(data, _binary_00_raw_start+index+offset, sizeof(data));
        paError = Pa_WriteStream(stream, data, BUFFER_LEN);
        if (paError != paNoError) {
            break;
        }
        memset(data, 0, sizeof(data));
        index = index + sizeof(data);
    }
    paError = Pa_CloseStream(stream);
    if (paError != paNoError) {
        Pa_Terminate();
        return false;
    }
    Pa_Terminate();
    return true;
}
