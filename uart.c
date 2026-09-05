/* Demo UART driver for an embedded MCU. */

#define UART_BAUD_9600  9600u
#define UART_TX_READY   (1u << 0)

volatile unsigned char *const UART_STATUS = (volatile unsigned char *)0x4000;
volatile unsigned char *const UART_DATA   = (volatile unsigned char *)0x4001;

static void uart_wait_tx_ready(void)
{
    while ((*UART_STATUS & UART_TX_READY) == 0) {
        /* spin until the UART can accept another byte */
    }
}

void uart_init(unsigned int baud)
{
    (void)baud;
    *UART_STATUS = 0;
}

void uart_putc(char c)
{
    uart_wait_tx_ready();
    *UART_DATA = (unsigned char)c;
}

void uart_puts(const char *s)
{
    while (*s != '\0') {
        uart_putc(*s++);
    }
}
