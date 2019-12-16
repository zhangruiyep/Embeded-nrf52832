
#include "wav_fmt.h"
#include "sfud.h"

extern sfud_flash *g_sfud_flash;

/* return: 0 OK, <0 ERR */
int get_pcm_data_from_file(uint32_t file_addr, uint32_t *pcm_addr, size_t *pcm_len)
{
    RIFF_HEADER_T riff_hdr;
    CHUNK_HEADER_T chunk_hdr;
    FMT_T fmt;
    uint32_t offset = 0;
    int32_t flen = 0;
	sfud_err rc;

	rc = sfud_read(g_sfud_flash, file_addr, sizeof(riff_hdr), (uint8_t *)&riff_hdr);
    if (!STR_EQU(riff_hdr.riff, RIFF_STR))
    {
        /* not "RIFF" format */
        return -1;
    }
    flen = riff_hdr.file_len - sizeof(riff_hdr.wave);    //all chunks size
    offset += sizeof(riff_hdr);

    while(flen > 0)
    {
        rc = sfud_read(g_sfud_flash, file_addr+offset, sizeof(chunk_hdr), (uint8_t *)&chunk_hdr);
        if (STR_EQU(chunk_hdr.type, DATA_STR))
        {
            *pcm_addr = file_addr + offset + sizeof(chunk_hdr);
            *pcm_len = chunk_hdr.size;
            return 0;
        }
        else if (STR_EQU(chunk_hdr.type, FMT_STR))
        {
            rc = sfud_read(g_sfud_flash, file_addr+offset+sizeof(chunk_hdr), sizeof(fmt), (uint8_t *)&fmt);
            /* debug print fmt */
        }
        else
        {
            /* other chunk */
        }
        flen -= sizeof(chunk_hdr) + chunk_hdr.size;
        offset += sizeof(chunk_hdr) + chunk_hdr.size;
    }

    /* "data" not found */
    return -2;
}

