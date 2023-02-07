/* linker_script cortexM3
Eng: Muhand
*/

MEMORY
{
  FLASH (RX): ORIGIN = 0x00000000, LENGTH =512M
  SRAM (RWX): ORIGIN = 0x20000000, LENGTH =512M
}

SECTIONS
{
   .text :
   { 
      *(.vectors*)
	  *(.text*)
	  *(.rodata)
	  . = ALIGN(4);
	  _E_text = .;
   }>FLASH
   .data :
   { 
      _s_data = .;
      *(.data)
	 . = ALIGN(4);
	 _E_data = .;
	  
   }> SRAM AT> FLASH
   .bss :
   { 
      _s_bss = .;
	  *(.bss*)
	  . = ALIGN(4);
	  _E_bss = .;
	  
   }>SRAM
   

}



