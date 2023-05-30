#include "bms.h"
#include "isl94202.h"

void bms_set_num_cells(uint8_t num)
{
    isl94202_setCellSelect(num);
}