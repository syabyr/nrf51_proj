/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x1b000, LENGTH = 0x25000
  RAM (rwx) :  ORIGIN = 0x200013c8, LENGTH = 0x2C38
  /*  RAM (rwx) :  ORIGIN = 0x20001fe8, LENGTH = 0x2700 尝试调整,错误*/
  /*  RAM (rwx) :  ORIGIN = 0x20001fe8, LENGTH = 0x2018 正确,不够用,少了682字节*/
  /*  RAM (rwx) :  ORIGIN = 0x20001870, LENGTH = 0x2790 够用,但是不知为啥报错*/
}

SECTIONS
{
  .fs_data :
  {
    PROVIDE(__start_fs_data = .);
    KEEP(*(.fs_data))
    PROVIDE(__stop_fs_data = .);
  } > RAM
  .pwr_mgmt_data :
  {
    PROVIDE(__start_pwr_mgmt_data = .);
    KEEP(*(.pwr_mgmt_data))
    PROVIDE(__stop_pwr_mgmt_data = .);
  } > RAM
} INSERT AFTER .data;

INCLUDE "nrf5x_common.ld"