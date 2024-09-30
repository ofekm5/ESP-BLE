#include "BLEClient.h"

BLEClient::BLEClient(): m_Service("fff0"), m_PropertyOne("fff1", BLERead | BLEWrite, 100), m_PropertyTwo("fff2", BLERead | BLEWrite, 10),
  m_PropertyThree("fff3", BLERead | BLEWrite, 20)
{
  this->m_Synced = false;
}

bool BLEClient::FinishedSync(){
  return this->m_Synced;
}

void BLEClient::Init(){
  while(!BLE.begin()) {
    Serial.println("failed to initialize BLE!");
  }
  this->setupBLE();
  this->startAdvertising();
}

void BLEClient::setupBLE() {
  BLE.setDeviceName("MyBLE");
  this->m_Service.addCharacteristic(this->m_PropertyOne);
  this->m_Service.addCharacteristic(this->m_PropertyTwo);
  this->m_Service.addCharacteristic(this->m_PropertyThree);

  BLE.addService(this->m_Service);
  BLE.setAdvertisedService(this->m_Service);

  const uint8_t completeRawAdvertisingData[] = {0x02, 0x01, 0x06, 0x09, 0xff, 0x01, 0x01, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
  BLE.setManufacturerData(completeRawAdvertisingData, sizeof(completeRawAdvertisingData));
}

void BLEClient::startAdvertising(){
  BLE.advertise();
  Serial.println("BLE advertising ...");
}

void BLEClient::Update(){
  BLEDevice central = BLE.central(); 

  if(central) { // if there is currently a central device connected to the peripheral (ESP32).
    Serial.println((String("Connected to central: ") + central.address()).c_str());

    while(central.connected()){
      BLE.poll();
      if(this->m_PropertyOne.written()) {
        Serial.println((String("PropertyOne: ") + this->m_PropertyOne.value()).c_str());
      }
      else if(this->m_PropertyTwo.written()) {
        Serial.println((String("PropertyTwo: ") + this->m_PropertyTwo.value()).c_str());
      }
      else if(this->m_PropertyThree.written()) {
        Serial.println((String("PropertyThree: ") + this->m_PropertyThree.value()).c_str());
      }
    }
  }

  if(!central.connected()) {
    Serial.println((String("Disconnected from central: ") + central.address()).c_str());
  }
}

String BLEClient::getPropertyOne(){
  return this->m_PropertyOne.value();
}

String BLEClient::getPropertyTwo(){
  return this->m_PropertyTwo.value();
}

String BLEClient::getPropertyThree(){
  return this->m_PropertyThree.value();
}
