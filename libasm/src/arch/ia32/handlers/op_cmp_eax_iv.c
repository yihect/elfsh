/*
** $Id: op_cmp_eax_iv.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_eax_iv" opcode="0x3d"/>
*/

int op_cmp_eax_iv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->instr = ASM_CMP;
  new->ptr_instr = opcode;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
  new->len += asm_operand_fetch(&new->op1, opcode, ASM_OTYPE_FIXED, proc);
  new->op1.content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op1.base_reg = ASM_REG_EAX;
  new->op1.regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->len += asm_operand_fetch(&new->op2, opcode + 1, ASM_OTYPE_IMMEDIATE, proc);
#else
  new->op1.type = ASM_OTYPE_FIXED;
  new->op2.type = ASM_OTYPE_IMMEDIATE;
  
  new->op1.content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op1.base_reg = ASM_REG_EAX;
  new->op1.regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  
  new->op2.content = ASM_OP_VALUE;
  new->op2.ptr = opcode;
  new->op2.len = asm_proc_vector_len(proc);
  memcpy(&new->op2.imm, opcode + 1, asm_proc_vector_len(proc));
  new->len += asm_proc_vector_len(proc);
#endif
  return (new->len);
}
