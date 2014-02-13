#ifndef RING_H
#define	RING_H

#include <stdint.h>

#define RBUF_SIZE   64

typedef struct ringBuffer_t
{
  uint8_t buf[RBUF_SIZE];
  uint8_t head;
  uint8_t tail;
} ringBuffer;

void ringBuffer_init(ringBuffer* _this);
uint8_t ringBuffer_empty(ringBuffer* _this);
uint8_t ringBuffer_full(ringBuffer* _this);
uint8_t ringBuffer_get(ringBuffer* _this);
void ringBuffer_put(ringBuffer* _this, uint8_t c);
void ringBuffer_flush(ringBuffer* _this, uint8_t clearBuffer);

#endif	/* RING_H */

