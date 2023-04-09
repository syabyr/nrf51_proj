cmake_minimum_required(VERSION 3.3)

include (CMakeForceCompiler)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m0plus)
set(CMAKE_INCLUDE_PATH "")
enable_language(ASM)

set(PROJECT_NAME fulltest)


set(CMAKE_C_COMPILER_WORKS 1)

CMAKE_FORCE_C_COMPILER(/usr/local/bin/arm-none-eabi-gcc GNU)

set(tools /usr/local)
set(CMAKE_CXX_COMPILER  ${tools}/bin/arm-none-eabi-g++)
set(CMAKE_C_COMPILER    ${tools}/bin/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER  ${tools}/bin/arm-none-eabi-gcc)
set(SIZE_COMMAND        ${tools}/bin/arm-none-eabi-size)
set(OBJCOPY_COMMAND     ${tools}/bin/arm-none-eabi-objcopy)


set(BUILD_SHARED_LIBS OFF)

# NRF related
set(PROJ_DIR ./)
set(NRF_ROOT                ../../)
set(SDK_ROOT                ../../)
set(NRF_SDK                 ${NRF_ROOT})
set(NRF_SDK_ROOT            ${NRF_ROOT})
set(SDK_COMPONENTS          ${NRF_ROOT}/components)
set(NRF_TOOLCHAIN           ${NRF_ROOT}/components/toolchain)
set(DEVICE_INCLUDES         ${NRF_ROOT}/device)
set(NRF_GCC                 ${NRF_ROOT}/components/toolchain/gcc)


set(TEMPLATE_PATH ${SDK_ROOT}/components/toolchain/gcc)


project(${PROJECT_NAME} C)

set(MAIN_TARGET ${PROJECT_NAME}.out)

set(LINKER_SCRIPT ../${NRF_GCC}/nrf51_xxaa.ld)


set(CMAKE_C_FLAGS "-T${LINKER_SCRIPT} -DNRF51 -DNRF51822 -DSWI_DISABLE0 -DBOARD_PCA10028 -DBSP_DEFINES_ONLY -DBLE_STACK_SUPPORT_REQD -DBSP_DEFINES_ONLY -mcpu=cortex-m0 -mthumb -mabi=aapcs --std=gnu99 -Wall -Werror -O3 -g3 -mfloat-abi=soft -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin --short-enums -lc -lnosys")



#add_definitions(-DDEBUG)
#add_definitions(-DSOFTDEVICE_PRESENT)
#add_definitions(-DS110)


add_link_options(-mthumb -mabi=aapcs -L ../${TEMPLATE_PATH}  -mcpu=cortex-m0 -Wl,--gc-sections --specs=nano.specs -lc -lnosys)

include_directories(
    ${NRF_TOOLCHAIN}
    ${NRF_GCC}
    ${SDK_COMPONENTS}/softdevice/${SOFTDEVICE}/headers
    ${NRF_SDK_ROOT}/examples/bsp
    ${SDK_COMPONENTS}/device
    ${SDK_COMPONENTS}/drivers_nrf/hal
    ${SDK_ROOT}/components/toolchain/cmsis/include
    ${SDK_ROOT}/components/drivers_nrf/delay
    ${SDK_ROOT}/components/boards
    ${SDK_ROOT}/components/libraries/util

    ${SDK_ROOT}/components/drivers_nrf/comp
    ${SDK_ROOT}/components/drivers_nrf/twi_master
    ${SDK_ROOT}/components/ble/ble_services/ble_ancs_c
    ${SDK_ROOT}/components/ble/ble_services/ble_ias_c
    ${SDK_ROOT}/components/libraries/pwm
    ${SDK_ROOT}/components/libraries/usbd/class/cdc/acm
    ${SDK_ROOT}/components/libraries/usbd/class/hid/generic
    ${SDK_ROOT}/components/libraries/usbd/class/msc
    ${SDK_ROOT}/components/libraries/usbd/class/hid
    ${SDK_ROOT}/components/libraries/log
    ${SDK_ROOT}/components/ble/ble_services/ble_gls
    ${SDK_ROOT}/components/libraries/fstorage
    ${SDK_ROOT}/components/drivers_nrf/i2s
    ${PROJ_DIR}
    ${SDK_ROOT}/components/libraries/gpiote
    ${SDK_ROOT}/components/drivers_nrf/gpiote
    ${SDK_ROOT}/components/drivers_nrf/nrf_soc_nosd
    ${SDK_ROOT}/components/boards
    ${SDK_ROOT}/components/drivers_nrf/common
    ${SDK_ROOT}/components/ble/ble_advertising
    ${SDK_ROOT}/components/drivers_nrf/adc
    ${SDK_ROOT}/components/ble/ble_services/ble_bas_c
    ${SDK_ROOT}/components/ble/ble_services/ble_hrs_c
    ${SDK_ROOT}/components/libraries/queue
    ${SDK_ROOT}/components/ble/ble_dtm
    ${SDK_ROOT}/components/toolchain/cmsis/include
    ${SDK_ROOT}/components/ble/ble_services/ble_rscs_c
    ${SDK_ROOT}/components/drivers_nrf/uart
    ${SDK_ROOT}/components/libraries/usbd/class/hid/kbd
    ${SDK_ROOT}/components/ble/ble_services/ble_lls
    ${SDK_ROOT}/components/drivers_nrf/wdt
    ${SDK_ROOT}/components/libraries/bsp
    ${SDK_ROOT}/components/ble/ble_services/ble_bas
    ${SDK_ROOT}/components/libraries/experimental_section_vars
    ${SDK_ROOT}/components/ble/ble_services/ble_ans_c
    ${SDK_ROOT}/components/libraries/slip
    ${SDK_ROOT}/external/segger_rtt
    ${SDK_ROOT}/components/libraries/csense_drv
    ${SDK_ROOT}/components/drivers_nrf/hal
    ${SDK_ROOT}/components/ble/ble_services/ble_nus_c
    ${SDK_ROOT}/components/drivers_nrf/rtc
    ${SDK_ROOT}/components/ble/ble_services/ble_ias
    ${SDK_ROOT}/components/libraries/usbd/class/hid/mouse
    ${SDK_ROOT}/components/drivers_nrf/ppi
    ${SDK_ROOT}/components/ble/ble_services/ble_dfu
    ${SDK_ROOT}/components/drivers_nrf/twis_slave
    ${SDK_ROOT}/components
    ${SDK_ROOT}/components/drivers_nrf/usbd
    ${SDK_ROOT}/components/libraries/scheduler
    ${SDK_ROOT}/components/ble/ble_services/ble_lbs
    ${SDK_ROOT}/components/ble/ble_services/ble_hts
    ${SDK_ROOT}/components/drivers_nrf/delay
    ${SDK_ROOT}/components/libraries/crc16
    ${SDK_ROOT}/components/drivers_nrf/timer
    ${SDK_ROOT}/components/libraries/util
    ${SDK_ROOT}/components/drivers_nrf/pwm
    ${SDK_ROOT}/components/libraries/usbd/class/cdc
    ${SDK_ROOT}/components/libraries/csense
    ${SDK_ROOT}/components/drivers_nrf/rng
    ${SDK_ROOT}/components/libraries/low_power_pwm
    ${SDK_ROOT}/components/libraries/hardfault
    ${SDK_ROOT}/components/ble/ble_services/ble_cscs
    ${SDK_ROOT}/components/libraries/uart
    ${SDK_ROOT}/components/libraries/hci
    ${SDK_ROOT}/components/drivers_nrf/spi_slave
    ${SDK_ROOT}/components/drivers_nrf/lpcomp
    ${SDK_ROOT}/components/libraries/timer
    ${SDK_ROOT}/components/drivers_nrf/power
    ${SDK_ROOT}/components/libraries/usbd/config
    ${SDK_ROOT}/components/toolchain
    ${SDK_ROOT}/components/libraries/led_softblink
    ${SDK_ROOT}/components/drivers_nrf/qdec
    ${SDK_ROOT}/components/ble/ble_services/ble_cts_c
    ${SDK_ROOT}/components/drivers_nrf/spi_master
    ${SDK_ROOT}/components/ble/ble_services/ble_nus
    ${SDK_ROOT}/components/ble/ble_services/ble_hids
    ${SDK_ROOT}/components/drivers_nrf/pdm
    ${SDK_ROOT}/components/libraries/crc32
    ${SDK_ROOT}/components/libraries/usbd/class/audio
    ${SDK_ROOT}/components/ble/peer_manager
    ${SDK_ROOT}/components/libraries/mem_manager
    ${SDK_ROOT}/components/ble/ble_services/ble_tps
    ${SDK_ROOT}/components/ble/ble_services/ble_dis
    ${SDK_ROOT}/components/device
    ${SDK_ROOT}/components/ble/nrf_ble_qwr
    ${SDK_ROOT}/components/libraries/button
    ${SDK_ROOT}/components/libraries/usbd
    ${SDK_ROOT}/components/drivers_nrf/saadc
    ${SDK_ROOT}/components/ble/ble_services/ble_lbs_c
    ${SDK_ROOT}/components/ble/ble_racp
    ${SDK_ROOT}/components/toolchain/gcc
    ${SDK_ROOT}/components/libraries/fds
    ${SDK_ROOT}/components/libraries/twi
    ${SDK_ROOT}/components/drivers_nrf/clock
    ${SDK_ROOT}/components/ble/ble_services/ble_rscs
    ${SDK_ROOT}/components/drivers_nrf/swi
    ${SDK_ROOT}/components/ble/ble_services/ble_hrs
    ${SDK_ROOT}/components/libraries/log/src
    ${SDK_ROOT}/components/libraries/fifo
    
)

set(SOURCE_FILES
    ${SDK_ROOT}/components/libraries/log/src/nrf_log_backend_serial.c
    ${SDK_ROOT}/components/libraries/log/src/nrf_log_frontend.c
    ${SDK_ROOT}/components/libraries/util/app_error.c
    ${SDK_ROOT}/components/libraries/util/app_error_weak.c
    ${SDK_ROOT}/components/libraries/timer/app_timer.c
    ${SDK_ROOT}/components/libraries/util/app_util_platform.c
    ${SDK_ROOT}/components/libraries/hardfault/hardfault_implementation.c
    ${SDK_ROOT}/components/libraries/util/nrf_assert.c
    ${SDK_ROOT}/components/libraries/util/sdk_errors.c
    ${SDK_ROOT}/components/boards/boards.c
    ${SDK_ROOT}/components/drivers_nrf/clock/nrf_drv_clock.c
    ${SDK_ROOT}/components/drivers_nrf/common/nrf_drv_common.c
    ${SDK_ROOT}/components/drivers_nrf/uart/nrf_drv_uart.c
    ${SDK_ROOT}/components/drivers_nrf/nrf_soc_nosd/nrf_nvic.c
    ${SDK_ROOT}/components/drivers_nrf/nrf_soc_nosd/nrf_soc.c
    ${SDK_ROOT}/external/segger_rtt/RTT_Syscalls_GCC.c
    ${SDK_ROOT}/external/segger_rtt/SEGGER_RTT.c
    ${SDK_ROOT}/external/segger_rtt/SEGGER_RTT_printf.c
    ${SDK_ROOT}/components/toolchain/gcc/gcc_startup_nrf51.S
    ${SDK_ROOT}/components/toolchain/system_nrf51.c
    ${SDK_ROOT}/components/libraries/uart/retarget.c
    ${SDK_ROOT}/components/libraries/fifo/app_fifo.c
    ${SDK_ROOT}/components/libraries/uart/app_uart_fifo.c
    ${SDK_ROOT}/components/drivers_nrf/gpiote/nrf_drv_gpiote.c
    ${SDK_ROOT}/components/drivers_nrf/adc/nrf_drv_adc.c
    ${PROJ_DIR}/main.c
    ${PROJ_DIR}/uart_init.c
    ${PROJ_DIR}/gpio_test.c
    ${PROJ_DIR}/adc_test.c
    )

add_executable(${MAIN_TARGET} ${SOURCE_FILES})

add_custom_command(
        TARGET ${MAIN_TARGET}
        COMMAND ${SIZE_COMMAND} ${MAIN_TARGET}
        COMMAND ${OBJCOPY_COMMAND} -O ihex ${MAIN_TARGET} ${PROJECT_NAME}.hex
        COMMAND ${OBJCOPY_COMMAND} -O binary ${MAIN_TARGET} ${PROJECT_NAME}.bin
)

add_custom_target(flash
    COMMAND nrfjprog --program ${PROJECT_NAME}.hex -f nrf51 --sectorerase
    COMMAND nrfjprog --reset -f nrf51
        DEPENDS ${PROJECT_NAME}.hex
    )