#include "circular_buffer.h"
#include<errno.h>
#include<stdlib.h>

struct circular_buffer_s{
   size_t capacity;
    size_t size;
    buffer_value_t *_head;
    buffer_value_t *_tail;
    buffer_value_t _data[];
};


circular_buffer_t *new_circular_buffer(size_t capacity){
    circular_buffer_t *buffer = malloc(sizeof(*buffer) + sizeof(buffer_value_t)*capacity);
    if(!buffer){
        return NULL;
    }
    buffer->capacity = capacity;
    clear_buffer(buffer);
    return buffer;
}


void delete_buffer(circular_buffer_t *buffer){
    free(buffer);
}


int16_t write(circular_buffer_t *buffer, buffer_value_t value){
    if(!buffer){
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    if(buffer->size == buffer->capacity){
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }
return overwrite(buffer, value);
}


int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value){
    if(!buffer){
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    if(buffer->size == buffer->capacity){
        buffer_value_t discard;
        read(buffer, &discard);
    }
    *(buffer->_tail++) = value;
    if(buffer->_tail == buffer->_data + buffer->capacity){
        buffer->_tail = buffer->_data;
    }
    ++buffer->size;
    return EXIT_SUCCESS;
}


int16_t read(circular_buffer_t *buffer, buffer_value_t *value){
    if(!buffer || !value || buffer->size == 0){
        errno = ENODATA;
        return EXIT_FAILURE;
    }
    *value = *(buffer->_head++);
    if(buffer->_head == buffer->_data + buffer->capacity){
        buffer->_head = buffer->_data;
    }
    --buffer->size;
    return EXIT_SUCCESS;
}


void clear_buffer(circular_buffer_t *buffer){
    buffer->size = 0;
    buffer->_head = buffer->_data;
    buffer->_tail = buffer->_data;
}