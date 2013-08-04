/* LCD functions to init and write to the LCD Screen
 */
#ifndef LCD_H
#define LCD_H

#define RS 0x01
#define E 0x02
#define DATA_PINS 0xf0

void byteCmd(int cmd);
int initLCD(void);
int writeLcdCmd(int cmd);
int writeLcdData(int Data);
void clearScreen(void);




#endif
