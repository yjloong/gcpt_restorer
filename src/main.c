#include <stdint.h>
#include "encoding.h"
#include "common.h"

static inline void dump() {
    uint32_t stage = csr_read(CSR_MHPMCOUNTER18);
    uint64_t cycles = csr_read(CSR_MCYCLE);
    uint64_t insns = csr_read(CSR_MINSTRET);

    printf("\r\nSTAGE:%d:CYCLE:%lx\r\n", stage, cycles);
    printf("STAGE:%d:INSN:%lx\r\n", stage, insns);

    stage++;
    csr_write(CSR_MHPMCOUNTER18, stage);
}

void main() {
    uint64_t inhibit = csr_swap(CSR_MCOUNTINHIBIT, ~0x0UL);

    dump();

    if (csr_read(CSR_MHPMEVENT15) & 0x8000000000000000UL) {
        inhibit |= (1 << 15);
        csr_clear(CSR_MHPMEVENT15, 0x8000000000000000UL);
    }

    if (csr_read(CSR_MHPMEVENT16) & 0x8000000000000000UL) {
        inhibit |= (1 << 16);
        csr_clear(CSR_MHPMEVENT16, 0x8000000000000000UL);
        while(1) asm("wfi");
    }

    csr_write(CSR_MCOUNTINHIBIT, inhibit);
    csr_clear(CSR_MIP, 0x2000);
}