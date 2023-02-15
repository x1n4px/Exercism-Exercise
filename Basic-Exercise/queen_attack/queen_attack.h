#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H
#include <stdint.h>
#include <stdbool.h>
typedef enum
{
   CAN_NOT_ATTACK,
   CAN_ATTACK,
   INVALID_POSITION
} attack_status_t;
typedef struct
{
   int row;
   int column;
} position_t;
attack_status_t can_attack(position_t queen_1, position_t queen_2);
#endif