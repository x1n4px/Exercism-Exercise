#include "queen_attack.h"
static bool is_valid_position(position_t queen)
{
    return queen.column >= 0 && queen.column < 8 && queen.row >= 0 && queen.row < 8;
}
static bool is_the_same_position(position_t queen_1, position_t queen_2)
{
    return queen_1.row == queen_2.row && queen_1.column == queen_2.column;
}
static bool is_on_the_same_line(position_t queen_1, position_t queen_2)
{
    return queen_1.row == queen_2.row || queen_1.column == queen_2.column;
}
static bool is_on_the_same_diagonal(position_t queen_1, position_t queen_2)
{
    bool lr = queen_1.column + queen_1.row == queen_2.column + queen_2.row;
    bool rl = queen_1.column - queen_1.row == queen_2.column - queen_2.row;
    return lr || rl;
}
attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (!is_valid_position(queen_1) || !is_valid_position(queen_2) || is_the_same_position(queen_1, queen_2))
        return INVALID_POSITION;
    if (is_on_the_same_line(queen_1, queen_2) || is_on_the_same_diagonal(queen_1, queen_2))
        return CAN_ATTACK;
    return CAN_NOT_ATTACK;
}