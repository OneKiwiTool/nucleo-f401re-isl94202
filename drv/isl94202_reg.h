#ifndef ISL94202_REG_H_
#define ISL94202_REG_H_

#include <stdint.h>

// RAM registers

static const uint16_t OCD_Thresholds[] = { 4, 8, 16, 24, 32, 48, 64, 96 }; // mV

static const uint16_t OCC_Thresholds[] = { 1, 2, 4, 6, 8, 12, 16, 24 }; // mV

static const uint16_t DSC_Thresholds[] = { 16, 24, 32, 48, 64, 96, 128, 256 }; // mV

static const uint16_t ISL94202_Current_Gain[] = { 50, 5, 500, 500 };

// Scale Value for delay times (first 2 bytes)
#define ISL94202_DELAY_US  (0U)
#define ISL94202_DELAY_MS  (1U)
#define ISL94202_DELAY_S   (2U)
#define ISL94202_DELAY_MIN (3U)

// Configuration Registers

// Overvoltage Threshold
// Charge Detect Pulse Width
#define REG_ISL94202_COV                0x00
#define ISL94202_COV                    0x0 // Overvoltage Threshold
#define ISL94202_COV_MASK               (0xFFF << ISL94202_COV)
#define ISL94202_CPW                    0x4 // Charge Detect Pulse-Width
#define ISL94202_CPW_MASK               (0xF << ISL94202_CPW)

// Overvoltage Recovery Threshold 
#define REG_ISL94202_OVR                0x02
#define ISL94202_OVR                    0x0
#define ISL94202_OVR_MASK               (0xFFF << ISL94202_OVR)

// Undervoltage Threshold
#define REG_ISL94202_UVL                0x04
#define ISL94202_UVL                    0x0 // Undervoltage Threshold
#define ISL94202_UVL_MASK               (0xFFF << ISL94202_UVL)
#define ISL94202_LPW                    0x4 // Load Detect Pulse Width
#define ISL94202_LPW_MASK               (0xF << ISL94202_LPW)

// Undervoltage Recovery Threshold
#define REG_ISL94202_UVR                0x06
#define ISL94202_UVR                    0x0
#define ISL94202_UVR_MASK               (0xFFF << ISL94202_UVR)

// Overvoltage Lockout Threshold
#define REG_ISL94202_OVLO               0x08
#define ISL94202_OVLO                   0x0
#define ISL94202_OVLO_MASK              (0xFFF << ISL94202_OVLO)

// Undervoltage Lockout Threshold
#define REG_ISL94202_UVLO               0x0A
#define ISL94202_UVLO                   0x0
#define ISL94202_UVLO_MASK              (0xFFF << ISL94202_UVLO)

//End-of-Charge Threshold EOC
#define REG_ISL94202_EOC                0x0C
#define ISL94202_EOC                    0x0
#define ISL94202_EOC_MASK               (0xFFF << ISL94202_EOC)

// Low Voltage Charge Level
#define REG_ISL94202_LVCL               0x0E
#define ISL94202_LVCL                   0x0
#define ISL94202_LVCL_MASK              (0xFFF << ISL94202_LVCL)

// Overvoltage Delay Timer
#define REG_ISL94202_OVDT               0x10
#define ISL94202_OVDT                   0x0 // Overvoltage Delay Timer
#define ISL94202_OVDT_MASK              (0x3FF << ISL94202_OVDT)
#define ISL94202_OVDTU                  0x2 // Overvoltage Delay Timer Unit
#define ISL94202_OVDTU_MASK             (0x3 << ISL94202_OVDTU)

// Undervoltage Delay Time
#define REG_ISL94202_UVDT               0x12
#define ISL94202_UVDT                   0x0 // Undervoltage Delay Time
#define ISL94202_UVDT_MASK              (0x3FF << ISL94202_UVDT)
#define ISL94202_UVDTU                  0x2 // Undervoltage Delay Time Unit
#define ISL94202_UVDTU_MASK             (0x3 << ISL94202_UVDTU)

// Open-Wire Timing
#define REG_ISL94202_OWT                0x14
#define ISL94202_OWT                    0x0 // Open-Wire Timing
#define ISL94202_OWT_MASK               (0x1FF << ISL94202_OWT)
#define ISL94202_OWTU                   0x1 // Open-Wire Timing Unit
#define ISL94202_OWTU_MASK              (0x1 << ISL94202_OWTU)

// Discharge Overcurrent Timer
#define REG_ISL94202_DOCT               0x16
#define ISL94202_DOCT                   0x0 // Discharge Overcurrent Timer
#define ISL94202_DOCT_MASK              (0x3FF << ISL94202_DOCT)
#define ISL94202_DOCTU                  0x2 // Discharge Overcurrent Timer Unit
#define ISL94202_DOCTU_MASK             (0x3 << ISL94202_DOCTU)
#define ISL94202_DOC                    0x4 // Discharge Overcurrent Threshold
#define ISL94202_DOC_MASK               (0x7 << ISL94202_DOC)

// Charge Overcurrent Timer
#define REG_ISL94202_COCT               0x18
#define ISL94202_COCT                   0x0 // Discharge Overcurrent Timer
#define ISL94202_COCT_MASK              (0x3FF << ISL94202_COCT)
#define ISL94202_COCTU                  0x2 // Discharge Overcurrent Timer Unit
#define ISL94202_COCTU_MASK             (0x3 << ISL94202_COCTU)
#define ISL94202_COC                    0x4 // Discharge Overcurrent Threshold
#define ISL94202_COC_MASK               (0x7 << ISL94202_COC)

// Discharge Short-Circuit Timer
#define REG_ISL94202_DSCT               0x1A
#define ISL94202_DSCT                   0x0 // Discharge Overcurrent Timer
#define ISL94202_DSCT_MASK              (0x3FF << ISL94202_DSCT)
#define ISL94202_DSCTU                  0x2 // Discharge Overcurrent Timer Unit
#define ISL94202_DSCTU_MASK             (0x3 << ISL94202_DSCTU)
#define ISL94202_COC                    0x4 // Discharge Overcurrent Threshold
#define ISL94202_COC_MASK               (0x7 << ISL94202_COC)

// Cell Balance Minimum Voltage
#define REG_ISL94202_CBMIN              0x1C
#define ISL94202_CBMIN                  0x0
#define ISL94202_CBMIN_MASK             (0xFFF << ISL94202_CBMIN)

// Cell Balance Maximum Voltage
#define REG_ISL94202_CBMAX              0x1E
#define ISL94202_CBMAX                  0x0
#define ISL94202_CBMAX_MASK             (0xFFF << ISL94202_CBMAX)

// Cell Balance Minimum Delta Voltage
#define REG_ISL94202_CBMIND             0x20
#define ISL94202_CBMIND                 0x0
#define ISL94202_CBMIND_MASK            (0xFFF << ISL94202_CBMIND)

// Cell Balance Maximum Delta Voltage
#define REG_ISL94202_CBMAXD             0x22
#define ISL94202_CBMAXD                 0x0
#define ISL94202_CBMAXD_MASK            (0xFFF << ISL94202_CBMAXD)

//  Cell Balance On-Time
#define REG_ISL94202_CBON               0x24
#define ISL94202_CBON                   0x0 // Cell Balance On Time
#define ISL94202_CBON_MASK              (0x3FF << ISL94202_CBON)
#define ISL94202_CBONU                  0x2 // Cell Balance On Time Unit
#define ISL94202_CBONU_MASK             (0x3 << ISL94202_CBONU)

// Cell Balance Off-Time
#define REG_ISL94202_CBOFF              0x26
#define ISL94202_CBOFF                  0x0 // Cell Balance Off Time
#define ISL94202_CBOFF_MASK             (0x3FF << ISL94202_CBOFF)
#define ISL94202_CBOFFU                 0x2 // Cell Balance Off Time Unit
#define ISL94202_CBOFFU_MASK            (0x3 << ISL94202_CBOFFU)

// Cell Balance Under-Temperature Limit
#define REG_ISL94202_CBUT               0x28
#define ISL94202_CBUT                   0x0
#define ISL94202_CBUT_MASK              (0xFFF << ISL94202_CBUT)

// Cell Balance Under-Temperature Recovery Level
#define REG_ISL94202_CBUTR              0x2A
#define ISL94202_CBUTR                  0x0
#define ISL94202_CBUTR_MASK             (0xFFF << ISL94202_CBUTR)

// Cell Balance Over-Temperature Limit
#define REG_ISL94202_CBOT               0x2C
#define ISL94202_CBOT                   0x0
#define ISL94202_CBOT_MASK              (0xFFF << ISL94202_CBOT)

// Cell Balance Over-Temperature Recovery Level
#define REG_ISL94202_CBOTR              0x2E
#define ISL94202_CBOTR                  0x0
#define ISL94202_CBOTR_MASK             (0xFFF << ISL94202_CBOTR)

// Charge Over-Temperature Limit
#define REG_ISL94202_COT                0x30
#define ISL94202_COT                    0x0
#define ISL94202_COT_MASK               (0xFFF << ISL94202_COT)

// Charge Over-Temperature Recovery Level
#define REG_ISL94202_COTR               0x32
#define ISL94202_COTR                   0x0
#define ISL94202_COTR_MASK              (0xFFF << ISL94202_COTR)

// Charge Under-Temperature Limit
#define REG_ISL94202_CUT                0x34
#define ISL94202_CUT                    0x0
#define ISL94202_CUT_MASK               (0xFFF << ISL94202_CUT)

// Charge Under-Temperature Recovery Level
#define REG_ISL94202_CUTR               0x36
#define ISL94202_CUTR                   0x0
#define ISL94202_CUTR_MASK              (0xFFF << ISL94202_CUTR)

// Discharge Over-Temperature Voltage
#define REG_ISL94202_DOT                0x38
#define ISL94202_DOT                    0x0
#define ISL94202_DOT_MASK               (0xFFF << ISL94202_DOT)

// Discharge Over-Temperature Recovery Level
#define REG_ISL94202_DOTR               0x3A
#define ISL94202_DOTR                   0x0
#define ISL94202_DOTR_MASK              (0xFFF << ISL94202_DOTR)

// Discharge Under-Temperature Limit
#define REG_ISL94202_DUT                0x3C
#define ISL94202_DUT                    0x0
#define ISL94202_DUT_MASK               (0xFFF << ISL94202_DUT)

// Discharge Under-Temperature Recovery Voltage
#define REG_ISL94202_DUTR               0x3E
#define ISL94202_DUTR                   0x0
#define ISL94202_DUTR_MASK              (0xFFF << ISL94202_DUTR)

// Internal Over-Temperature Voltage Limit  
#define REG_ISL94202_IOT                0x40
#define ISL94202_IOT                    0x0
#define ISL94202_IOT_MASK               (0xFFF << ISL94202_IOT)

// Internal Over-Temperature Recovery Voltage
#define REG_ISL94202_IOTR               0x42
#define ISL94202_IOTR                   0x0
#define ISL94202_IOTR_MASK              (0xFFF << ISL94202_IOTR)

// Sleep Level Voltage
#define REG_ISL94202_SLV                0x44
#define ISL94202_SLV                    0x0
#define ISL94202_SLV_MASK               (0xFFF << ISL94202_SLV)

// Watchdog Timer and Sleep Delay Timer
#define REG_ISL94202_SLT_WDT            0x46
#define ISL94202_SLT_WDT_SLT            0x0 // Sleep Level Timer
#define ISL94202_SLT_WDT_SLT_MASK       (0x1FF << ISL94202_SLT_WDT_SLT)
#define ISL94202_SLT_WDT_SDTU           0x1 // Sleep Level Timer Unit selection
#define ISL94202_SLT_WDT_SDTU_MASK      (0x3 << ISL94202_SLT_WDT_SDTU)
#define ISL94202_SLT_WDT_SDTU           0x3 // Watchdog Timer prevents
#define ISL94202_SLT_WDT_SDTU_MASK      (0x1F << ISL94202_SLT_WDT_SDTU)

// Cell Select (Enable) - R/W
#define REG_ISL94202_MODE_TIMER         0x48
#define ISL94202_MOD_DOZE               0x0 // IDLE/DOZE Timer
#define ISL94202_MOD_DOZE_MASK          (0xF << ISL94202_MOD_DOZE)
#define ISL94202_MOD_SLEEP              0x4 // SLEEP Timer
#define ISL94202_MOD_SLEEP_MASK         (0xF << ISL94202_MOD_SLEEP)

// Cell Select (Enable) - R/W
#define REG_ISL94202_CELL_SEL           0x49

// Setup 0 - R/W
#define REG_ISL94202_SETUP0             0x4A
#define ISL94202_SETUP0_OWPSD           0x0 // Open Wire Pack Shutdown
#define ISL94202_SETUP0_OWPSD_MASK      (0x1 << ISL94202_SETUP0_OWPSD)
#define ISL94202_SETUP0_DOWD            0x1 // Disable Open Wire Detection
#define ISL94202_SETUP0_DOWD_MASK       (0x1 << ISL94202_SETUP0_DOWD)
#define ISL94202_SETUP0_PCFETE          0x2 // Pre-Charge FET Enable
#define ISL94202_SETUP0_PCFETE_MASK     (0x1 << ISL94202_SETUP0_PCFETE)
#define ISL94202_SETUP0_TGAIN           0x4 // Temperature Gain
#define ISL94202_SETUP0_TGAIN_MASK      (0x1 << ISL94202_SETUP0_TGAIN)
#define ISL94202_SETUP0_XT2M            0x5 //  Second External Temperature Monitor
#define ISL94202_SETUP0_XT2M_MASK       (0x1 << ISL94202_SETUP0_XT2M)
#define ISL94202_SETUP0_CFPSD           0x7 // Cell Fail Pack Shutdown
#define ISL94202_SETUP0_CFPSD_MASK      (0x1 << ISL94202_SETUP0_CFPSD)

// Setup 1 - R/W
#define REG_ISL94202_SETUP1             0x4B
#define ISL94202_SETUP1_CB_EOC          0x0 // Cell Balance During End-of-Charge
#define ISL94202_SETUP1_CB_EOC_MASK     (0x1 << ISL94202_SETUP1_CB_EOC)
#define ISL94202_SETUP1_UVLOPD          0x3 // Undervoltage Lockout Powerdown
#define ISL94202_SETUP1_UVLOPD_MASK     (0x1 << ISL94202_SETUP1_UVLOPD)
#define ISL94202_SETUP1_DFODOV          0x4 // CFET On During Overvoltage
#define ISL94202_SETUP1_DFODOV_MASK     (0x1 << ISL94202_SETUP1_DFODOV)
#define ISL94202_SETUP1_DFODUV          0x5 // DFET On During Undervoltage
#define ISL94202_SETUP1_DFODUV_MASK     (0x1 << ISL94202_SETUP1_DFODUV)
#define ISL94202_SETUP1_CBDC            0x6 // Cell Balance During Charge
#define ISL94202_SETUP1_CBDC_MASK       (0x1 << ISL94202_SETUP1_CBDC)
#define ISL94202_SETUP1_CBDD            0x7 // Cell Balance During Discharge
#define ISL94202_SETUP1_CBDD_MASK       (0x1 << ISL94202_SETUP1_CBDD)

// Operations Registers
// Status 0 - R
#define REG_ISL94202_STATUS0            0x80
#define ISL94202_STATUS0_OVF            0x0 // Overvoltage Fault
#define ISL94202_STATUS0_OVF_MASK       (0x1 << ISL94202_STATUS0_OVF)
#define ISL94202_STATUS0_OVLOF          0x1 // Overvoltage Lockout Fault
#define ISL94202_STATUS0_OVLOF_MASK     (0x1 << ISL94202_STATUS0_OVLOF)
#define ISL94202_STATUS0_UVF            0x2 // Undervoltage Fault
#define ISL94202_STATUS0_UVF_MASK       (0x1 << ISL94202_STATUS0_UVF)
#define ISL94202_STATUS0_UVLOF          0x3 // Undervoltage Lockout Fault
#define ISL94202_STATUS0_UVLOF_MASK     (0x1 << ISL94202_STATUS0_UVLOF)
#define ISL94202_STATUS0_DOTF           0x4 // Discharge Over-Temperature Fault
#define ISL94202_STATUS0_DOTF_MASK      (0x1 << ISL94202_STATUS0_DOTF)
#define ISL94202_STATUS0_DUTF           0x5 // Discharge Under-Temperature Fault
#define ISL94202_STATUS0_DUTF_MASK      (0x1 << ISL94202_STATUS0_DUTF)
#define ISL94202_STATUS0_COTF           0x6 // Charge Over-Temperature Fault
#define ISL94202_STATUS0_COTF_MASK      (0x1 << ISL94202_STATUS0_COTF)
#define ISL94202_STATUS0_CUTF           0x7 // Charge Under-Temperature Fault
#define ISL94202_STATUS0_CUTF_MASK      (0x1 << ISL94202_STATUS0_CUTF)

// Status 1 - R
#define REG_ISL94202_STATUS1            0x81
#define ISL94202_STATUS1_IOTF           0x0 // Internal Over-Temperature Fault
#define ISL94202_STATUS1_IOTF_MASK      (0x1 << ISL94202_STATUS1_IOTF)
#define ISL94202_STATUS1_COCF           0x1 // Charge Overcurrent Fault
#define ISL94202_STATUS1_COCF_MASK      (0x1 << ISL94202_STATUS1_COCF)
#define ISL94202_STATUS1_DOCF           0x2 // Discharge Overcurrent Fault
#define ISL94202_STATUS1_DOCF_MASK      (0x1 << ISL94202_STATUS1_DOCF)
#define ISL94202_STATUS1_DSCF           0x3 // Discharge Short Circuit Fault
#define ISL94202_STATUS1_DSCF_MASK      (0x1 << ISL94202_STATUS1_DSCF)
#define ISL94202_STATUS1_CELLF          0x4 // Cell Fail Fault
#define ISL94202_STATUS1_CELLF_MASK     (0x1 << ISL94202_STATUS1_CELLF)
#define ISL94202_STATUS1_OPENF          0x5 // Open-Wire Fault
#define ISL94202_STATUS1_OPENF_MASK     (0x1 << ISL94202_STATUS1_OPENF)
#define ISL94202_STATUS1_VEOC           0x7 // Voltage End-of-Charge 
#define ISL94202_STATUS1_VEOC_MASK      (0x1 << ISL94202_STATUS1_VEOC)

// Status 2 - R
#define REG_ISL94202_STATUS2            0x82
#define ISL94202_STATUS_LDPRSNT         0x0 // Load Present
#define ISL94202_STATUS_LDPRSNT_MASK    (0x1 << ISL94202_STATUS_LDPRSNT)
#define ISL94202_STATUS_CHPRSNT         0x1 // Charger Present
#define ISL94202_STATUS_CHPRSNT_MASK    (0x1 << ISL94202_STATUS_CHPRSNT)
#define ISL94202_STATUS_CHING           0x2 // Charging
#define ISL94202_STATUS_CHING_MASK      (0x1 << ISL94202_STATUS_CHING)
#define ISL94202_STATUS_DCHING          0x3 // Discharging
#define ISL94202_STATUS_DCHING_MASK     (0x1 << ISL94202_STATUS_DCHING)
#define ISL94202_STATUS_ECCUSED         0x4 // ECC_USED
#define ISL94202_STATUS_ECCUSED_MASK    (0x1 << ISL94202_STATUS_ECCUSED)
#define ISL94202_STATUS_ECCFAIL         0x5 // ECC_FAIL
#define ISL94202_STATUS_ECCFAIL_MASK    (0x1 << ISL94202_STATUS_ECCFAIL)
#define ISL94202_STATUS_INTSCAN         0x6 // Internal Scan
#define ISL94202_STATUS_INTSCAN_MASK    (0x1 << ISL94202_STATUS_INTSCAN)
#define ISL94202_STATUS_LVCHG           0x7 // Low Voltage Charge
#define ISL94202_STATUS_LVCHG_MASK      (0x1 << ISL94202_STATUS_LVCHG)

// Status 3 - R
#define REG_ISL94202_STATUS3            0x83
#define ISL94202_STATUS3_CBOT           0x0 // Cell Balance Over-Temperature Fault
#define ISL94202_STATUS3_CBOT_MASK      (0x1 << ISL94202_STATUS3_CBOT)
#define ISL94202_STATUS3_CBUT           0x1 // Cell Balance Under-Temperature Fault
#define ISL94202_STATUS3_CBUT_MASK      (0x1 << ISL94202_STATUS3_CBUT)
#define ISL94202_STATUS3_CBOV           0x2 // Cell Balance Overvoltage
#define ISL94202_STATUS3_CBOV_MASK      (0x1 << ISL94202_STATUS3_CBOV)
#define ISL94202_STATUS3_CBUV           0x3 // Cell Balance Undervoltage
#define ISL94202_STATUS3_CBUV_MASK      (0x1 << ISL94202_STATUS3_CBUV)
#define ISL94202_STATUS3_INIDLE         0x4 // In IDLE Mode
#define ISL94202_STATUS3_INIDLE_MASK    (0x1 << ISL94202_STATUS3_INIDLE)
#define ISL94202_STATUS3_INDOZE         0x5 // In DOZE Mode
#define ISL94202_STATUS3_INDOZE_MASK    (0x1 << ISL94202_STATUS3_INDOZE)
#define ISL94202_STATUS3_INSLEEP        0x6 // In SLEEP Mode
#define ISL94202_STATUS3_INSLEEP_MASK   (0x1 << ISL94202_STATUS3_INSLEEP)

// Cell Balance FET Control CBFC - R/W
#define REG_ISL94202_CBFC               0x84

// Control 0 - R/W
#define REG_ISL94202_CONTROL0           0x85
#define ISL94202_CONTROL0_AO            0x0 // Analog Output selection
#define ISL94202_CONTROL0_AO_MASK       (0xF << ISL94202_CONTROL0_AO)
#define ISL94202_CONTROL0_CG            0x4 // Current Gain setting
#define ISL94202_CONTROL0_CG_MASK       (0x3 << ISL94202_CONTROL0_CG)
#define ISL94202_CONTROL0_ADCSTRT       0x6 // ADC conversion start
#define ISL94202_CONTROL0_ADCSTRT_MASK  (0x1 << ISL94202_CONTROL0_ADCSTRT)

// Control 1 - R/W
#define REG_ISL94202_CONTROL1           0x86
#define ISL94202_CONTROL1_DFET          0x0 // Discharge FET
#define ISL94202_CONTROL1_DFET_MASK     (0x1 << ISL94202_CONTROL1_DFET)
#define ISL94202_CONTROL1_CFET          0x1 // Charge FET
#define ISL94202_CONTROL1_CFET_MASK     (0x1 << ISL94202_CONTROL1_CFET)
#define ISL94202_CONTROL1_PCFET         0x2 // Pre-Charge FET
#define ISL94202_CONTROL1_PCFET_MASK    (0x1 << ISL94202_CONTROL1_PCFET)
#define ISL94202_CONTROL1_PSD           0x3 // Pack Shutdown
#define ISL94202_CONTROL1_PSD_MASK      (0x1 << ISL94202_CONTROL1_PSD)
#define ISL94202_CONTROL1_CMONEN        0x4 // Charger Monitor Enable
#define ISL94202_CONTROL1_CMONEN_MASK   (0x1 << ISL94202_CONTROL1_CMONEN)
#define ISL94202_CONTROL1_CLRCERR       0x5 // Clear Charger Error
#define ISL94202_CONTROL1_CLRCERR_MASK  (0x1 << ISL94202_CONTROL1_CLRCERR)
#define ISL94202_CONTROL1_LMONEN        0x6 // Load Monitor Enable
#define ISL94202_CONTROL1_LMONEN_MASK   (0x1 << ISL94202_CONTROL1_LMONEN)
#define ISL94202_CONTROL1_CLRLERR       0x7 //  Clear Load Error
#define ISL94202_CONTROL1_CLRLERR_MASK  (0x1 << ISL94202_CONTROL1_CLRLERR)

// Control 2 - R/W
#define REG_ISL94202_CONTROL2           0x87
#define ISL94202_CONTRO2_CBAL_ON        0x0 // Cell Balance on
#define ISL94202_CONTRO2_CBAL_ON_MASK   (0x1 << ISL94202_CONTRO2_CBAL_ON)
#define ISL94202_CONTRO2_OW_STRT        0x1 // Open Wire Start
#define ISL94202_CONTRO2_OW_STRT_MASK   (0x1 << ISL94202_CONTRO2_OW_STRT)
#define ISL94202_CONTRO2_UCSCAN         0x2 // MCU System Scan
#define ISL94202_CONTRO2_UCSCAN_MASK    (0x1 << ISL94202_CONTRO2_UCSCAN)
#define ISL94202_CONTRO2_UCCMON         0x3 // MCU Charger Monitoring
#define ISL94202_CONTRO2_UCCMON_MASK    (0x1 << ISL94202_CONTRO2_UCCMON)
#define ISL94202_CONTRO2_UCLMON         0x4 // MCU Load Monitoring
#define ISL94202_CONTRO2_UCLMON_MASK    (0x1 << ISL94202_CONTRO2_UCLMON)
#define ISL94202_CONTRO2_UCCBAL         0x5 // MCU Cell Balancing
#define ISL94202_CONTRO2_UCCBAL_MASK    (0x1 << ISL94202_CONTRO2_UCCBAL)
#define ISL94202_CONTRO2_UCFET          0x6 // MCU FET control
#define ISL94202_CONTRO2_UCFET_MASK     (0x1 << ISL94202_CONTRO2_UCFET)

// Control 3 - R/W
#define REG_ISL94202_CONTROL3           0x88
#define ISL94202_CONTRO3_IDLE           0x0 // IDLE
#define ISL94202_CONTRO3_IDLE_MASK      (0x1 << ISL94202_CONTRO3_IDLE)
#define ISL94202_CONTRO3_DOZE           0x1 // DOZE
#define ISL94202_CONTRO3_DOZE_MASK      (0x1 << ISL94202_CONTRO3_DOZE)
#define ISL94202_CONTRO3_SLEEP          0x2 // SLEEP
#define ISL94202_CONTRO3_SLEEP_MASK     (0x1 << ISL94202_CONTRO3_SLEEP)
#define ISL94202_CONTRO3_PDWN           0x3 // Powerdown
#define ISL94202_CONTRO3_PDWN_MASK      (0x1 << ISL94202_CONTRO3_PDWN)

// EEPROM Enable - R/W
#define REG_ISL94202_EEPROM             0x89

// Data Registers
#define REG_ISL94202_CELLMIN            0x8A    // Minimum Cell Voltage CELMIN - R
#define REG_ISL94202_CELLMAX            0x8C    // Maximum Cell Voltage CELMAX - R
#define REG_ISL94202_IPACK              0x8E    // Pack Current IPACK -R
#define REG_ISL94202_CELL1              0x90    // Cell 1 Voltage VCELL1 - R 
#define REG_ISL94202_CELL2              0x92    // Cell 2 Voltage VCELL2 - R 
#define REG_ISL94202_CELL3              0x94    // Cell 3 Voltage VCELL3 - R 
#define REG_ISL94202_CELL4              0x96    // Cell 4 Voltage VCELL4 - R 
#define REG_ISL94202_CELL5              0x98    // Cell 5 Voltage VCELL5 - R 
#define REG_ISL94202_CELL6              0x9A    // Cell 6 Voltage VCELL6 - R 
#define REG_ISL94202_CELL7              0x9C    // Cell 7 Voltage VCELL7 - R 
#define REG_ISL94202_CELL8              0x9E    // Cell 8 Voltage VCELL8 - R 
#define REG_ISL94202_IT                 0xA0    // Internal Temperature IT - R 
#define REG_ISL94202_XT1                0xA2    // External Temperature 1 XT1 - R 
#define REG_ISL94202_XT2                0xA4    // External Temperature 2 XT2- R 
#define REG_ISL94202_VBATT              0xA6    // Pack Voltage VBATT - R 
#define REG_ISL94202_VRGO               0xA8    // RGO Voltage VRGO - R 
#define REG_ISL94202_ADC                0xAA    // 14-bit ADC Voltage ADC - R 

#endif /* ISL94202_REG_H_ */
