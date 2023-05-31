#ifndef BMS_H_
#define BMS_H_

#include <stdint.h>
#include <stdbool.h>
#include "bms_config.h"

/**
 * Possible BMS states
 */
enum BmsState
{
    BMS_STATE_OFF,      ///< Off state (charging and discharging disabled)
    BMS_STATE_CHG,      ///< Charging state (discharging disabled)
    BMS_STATE_DIS,      ///< Discharging state (charging disabled)
    BMS_STATE_NORMAL,   ///< Normal operating mode (both charging and discharging enabled)
    BMS_STATE_SHUTDOWN, ///< BMS starting shutdown sequence
};

/**
 * Battery cell types
 */
enum CellType
{
    CELL_TYPE_CUSTOM = 0, ///< Custom settings
    CELL_TYPE_LFP,        ///< LiFePO4 Li-ion cells (3.3 V nominal)
    CELL_TYPE_NMC,        ///< NMC/Graphite Li-ion cells (3.7 V nominal)
    CELL_TYPE_NMC_HV,     ///< NMC/Graphite High Voltage Li-ion cells (3.7 V nominal, 4.35 V max)
    CELL_TYPE_LTO         ///< NMC/Titanate (2.4 V nominal)
};

/**
 * BMS configuration values, stored in RAM. The configuration is not automatically applied after
 * values are changed!
 */
typedef struct
{
    /// Effective resistance of the current measurement shunt(s) on the PCB (milli-Ohms)
    float shunt_res_mOhm;

    /// Beta value of the used thermistor. Typical value for Semitec 103AT-5 thermistor: 3435
    uint16_t thermistor_beta;

    /// \brief Pointer to an array containing the Open Circuit Voltage of the cell vs. SOC.
    /// SOC must be equally spaced in descending order (100%, 95%, ..., 5%, 0%)
    float *ocv;

    float nominal_capacity_Ah; ///< Nominal capacity of battery pack (Ah)

    // Current limits
    float dis_sc_limit;       ///< Discharge short circuit limit (A)
    uint32_t dis_sc_delay_us; ///< Discharge short circuit delay (us)
    float dis_oc_limit;       ///< Discharge over-current limit (A)
    uint32_t dis_oc_delay_ms; ///< Discharge over-current delay (ms)
    float chg_oc_limit;       ///< Charge over-current limit (A)
    uint32_t chg_oc_delay_ms; ///< Charge over-current delay (ms)

    // Cell voltage limits
    float cell_chg_voltage;    ///< Cell target charge voltage (V)
    float cell_dis_voltage;    ///< Cell discharge voltage limit (V)
    float cell_ov_limit;       ///< Cell over-voltage limit (V)
    float cell_ov_reset;       ///< Cell over-voltage error reset threshold (V)
    uint32_t cell_ov_delay_ms; ///< Cell over-voltage delay (ms)
    float cell_uv_limit;       ///< Cell under-voltage limit (V)
    float cell_uv_reset;       ///< Cell under-voltage error reset threshold (V)
    uint32_t cell_uv_delay_ms; ///< Cell under-voltage delay (ms)

    // Temperature limits (°C)
    float dis_ot_limit; ///< Discharge over-temperature (DOT) limit (°C)
    float dis_ut_limit; ///< Discharge under-temperature (DUT) limit (°C)
    float chg_ot_limit; ///< Charge over-temperature (COT) limit (°C)
    float chg_ut_limit; ///< Charge under-temperature (CUT) limit (°C)
    float t_limit_hyst; ///< Temperature limit hysteresis (°C)

    // Balancing settings
    float bal_cell_voltage_diff; ///< Balancing cell voltage target difference (V)
    float bal_cell_voltage_min;  ///< Minimum cell voltage to start balancing (V)
    float bal_idle_current;      ///< Current threshold to be considered idle (A)
    uint16_t bal_idle_delay;     ///< Minimum idle duration before balancing (s)
} BmsConfig;

/**
 * Current BMS status including measurements and error flags
 */
typedef struct
{
    uint16_t state;  ///< Current state of the battery
    bool chg_enable; ///< Manual enable/disable setting for charging
    bool dis_enable; ///< Manual enable/disable setting for discharging

    uint16_t connected_cells; ///< \brief Actual number of cells connected (might
                              ///< be less than BOARD_NUM_CELLS_MAX)

    float cell_voltages[BMS_NUM_CELLS]; ///< Single cell voltages (V)
    float cell_voltage_max;                   ///< Maximum cell voltage (V)
    float cell_voltage_min;                   ///< Minimum cell voltage (V)
    float cell_voltage_avg;                   ///< Average cell voltage (V)
    float pack_voltage;                       ///< Battery external pack voltage (V)
    float stack_voltage;                      ///< Battery internal stack voltage (V)

    float pack_current; ///< \brief Battery pack current, charging direction
                        ///< has positive sign (A)

    float bat_temps[BMS_NUM_THERMISTORS_MAX]; ///< Battery temperatures (°C)
    float bat_temp_max;                         ///< Maximum battery temperature (°C)
    float bat_temp_min;                         ///< Minimum battery temperature (°C)
    float bat_temp_avg;                         ///< Average battery temperature (°C)
    float mosfet_temp;                          ///< MOSFET temperature (°C)
    float ic_temp;                              ///< Internal BMS IC temperature (°C)
    float mcu_temp;                             ///< MCU temperature (°C)

    bool full;  ///< CV charging to cell_chg_voltage finished
    bool empty; ///< Battery is discharged below cell_dis_voltage

    float soc; ///< Calculated State of Charge (%)

    uint32_t balancing_status; ///< holds on/off status of balancing switches
    //time_t no_idle_timestamp;  ///< Stores last time of current > idle threshold

    uint32_t error_flags; ///< Bit array for different BmsErrorFlag errors
} BmsStatus2;

/**
 * BMS error flags
 */
enum BmsErrorFlag
{
    BMS_ERR_CELL_UNDERVOLTAGE = 0, ///< Cell undervoltage flag
    BMS_ERR_CELL_OVERVOLTAGE = 1,  ///< Cell undervoltage flag
    BMS_ERR_SHORT_CIRCUIT = 2,     ///< Pack short circuit (discharge direction)
    BMS_ERR_DIS_OVERCURRENT = 3,   ///< Pack overcurrent (discharge direction)
    BMS_ERR_CHG_OVERCURRENT = 4,   ///< Pack overcurrent (charge direction)
    BMS_ERR_OPEN_WIRE = 5,         ///< Cell open wire
    BMS_ERR_DIS_UNDERTEMP = 6,     ///< Temperature below discharge minimum limit
    BMS_ERR_DIS_OVERTEMP = 7,      ///< Temperature above discharge maximum limit
    BMS_ERR_CHG_UNDERTEMP = 8,     ///< Temperature below charge maximum limit
    BMS_ERR_CHG_OVERTEMP = 9,      ///< Temperature above charge maximum limit
    BMS_ERR_INT_OVERTEMP = 10,     ///< Internal temperature above limit (e.g. BMS IC)
    BMS_ERR_CELL_FAILURE = 11,     ///< Cell failure (too high voltage difference)
    BMS_ERR_DIS_OFF = 12,          ///< Discharge FET is off even though it should be on
    BMS_ERR_CHG_OFF = 13,          ///< Charge FET is off even though it should be on
    BMS_ERR_FET_OVERTEMP = 14,     ///< MOSFET temperature above limit
};

typedef struct
{
    BmsConfig conf;
    BmsStatus2 status;
} Bms2;

///////////////////

typedef struct
{
    uint16_t state;                                 // Current state of the battery
    uint32_t error_flags;                           // Bit array for different BmsErrorFlag errors

    uint16_t cell_voltages[BMS_NUM_CELLS];          // Single cell voltages (mV)
    uint16_t cell_voltage_max;                      // Maximum cell voltage (mV)
    uint16_t cell_voltage_min;                      // Minimum cell voltage (mV)
    uint16_t cell_voltage_avg;                      // Average cell voltage (mV)
    uint16_t pack_voltage;                          // Battery pack voltage (mV)
    uint16_t vrgo_voltage;                          // VRGO voltage (mV)
    uint16_t pack_current;                          // Battery pack current (mA)
    uint16_t adc_voltage;

} BmsStatus;

typedef struct
{
    BmsConfig conf;
    BmsStatus status;
} Bms;

void bms_setNumCells(uint8_t num);
void bms_getCurrent(Bms *bms);
void bms_getVoltages(Bms *bms);
void bms_getAdcVoltage(Bms *bms);
void bms_updateErrorFlags(Bms *bms);

#endif /* BMS_H_ */
