.PHONY: mother vindriktning

OTA_PASSWORD := $(shell cat secrets.yaml | sed -n 's/ota_password: //p')

mother:
	esphome run mother.yaml --password $(OTA_PASSWORD) --device $@.lan --no-logs

plug-6c5e9e:
	esphome --substitution voltage_divider 777 run plug.yaml --password $(OTA_PASSWORD) --device $@.lan --no-logs

plug-6e6387:
	esphome --substitution voltage_divider 808 run plug.yaml --password $(OTA_PASSWORD) --device $@.lan --no-logs

vindriktning:
	esphome run vindriktning.yaml --password $(OTA_PASSWORD) --device $@.lan --no-logs

plugs: plug-6c5e9e plug-6e6387

all: mother plugs vindriktning
