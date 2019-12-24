/// <summary>
/// Объявление класса CLogic
/// </summary>
#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <cstdint>

#include "global.h"
#include "field.h"

/// <summary>
/// Класс игровой логики
/// </summary>
class CLogic
{
public:
    /// <summary>
    /// Структура для описания координаты курсора
    /// </summary>
    struct TCursor
    {
        uint8_t x;
        uint8_t y;
    };

public:
    /// <summary>
    /// Проверка окончания игры
    /// </summary>
    /// <param name="cursorX">[in] Позиция курсора по X</param>
    /// <param name="cursorY">[in] Позиция курсора по Y</param>
    /// <returns>Возращает true, если нельзя сделать больше ходов и false в ином случае</returns>
    /// <remarks>Игра считает оконченной, если все ячейки открыты или нельзя сделать ход из заданной позиции</remarks>
    bool IsEndGame(const uint8_t cursorX, const uint8_t cursorY);

private:
    /// <summary>
    /// Счёт очков
    /// </summary>
    uint16_t m_score[PLAYERS];

    uint8_t m_activePlayer = 0;

    /// <summary>
    /// Игровое поле
    /// </summary>
    CField m_field;

    /// <summary>
    /// Положение игрового курсора
    /// </summary>
    TCursor m_cursor = {FIELD_SIZE / 2, FIELD_SIZE / 2};
};

#endif // __LOGIC_H__
