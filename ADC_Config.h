#pragma once

#ifndef UNTITLED_ADC_CONFIG_H
#define UNTITLED_ADC_CONFIG_H

void ADC_Config(){
   //ADC1 Clock activated
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

   ADC_InitTypeDef       ADC_InitStruct;
   ADC_CommonInitTypeDef ADC_CommonInitStructure;

   //ADC_Init
   ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;
   ADC_InitStruct.ADC_ScanConvMode = DISABLE;
   ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
   ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
   ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
   ADC_InitStruct.ADC_NbrOfConversion = 1;
   ADC_Init(ADC1, &ADC_InitStruct);

   // ADC Common Init **********************************************************
   ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
   ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
   ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
   ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
   ADC_CommonInit(&ADC_CommonInitStructure);

   //PA16 temperature sensor activated
   ADC_TempSensorVrefintCmd(ENABLE);

   // ADC1 regular channel12 configuration
   ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_3Cycles);

   // Enable ADC1
   ADC_Cmd(ADC1, ENABLE);
}


#endif //UNTITLED_ADC_CONFIG_H