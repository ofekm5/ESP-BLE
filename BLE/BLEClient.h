#ifndef BLE_H
#define BLE_H

#include <ArduinoBLE.h>

class BLEClient {
  public:
    BLEClient();
    void Init();
    void Update();
    bool FinishedSync();
    String getPropertyOne();
    String getPropertyTwo();
    String getPropertyThree();
  private:
    bool m_Synced;
    BLEService m_Service;
    BLEStringCharacteristic m_PropertyOne;
    BLEStringCharacteristic m_PropertyTwo;
    BLEStringCharacteristic m_PropertyThree;
    void setupBLE();
    void startAdvertising();
};

#endif 
