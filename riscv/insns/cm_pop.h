require_zcmp_pushpop;

const auto new_sp = SP + insn.zcmp_stack_adjustment(xlen);
auto addr = new_sp;

for (int i = Sn(11); i >= 0; i--) {
  if (insn.zcmp_regmask() & (1 << i)) {
    addr -= xlen / 8;

    if (xlen == 32)
      WRITE_REG(i, MMU.load_int32(addr));
    else
      WRITE_REG(i, MMU.load_int64(addr));
  }
}

WRITE_REG(X_SP, new_sp);
