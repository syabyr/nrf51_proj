#include "nrf.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "nrf_drv_adc.h"
#include "nordic_common.h"
#include "boards.h"
#define NRF_LOG_MODULE_NAME "APP"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "app_util_platform.h"
#include "adc_test.h"


#define ADC_BUFFER_SIZE 10                                /**< Size of buffer for ADC samples.  */
static nrf_adc_value_t       adc_buffer[ADC_BUFFER_SIZE]; /**< ADC buffer. */


/**
 * @brief ADC interrupt handler.
 */
static void adc_event_handler(nrf_drv_adc_evt_t const * p_event)
{
    if (p_event->type == NRF_DRV_ADC_EVT_DONE)
    {
        uint32_t i;
        for (i = 0; i < p_event->data.done.size; i++)
        {
            printf("Current sample value: %d\r\n", p_event->data.done.p_buffer[i]);
        }
    }
}

void adc_config(void) {
    ret_code_t ret_code;
    nrf_drv_adc_config_t config = NRF_DRV_ADC_DEFAULT_CONFIG;

    ret_code = nrf_drv_adc_init(&config, adc_event_handler);
    APP_ERROR_CHECK(ret_code);

    static nrf_drv_adc_channel_t m_channel_config = NRF_DRV_ADC_DEFAULT_CHANNEL(NRF_ADC_CONFIG_INPUT_2); /**< Channel instance. Default configuration used. */
    m_channel_config.config.config.input = NRF_ADC_CONFIG_SCALING_INPUT_ONE_THIRD;

    nrf_drv_adc_channel_enable(&m_channel_config);
}

void adc_convert(void) {
    APP_ERROR_CHECK(nrf_drv_adc_buffer_convert(adc_buffer,ADC_BUFFER_SIZE));
    uint32_t i;
    for (i = 0; i < ADC_BUFFER_SIZE; i++)
    {
        // manually trigger ADC conversion
        nrf_drv_adc_sample();
        // enter into sleep mode
        __SEV();
        __WFE();
        __WFE();

        nrf_delay_ms(100);
        //bsp_board_led_invert(BSP_BOARD_LED_0);
        NRF_LOG_FLUSH();
    }
}