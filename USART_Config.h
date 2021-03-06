#pragma once
#ifndef UNTITLED_USART_CONFIG_H
#define UNTITLED_USART_CONFIG_H


void USART_Init(){

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

   USART_InitTypeDef USART_InitStruct;
   GPIO_InitTypeDef GPIO_InitStruct;

   GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF ;
   GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
   GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
   GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
   GPIO_Init(GPIOA , &GPIO_InitStruct);

   GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);

   USART_InitStruct.USART_Mode = USART_Mode_Tx;
   USART_InitStruct.USART_BaudRate = 9600;
   USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART_InitStruct.USART_Parity = USART_Parity_Even;
   USART_InitStruct.USART_StopBits = USART_StopBits_1;
   USART_InitStruct.USART_WordLength = USART_WordLength_8b;
   USART_Init(USART1 , &USART_InitStruct);
   USART_Cmd(USART1, ENABLE);
}
#endif