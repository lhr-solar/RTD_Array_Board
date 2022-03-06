#include "mbed.h"
#include "MAX31865.h"

//Serial pc(SERIAL_TX, SERIAL_RX)
MAX31865_RTD rtd0(MAX31865_RTD::RTD_PT100, D11, D12, D13, A1); //miso = master input slave output (SDI on nucleo), 
//RTD parameters: (ptd_type type,PinName mosi, PinName miso, PinName sclk, PinName nss); nss is chip select, negative logic
// main() runs in its own thread in the OS
//RTD1 ADC is shorted

MAX31865_RTD rtd1(MAX31865_RTD::RTD_PT100, D11, D12, D13, A0); //miso = master input slave output (SDI on nucleo), 
MAX31865_RTD rtd2(MAX31865_RTD::RTD_PT100, D11, D12, D13, D8); //miso = master input slave output (SDI on nucleo),
MAX31865_RTD rtd3(MAX31865_RTD::RTD_PT100, D11, D12, D13, D9); //miso = master input slave output (SDI on nucleo),
MAX31865_RTD rtd4(MAX31865_RTD::RTD_PT100, D11, D12, D13, A3); //miso = master input slave output (SDI on nucleo),
MAX31865_RTD rtd5(MAX31865_RTD::RTD_PT100, D11, D12, D13, D6); //miso = master input slave output (SDI on nucleo),
MAX31865_RTD rtd6(MAX31865_RTD::RTD_PT100, D11, D12, D13, A6); //miso = master input slave output (SDI on nucleo),
MAX31865_RTD rtd7(MAX31865_RTD::RTD_PT100, D11, D12, D13, D3); //miso = master input slave output (SDI on nucleo),

int main()
{
    //when configuring RTDs to test, make sure that ALL RTDs are configured! If not, the default setting of the chip select pins is sitting at 0,
    //which is normally the chip enable signal. When the RTD is configured, the pin idles at high and prevents unwanted data being sent by
    //chips over the SPI bus, as all chips are tied to the same bus.
    
    //configure( bool v_bias, bool conversion_mode, bool one_shot, bool three_wire, uint8_t fault_cycle, bool fault_clear,
                            //   bool filter_50hz, uint16_t low_threshold, uint16_t high_threshold )

    rtd0.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd1.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    // rtd2.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
    //                true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd3.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd4.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd5.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd6.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);

    rtd7.configure( true, true, false, false, MAX31865_FAULT_DETECTION_NONE,
                   true, true, 0x0000, 0x7fff );
    osDelay(200);               
    
    while (1) {
        
 
        //if( rtd.status( ) == 0 ) {

            //rtd0 is good

            // rtd0.read_all( );
            // double temperature0 = rtd0.temperature( );
            // printf( " T0 = %f deg C \n\r",temperature0);
            // double resistance0 = rtd0.resistance();
            // printf("Resistance0 is %f \n", resistance0);

            // osDelay(1000);
            
 
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
        
        //wait(1);  rtd 1 good
        // rtd1.read_all( );
        // double temperature1 = rtd1.temperature( );
        // printf( " T1 = %f deg C \n\r",temperature1);
        // double resistance1 = rtd1.resistance();
        // printf("Resistance1 is %f \n", resistance1);

        //need new board
        // rtd2.read_all( );
        // double temperature2 = rtd2.temperature( );
        // printf( " T2 = %f deg C \n\r",temperature2);
        // double resistance2 = rtd2.resistance();
        // printf("Resistance2 is %f \n", resistance2);

        //rtd3 is good
        rtd3.read_all( );
        double temperature3 = rtd3.temperature( );
        printf( " T3 = %f deg C \n\r",temperature3);
        double resistance3 = rtd3.resistance();
        printf("Resistance3 is %f \n", resistance3);

        rtd4.read_all( );
        
        
        // rtd4.read_all( );   //rtd4 is good
        // double temperature4 = rtd4.temperature( );
        // printf( " T4 = %f deg C \n\r",temperature4);
        // double resistance4 = rtd4.resistance();
        // printf("Resistance4 is %f \n", resistance4);

        
        // rtd5 is good
        // rtd5.read_all( );
        // double temperature5 = rtd5.temperature( );
        // printf( " T5 = %f deg C \n\r",temperature5);
        // double resistance5 = rtd5.resistance();
        // printf("Resistance5 is %f \n", resistance5);

        // rtd6 is good
        // rtd6.read_all( );
        // double temperature6 = rtd6.temperature( );
        // printf( " T6 = %f deg C \n\r",temperature6);
        // double resistance6 = rtd6.resistance();
        // printf("Resistance6 is %f \n", resistance6);

        // rtd7 is good
        // rtd7.read_all( );
        // double temperature7 = rtd7.temperature( );
        // printf( " T7 = %f deg C \n\r",temperature7);
        // double resistance7 = rtd7.resistance();
        // printf("Resistance7 is %f \n", resistance7);
        

        printf("\n");
        osDelay(1000);
 
    }
}
