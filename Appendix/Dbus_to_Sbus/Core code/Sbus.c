/*
 * @Author: hwwx 93569047+hwwx@users.noreply.github.com
 * @Date: 2023-12-27 10:22:18
 * @LastEditors: hwwx 93569047+hwwx@users.noreply.github.com
 * @LastEditTime: 2024-01-02 09:02:46
 * @FilePath: \Master(GS)\Application\Remote\Sbus.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Sbus.h"

extern UART_HandleTypeDef huart3;
uint8_t packet[25];
uint16_t channels[16] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
extern rc_t    rc_structure;

void move_control()
{ 

}

void Sbus_motifily()
{
  if(rc_structure.base_info->s1.value == 1 && rc_structure.base_info->s2.value == 1)
  {
    move_control();
  }
}

void Sbus_encore()
{

    channels[0] = rc_structure.base_info->ch0 + 1024; // roll
    channels[1] = rc_structure.base_info->ch1 + 1024; // pitch
    channels[2] = rc_structure.base_info->ch2 + 1024; // yaw
    channels[3] = rc_structure.base_info->ch3 + 1024; // 油门
    channels[4] = rc_structure.base_info->s1.value;
    channels[5] = rc_structure.base_info->s2.value;
    channels[6] = rc_structure.base_info->thumbwheel.value + 1024;
    
    // SBUS header

    packet[0] = 0x0F; 

    // 16 channels of 11 bit data

    packet[1]  = (unsigned char) ((channels[0] & 0x07FF));

    packet[2]  = (unsigned char) ((channels[0] & 0x07FF)>>8   | (channels[1] & 0x07FF)<<3);

    packet[3]  = (unsigned char) ((channels[1] & 0x07FF)>>5   | (channels[2] & 0x07FF)<<6);

    packet[4]  = (unsigned char) ((channels[2] & 0x07FF)>>2);

    packet[5]  = (unsigned char) ((channels[2] & 0x07FF)>>10  | (channels[3] & 0x07FF)<<1);

    packet[6]  = (unsigned char) ((channels[3] & 0x07FF)>>7   | (channels[4] & 0x07FF)<<4);

    packet[7]  = (unsigned char) ((channels[4] & 0x07FF)>>4   | (channels[5] & 0x07FF)<<7);

    packet[8]  = (unsigned char) ((channels[5] & 0x07FF)>>1);

    packet[9]  = (unsigned char) ((channels[5] & 0x07FF)>>9   | (channels[6] & 0x07FF)<<2);

    packet[10] = (unsigned char) ((channels[6] & 0x07FF)>>6   | (channels[7] & 0x07FF)<<5);

    packet[11] = (unsigned char) ((channels[7] & 0x07FF)>>3);

    packet[12] = (unsigned char) ((channels[8] & 0x07FF));

    packet[13] = (unsigned char) ((channels[8] & 0x07FF)>>8   | (channels[9] & 0x07FF)<<3);

    packet[14] = (unsigned char) ((channels[9] & 0x07FF)>>5   | (channels[10] & 0x07FF)<<6);  

    packet[15] = (unsigned char) ((channels[10] & 0x07FF)>>2);

    packet[16] = (unsigned char) ((channels[10] & 0x07FF)>>10 | (channels[11] & 0x07FF)<<1);

    packet[17] = (unsigned char) ((channels[11] & 0x07FF)>>7  | (channels[12] & 0x07FF)<<4);

    packet[18] = (unsigned char) ((channels[12] & 0x07FF)>>4  | (channels[13] & 0x07FF)<<7);

    packet[19] = (unsigned char) ((channels[13] & 0x07FF)>>1);

    packet[20] = (unsigned char) ((channels[13] & 0x07FF)>>9  | (channels[14] & 0x07FF)<<2);

    packet[21] = (unsigned char) ((channels[14] & 0x07FF)>>6  | (channels[15] & 0x07FF)<<5);

    packet[22] = (unsigned char) ((channels[15] & 0x07FF)>>3);

    // flags

    packet[23] = 0x00;

    // footer

    packet[24] = 0X00;
}


void Sbus_transimit()
{
    /*
    a.高速模式：每4ms发送一次
    b.低速模式：每14ms发送一次
    */
   if(rc_structure.info->status == REMOTE_ONLINE)
   {
      HAL_UART_Transmit_DMA(&huart3,packet,sizeof(packet));
   }
   else
   {

   }
  
}

void Sbus_work()
{
    Sbus_motifily();
    Sbus_encore();
    Sbus_transimit();
}
