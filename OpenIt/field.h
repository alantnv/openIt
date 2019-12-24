/// <summary>
/// Объявление класса CField
/// </summary>
#ifndef __FIELD_H__
#define __FIELD_H__

#include <cstdint>
#include <memory>   // shared_ptr

#include "global.h"


using namespace std;


/// <summary>
/// Класс "Игровое поле"
/// </summary>
class CField
{
public:
    /// <summary>
    /// Тип данных элементов игрового поля
    /// </summary>
    typedef uint8_t TFieldItem;

public:
    /// <summary>
    /// Конструктор
    /// </summary>
    CField();

    /// <summary>
    /// Деструктор
    /// </summary>
    ~CField();

    /// <summary>
    /// Инициализация игрового поля
    /// </summary>
    void Init();

    /// <summary>
    /// Предоставляет копию игрового поля (например, для визуализации)
    /// </summary>
    /// <returns>Возвращает указатель на пямять с копией игрового поля</returns>
    shared_ptr<TFieldItem> GetField();

    /// <summary>
    /// Открывает ячейку на игровом поле
    /// </summary>
    /// <param name="posX">[in] X-координата открываемой ячейки</param>
    /// <param name="posY">[in] Y-координата открываемой ячейки</param>
    /// <param name="value">[out] Количество полученных баллов</param>
    /// <returns>Возвращает true, если ячейка открыта успешно или false в случае ошибки
    /// (недопустимая координата или ячейка уже открыта)</returns>
    /// <remarks>Параметр <param name="value"></param> может принимать произольное значение
    /// и должен быть проигнорирован, если функция завершилась с ошибкой</remarks>
    bool OpenCell(const uint8_t posX, const uint8_t posY, TFieldItem& value);

private:
    /// <summary>
    /// Игровое поле
    /// </summary>
    TFieldItem m_field[FIELD_SIZE][FIELD_SIZE];
};

#endif // __FIELD_H__