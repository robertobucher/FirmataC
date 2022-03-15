Customized INO files for Firmata

## VL53L0X - v25_with_vl53l0x.ino

Extends the standard Firmata library with the VL53L0X sensor.

* based on StandardFirmata-2.5.ino
* requires VL53L0X library https://github.com/pololu/vl53l0x-arduino

| Command                               | Description                                                      |
|---------------------------------------|------------------------------------------------------------------|
| FIRMATA_VL53L0X_GET_DISTANCE ( 0x81 ) | Returns message from VL53L0X 0 to 255 where 255 represents 512mm | 
