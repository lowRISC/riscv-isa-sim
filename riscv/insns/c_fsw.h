if (xlen == 32) {
  require_extension(EXT_ZCF);
  require_fp;
  MMU.store_uint32(RVC_RS1S + insn.rvc_lw_imm(), RVC_FRS2S.v[0]);
} else { // c.sd
  require_extension(EXT_ZCA);
  MMU.store_uint64(RVC_RS1S + insn.rvc_ld_imm(), RVC_RS2S);
}
