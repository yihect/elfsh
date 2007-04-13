/*
** $Id: op_das.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_das" opcode="0x2f"/>
 */

int     op_das(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_DAS;
  #if LIBASM_USE_OPERAND_VECTOR
  #endif
  return (new->len);
}
