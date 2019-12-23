#pragma once
#define MIN_PULSE_WIDTH  544             // microsecWrite  最小PWM
#define MAX_PULSE_WIDTH 2400             // microsecWrite  最大PWM
#define SERVOMIN 150                     // PCA9
#define SERVOMAX 600                     // this is the 'maximum' pulse length count (out of 4096)
#define FUNC_MAX 4                       // 関数テーブルの数


// インクリメントできるようにenumのオーバーロード
template<typename ENAM_T>
ENAM_T& operator ++ (ENAM_T& pos, int)
{
  pos = static_cast<ENAM_T>(pos + 1);
  return pos;
}

/* スタートポジション用 */
enum eUnitStartPos
{
    FRONT_RIGHT_INNER_START_POS = 120,
    BACK_RIGHT_INNER_START_POS  =  30,
    FRONT_LEFT_INNER_START_POS  =  60,
    BACK_LEFT_INNER_START_POS   = 150,
    FRONT_RIGHT_OUTER_START_POS =  30,
    BACK_RIGHT_OUTER_START_POS  = 150,
    FRONT_LEFT_OUTER_START_POS  = 150,
    BACK_LEFT_OUTER_START_POS   =  30,
    HEAD_START_POS              =  90,
    UNIT_POS_SETEND,
};

enum eServoPinsSet
{
    FRONT_RIGHT_INNER,
    BACK_RIGHT_INNER,
    FRONT_LEFT_INNER,
    BACK_LEFT_INNER,
    FRONT_RIGHT_OUTER,
    BACK_RIGHT_OUTER,
    FRONT_LEFT_OUTER,
    BACK_LEFT_OUTER,
    HEAD,
    UNIT_MAX,
};

enum eUnitModeState
{
  INIT,
  OPERATION,
  TORN_OFF, 
};

enum eBootMode
{
  ADDR_JUMPER_NOT_CON = 0x40,
  A_ZERO_JUMPER_CON,
};
