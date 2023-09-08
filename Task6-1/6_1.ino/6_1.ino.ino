#include <Wire.h>

const int MPU_addr=0x68;  // I2C address of MPU6050

int16_t accel_x, accel_y, accel_z;
int16_t gyro_x, gyro_y, gyro_z;

float yaw_angle = 0.0;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers

  accel_x=Wire.read()<<8|Wire.read();  // combine high and low byte for each axis
  accel_y=Wire.read()<<8|Wire.read();
  accel_z=Wire.read()<<8|Wire.read();
  Wire.read()<<8|Wire.read();  // temperature (discard)
  gyro_x=Wire.read()<<8|Wire.read();
  gyro_y=Wire.read()<<8|Wire.read();
  gyro_z=Wire.read()<<8|Wire.read();

  float gyro_rate_z = (float)gyro_z / 131.0;  // convert raw gyro data to degrees per second
  yaw_angle += gyro_rate_z * 0.01; // integrate over time (assuming 100Hz update rate)

  Serial.print("Yaw angle: ");
  Serial.println(yaw_angle);

  delay(10);
}