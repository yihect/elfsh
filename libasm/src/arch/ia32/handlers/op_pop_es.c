/*
** $Id: op_pop_es.c,v 1.6 2007-08-15 21:30:20 strauss Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x07
  Instruction :         POP
*/

int op_pop_es(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_POP;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_ASSIGN | ASM_TYPE_LOAD;
  new->spdiff = 4;
  new->len += 1;

  new->len += asm_operand_fetch(&new->op1, opcode, ASM_OTYPE_FIXED, new);
  new->op1.content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op1.regset = ASM_REGSET_SREG;
  new->op1.baser = ASM_REG_ES;

  return (new->len);
}
