#include <stdint.h>

static inline void outb(uintptr_t addr, uint8_t data) { *(volatile uint8_t *)addr = data; }
static inline uint8_t inb(uintptr_t addr) { return *(volatile uint8_t *)addr; }

#define UARTLITE_MMIO 0x40600000
#define UARTLITE_RX_FIFO 0x0
#define UARTLITE_TX_FIFO 0x4
#define UARTLITE_STAT_REG 0x8
#define UARTLITE_CTRL_REG 0xc

#define UARTLITE_RST_FIFO 0x3
#define UARTLITE_TX_FULL 0x8
#define UARTLITE_RX_VALID 0x1

static inline void putchr(char ch)
{
    while (inb(UARTLITE_MMIO + UARTLITE_STAT_REG) & UARTLITE_TX_FULL);
    outb(UARTLITE_MMIO + UARTLITE_TX_FIFO, ch);
}

void gcpt_puts(const char *str) 
{
    while (*str != '\0')
        putchr(*str++);
}