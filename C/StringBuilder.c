#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER 16

struct StringBuilder {
    char* buffer;
    size_t buffer_length;
    size_t position;
};

struct StringBuilder* make_sb(void)
{
    struct StringBuilder* this = (struct StringBuilder*)malloc(sizeof(struct StringBuilder));
    this->buffer_length = INITIAL_BUFFER;
    this->buffer = malloc(this->buffer_length);
    this->buffer[0] = '\0';
    this->position = 0;
    return this;
}

static void sb_ensure_size(struct StringBuilder* this, size_t length)
{
    size_t size = this->position + length + 1;
    if (this->buffer_length > size) {
        return;
    }

    char* old_buffer = this->buffer;
    while (this->buffer_length < size) {
        this->buffer_length *= 2;
    }
    this->buffer = malloc(this->buffer_length);
    memcpy(this->buffer, old_buffer, this->position + 1);
    free(old_buffer);
}

void sb_append(struct StringBuilder* this, const char* s)
{
    size_t length = strlen(s);
    sb_ensure_size(this, length);
    memcpy(this->buffer + this->position, s, length + 1);
    this->position += length;
}

void sb_append_long(struct StringBuilder* this, long l)
{
    sb_ensure_size(this, 10);
    int written = sprintf(this->buffer + this->position, "%lu", l);
    this->position += written;
}

void sb_append_double(struct StringBuilder* this, double d)
{
    sb_ensure_size(this, 24);
    int written = sprintf(this->buffer + this->position, "%f", d);
    this->position += written;
}

const char* sb_string(struct StringBuilder* this)
{
    const char* s = this->buffer;
    free(this);
    return s;
}
