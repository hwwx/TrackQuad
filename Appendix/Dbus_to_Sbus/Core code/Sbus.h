/*
 * @Author: hwwx 93569047+hwwx@users.noreply.github.com
 * @Date: 2023-12-27 10:22:12
 * @LastEditors: hwwx 93569047+hwwx@users.noreply.github.com
 * @LastEditTime: 2023-12-27 12:46:57
 * @FilePath: \MDK-ARMc:\Users\HWX\Desktop\YOLO\New_Sentinel\Master(GS)\Application\Remote\Sbus.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __SBUS_H
#define __SBUS_H

#include "stm32f4xx_hal.h"
#include "remote.h"


void Sbus_motifily();
void Sbus_encore();
void Sbus_transimit();
void Sbus_work();
void move_control();

#endif