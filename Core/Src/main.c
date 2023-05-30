#include "main.h"
#include "board.h"
#include "isl94202.h"
#include <stdio.h>

int main(void)
{
    uint8_t data = 0;
    uint16_t data2 = 0;
    board_init();
    printf("\nStart Program!\n");
    //read_register_list();
    //data = isl94202_readEEPROMAccess();
    //printf("\nstart: %d\n", data);

    //isl94202_enableEEPROMAccess();
    //data = isl94202_readEEPROMAccess();
    //printf("\nenable: %d\n", data);

    //isl94202_disableEEPROMAccess();
    //data = isl94202_readEEPROMAccess();
    //printf("\ndisable: %d\n", data);

    //data2 = isl94202_getOverVoltageThreshold();
    //printf("rgo: %04x\n", data2);


    while (1)
    {
        led_toggle();
        HAL_Delay(1000);
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
