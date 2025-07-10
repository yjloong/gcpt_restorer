/* See LICENSE for license details. */

OUTPUT_ARCH( "riscv" )

ENTRY( restorer_size_location )

SECTIONS
{

  /*--------------------------------------------------------------------*/
  /* Code and read-only segment                                         */
  /*--------------------------------------------------------------------*/

  /* Beginning of code and text segment */
  . = ALIGN(4);
  . = 0x80000000;

  gcpt_begin = .;

  .restore.size :
  {
    *(.restore.size)
  }

  . = gcpt_begin + 0x10;

  .restore.location :
  {
    *(.restore.location)
  }

  /* restore: Restore Program code section */
  .restore.code :
  {
    *(.restore.code)
  }

  . = ALIGN(0x400);
  .restore.flag :
  {
    *(.restore.flag)
  }

  .trap_wrapper :
  {
    *(.trap_wrapper)
  }

  .text :
  {
    *(.text .text.*)
  }

  .rodata :
  {
    *(.rodata .rodata.*)
  }

  .data :
  {
    *(.data .data.*)
  }

  .bss :
  {
    *(.bss .bss.*)
  }

  gcpt_end = .;

}
