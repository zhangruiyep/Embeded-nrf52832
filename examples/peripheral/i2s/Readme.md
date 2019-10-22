### FLASH

#### 架构 

应用场景单一，不需要考虑多任务，不支持nordic的softdevice等访问，仅向应用程序提供基础的读写接口，不支持文件系统。

app -> SFUD -> nrf SPI driver

#### SFUD（Serial Flash Universal Driver）

https://github.com/armink/SFUD

##### 修改点：
sfud_port.c中，对接了NRF_DRV_SPI init/write/read API。

QSPI未支持，如果需要使用，可以对接NRF_DRV_SPI中的相关API。

