
#ifndef _WAV_FMT_H_
#define _WAV_FMT_H_

#include <stdint.h>
#include <stdlib.h>

#define RIFF_STR "RIFF"
#define WAVE_STR "WAVE"
#define FMT_STR  "fmt "
#define DATA_STR "data"

typedef struct
{
    char riff[4];
    uint32_t file_len;
    char wave[4];
} __attribute__((packed)) RIFF_HEADER_T;

typedef struct
{
    char type[4];
    uint32_t size;
} __attribute__((packed)) CHUNK_HEADER_T;

typedef struct
{
    uint16_t format_tag;
    uint16_t channels;
    uint32_t samples;
    uint32_t bytes;
    uint16_t align;
    uint16_t swidth;
} __attribute__((packed)) FMT_T;

#define STR_EQU(addr, str) (!memcmp(addr, str, strlen(str)))

int get_pcm_data_from_file(uint32_t file_addr, uint32_t *pcm_addr, size_t *pcm_len);

#endif

