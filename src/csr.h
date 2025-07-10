/***************************************************************************************
* Copyright (c) 2020-2022 Institute of Computing Technology, Chinese Academy of Sciences
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __CSR_H__
#define __CSR_H__

//no mhartid here

#define CSRS(f) \
  f(frm        , 0x002) \
  f(mstatus    , 0x300) f(medeleg    , 0x302) f(mideleg    , 0x303) \
  f(mie        , 0x304) f(mtvec      , 0x305) f(mcounteren , 0x306) \
  f(mscratch   , 0x340) f(mepc       , 0x341) f(mcause     , 0x342) \
  f(mtval      , 0x343) f(mip        , 0x344) \
  f(pmpcfg0    , 0x3a0) f(pmpcfg2    , 0x3a2) \
  f(pmpaddr0   , 0x3b0) f(pmpaddr1   , 0x3b1) f(pmpaddr2   , 0x3b2) f(pmpaddr3   , 0x3b3) \
  f(pmpaddr4   , 0x3b4) f(pmpaddr5   , 0x3b5) f(pmpaddr6   , 0x3b6) f(pmpaddr7   , 0x3b7) \
  f(pmpaddr8   , 0x3b8) f(pmpaddr9   , 0x3b9) f(pmpaddr10  , 0x3ba) f(pmpaddr11  , 0x3bb) \
  f(pmpaddr12  , 0x3bc) f(pmpaddr13  , 0x3bd) f(pmpaddr14  , 0x3be) f(pmpaddr15  , 0x3bf) \
  f(stvec      , 0x105) f(scounteren , 0x106) \
  f(sscratch   , 0x140) f(sepc       , 0x141) f(scause     , 0x142) \
  f(stval      , 0x143) \
  f(satp       , 0x180)

#define NOP \
  addi x0, x0, 0;

#define HCSRS(f) \
  f(hstatus    , 0x600) f(hedeleg    , 0x602) f(hideleg    , 0x603) \
  f(hcounteren , 0x606) f(hgeie      , 0x607) \
  f(htval      , 0x643) f(hip        , 0x644) f(hvip       , 0x645) \
  f(htinst     , 0x64A) f(henvcfg    , 0x60A) \
  f(hgatp      , 0x680) \
  f(vsstatus   , 0x200) f(vstvec     , 0x205) \
  f(vsscratch  , 0x240) f(vsepc      , 0x241) f(vscause    , 0x242) \
  f(vstval     , 0x243) f(vsip       , 0x244) f(vsatp      , 0x280) \
  f(mtval2     , 0x34b) f(mtinst     , 0x34A) f(mcycle     , 0xB00) f(mcountinhibit  , 0x320)

#define CSRS_MHPMEVENTS(f) \
  f(mhpmevent3, 0x323) f(mhpmevent4, 0x324) f(mhpmevent5, 0x325) f(mhpmevent6, 0x326) f(mhpmevent7, 0x327) \
  f(mhpmevent8, 0x328) f(mhpmevent9, 0x329) f(mhpmevent10, 0x32a) f(mhpmevent11, 0x32b) f(mhpmevent12, 0x32c) \
  f(mhpmevent13, 0x32d) f(mhpmevent14, 0x32e) f(mhpmevent15, 0x32f) f(mphmevent16, 0x330) f(mhpmevent17, 0x331) \
  f(mhpmevent18, 0x332) f(mhpmevent19, 0x333) f(mhpmevent20, 0x334) f(mhpmevent21, 0x335) f(mhpmevent22, 0x336) \
  f(mhpmevent23, 0x337) f(mhpmevent24, 0x338) f(mhpmevent25, 0x339) f(mhpmevent26, 0x33a) f(mhpmevent27, 0x33b) \
  f(mhpmevent28, 0x33c) f(mhpmevent29, 0x33d) f(mhpmevent30, 0x33e) f(mhpmevent31, 0x33f)

#define CSRS_MHPMCOUNTERS(f) \
  f(mhpmcounter3, 0xb03) f(mhpmcounter4, 0xb04) f(mhpmcounter5, 0xb05) f(mhpmcounter6, 0xb06) f(mhpmcounter7, 0xb07) \
  f(mhpmcounter8, 0xb08) f(mhpmcounter9, 0xb09) f(mhpmcounter10, 0xb0a) f(mhpmcounter11, 0xb0b) f(mhpmcounter12, 0xb0c) \
  f(mhpmcounter13, 0xb0d) f(mhpmcounter14, 0xb0e) f(mhpmcounter15, 0xb0f) f(mhpmcounter16, 0xb10) f(mhpmcounter17, 0xb11) \
  f(mhpmcounter18, 0xb12) f(mhpmcounter19, 0xb13) f(mhpmcounter20, 0xb14) f(mhpmcounter21, 0xb15) f(mhpmcounter22, 0xb16) \
  f(mhpmcounter23, 0xb17) f(mhpmcounter24, 0xb18) f(mhpmcounter25, 0xb19) f(mhpmcounter26, 0xb1a) f(mhpmcounter27, 0xb1b) \
  f(mhpmcounter28, 0xb1c) f(mhpmcounter29, 0xb1d) f(mhpmcounter30, 0xb1e) f(mhpmcounter31, 0xb1f)


#define VL_ID (0xc20)
#define VTYPE_ID (0xc21)
#define VLENB_ID (0xc22)

#define VTYPE_VL_RESTORE \
  csrr t3, CSR_MSTATUS; \
  li t0, MSTATUS_VS; \
  csrs  CSR_MSTATUS, t0; \
  li t0, CSR_REG_CPT_ADDR; \
  jal ra, get_restorer_entry_pc; \
  add t0, t0, s1; \
  li t2,VTYPE_ID;\
  slli t2,t2,3; \
  add t2,t0,t2; \
  ld t1,(t2);\
  li t2,VL_ID;\
  slli t2,t2,3; \
  add t2,t0,t2; \
  ld t2,(t2);\
  vsetvl t2, t2, t1; \

#define RESTORE_VECTORS(f) \
  VTYPE_VL_RESTORE; \
  li sp, VECTOR_REG_CPT_ADDR; \
  jal ra, get_restorer_entry_pc; \
  add sp, sp, s1; \
  addi sp,sp,0;\
  vl1re64.v v0, (sp); \
  addi sp,sp,16;\
  vl1re64.v v1, (sp); \
  addi sp,sp,16;\
  vl1re64.v v2, (sp); \
  addi sp,sp,16;\
  vl1re64.v v3, (sp); \
  addi sp,sp,16;\
  vl1re64.v v4, (sp); \
  addi sp,sp,16;\
  vl1re64.v v5, (sp); \
  addi sp,sp,16;\
  vl1re64.v v6, (sp); \
  addi sp,sp,16;\
  vl1re64.v v7, (sp); \
  addi sp,sp,16;\
  vl1re64.v v8, (sp); \
  addi sp,sp,16;\
  vl1re64.v v9, (sp); \
  addi sp,sp,16;\
  vl1re64.v v10, (sp); \
  addi sp,sp,16;\
  vl1re64.v v11, (sp); \
  addi sp,sp,16;\
  vl1re64.v v12, (sp); \
  addi sp,sp,16;\
  vl1re64.v v13, (sp); \
  addi sp,sp,16;\
  vl1re64.v v14, (sp); \
  addi sp,sp,16;\
  vl1re64.v v15, (sp); \
  addi sp,sp,16;\
  vl1re64.v v16, (sp); \
  addi sp,sp,16;\
  vl1re64.v v17, (sp); \
  addi sp,sp,16;\
  vl1re64.v v18, (sp); \
  addi sp,sp,16;\
  vl1re64.v v19, (sp); \
  addi sp,sp,16;\
  vl1re64.v v20, (sp); \
  addi sp,sp,16;\
  vl1re64.v v21, (sp); \
  addi sp,sp,16;\
  vl1re64.v v22, (sp); \
  addi sp,sp,16;\
  vl1re64.v v23, (sp); \
  addi sp,sp,16;\
  vl1re64.v v24, (sp); \
  addi sp,sp,16;\
  vl1re64.v v25, (sp); \
  addi sp,sp,16;\
  vl1re64.v v26, (sp); \
  addi sp,sp,16;\
  vl1re64.v v27, (sp); \
  addi sp,sp,16;\
  vl1re64.v v28, (sp); \
  addi sp,sp,16;\
  vl1re64.v v29, (sp); \
  addi sp,sp,16;\
  vl1re64.v v30, (sp); \
  addi sp,sp,16;\
  vl1re64.v v31, (sp); \
  csrw CSR_MSTATUS, t3; \


//#else
//#define VCSRS(f) NOP;
//#define RESTORE_VECTORS(f) NOP;
//#endif // CONFIG_RVV

#define CSRS_RESTORE(name, addr) \
  li t2, addr; \
  slli t2, t2, 3; \
  add t2, t0, t2; \
  ld t1, (t2); \
  csrw addr, t1; \

#endif
