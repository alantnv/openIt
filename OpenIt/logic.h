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
    /// Победитель
    /// </summary>
    enum EWinner
    {
        /// <summary>
        /// Не определён, т.к. игра ещё не окончена
        /// </summary>
        INDEFINED,
        PLAYER_1,
        PLAYER_2,
        /// <summary>
        /// Ничья
        /// </summary>
        DRAW
    };

    /// <summary>
    /// Направления перемещения курсора
    /// </summary>
    enum EDirection
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    /// <summary>
    /// Структура для описания координаты курсора
    /// </summary>
    struct SCursor
    {
        uint8_t x;
        uint8_t y;
    };

public:
    /// <summary>
    /// Конструктор
    /// </summary>
    CLogic();

    /// <summary>
    /// Деструктор
    /// </summary>
    ~CLogic();

    /// <summary>
    /// Начинает новую игру
    /// </summary>
    void NewGame();

    /// <summary>
    /// Проверка окончания игры
    /// </summary>
    /// <returns>Возращает true, если нельзя сделать больше ходов и false в ином случае</returns>
    /// <remarks>Игра считает оконченной, если все ячейки открыты или нельзя сделать ход из заданной позиции</remarks>
    bool IsEndGame();

    /// <summary>
    /// Сообщает победителя
    /// </summary>
    /// <returns>Возвращает:
    /// <see cref="EWinner::INDEFINED"/>, если игра не завершена и победитель не определён;
    /// <see cref="EWinner::DRAW"/>, если игра окончилась в ничью;
    /// <see cref="EWinner::PLAYER_1"/> или <see cref="EWinner::PLAYER_2"/> в зависимости от победителя</returns>
    EWinner GetWinner();

    /// <summary>
    /// Смещает курсор на одну позицию в заданном направлении
    /// </summary>
    /// <param name="direction">[in] Направление перемещения курсора</param>
    /// <returns>Возвращает true, если курсор был перемещён или false, если перемещение невозможно</returns>
    /// <remarks>Смещение курсора в указанном направлении невозможно, если новая позиция окажется за пределами поля
    /// или активный игрок не может перемещать курсор в данном направлении</remarks>
    bool MoveCursor(EDirection direction);

private:
    /// <summary>
    /// Счёт очков
    /// </summary>
    uint16_t m_score[PLAYERS];

    /// <summary>
    /// Номер активного игрока(того, которой должен делать ход)
    /// </summary>
    uint8_t  m_activePlayer     = 0;

    /// <summary>
    /// Игровое поле
    /// </summary>
    CField   m_field;

    /// <summary>
    /// Положение игрового курсора
    /// </summary>
    SCursor  m_cursor           = {FIELD_SIZE / 2, FIELD_SIZE / 2};
};

#endif // __LOGIC_H__
