#include "BQ20Z45.h"
#include "Arduino.h"


/////////////////////////////////////////////////////////////////////////////
// Functions Below

void BQ20Z45::write(uint8_t address, uint8_t data)
{
  Wire.beginTransmission(BQ20Z45_Address);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

uint8_t BQ20Z45::read(uint8_t address)
{
	uint8_t registerValue;
      Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(BQ20Z45_Address,1,true);
	registerValue = Wire.read();
	Wire.endTransmission();
        return registerValue;
}

uint16_t BQ20Z45::read16u(uint8_t address)
{
	uint16_t registerValue;
      Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	Wire.requestFrom(BQ20Z45_Address,2,true);
	registerValue = Wire.read();
     registerValue |= (Wire.read()<<8);
	
        return registerValue;
}

uint16_t BQ20Z45::read16u2(uint8_t address)
{
	uint16_t registerValue;
      Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	Wire.requestFrom(BQ20Z45_Address,4,true);
	Wire.read();
        registerValue = Wire.read();
        registerValue |= (Wire.read()<<8);;
	
        return registerValue;
}

int16_t BQ20Z45::read16(uint8_t address)
{
	int16_t registerValue;
        Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	Wire.requestFrom(BQ20Z45_Address,2,true);
	registerValue = Wire.read();
        registerValue += (Wire.read()*256);

        return registerValue;
}

uint32_t BQ20Z45::read32u(uint8_t address)
{
	uint32_t registerValue;
      Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	Wire.requestFrom(BQ20Z45_Address,5,true);
	    Wire.read();
        registerValue = Wire.read();
        registerValue |= (Wire.read()<<8);
        registerValue |= (Wire.read() << 16);
        registerValue |= (Wire.read() << 24);
		
        return registerValue;
}


// pass a pointer to a char[] that can take up to 33 chars
// will return the length of the string received
int readString(uint8_t address, char* result)
{
	int pos = 0;
	int len;

        // Read the length of the string
	Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	Wire.requestFrom(BQ20Z45_Address, 1, true);
	len = Wire.read();    // length of the string
        len++;            // plus one to allow for the length byte on the reread
                          // if len > 32 then the it will be truncated to 32 by requestFrom

        // Now that we know the length, repeat the read to get all the string data. 
        // we need to write the address again and do a restart so its a valid SMBus transaction
	Wire.beginTransmission(BQ20Z45_Address);
	Wire.write(address);
	Wire.endTransmission(false);
	len = Wire.requestFrom(BQ20Z45_Address, len, true);    // readRequest returns # bytes actually read

        len--;                                             // we won't move the first byte as its not part of the string
	if (len > 0)
	{
                Wire.read();
		for (pos = 0; pos < len; pos++)
			result[pos] = Wire.read();
	}
	result[pos] = '\0';  // append the zero terminator
	
	return len;
}

/////////////////////////////////////////////////////////////////////////////
// Class Methods Below


float BQ20Z45::GetTemp()
{
 
	return (float)read16u(BQ20Z45_Temp)/10;
}

float BQ20Z45::GetVoltage()
{
 
	return (float)read16u(BQ20Z45_Volt)/1000;
}

float BQ20Z45::GetCurrent()
{
 
	return (float)read16(BQ20Z45_Current)/1000;
}
float BQ20Z45::AverageCurrent()
{
 
	return (float)read16(BQ20Z45_AveCurrent)/1000;
}
uint8_t BQ20Z45::RelativeSOC()
{
 
	return (float)read(BQ20Z45_RelativeSOC);

}
uint8_t BQ20Z45::AbsoluteSOC()
{
 
	return (float)read(BQ20Z45_AbsoluteSOC);

}
float BQ20Z45::RemainingCapAlarm()
{
 
	return (float)read16u(BQ20Z45_RemainCapAlarm);
}
float BQ20Z45::RemainingTimeAlarm()
{
 
	return (float)read16u(BQ20Z45_RemainTimeAlarm);
}
float BQ20Z45::AtRate()
{

	return (float)read16(BQ20Z45_AtRate);
}
uint8_t BQ20Z45::MaxError()
{
 
	return (float)read(BQ20Z45_MaxError);
}
float BQ20Z45::AtRateTimeToFull()
{
 
	return (float)read16u(BQ20Z45_AtRateTimeToFull);
}
float BQ20Z45::AtRateTimeToEmpty()
{
 
	return (float)read16u(BQ20Z45_AtRateTimeToEmpty);
}
float BQ20Z45::AtRateOK()
{
 
	return (float)read16u(BQ20Z45_AtRateOK);
}
float BQ20Z45::RemainingBatteryCapacity()
{
 
	return (float)read16u(BQ20Z45_RemCap );
}
float BQ20Z45::FullBatteryCapacity()
{
 
	return (float)read16u(BQ20Z45_FullChargCap );
}
float BQ20Z45::RunTimeTillEmpty()
{
 
	return (float)read16u(BQ20Z45_RunTime2Empty );
}
float BQ20Z45::AverageTimeTillEmpty()
{
 
	return (float)read16u(BQ20Z45_AveTime2Empty );	
}
float BQ20Z45::AverageTimeTillFull()
{
 
	return (float)read16u(BQ20Z45_AveTime2Full );	
}
float BQ20Z45::ChargingCurrent()
{
 
	return (float)read16u(BQ20Z45_ChargCurrent );	
}
float BQ20Z45::ChargingVoltage()
{
 
	return (float)read16u(BQ20Z45_ChargVolt );	
}
float BQ20Z45::CycleCount()
{
 
	return (float)read16u(BQ20Z45_CycleCount );	
}
float BQ20Z45::DesignCapacity()
{
 
	return (float)read16u(BQ20Z45_DesignCapacity );	
}
float BQ20Z45::DesignVoltage()
{
 
	return (float)read16u(BQ20Z45_DesignVoltage );	
}
float BQ20Z45::CellVoltage1()
{
 
	return (float)read16u(BQ20Z45_CellVolt1 );	
}
float BQ20Z45::CellVoltage2()
{
 
	return (float)read16u(BQ20Z45_CellVolt2 );	
}
float BQ20Z45::CellVoltage3()
{
 
	return (float)read16u(BQ20Z45_CellVolt3 );	
}
float BQ20Z45::CellVoltage4()
{
 
	return (float)read16u(BQ20Z45_CellVolt4 );	
}
float BQ20Z45::PendingEVD()
{
 
	return (float)read16u(BQ20Z45_PendingEDV );	
}
uint8_t BQ20Z45::StateOfHealth()
{
 
	return (float)read(BQ20Z45_StateOfHealth);
}

uint16_t BQ20Z45::BatteryStatus()
{
 
	return read16u(BQ20Z45_BatteryStatus);
}

uint32_t BQ20Z45::SafetyAlert()
{
 
	return read32u(BQ20Z45_SafetyAlert);
}

uint32_t BQ20Z45::SafetyStatus()
{
 
	return read32u(BQ20Z45_SafetyStatus);
}

uint16_t BQ20Z45::PFAlert()
{
 
	return read16u2(BQ20Z45_PFAlert);
}

uint16_t BQ20Z45::PFStatus()
{
 
	return read16u2(BQ20Z45_PFStatus);
}

uint32_t BQ20Z45::OperationStatus()
{
 
	return read32u(BQ20Z45_OperationStatus);
}

uint16_t BQ20Z45::ChargingStatus()
{
 
	return read16u(BQ20Z45_ChargingStatus);
}


int BQ20Z45::readString(uint8_t address, char* result) /// This isn't all thats needed here right? I don't know what should go below. HELP!
