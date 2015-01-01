// Include the Wire library for I2C access.
#include <Wire.h>

// BQ20Z45 library.
#include <BQ20Z45.h>

// Store an instance of the BQ20Z45 Sensor
BQ20Z45 bms;

char strBuffer[33];    // Is this where this code should be place? Inside loop better? 

void setup()
{
  // We start the serial library to output our messages.
  Serial.begin(115200);
  
  // Start i2c communication. 
  Wire.begin();
  
}

void loop()
{

    Serial.print("Temp: ");
    Serial.println(bms.GetTemp()-273);  
    
    Serial.print("Volt: ");
    Serial.println(bms.GetVoltage()); 
    
    Serial.print("Current: ");
    Serial.println(bms.GetCurrent());
    
    Serial.print("AverageCurrent: ");
    Serial.println(bms.AverageCurrent()); 
    	
    Serial.print("Realtive SOC: ");
    Serial.println(bms.RelativeSOC()); 
    
    Serial.print("Absolute SOC: ");
    Serial.println(bms.AbsoluteSOC()); 
   
    Serial.print("Remaining Capacity Alarm: ");
    Serial.println(bms.RemainingCapAlarm());  
    
    Serial.print("Remaining Time Alarm: ");
    Serial.println(bms.RemainingTimeAlarm()); 
    
    Serial.print("At Rate: ");
    Serial.println(bms.AtRate());
    	
    Serial.print("At Rate Time To Full: ");
    Serial.println(bms.AtRateTimeToFull()); 
    
    Serial.print("At Rate Time To Empty: ");
    Serial.println(bms.AtRateTimeToEmpty());
    
    Serial.print("AtRateOK: ");
    Serial.println(bms.AtRateOK());  
    
    Serial.print("MaxError: ");
    Serial.println(bms.MaxError());
    	
    Serial.print("Remaining Battery Capacity: ");
    Serial.println(bms.RemainingBatteryCapacity()); 
    
    Serial.print("Full Battery Capacity: ");
    Serial.println(bms.FullBatteryCapacity());
    
    Serial.print("Run Time Till Empty: ");
    Serial.println(bms.RunTimeTillEmpty());
    
    Serial.print("Average Time Till Empty: ");
    Serial.println(bms.AverageTimeTillEmpty());
    
    Serial.print("Average Time Till Full: ");
    Serial.println(bms.AverageTimeTillFull());
    
    Serial.print("Charging Current: ");
    Serial.println(bms.ChargingCurrent());
    
    Serial.print("Charging Voltage: ");
    Serial.println(bms.ChargingVoltage());
    
    Serial.print("Cycle Count: ");
    Serial.println(bms.CycleCount());
    
    Serial.print("Design Capacity: ");
    Serial.println(bms.DesignCapacity());
    
    Serial.print("Design Voltage: ");
    Serial.println(bms.DesignVoltage());
    
    Serial.print("Cell 1 Voltage: ");
    Serial.println(bms.CellVoltage1());
    
    Serial.print("Cell 2 Voltage: ");
    Serial.println(bms.CellVoltage2());
    
    Serial.print("Cell 3 Voltage: ");
    Serial.println(bms.CellVoltage3());
    
    Serial.print("Cell 4 Voltage: ");
    Serial.println(bms.CellVoltage4());
    
    Serial.print("Pending EVD: ");
    Serial.println(bms.PendingEVD());
    
    Serial.print("State of Health: ");
    Serial.println(bms.StateOfHealth());
    
    Serial.print("Battery Status Flags: ");
    Serial.println(bms.BatteryStatus(),HEX);
    
    Serial.print("Safety Alerts: ");
    Serial.println(bms.SafetyAlert(),HEX);
    
    Serial.print("Safety Status: ");
    Serial.println(bms.SafetyStatus(),HEX);
    
    Serial.print("Permanent Failure Alert: ");
    Serial.println(bms.PFAlert(),HEX);
    
    Serial.print("Permanent Failure Status: ");
    Serial.println(bms.PFStatus(),HEX);
    
    Serial.print("Operating Status: ");
    Serial.println(bms.OperationStatus(),HEX);
    
    Serial.print("Charging Status: ");
    Serial.println(bms.ChargingStatus(),HEX);
  

   bms.readString(BQ20Z45_ManufactureName, strBuffer);    //This is exactly as suggested right? 
   Serial.println(strBuffer);

 
    


    Serial.println();
    delay(3000); // Show new results every second.
  
}
