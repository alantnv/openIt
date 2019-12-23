/// <summary>
/// ���������� ������ CLogic
/// </summary>
#ifndef __LOGIC_H__
#define __LOGIC_H__

#include <cstdint>

#include "field.h"

#define PLAYERS 2

/// <summary>
/// ����� ������� ������
/// </summary>
class CLogic
{
public:
    /// <summary>
    /// ��������� ��� �������� ���������� �������
    /// </summary>
    struct TCursor
    {
        uint8_t x;
        uint8_t y;
    };

public:
    /// <summary>
    /// �������� ��������� ����
    /// </summary>
    /// <param name="cursorX">[in] ������� ������� �� X</param>
    /// <param name="cursorY">[in] ������� ������� �� Y</param>
    /// <returns>��������� true, ���� ������ ������� ������ ����� � false � ���� ������</returns>
    /// <remarks>���� ������� ����������, ���� ��� ������ ������� ��� ������ ������� ��� �� �������� �������</remarks>
    bool IsEndGame(const uint8_t cursorX, const uint8_t cursorY);

private:
    /// <summary>
    /// ���� �����
    /// </summary>
    uint16_t m_score[PLAYERS];

    uint8_t m_activePlayer = 0;

    /// <summary>
    /// ������� ����
    /// </summary>
    CField m_field;

    /// <summary>
    /// ��������� �������� �������
    /// </summary>
    TCursor m_cursor = {FIELD_SIZE / 2, FIELD_SIZE / 2};
};

#endif // __LOGIC_H__
