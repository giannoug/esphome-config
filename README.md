<h1 align="center">
  <br>
    <a href="https://github.com/giannoug/esphome-config"><img src="https://i.imgur.com/I6v9SDO.png" alt="esphome-config" width="100"></a>
  <br>
    esphome-config
  <br>
</h1>

<h4 align="center">A collection of ESPHome configuration files</h4>

# Devices
Devices are currently only used to collect data in a Prometheus database and are primarily used for monitoring. This configuration currently also doesn't rely on Home Assistant or any home automation system at all.

## Mother
An ESP32 dev board that acts as a BLE tracker using the [esp32_ble_tracker](https://esphome.io/components/esp32_ble_tracker.html) component. Currently, it receives messages from six different Xiaomi LYWSD03MMC thermometers. The devices are flashed with the [pvvx_mithermometer](https://github.com/airy10/pvvx_mithermometer) custom firmware and using the [pvvx_mithermometer ESPHome sensor](https://esphome.io/components/sensor/xiaomi_ble.html#lywsd03mmc).

Minor detail: Device's name is based on a protagonist of [Raised by Wolves](https://www.imdb.com/title/tt9170108/)

## Plug
Two [ATHOM smart plugs](https://www.aliexpress.com/item/1005002984938182.html) that use an ESP8285 are used. The devices are programmed to behave like regular smart plugs, but they are mainly used for monitoring data such as voltage and power being logged. Also, the current price of a single kWh, taking into account tariff changes (also called peak and off-peak electricity times) throughout the day, is calculated in the `kwh_price_cents` custom sensor. The total cost of power is also aggregated per day in the `total_daily_energy` custom sensor.

## VINDRIKTNING
An [IKEA VINDRIKTNING](https://www.ikea.com/us/en/p/vindriktning-air-quality-sensor-60515911/) air quality sensor has been hacked with an ESP-12E which passively reads the [PM1006 particulate matter sensor](https://esphome.io/components/sensor/pm1006.html) of the device.

# Acknowledgments
* Icon made by [Freepik](https://www.flaticon.com/authors/freepik) from [www.flaticon.com](https://www.flaticon.com/)
