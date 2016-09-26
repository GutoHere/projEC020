/*
 * Sensor.c
 *
 *  Created on: 19/09/2016
 *      Author: aluno
 */

#include "lpc17xx_pinsel.h"
#include "lpc17xx_i2c.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_timer.h"

static void Sensor_initADC(void);
static void Sensor_initI2C(void);

typedef struct tag_sensor
{
	int32_t sensor_data;
	uint32_t ADC_Interrupt_Done_Flag;
}ttag_sensor;

ttag_sensor ClassHandler;

void Sensor_new(void)
{
	Sensor_initADC();
	Sensor_initI2C();
	ClassHandler.sensor_data = 0;
	ClassHandler.ADC_Interrupt_Done_Flag = 0;
}

int Sensor_read(void)
{
	//if(ClassHandler.ADC_Interrupt_Done_Flag == 1){
		//ClassHandler.sensor_data = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_5);
		ClassHandler.sensor_data = temp_read();
		//ClassHandler.ADC_Interrupt_Done_Flag = 0;
		//NVIC_EnableIRQ(ADC_IRQn);
		/* analog input connected to BNC */
		//ADC_StartCmd(LPC_ADC,ADC_START_NOW);
	//}
	return ClassHandler.sensor_data;
}

static void Sensor_initADC(void)
{
	PINSEL_CFG_Type PinCfg;
	/*
	 * Init ADC pin connect
	 * AD0.0 on P0.23
	 */
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Pinnum = 23;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	/* Configuration for ADC :
	 * 	Frequency at 0.2Mhz
	 *  ADC channel 0, no Interrupt
	 */
	//ADC_IntConfig(LPC_ADC,ADC_CHANNEL_0,DISABLE);
	//ADC_ChannelCmd(LPC_ADC,ADC_CHANNEL_0,ENABLE);

	ADC_Init(LPC_ADC, 200000);
	ADC_IntConfig(LPC_ADC,ADC_CHANNEL_0,DISABLE);
	ADC_ChannelCmd(LPC_ADC,ADC_CHANNEL_0,ENABLE);
}

static void Sensor_initI2C(void)
{
	PINSEL_CFG_Type PinCfg;

	/* Initialize I2C2 pin connect */
	PinCfg.Funcnum = 2;
	PinCfg.Pinnum = 10;
	PinCfg.Portnum = 0;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 11;
	PINSEL_ConfigPin(&PinCfg);

	// Initialize I2C peripheral
	I2C_Init(LPC_I2C2, 100000);

	/* Enable I2C1 operation */
	I2C_Cmd(LPC_I2C2, ENABLE);
}

void ADC_IRQHandler(void){
	NVIC_DisableIRQ(ADC_IRQn);
	ClassHandler.sensor_data = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_5);
	ClassHandler.ADC_Interrupt_Done_Flag = 1;
}
