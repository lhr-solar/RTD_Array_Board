#include "mbed.h"
#include "MAX31865.h"

//Serial pc(SERIAL_TX, SERIAL_RX)
MAX31865_RTD rtd0(MAX31865_RTD::RTD_PT100, D11, D12, D13, A1); //miso = master input slave output (SDI on nucleo), 
//RTD parameters: (ptd_type type,PinName mosi, PinName miso, PinName sclk, PinName nss); nss is chip select, negative logic
// main() runs in its own thread in the OS
//RTD1 ADC is shorted
int main()
{
    rtd0.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    
    while (1) {
        rtd0.read_all( );
 
        //if( rtd.status( ) == 0 ) {
            double temperature1 = rtd0.temperature( );
            printf( " T = %f deg C \n\r",temperature1);
            double resistance1 = rtd0.resistance();
            printf("Resistance is %f \n", resistance1);
 
        // } else
        // {
        //     printf( "RTD fault register: %d :\r\n",rtd.status( ));
        //     if( rtd.status( ) & MAX31865_FAULT_HIGH_THRESHOLD ) {
        //         printf( "RTD high threshold exceeded\r\n" );
        //     } else if( rtd.status( ) & MAX31865_FAULT_LOW_THRESHOLD ) {
        //         printf( "RTD low threshold exceeded\r\n" );
        //     } else if( rtd.status( ) & MAX31865_FAULT_REFIN ) {
        //         printf( "REFIN- > 0.85 x V_BIAS\r\n" );
        //     } else if( rtd.status( ) & MAX31865_FAULT_REFIN_FORCE ) {
        //         printf( "REFIN- < 0.85 x V_BIAS, FORCE- open\r\n" );
        //     } else if( rtd.status( ) & MAX31865_FAULT_RTDIN_FORCE ) {
        //         printf( "RTDIN- < 0.85 x V_BIAS, FORCE- open\r\n" );
        //     } else if( rtd.status( ) & MAX31865_FAULT_VOLTAGE ) {
        //         printf( "Overvoltage/undervoltage fault\r\n");
        //     } else {
        //         printf( "Unknown fault; check connection\r\n" );
        //     }
        // }
        //wait(1);
        osDelay(1000);
 
    }
}

