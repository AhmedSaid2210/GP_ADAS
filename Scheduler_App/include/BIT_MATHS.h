/*
 * BIT_MATHS.h
 *
 *  Created on: 8 Aug 2023
 *      Author: AHMED KHALED ANWAR
 */

#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(BYTE,BIT_NUM)		(BYTE) |= (1<<(BIT_NUM))
#define CLEAR_BIT(BYTE,BIT_NUM)		(BYTE) &=(~(1<<BIT_NUM))
#define TGL_BIT(BYTE,BIT_NUM)	    (BYTE)^=((1<<BIT_NUM))
#define GET_BIT(BYTE,BIT_NUM)		((BYTE>>BIT_NUM)&1)

#define READ_REG(REG)				((REG))
#define CLEAR_REG(REG)				((REG &=( 0x0)))
#define SET_REG(REG)				((REG)|=(0xFFFFFFFF))
#define WRITE_REG(REG,VALUE)		((REG)=(VALUE))
#define MODIFY_REG(REG,SET_MSK,CLEAR_MSK)	 (WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEAR_MSK))) | (SET_MSK))))

#define SET_BYTE(BYTE) (BYTE|=(0xFF))
#define CLEAR_BYTE(BYTE) (BYTE &=0x00
#define SET_NIBBLE_HIGH(Byte) (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte) (Byte |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte) (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte) (Byte &=(0xF0)))

#endif /* BIT_MATHS_H_ */
