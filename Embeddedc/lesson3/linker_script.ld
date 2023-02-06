/* linker_script cortexM3
Eng: Muhand
*/

MEMORY
{
  FLASH (RX): ORIGIN = 0x08000000, LENGTH =128K
  SRAM (RWX): ORIGIN = 0x20000000, LENGTH =20K
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
	  . = ALIGN(4);
	  . = . + 0x1000;
	  _stack_top = .;
   }>SRAM
   

}



