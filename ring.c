/* http://www.ganssle.com/tem/tem110.pdf */

#include "ring.h"
#include  <string.h>


void ringBuffer_init (ringBuffer* _this)
{
    memset (_this->buf, 0, sizeof(_this->buf));
    _this->head = 0;
    _this->tail = 0;
}

uint8_t ringBuffer_empty (ringBuffer* _this)
{
    return (_this->head == _this->tail);
}

uint8_t ringBuffer_get (ringBuffer* _this)
{
    if (ringBuffer_empty(_this))
        return (0);

    uint8_t c;
    c = _this->buf[_this->tail & (RBUF_SIZE - 1)];
    _this->tail++;
    return (c);
}

void ringBuffer_put(ringBuffer* _this, uint8_t c)
{
    if (!ringBuffer_empty(_this))
        return;

    _this->buf[_this->head & (RBUF_SIZE - 1)] = c;
    _this->head++;
}
