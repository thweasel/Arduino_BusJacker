EESchema Schematic File Version 4
LIBS:BusJacker-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "BUS Jacker"
Date ""
Rev ""
Comp "FujiNet"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74xx_IEEE:74164 U?
U 1 1 62A12EC5
P 7400 5450
F 0 "U?" H 7400 6016 50  0000 C CNN
F 1 "74164" H 7400 5925 50  0000 C CNN
F 2 "" H 7400 5450 50  0001 C CNN
F 3 "" H 7400 5450 50  0001 C CNN
	1    7400 5450
	-1   0    0    -1  
$EndComp
$Comp
L 74xx:74LS245 U?
U 1 1 62A1317B
P 5650 6650
F 0 "U?" H 5650 7628 50  0000 C CNN
F 1 "74LS245" H 5650 7537 50  0000 C CNN
F 2 "" H 5650 6650 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS245" H 5650 6650 50  0001 C CNN
	1    5650 6650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x27_Top_Bottom J?
U 1 1 62A13558
P 1350 5150
F 0 "J?" H 1400 6667 50  0000 C CNN
F 1 "Conn_02x27_Top_Bottom" H 1400 6576 50  0000 C CNN
F 2 "" H 1350 5150 50  0001 C CNN
F 3 "~" H 1350 5150 50  0001 C CNN
	1    1350 5150
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS138 U?
U 1 1 62A1D21F
P 8600 1400
F 0 "U?" H 8600 2178 50  0000 C CNN
F 1 "74LS138" H 8600 2087 50  0000 C CNN
F 2 "" H 8600 1400 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS138" H 8600 1400 50  0001 C CNN
	1    8600 1400
	-1   0    0    -1  
$EndComp
Entry Wire Line
	6300 6150 6400 6250
Entry Wire Line
	6300 6250 6400 6350
Entry Wire Line
	6300 6350 6400 6450
Entry Wire Line
	6300 6450 6400 6550
Entry Wire Line
	6300 6550 6400 6650
Entry Wire Line
	6300 6650 6400 6750
Entry Wire Line
	6300 6750 6400 6850
Entry Wire Line
	6300 6850 6400 6950
Wire Wire Line
	6150 6150 6300 6150
Wire Wire Line
	6300 6250 6150 6250
Wire Wire Line
	6150 6350 6300 6350
Wire Wire Line
	6300 6450 6150 6450
Wire Wire Line
	6150 6550 6300 6550
Wire Wire Line
	6300 6650 6150 6650
Wire Wire Line
	6150 6750 6300 6750
Wire Wire Line
	6300 6850 6150 6850
Entry Wire Line
	6400 4100 6500 4000
Entry Wire Line
	6400 4200 6500 4100
Entry Wire Line
	6400 4300 6500 4200
Entry Wire Line
	6400 4400 6500 4300
Entry Wire Line
	6400 4500 6500 4400
Entry Wire Line
	6400 4600 6500 4500
Entry Wire Line
	6400 4700 6500 4600
Entry Wire Line
	6400 4800 6500 4700
Wire Wire Line
	6500 4000 7800 4000
Wire Wire Line
	7800 4100 6500 4100
Text Notes 4000 1400 0    50   ~ 0
RegAddrHi_Out
Text Notes 2100 1400 0    50   ~ 0
RegAddrLo_Out
Text Notes 5700 6000 0    50   ~ 0
GateDataBus
Text GLabel 2750 3500 0    50   Input ~ 0
ZX_WR
Text GLabel 2750 3050 0    50   Input ~ 0
ZX_MEMRQ
Text GLabel 2750 3150 0    50   Input ~ 0
ZX_RD
Text GLabel 2750 2950 0    50   Input ~ 0
ZX_BUSRQ
Text GLabel 9400 4700 2    50   Input ~ 0
ESP_SRegBus_In_Data
Text GLabel 9400 5450 2    50   Input ~ 0
ESP_SRegBus_Out_Data
Text Notes 8700 950  0    50   ~ 0
Clock Control
Text Notes 8700 4300 1    50   ~ 0
SRegBus_In
Text Notes 7750 6150 1    50   ~ 0
SRegBus_Out\n
Text GLabel 9400 1100 2    50   Input ~ 0
ESP_CC_A0
Text GLabel 9400 1200 2    50   Input ~ 0
ESP_CC_A1
Text GLabel 9400 1600 2    50   Input ~ 0
ESP_CC_Pulse
Text GLabel 9400 1300 2    50   Input ~ 0
ESP_CC_A2
Wire Wire Line
	9100 1100 9400 1100
Wire Wire Line
	7950 5450 8550 5450
Wire Wire Line
	8900 4700 9400 4700
Text GLabel 9400 2400 2    50   Input ~ 0
ESP_SRegBus_In_ShiftLoad
Text Notes 9450 2700 0    50   ~ 0
Normally high (Shift) and low only \nto Load data, Shift/Load when pulsed \nfrom the Clock Control (1_CCAddr)
Wire Wire Line
	6500 4700 7800 4700
Wire Wire Line
	7800 4600 6500 4600
Wire Wire Line
	6500 4500 7800 4500
Wire Wire Line
	7800 4400 6500 4400
Wire Wire Line
	6500 4300 7800 4300
Wire Wire Line
	7800 4200 6500 4200
$Comp
L 74xx_IEEE:74166 U?
U 1 1 62AA37DC
P 8350 3900
F 0 "U?" H 8350 4766 50  0000 C CNN
F 1 "74166" H 8350 4675 50  0000 C CNN
F 2 "" H 8350 3900 50  0001 C CNN
F 3 "" H 8350 3900 50  0001 C CNN
	1    8350 3900
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS374 U?
U 1 1 62AF8F70
P 5450 3450
F 0 "U?" H 5450 4428 50  0000 C CNN
F 1 "74LS374" H 5450 4337 50  0000 C CNN
F 2 "" H 5450 3450 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS374" H 5450 3450 50  0001 C CNN
	1    5450 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8100 1200 6900 1200
Entry Wire Line
	6400 5600 6500 5500
Entry Wire Line
	6400 5750 6500 5650
Entry Wire Line
	6400 5850 6500 5750
Entry Wire Line
	6400 5950 6500 5850
Wire Wire Line
	6500 5500 6850 5500
Wire Wire Line
	6850 5650 6500 5650
Wire Wire Line
	6500 5750 6850 5750
Wire Wire Line
	6850 5850 6500 5850
Entry Wire Line
	6400 6050 6500 5950
Entry Wire Line
	6400 6150 6500 6050
Entry Wire Line
	6400 6250 6500 6150
Entry Wire Line
	6400 6350 6500 6250
Wire Wire Line
	6500 5950 6850 5950
Wire Wire Line
	6850 6050 6500 6050
Wire Wire Line
	6500 6150 6850 6150
Wire Wire Line
	6500 6250 6850 6250
Wire Wire Line
	6800 1100 8100 1100
Wire Wire Line
	8100 1500 6500 1500
Wire Wire Line
	9100 1600 9400 1600
Wire Wire Line
	9100 1200 9400 1200
Wire Wire Line
	9100 1300 9400 1300
Text GLabel 9400 2850 2    50   Input ~ 0
ESP_ControlLines_Enable
Text GLabel 9850 3800 0    50   Input ~ 0
ESP_Z80IO_WR_IRQ
Text GLabel 7600 1800 0    50   Input ~ 0
ESP_IO_RD
Text GLabel 9850 3900 0    50   Input ~ 0
ESP_Z80IO_RD_FLAG
Text GLabel 7600 1700 0    50   Input ~ 0
CCAddr_IO_WR
Wire Wire Line
	8100 1700 7600 1700
Text GLabel 10050 3800 2    50   Input ~ 0
ESP_Z80IO_IRQ
Text GLabel 10050 3900 2    50   Input ~ 0
ESP_IO_WRCLEAR
Wire Wire Line
	9850 3800 10050 3800
Wire Wire Line
	10050 3900 9850 3900
Text Notes 9400 1000 0    50   ~ 0
Clock control, select device address and \nthen send the pulse to trigger device actions
Text GLabel 2750 4350 0    50   Input ~ 0
ZX_IRQ
Text GLabel 2750 4050 0    50   Input ~ 0
ZX_NMI
Text GLabel 2750 4200 0    50   Input ~ 0
ZX_ROMCS
Text Notes 5550 2800 0    50   ~ 0
RegControlLines_Out
Text Label 6400 1100 1    50   ~ 0
ESP_BUS
Wire Wire Line
	9200 1700 9200 1800
Wire Wire Line
	9100 1800 9200 1800
$Comp
L power:GND #PWR?
U 1 1 62CEBAC0
P 9200 1700
F 0 "#PWR?" H 9200 1450 50  0001 C CNN
F 1 "GND" V 9205 1572 50  0000 R CNN
F 2 "" H 9200 1700 50  0001 C CNN
F 3 "" H 9200 1700 50  0001 C CNN
	1    9200 1700
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 62CEBBA6
P 7600 200
F 0 "#PWR?" H 7600 50  50  0001 C CNN
F 1 "+5V" H 7615 373 50  0000 C CNN
F 2 "" H 7600 200 50  0001 C CNN
F 3 "" H 7600 200 50  0001 C CNN
	1    7600 200 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 200  7600 800 
Wire Wire Line
	7600 800  8600 800 
Wire Wire Line
	7950 5300 8000 5300
Wire Wire Line
	8000 5050 8000 5300
$Comp
L power:+5V #PWR?
U 1 1 62CF9D79
P 9750 5200
F 0 "#PWR?" H 9750 5050 50  0001 C CNN
F 1 "+5V" H 9765 5373 50  0000 C CNN
F 2 "" H 9750 5200 50  0001 C CNN
F 3 "" H 9750 5200 50  0001 C CNN
	1    9750 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 62CF9DEC
P 9300 5200
F 0 "R?" V 9093 5200 50  0000 C CNN
F 1 "22K" V 9184 5200 50  0000 C CNN
F 2 "" V 9230 5200 50  0001 C CNN
F 3 "~" H 9300 5200 50  0001 C CNN
	1    9300 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 3900 7550 3900
Wire Wire Line
	9750 5200 9450 5200
Wire Wire Line
	9150 5200 8850 5200
Wire Wire Line
	7900 3350 7850 3350
Connection ~ 8850 5200
Wire Wire Line
	8850 5200 7950 5200
Wire Wire Line
	8550 5550 8550 5450
Connection ~ 8550 5450
Wire Wire Line
	8550 5450 9400 5450
Wire Wire Line
	7950 5550 8550 5550
Text Label 8100 1100 2    50   ~ 0
0_CCAddr_SRegBus_Out
Text Label 8100 1200 2    50   ~ 0
1_CCAddr_SRegBus_In
Wire Wire Line
	8850 3200 8850 5200
Wire Wire Line
	8850 3200 7850 3200
Wire Wire Line
	7850 3200 7850 3350
Text Notes 9450 1550 0    50   ~ 0
CC_Pulse Normally low, pulsed high\n
Text Label 7800 4000 2    50   ~ 0
BUS_D0
Text Label 6850 5500 2    50   ~ 0
BUS_D0
Text Label 8100 1400 2    50   ~ 0
3_CCAddr_RegAddrHi_Out
Text Label 8100 1300 2    50   ~ 0
2_CCAddr_RegAddrLo_Out
Wire Wire Line
	7600 1800 8100 1800
$Comp
L Diode:1N4148 D?
U 1 1 62B637B4
P 4200 7000
F 0 "D?" H 4200 6784 50  0000 C CNN
F 1 "1N4148" H 4200 6875 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4200 6825 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 4200 7000 50  0001 C CNN
	1    4200 7000
	0    -1   -1   0   
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 62B6385C
P 4400 7000
F 0 "D?" H 4400 6784 50  0000 C CNN
F 1 "1N4148" H 4400 6875 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4400 6825 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 4400 7000 50  0001 C CNN
	1    4400 7000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2750 3150 2850 3150
Text Label 8100 1600 2    50   ~ 0
5_CCAddr_Host
Text Label 8100 1500 2    50   ~ 0
4_CCAddr_RegControlLines_Out
Text Label 4950 3250 2    50   ~ 0
CL_WR
Text Label 4950 3150 2    50   ~ 0
CL_RD
Text Label 4950 3050 2    50   ~ 0
CL_MEMRQ
Text Label 4950 2950 2    50   ~ 0
CL_BUSRQ
Text Label 5900 3850 0    50   ~ 0
CCAddr_RegControlLines_Out
Text Label 8300 2850 0    50   ~ 0
ESP_ControlLines_Enable
Text Label 5900 3950 0    50   ~ 0
ESP_ControlLines_Enable
$Comp
L 74xx:74LS374 U?
U 1 1 62A0E412
P 1550 1750
F 0 "U?" H 1550 2728 50  0000 C CNN
F 1 "74LS374" H 1550 2637 50  0000 C CNN
F 2 "" H 1550 1750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS374" H 1550 1750 50  0001 C CNN
	1    1550 1750
	0    -1   1    0   
$EndComp
Wire Wire Line
	1950 700  6050 700 
$Comp
L 74xx:74LS374 U?
U 1 1 62A0E521
P 3450 1750
F 0 "U?" H 3450 2728 50  0000 C CNN
F 1 "74LS374" H 3450 2637 50  0000 C CNN
F 2 "" H 3450 1750 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS374" H 3450 1750 50  0001 C CNN
	1    3450 1750
	0    -1   1    0   
$EndComp
Wire Wire Line
	3950 1250 3950 1000
Wire Wire Line
	3850 1250 3850 850 
Wire Wire Line
	3850 850  5950 850 
Wire Wire Line
	5950 850  5950 1400
Wire Wire Line
	5950 1400 8100 1400
Wire Wire Line
	6050 700  6050 1300
Wire Wire Line
	6050 1300 8100 1300
Wire Wire Line
	2050 1000 2050 1250
Wire Wire Line
	1950 700  1950 1250
Entry Wire Line
	2950 1250 3050 1150
Entry Wire Line
	3050 1250 3150 1150
Entry Wire Line
	3150 1250 3250 1150
Entry Wire Line
	3250 1250 3350 1150
Entry Wire Line
	3350 1250 3450 1150
Entry Wire Line
	3450 1250 3550 1150
Entry Wire Line
	3550 1250 3650 1150
Entry Wire Line
	3650 1250 3750 1150
Entry Wire Line
	1750 1250 1850 1150
Entry Wire Line
	1650 1250 1750 1150
Entry Wire Line
	1550 1250 1650 1150
Entry Wire Line
	1450 1250 1550 1150
Entry Wire Line
	1350 1250 1450 1150
Entry Wire Line
	1250 1250 1350 1150
Entry Wire Line
	1150 1250 1250 1150
Entry Wire Line
	1050 1250 1150 1150
Wire Bus Line
	6400 700  6400 1150
Connection ~ 6400 1150
Wire Wire Line
	6900 1200 6900 3700
Wire Wire Line
	6650 2850 9400 2850
Wire Wire Line
	6650 2850 6650 3950
Wire Wire Line
	2750 3050 3250 3050
Wire Wire Line
	2050 1000 3950 1000
Connection ~ 3950 1000
Wire Wire Line
	6500 1500 6500 3850
Wire Wire Line
	5950 3950 6650 3950
Wire Wire Line
	5950 3850 6500 3850
Entry Wire Line
	6300 2950 6400 2850
Entry Wire Line
	6300 3050 6400 2950
Entry Wire Line
	6300 3150 6400 3050
Entry Wire Line
	6300 3250 6400 3150
Entry Wire Line
	6300 3350 6400 3250
Entry Wire Line
	6300 3450 6400 3350
Entry Wire Line
	6300 3550 6400 3450
Entry Wire Line
	6300 3650 6400 3550
Wire Wire Line
	5950 2950 6300 2950
Wire Wire Line
	5950 3050 6300 3050
Wire Wire Line
	5950 3150 6300 3150
Wire Wire Line
	5950 3250 6300 3250
Wire Wire Line
	5950 3350 6300 3350
Wire Wire Line
	5950 3450 6300 3450
Wire Wire Line
	5950 3550 6300 3550
Wire Wire Line
	5950 3650 6300 3650
$Comp
L 74xx:74LS32 U?
U 2 1 62C3FF66
P 4200 5050
F 0 "U?" V 4154 5238 50  0000 L CNN
F 1 "74LS32" V 4245 5238 50  0000 L CNN
F 2 "" H 4200 5050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 4200 5050 50  0001 C CNN
	2    4200 5050
	0    1    1    0   
$EndComp
$Comp
L 74xx:74LS32 U?
U 1 1 62C465D5
P 3450 3500
F 0 "U?" H 3450 3183 50  0000 C CNN
F 1 "74LS32" H 3450 3274 50  0000 C CNN
F 2 "" H 3450 3500 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS32" H 3450 3500 50  0001 C CNN
	1    3450 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4400 3250 4650 3250
Wire Wire Line
	4400 1600 8100 1600
Wire Wire Line
	4100 4750 4100 3150
Wire Wire Line
	4400 1600 4400 2300
Wire Wire Line
	3750 3400 3950 3400
Wire Wire Line
	3100 3500 3150 3500
Wire Wire Line
	4650 7050 5150 7050
Wire Wire Line
	7550 3600 7800 3600
Wire Wire Line
	7800 3450 7750 3450
Wire Wire Line
	7750 3450 7750 2400
Wire Wire Line
	7750 2400 9400 2400
Wire Wire Line
	6900 3700 7800 3700
Wire Wire Line
	3950 2300 4400 2300
Wire Wire Line
	4300 4750 4300 2400
Connection ~ 7750 2400
Wire Wire Line
	4300 2400 7750 2400
Wire Wire Line
	4100 3150 4950 3150
Wire Wire Line
	4650 7050 4650 3250
Connection ~ 4650 3250
Wire Wire Line
	4650 3250 4950 3250
Text Label 8300 2400 0    50   ~ 0
SRegBus_In_ShiftLoad
$Comp
L power:GND #PWR?
U 1 1 62AEB787
P 7550 3900
F 0 "#PWR?" H 7550 3650 50  0001 C CNN
F 1 "GND" V 7555 3772 50  0000 R CNN
F 2 "" H 7550 3900 50  0001 C CNN
F 3 "" H 7550 3900 50  0001 C CNN
	1    7550 3900
	0    1    1    0   
$EndComp
Text Label 5950 2950 0    50   ~ 0
BUS_D0
Text Label 2950 1250 2    50   ~ 0
BUS_D0
Text Label 1050 1250 2    50   ~ 0
BUS_D0
Text Label 6100 6150 0    50   ~ 0
BUS_D0
Wire Wire Line
	2750 2950 2900 2950
Wire Wire Line
	4550 3050 4550 1000
Wire Wire Line
	3950 1000 4550 1000
Connection ~ 4550 3050
Wire Wire Line
	4550 3050 4950 3050
$Comp
L Device:R R?
U 1 1 62AFDEA6
P 3000 3150
F 0 "R?" V 2793 3150 50  0000 C CNN
F 1 "1k" V 2884 3150 50  0000 C CNN
F 2 "" V 2930 3150 50  0001 C CNN
F 3 "~" H 3000 3150 50  0001 C CNN
	1    3000 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B0343C
P 2950 3500
F 0 "R?" V 2743 3500 50  0000 C CNN
F 1 "1k" V 2834 3500 50  0000 C CNN
F 2 "" V 2880 3500 50  0001 C CNN
F 3 "~" H 2950 3500 50  0001 C CNN
	1    2950 3500
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B08B5F
P 3050 2950
F 0 "R?" V 2843 2950 50  0000 C CNN
F 1 "1k" V 2934 2950 50  0000 C CNN
F 2 "" V 2980 2950 50  0001 C CNN
F 3 "~" H 3050 2950 50  0001 C CNN
	1    3050 2950
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 62B08BB1
P 3400 3050
F 0 "R?" V 3193 3050 50  0000 C CNN
F 1 "1k" V 3284 3050 50  0000 C CNN
F 2 "" V 3330 3050 50  0001 C CNN
F 3 "~" H 3400 3050 50  0001 C CNN
	1    3400 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	3200 2950 4950 2950
Wire Wire Line
	3550 3050 4550 3050
$Comp
L Device:R R?
U 1 1 62B459FD
P 3750 7150
F 0 "R?" V 3543 7150 50  0000 C CNN
F 1 "10k" V 3634 7150 50  0000 C CNN
F 2 "" V 3680 7150 50  0001 C CNN
F 3 "~" H 3750 7150 50  0001 C CNN
	1    3750 7150
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 5350 4200 6850
Wire Wire Line
	3900 7150 4200 7150
Connection ~ 4200 7150
Wire Wire Line
	4200 7150 4400 7150
Connection ~ 4400 7150
Wire Wire Line
	4400 7150 5150 7150
$Comp
L power:+5V #PWR?
U 1 1 62B848B5
P 3400 7150
F 0 "#PWR?" H 3400 7000 50  0001 C CNN
F 1 "+5V" H 3415 7323 50  0000 C CNN
F 2 "" H 3400 7150 50  0001 C CNN
F 3 "" H 3400 7150 50  0001 C CNN
	1    3400 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 7150 3600 7150
Connection ~ 9200 1700
Wire Wire Line
	9100 1700 9200 1700
Text Label 4300 4750 1    50   ~ 0
SRegBus_In_ShiftLoad
Text Label 4100 4750 1    50   ~ 0
CL_RD
$Comp
L Diode:1N4148 D?
U 1 1 62B60B5A
P 3700 3150
F 0 "D?" H 3700 2934 50  0000 C CNN
F 1 "1N4148" H 3700 3025 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 3700 2975 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 3700 3150 50  0001 C CNN
	1    3700 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 3150 3850 3150
Connection ~ 4100 3150
Wire Wire Line
	3550 3150 3150 3150
Wire Wire Line
	2800 3500 2750 3500
Wire Wire Line
	3950 2300 3950 3400
Wire Wire Line
	4400 3250 4400 3600
Wire Wire Line
	3750 3600 4400 3600
Connection ~ 4400 3600
Wire Wire Line
	4400 3600 4400 6850
Text Label 4550 1000 2    50   ~ 0
CL_MEMRQ
Text Label 3750 3600 0    50   ~ 0
CL_WR
Text Label 3750 3400 0    50   ~ 0
5_CCAddr_Host
Text Label 1950 700  0    50   ~ 0
2_CCAddr_RegAddrLo_Out
Text Label 3850 850  0    50   ~ 0
3_CCAddr_RegAddrHi_Out
$Comp
L power:GND #PWR?
U 1 1 62BA4AE1
P 7550 3600
F 0 "#PWR?" H 7550 3350 50  0001 C CNN
F 1 "GND" V 7555 3472 50  0000 R CNN
F 2 "" H 7550 3600 50  0001 C CNN
F 3 "" H 7550 3600 50  0001 C CNN
	1    7550 3600
	0    1    1    0   
$EndComp
Text Label 7800 3700 2    50   ~ 0
1_CCAddr_SRegBus_In
Text Label 7750 3450 2    50   ~ 0
SRegBus_In_ShiftLoad
Text Label 8000 5300 0    50   ~ 0
0_CCAddr_SRegBus_Out
Wire Wire Line
	6800 1100 6800 5050
Wire Wire Line
	6800 5050 8000 5050
Wire Bus Line
	1150 1150 6400 1150
Wire Bus Line
	6400 1150 6400 7200
$EndSCHEMATC
