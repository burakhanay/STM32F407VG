#pragma once

#ifndef UNTITLED_DMA_CONFIG_H
#define UNTITLED_DMA_CONFIG_H

void DMA_Config(uint32_t s_adress, float *d_adress){
    //DMA Clock is activated
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

    DMA_InitTypeDef DMA_InitStructure;
    // DMA2 Stream0 channel0 configuration
    DMA_InitStructure.DMA_Channel = DMA_Channel_0;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)s_adress;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)d_adress;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_BufferSize = 1;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_Init(DMA2_Stream0, &DMA_InitStructure);
    DMA_Cmd(DMA2_Stream0, ENABLE);
    //DMA kendi istegine gore ayarlanmali

    // Enable ADC1 DMA
    ADC_DMACmd(ADC1, ENABLE);

    // Enable DMA request after last transfer (Single-ADC mode)
    ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
}

#endif //UNTITLED_DMA_CONFIG_H
