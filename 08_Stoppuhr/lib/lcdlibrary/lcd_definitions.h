#ifndef LCD_DEFINES_H
#define LCD_DEFINES_H

#define 	LCD_IO_MODE   1
 
#define 	LCD_PORT   PORTB
#define 	LCD_DATA0_PORT   LCD_PORT   /**< port for 4bit data bit 0  -> D4 */
#define 	LCD_DATA1_PORT   LCD_PORT   /**< port for 4bit data bit 0  -> D4 */
#define 	LCD_DATA2_PORT   LCD_PORT   /**< port for 4bit data bit 0  -> D4 */
#define 	LCD_DATA3_PORT   LCD_PORT   /**< port for 4bit data bit 0  -> D4 */
 
#define 	LCD_DATA0_PIN   0           /**< pin for 4bit data bit 0  -> D4 */
#define 	LCD_DATA1_PIN   1           /**< pin for 4bit data bit 1  -> D5 */
#define 	LCD_DATA2_PIN   2           /**< pin for 4bit data bit 2  -> D6 */
#define 	LCD_DATA3_PIN   3           /**< pin for 4bit data bit 3  -> D7 */

#define     LCD_CONTROL_PORT PORTD

#define 	LCD_RS_PORT   LCD_CONTROL_PORT  /**< port for RS line        */
#define 	LCD_RS_PIN   4                  /**< pin for RS line         */
 
#define 	LCD_RW_PORT   LCD_CONTROL_PORT  /**< port for RW line        */
#define 	LCD_RW_PIN   5                  /**< pin for RW line         */

#define 	LCD_E_PORT   LCD_CONTROL_PORT   /**< port for enable line    */
#define 	LCD_E_PIN    6                  /**< pin for enable line     */

#endif /*LCD_DEFINES_H*/