#include <stdlib.h>

#define SHT31_ADDRESS		(0x44 << 1)

#define POLYNOMIAL			(0x31)

#define CMD_SOFT_RESET		(0x30a2)
#define CMD_SINGLE_HIGH		(0x2400)
#define CMD_HEATER_ENABLE	(0x306d)
#define CMD_HEATER_DISABLE	(0x3066)

typedef struct
{
	int I2cFd;
	float Temperature;
	float Humidity;
}
GroveTempHumiSHT31Instance;


static void SendCommand(GroveTempHumiSHT31Instance* this, uint16_t cmd);
static uint8_t CalcCRC8(const uint8_t* data, int dataSize);
void* GroveTempHumiSHT31_Open(int i2cFd);
void GroveTempHumiSHT31_Read(void* inst);
void GroveTempHumiSHT31_EnableHeater(void* inst);
void GroveTempHumiSHT31_DisableHeater(void* inst);
float GroveTempHumiSHT31_GetTemperature(void* inst);
float GroveTempHumiSHT31_GetHumidity(void* inst);