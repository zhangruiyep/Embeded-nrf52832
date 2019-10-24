/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __ES8374_H__
#define __ES8374_H__

//#include "esp_types.h"
//#include "audio_hal.h"
//#include "esxxx_common.h"
#define FEATURE_MIC_EN

/* nrf52832 port begin */
#include <stdint.h>
#include <stdbool.h>

typedef int esp_err_t;
#define ESP_OK 0
#define ESP_FAIL 1

/* nrf52832 port end */

/* audio_hal.h begin */
#if 1
/**
 * @brief Select media hal codec mode
 */
typedef enum {
    AUDIO_HAL_CODEC_MODE_ENCODE = 1,  /*!< select adc */
    AUDIO_HAL_CODEC_MODE_DECODE,      /*!< select dac */
    AUDIO_HAL_CODEC_MODE_BOTH,        /*!< select both adc and dac */
    AUDIO_HAL_CODEC_MODE_LINE_IN,     /*!< set adc channel */
} audio_hal_codec_mode_t;

/**
 * @brief Select adc channel for input mic signal
 */
typedef enum {
    AUDIO_HAL_ADC_INPUT_LINE1 = 0x00,  /*!< mic input to adc channel 1 */
    AUDIO_HAL_ADC_INPUT_LINE2,         /*!< mic input to adc channel 2 */
    AUDIO_HAL_ADC_INPUT_ALL,           /*!< mic input to both channels of adc */
    AUDIO_HAL_ADC_INPUT_DIFFERENCE,    /*!< mic input to adc difference channel */
} audio_hal_adc_input_t;

/**
 * @brief Select channel for dac output
 */
typedef enum {
    AUDIO_HAL_DAC_OUTPUT_LINE1 = 0x00,  /*!< dac output signal to channel 1 */
    AUDIO_HAL_DAC_OUTPUT_LINE2,         /*!< dac output signal to channel 2 */
    AUDIO_HAL_DAC_OUTPUT_ALL,           /*!< dac output signal to both channels */
} audio_hal_dac_output_t;

/**
 * @brief Select operating mode i.e. start or stop for audio codec chip
 */
typedef enum {
    AUDIO_HAL_CTRL_STOP  = 0x00,  /*!< set stop mode */
    AUDIO_HAL_CTRL_START = 0x01,  /*!< set start mode */
} audio_hal_ctrl_t;

/**
 * @brief Select I2S interface operating mode i.e. master or slave for audio codec chip
 */
typedef enum {
    AUDIO_HAL_MODE_SLAVE = 0x00,   /*!< set slave mode */
    AUDIO_HAL_MODE_MASTER = 0x01,  /*!< set master mode */
} audio_hal_iface_mode_t;

/**
 * @brief Select I2S interface samples per second
 */
typedef enum {
    AUDIO_HAL_08K_SAMPLES,   /*!< set to  8k samples per second */
    AUDIO_HAL_11K_SAMPLES,   /*!< set to 11.025k samples per second */
    AUDIO_HAL_16K_SAMPLES,   /*!< set to 16k samples in per second */
    AUDIO_HAL_22K_SAMPLES,   /*!< set to 22.050k samples per second */
    AUDIO_HAL_24K_SAMPLES,   /*!< set to 24k samples in per second */
    AUDIO_HAL_32K_SAMPLES,   /*!< set to 32k samples in per second */
    AUDIO_HAL_44K_SAMPLES,   /*!< set to 44.1k samples per second */
    AUDIO_HAL_48K_SAMPLES,   /*!< set to 48k samples per second */
} audio_hal_iface_samples_t;

/**
 * @brief Select I2S interface number of bits per sample
 */
typedef enum {
    AUDIO_HAL_BIT_LENGTH_16BITS = 1,   /*!< set 16 bits per sample */
    AUDIO_HAL_BIT_LENGTH_24BITS,       /*!< set 24 bits per sample */
    AUDIO_HAL_BIT_LENGTH_32BITS,       /*!< set 32 bits per sample */
} audio_hal_iface_bits_t;

/**
 * @brief Select I2S interface format for audio codec chip
 */
typedef enum {
    AUDIO_HAL_I2S_NORMAL = 0,  /*!< set normal I2S format */
    AUDIO_HAL_I2S_LEFT,        /*!< set all left format */
    AUDIO_HAL_I2S_RIGHT,       /*!< set all right format */
    AUDIO_HAL_I2S_DSP,         /*!< set dsp/pcm format */
} audio_hal_iface_format_t;

/**
 * @brief I2s interface configuration for audio codec chip
 */
typedef struct {
    audio_hal_iface_mode_t mode;        /*!< audio codec chip mode */
    audio_hal_iface_format_t fmt;       /*!< I2S interface format */
    audio_hal_iface_samples_t samples;  /*!< I2S interface samples per second */
    audio_hal_iface_bits_t bits;        /*!< i2s interface number of bits per sample */
} audio_hal_codec_i2s_iface_t;

/**
 * @brief Configure media hal for initialization of audio codec chip
 */
typedef struct {
    audio_hal_adc_input_t adc_input;       /*!< set adc channel */
    audio_hal_dac_output_t dac_output;     /*!< set dac channel */
    audio_hal_codec_mode_t codec_mode;     /*!< select codec mode: adc, dac or both */
    audio_hal_codec_i2s_iface_t i2s_iface; /*!< set I2S interface configuration */
} audio_hal_codec_config_t;
#endif
/* audio_hal.h end */

/* esxxx_common.h begin */
typedef enum {
    BIT_LENGTH_MIN = -1,
    BIT_LENGTH_16BITS = 0x03,
    BIT_LENGTH_18BITS = 0x02,
    BIT_LENGTH_20BITS = 0x01,
    BIT_LENGTH_24BITS = 0x00,
    BIT_LENGTH_32BITS = 0x04,
    BIT_LENGTH_MAX,
} es_bits_length_t;

typedef enum {
    MCLK_DIV_MIN = -1,
    MCLK_DIV_1 = 1,
    MCLK_DIV_2 = 2,
    MCLK_DIV_3 = 3,
    MCLK_DIV_4 = 4,
    MCLK_DIV_6 = 5,
    MCLK_DIV_8 = 6,
    MCLK_DIV_9 = 7,
    MCLK_DIV_11 = 8,
    MCLK_DIV_12 = 9,
    MCLK_DIV_16 = 10,
    MCLK_DIV_18 = 11,
    MCLK_DIV_22 = 12,
    MCLK_DIV_24 = 13,
    MCLK_DIV_33 = 14,
    MCLK_DIV_36 = 15,
    MCLK_DIV_44 = 16,
    MCLK_DIV_48 = 17,
    MCLK_DIV_66 = 18,
    MCLK_DIV_72 = 19,
    MCLK_DIV_5 = 20,
    MCLK_DIV_10 = 21,
    MCLK_DIV_15 = 22,
    MCLK_DIV_17 = 23,
    MCLK_DIV_20 = 24,
    MCLK_DIV_25 = 25,
    MCLK_DIV_30 = 26,
    MCLK_DIV_32 = 27,
    MCLK_DIV_34 = 28,
    MCLK_DIV_7  = 29,
    MCLK_DIV_13 = 30,
    MCLK_DIV_14 = 31,
    MCLK_DIV_MAX,
} es_sclk_div_t;

typedef enum {
    LCLK_DIV_MIN = -1,
    LCLK_DIV_128 = 0,
    LCLK_DIV_192 = 1,
    LCLK_DIV_256 = 2,
    LCLK_DIV_384 = 3,
    LCLK_DIV_512 = 4,
    LCLK_DIV_576 = 5,
    LCLK_DIV_768 = 6,
    LCLK_DIV_1024 = 7,
    LCLK_DIV_1152 = 8,
    LCLK_DIV_1408 = 9,
    LCLK_DIV_1536 = 10,
    LCLK_DIV_2112 = 11,
    LCLK_DIV_2304 = 12,
    LCLK_DIV_96 = 13,

    LCLK_DIV_125 = 16,
    LCLK_DIV_136 = 17,
    LCLK_DIV_250 = 18,
    LCLK_DIV_272 = 19,
    LCLK_DIV_375 = 20,
    LCLK_DIV_500 = 21,
    LCLK_DIV_544 = 22,
    LCLK_DIV_750 = 23,
    LCLK_DIV_1000 = 24,
    LCLK_DIV_1088 = 25,
    LCLK_DIV_1496 = 26,
    LCLK_DIV_1500 = 27,
    LCLK_DIV_MAX,
} es_lclk_div_t;

typedef enum {
    D2SE_PGA_GAIN_MIN = -1,
    D2SE_PGA_GAIN_DIS = 0,
    D2SE_PGA_GAIN_EN = 1,
    D2SE_PGA_GAIN_MAX = 2,
} es_d2se_pga_t;

typedef enum {
    ADC_INPUT_MIN = -1,
    ADC_INPUT_LINPUT1_RINPUT1 = 0x00,
    ADC_INPUT_MIC1  = 0x05,
    ADC_INPUT_MIC2  = 0x06,
    ADC_INPUT_LINPUT2_RINPUT2 = 0x50,
    ADC_INPUT_DIFFERENCE = 0xf0,
    ADC_INPUT_MAX,
} es_adc_input_t;

typedef enum {
    DAC_OUTPUT_MIN = -1,
    DAC_OUTPUT_LOUT1 = 0x04,
    DAC_OUTPUT_LOUT2 = 0x08,
    DAC_OUTPUT_SPK   = 0x09,
    DAC_OUTPUT_ROUT1 = 0x10,
    DAC_OUTPUT_ROUT2 = 0x20,
    DAC_OUTPUT_ALL = 0x3c,
    DAC_OUTPUT_MAX,
} es_dac_output_t;

typedef enum {
    MIC_GAIN_MIN = -1,
    MIC_GAIN_0DB = 0,
    MIC_GAIN_3DB = 3,
    MIC_GAIN_6DB = 6,
    MIC_GAIN_9DB = 9,
    MIC_GAIN_12DB = 12,
    MIC_GAIN_15DB = 15,
    MIC_GAIN_18DB = 18,
    MIC_GAIN_21DB = 21,
    MIC_GAIN_24DB = 24,
    MIC_GAIN_MAX,
} es_mic_gain_t;

typedef enum {
    ES_MODULE_MIN = -1,
    ES_MODULE_ADC = 0x01,
    ES_MODULE_DAC = 0x02,
    ES_MODULE_ADC_DAC = 0x03,
    ES_MODULE_LINE = 0x04,
    ES_MODULE_MAX
} es_module_t;

typedef enum {
    ES_MODE_MIN = -1,
    ES_MODE_SLAVE = 0x00,
    ES_MODE_MASTER = 0x01,
    ES_MODE_MAX,
} es_mode_t;

typedef enum {
    ES_I2S_MIN = -1,
    ES_I2S_NORMAL = 0,
    ES_I2S_LEFT = 1,
    ES_I2S_RIGHT = 2,
    ES_I2S_DSP = 3,
    ES_I2S_MAX
} es_i2s_fmt_t;

/**
 * @brief Configure ES8388 clock
 */
typedef struct {
    es_sclk_div_t sclk_div;    /*!< bits clock divide */
    es_lclk_div_t lclk_div;    /*!< WS clock divide */
} es_i2s_clock_t;

/* esxxx_common.h end */

/* ES8374 address */
#define ES8374_ADDR 0x20  // 0x22:CE=1;0x20:CE=0

/* ES8374 init config */
#define ES8374_MODULE_DEFAULT   ES_MODULE_DAC
#define ES8374_MODE_DEFAULT     ES_MODE_SLAVE
#define ES8374_BIT_LENGTH_DEFAULT   BIT_LENGTH_16BITS
#define ES8374_I2S_FMT_DEFAULT  ES_I2S_NORMAL
#define ES8374_OUTPUT_DEFAULT   DAC_OUTPUT_SPK
#define ES8374_INPUT_DEFAULT    ADC_INPUT_MIC1

/**
 * @brief Initialize ES8374 codec chip
 *
 * @param cfg configuration of ES8374
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_codec_init(void);

/**
 * @brief Deinitialize ES8374 codec chip
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_codec_deinit(void);

/**
 * @brief Configure ES8374 I2S format
 *
 * @param mode:  set ADC or DAC or both
 * @param fmt:  ES8374 I2S format
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_config_fmt(es_module_t mode, uint8_t fmt);

/**
 * @brief Configure I2S clock in MSATER mode
 *
 * @param cfg:  set bits clock and WS clock
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_i2s_config_clock(es_i2s_clock_t cfg);

/**
 * @brief Configure ES8374 data sample bits
 *
 * @param mode:  set ADC or DAC or both
 * @param bit_per_sample:  bit number of per sample
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_set_bits_per_sample(es_module_t mode, es_bits_length_t bit_per_sample);

/**
 * @brief  Start ES8374 codec chip
 *
 * @param mode:  set ADC or DAC or both
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_start(es_module_t mode);

/**
 * @brief  Stop ES8374 codec chip
 *
 * @param mode:  set ADC or DAC or both
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_stop(es_module_t mode);

/**
 * @brief  Set voice volume
 *
 * @param volume:  voice volume (0~100)
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_codec_set_voice_volume(int volume);

/**
 * @brief Get voice volume
 *
 * @param[out] *volume:  voice volume (0~100)
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t es8374_codec_get_voice_volume(int *volume);

/**
 * @brief Mute or unmute ES8374 DAC. Basically you can use this function to mute or unmute the output
 *
 * @param enable mute(1) or unmute(0)
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_set_voice_mute(bool enable);

/**
 * @brief Get ES8374 DAC mute status
 *
 * @return
 *     - -1: Parameter error
 *     -  0: Voice is unmuted
 *     -  1: Voice is muted
 */
esp_err_t es8374_get_voice_mute(void);

#ifdef FEATURE_MIC_EN
/**
 * @brief Set ES8374 mic gain
 *
 * @param gain db of mic gain
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_set_mic_gain(es_mic_gain_t gain);

/**
 * @brief Set ES8374 ADC input mode
 *
 * @param input adc input mode
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_config_adc_input(es_adc_input_t input);
#endif

/**
 * @brief Set ES8374 DAC output mode
 *
 * @param output dac output mode
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_config_dac_output(es_dac_output_t output);

/**
 * @brief Write ES8374 register
 *
 * @param reg_add address of register
 * @param data data of register
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_write_reg(uint8_t reg_add, uint8_t data);

/**
 * @brief Print all ES8374 registers
 *
 * @return
 *     - void
 */
void es8374_read_all(void);

/**
 * @brief Configure ES8374 codec mode and I2S interface
 *
 * @param mode codec mode
 * @param iface I2S config
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_codec_config_i2s(es_module_t mode, audio_hal_codec_i2s_iface_t *iface);

/**
 * @brief Control ES8374 codec chip
 *
 * @param mode codec mode
 * @param ctrl_state start or stop decode or encode progress
 *
 * @return
 *     - ESP_FAIL Parameter error
 *     - ESP_OK   Success
 */
esp_err_t es8374_codec_ctrl_state(audio_hal_codec_mode_t mode, audio_hal_ctrl_t ctrl_state);

/**
 * @brief Set ES8374 PA power
 *
 * @param enable true for enable PA power, false for disable PA power
 *
 * @return
 *     - void
 */
void es8374_pa_power(bool enable);

#endif  //__ES8374_H__

