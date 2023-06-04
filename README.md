# nucleo-f401re-isl94202
- LED - PA5
- USART1_TX - PA2
- USART1_RX - PA3
- I2C_SCL - PB8
- I2C_SDA - PB9

0x00-0x4B EEPROM/Configuration Registers
0x80-0x89 Other Registers
    0x50-57 User EEPROM
0x80-0x89 Operations Registers
Status 0
REG_ISL94202_STATUS0 0x80
0x8A-0xAB Data Registers

$$I_{INCC}=\frac{1.2-I_{ICSOFFSET}*R_{IM\_IN}}{b}$$

- Over Voltage
    0x00-0x01
- Overvoltage Recovery
    0x02-0x03
- Under Voltage
    0x04-0x05
- Undervoltage Recovery
    0x06-0x07
- Overvoltage Lockout
    0x08-0x09
- Undervoltage Lockout
    0x0A-0x0B
- End of Charge
    0x0C-0x0D
- Low Voltage Charge
    0x0E-0x0F
- Sleep Voltage
    0x44-0x45
- Overvoltage Delay Timer (1sec)
    0x10-0x11
- Undervoltage Delay Time (1sec)
    0x12-0x13
- Open Wire Timing
    0x14-0x15
- Sleep Volt Delay Time (1sec)
    0x46-0x47

- Discharge OC
- DOC Delay
- Charge OC
- COC Delay
- Discharge SC
- DSC Delay
- Charge Detect Pluse Width
    0x01.[7-4]
- Load Detect Pluse Width
    0x04.[7-4]

- IDLE/DOZE Mode Timer
    0x48
- SLEEP Mode Timer
    0x48
- Watchdog Timer
    0x47

////////////////////
- CB Upper Limit
- CB Lower Limit
- CB Max Delta
    0x22-0x22
- CB Min Delta
    0x20-0x21

- CB during charge
- CB during discharge
- CB during EOC

- CB Over Temp
    0x2C-0x2D
- CB Under Temp
    0x28-0x29
- CB OT Recover
    0x2E-0x2F
- CB UT Recover
    0x2A-0x2B
- CB On Time
    0x24-0x25
- CB Off Time
    0x26-0x27

- Charge Over Temp
    0x30-0x31
- Charge Under Temp
    0x34-0x35
- Charge OT Recover
    0x32-0x33
- Charge UT Recover
    0x36-0x37
- Discharge Over Temp
- Discharge Under Temp
- Discharge OT Recover
- Discharge UT Recover
- Internal Over Tmp  //Internal Over-Temperature Voltage Limit
- Internal OT Recover

- Enable Open Wire PSD
- Enbal UVLO Power Down
- Disable Open Wire Scan
- xT2 Monitors FET Temp
- Enable CELLF PSD action