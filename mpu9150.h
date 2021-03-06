
#ifndef MPU9150_H
#define MPU9150_H

/*lint ++flb "Enter library region" */

#include <stdbool.h>
#include <stdint.h>

/** @file
* @brief MPU6050 gyro/accelerometer driver.
*
*
* @defgroup nrf_drivers_mpu9150 MPU6050 gyro/accelerometer driver
* @{
* @ingroup nrf_drivers
* @brief MPU6050 gyro/accelerometer driver.
*/

/**
 * @brief Function for initializing MPU6050 and verifies it's on the bus.
 *
 * @param device_address Device TWI address in bits [6:0].
 * @return
 * @retval true MPU6050 found on the bus and ready for operation.
 * @retval false MPU6050 not found on the bus or communication failure.
 */
bool mpu9150_init(uint8_t device_address);

/**
  @brief Function for writing a MPU6050 register contents over TWI.
  @param[in]  register_address Register address to start writing to
  @param[in] value Value to write to register
  @retval true Register write succeeded
  @retval false Register write failed
*/
bool mpu9150_register_write(uint8_t register_address, const uint8_t value);

/**
  @brief Function for reading MPU6050 register contents over TWI.
  Reads one or more consecutive registers.
  @param[in]  register_address Register address to start reading from
  @param[in]  number_of_bytes Number of bytes to read
  @param[out] destination Pointer to a data buffer where read data will be stored
  @retval true Register read succeeded
  @retval false Register read failed
*/
bool mpu9150_register_read(uint8_t register_address, uint8_t *destination, uint8_t number_of_bytes);

/**
  @brief Function for reading and verifying MPU6050 product ID.
  @retval true Product ID is what was expected
  @retval false Product ID was not what was expected
*/
bool mpu9150_verify_product_id(void);

int mpu6050_i2c_write(unsigned char slave_addr,
                     unsigned char reg_addr,
                     unsigned char length,
                     unsigned char const *data);

int mpu6050_i2c_read(unsigned char slave_addr,
                     unsigned char reg_addr,
                     unsigned char length,
                     unsigned char const *data);

/**
 *@}
 **/

/*lint --flb "Leave library region" */

#endif /* MPU6050_H */
