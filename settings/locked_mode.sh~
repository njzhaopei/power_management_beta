#!/bin/bash

#设置cpu频率
cpufreq-set -c 0 -g ondemand
cpufreq-set -c 1 -g ondemand
#设置ALPM achi,在电池模式下有效
echo SATA_ALPM_ENABLE=true | sudo tee /etc/pm/config.d/sata_alpm

