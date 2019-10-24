### AUDIO

#### 架构

app -> es8374 driver -> nrf I2C & I2S

PIN定义在sdk_config.h中。

#### I2C

使用nrf_drv_twi相关接口。

默认配置在i2c_init()中。

#### I2S

使用nrf_drv_i2s相关接口。

host侧默认配置在i2s_init()中，时钟频率需要按实际音频文件参数调整。

es8374侧默认配置在es8374_codec_init()中。

#### ES8374 driver

来源：https://github.com/espressif/esp-adf/tree/master/components/audio_hal/driver/es8374

原始代码成熟度较低，移植过程中做了比较大的修改。实际功能需要验证。


### FLASH

#### 架构 

应用场景单一，不需要考虑多任务，不支持nordic的softdevice等访问，仅向应用程序提供基础的读写接口，不支持文件系统。

app -> SFUD -> nrf SPI driver

#### SFUD（Serial Flash Universal Driver）

https://github.com/armink/SFUD

##### 修改点：
###### 1022
sfud_cfg.h中，增加GD25设备。

sfud_port.c中，对接了NRF_DRV_SPI init/write/read API。

QSPI未支持，如果需要使用，可以对接NRF_DRV_SPI中的相关API。
###### 1023
FLASH TABLE中增加MX25L64。

SPI MODE改为3。（尝试，如无效回退到默认mode0）

增加spi_lock、spi_unlock，SPI操作时关中断。

增加更多debug。

