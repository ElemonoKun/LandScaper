#include "MainUnit.h"
#include "GenDef.h"
#include <Adafruit_PWMServoDriver.h>

/* 現在のモードステータスのゲッター */
eUnitModeState MainUnit::GetNowUnitState()
{
    return _NowModeState;
}

/* 現在のモードステータスのセッター */
void MainUnit::SetNowUnitState(eUnitModeState unitModeState)
{
    _NowModeState = unitModeState;
}

/* 関数テーブルを実行する関数 */
void MainUnit::Exec(int funcIndex)
{
    (this->*funcTable[funcIndex])(); 
}

/* ユニット初期化関数 */
void MainUnit::Init(void)
{
  if(GetNowUnitState() == INIT)
  {
      Serial.println("UnitCreate!!!");
      _servo = Adafruit_PWMServoDriver();
      _servo.begin();
      _servo.setPWMFreq(60); //60Hz
  }
}

/* サーボの角度を書き込みする関数 */
void MainUnit::ServoWrite(int id, int ang)
{
    Serial.println("servoWrite");
#ifdef DEBUG
    Serial.println(id);
    Serial.println(ang);
#endif
    ang = map(ang, 0, 180, SERVOMIN, SERVOMAX);
    _servo.setPWM(id, 0, ang);
}

/* 各サーボをスタートポジションにセットする関数 */
void MainUnit::SetStartPos(void)
{
  for(eServoPinsSet unit_i = eServoPinsSet::FRONT_RIGHT_INNER;
      unit_i < eServoPinsSet::UNIT_MAX;
      unit_i++)
  {
    switch(unit_i)
    {
      case FRONT_RIGHT_INNER:
          ServoWrite(unit_i,FRONT_RIGHT_INNER_START_POS);
          break;
      case BACK_RIGHT_INNER:
          ServoWrite(unit_i,BACK_RIGHT_INNER_START_POS);
          break;
      case FRONT_LEFT_INNER:
          ServoWrite(unit_i,FRONT_LEFT_INNER_START_POS);
          break;
      case BACK_LEFT_INNER:
          ServoWrite(unit_i,BACK_LEFT_INNER_START_POS);
          break;
      case FRONT_RIGHT_OUTER:
          ServoWrite(unit_i,FRONT_RIGHT_OUTER_START_POS);
          break;
      case BACK_RIGHT_OUTER:
          ServoWrite(unit_i,BACK_RIGHT_OUTER_START_POS);
          break;
      case FRONT_LEFT_OUTER:
          ServoWrite(unit_i,FRONT_LEFT_OUTER_START_POS);
          break;
      case BACK_LEFT_OUTER:
          ServoWrite(unit_i,BACK_LEFT_OUTER_START_POS);
          break;
      case HEAD:
          ServoWrite(unit_i,HEAD_START_POS);
          break;
      default:
          break;    
    }
    delay(1000);
  }
    
}

/* 各サーボをスタートポジションにセットする関数 */
void MainUnit::Set90DegPos(void)
{
  for(eServoPinsSet unit_i = eServoPinsSet::FRONT_RIGHT_INNER;
      unit_i < eServoPinsSet::UNIT_MAX;
      unit_i++)
  {
    switch(unit_i)
    {
      case FRONT_RIGHT_INNER:
          ServoWrite(unit_i,90);
          break;
      case BACK_RIGHT_INNER:
          ServoWrite(unit_i,90);
          break;
      case FRONT_LEFT_INNER:
          ServoWrite(unit_i,90);
          break;
      case BACK_LEFT_INNER:
          ServoWrite(unit_i,90);
          break;
      case FRONT_RIGHT_OUTER:
          ServoWrite(unit_i,90);
          break;
      case BACK_RIGHT_OUTER:
          ServoWrite(unit_i,90);
          break;
      case FRONT_LEFT_OUTER:
          ServoWrite(unit_i,90);
          break;
      case BACK_LEFT_OUTER:
          ServoWrite(unit_i,90);
          break;
      case HEAD:
          //ServoWrite(unit_i,90);
          break;
      default:
          break;    
    }
    delay(1000);
    Serial.println(unit_i);
  }
    
}

void MainUnit::FrontWalk(void) 
{
    //TBD
}

/* 静的配列サイズ取得用関数 */
template<typename T, std::size_t size>
std::size_t ArrayLength(const T(&)[size])
{
  return size;
}
