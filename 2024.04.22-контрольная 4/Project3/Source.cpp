#include <iostream>
#include <math.h>
#include <complex>
#include <windows.h>
#include <vector>
#include <SDL.h>

#define RATE 44100                      /// Sample rate
#define CHUNK 64                        /// Buffer size
#define CHANNELS 1                      /// Mono audio
#define FORMAT AUDIO_S16SYS             /// Sample format: signed system-endian 16 bit integers
#define MAX_SAMPLE_VALUE 32767          /// Max sample value based on sample datatype

#define DATALEN 65536                   /// Number of samples to perform FFT on. Must be power of 2.

typedef short sample;                   /// Datatype of samples. Also used to store frequency coefficients.
typedef std::complex<double> cmplx;     /// Complex number datatype for fft

sample currentaudio[DATALEN];
int writepos = 0;

void RecCallback(void* userdata, Uint8* stream, int streamLength)
{
    sample* newdata = (sample*)stream;
    int num_samples = streamLength / sizeof(sample);
    for (int i = 0; i < num_samples; i++)
    {
        currentaudio[writepos] = newdata[i];
        writepos = (writepos + 1) % DATALEN;
    }
}

void fft(vector<cmplx> output, vector<cmplx> input, int n)                            /// Simplest FFT algorithm
{
    if (n == 1)
    {
        output[0] = input[0];
        return;
    }

    vector <cmplx> even;
    for (int i = 0; i < n / 2; i++)
        even[i] = input[2 * i];
    cmplx* odd = new cmplx[n / 2];
    for (int i = 0; i < n / 2; i++)
        odd[i] = input[2 * i + 1];

    cmplx* evenOut = new cmplx[n / 2];
    fft(evenOut, even, n / 2);
    cmplx* oddOut = new cmplx[n / 2];
    fft(oddOut, odd, n / 2);

    for (int i = 0; i < n / 2; i++)
    {
        cmplx t = exp(cmplx(0, -2 * 3.14159 * i / n)) * oddOut[i];
        output[i] = evenOut[i] + t;
        output[i + n / 2] = evenOut[i] - t;
    }

    delete[] even;
    delete[] odd;
    delete[] evenOut;
    delete[] oddOut;

    return;
}

void FindFrequencyContent(sample* output, sample* input, int n)
{
    cmplx* fftin = new cmplx[n];
    cmplx* fftout = new cmplx[n];
    for (int i = 0; i < n; i++)                                              /// Convert input to complex
        fftin[i] = (cmplx)input[i];
    fft(fftout, fftin, n);                                              /// FFT
    for (int i = 0; i < n; i++)                                              /// Convert output to real samples
    {
        double currentvalue = abs(fftout[i]) / 200;
        output[i] = (sample)(currentvalue > MAX_SAMPLE_VALUE ? MAX_SAMPLE_VALUE : currentvalue);
    }

    delete[] fftin;
    delete[] fftout;
}

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_AUDIO);                                       /// Initialize SDL audio

    SDL_AudioSpec RecAudiospec;                                     /// SDL_AudioSpec object used to tell SDL sample rate, buffer size etc.

    /// Setting audio parameters
    RecAudiospec.freq = RATE;
    RecAudiospec.format = FORMAT;
    RecAudiospec.samples = CHUNK;
    RecAudiospec.callback = RecCallback;                            /// Callback functions also passed to SDL through SDL_AudioSpec objects

    /// Opening audio device for recording
    SDL_AudioDeviceID RecDevice = SDL_OpenAudioDevice(NULL, 1, &RecAudiospec, NULL, 0);

    SDL_PauseAudioDevice(RecDevice, 0);                             /// Start recording

    char pitchnames[] = "A   A#  B   C   C#  D   D#  E   F   F#  G   G#\n";
    int bargraph[48];
    float OneFortyEighthOfAnOctave = pow(2, 1.0 / 48.0);
    float PitchA1 = 55.0;
    sample spectrum[DATALEN];

    for (int i = 0; i < 100; i++)
    {
        FindFrequencyContent(spectrum, currentaudio, DATALEN);

        for (int j = 0; j < 48; j++)                                     /// Iterating through bars
        {
            bargraph[j] = 0;
            float frequency = PitchA1 * pow(OneFortyEighthOfAnOctave, (float)j);
            float next_frequency = frequency * OneFortyEighthOfAnOctave;
            float spectral_index = frequency * (float)DATALEN / (float)RATE;
            float next_spectral_index = next_frequency * (float)DATALEN / (float)RATE;
            for (int k = 0; k < 8; k++)
            {
                for (int m = round(spectral_index); m < round(next_spectral_index); m++)
                    bargraph[j] += spectrum[m] / (8 * (next_spectral_index - spectral_index));
                spectral_index *= 2;
                next_spectral_index *= 2;
            }
        }

        system("cls");

        std::cout << pitchnames;
        for (int i = 20; i > 0; i--)
        {
            for (int j = 0; j < 48; j++)
                if (bargraph[j] > i * 200)
                    std::cout << '=';
                else
                    std::cout << ' ';
            std::cout << '\n';
        }
    }

    /// Close audio devices
    SDL_CloseAudioDevice(RecDevice);

    return 0;
}