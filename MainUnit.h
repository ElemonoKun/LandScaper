#pragma once
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Oscillator.h"
#include "GenDef.h"

class MainUnit
{
public :
//    MainUnit();
//    ~MainUnit();
    void Init(void);
    void FrontWalk(void);
    void ServoWrite(int id, int ang);
    void Exec(int funcIndex);
    eUnitModeState GetNowUnitState();
    void SetStartPos(void);
    void Set90DegPos(void);
    void SetNowUnitState(eUnitModeState unitModeState);
    /* 関数テーブル */
    void (MainUnit::* funcTable[10])(void) = { 
        &MainUnit::Init, 
        &MainUnit::Set90DegPos,
        &MainUnit::SetStartPos,
        &MainUnit::FrontWalk
    };
private:
    eUnitModeState _NowModeState = eUnitModeState::INIT;
    Adafruit_PWMServoDriver _servo;           // PCA9685のアドレス指定（アドレスジャンパ未接続時）
};
