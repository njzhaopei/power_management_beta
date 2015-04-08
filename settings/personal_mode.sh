#!/bin/bash
if [ "high" = $1 ]; then
	xrandr --output LVDS-1 --brightness 1
elif [ "middle" = $1 ]; then
	xrandr --output LVDS-1 --brightness 0.8
elif [ "low" = $1 ]; then
	xrandr --output LVDS-1 --brightness 0.5
fi

if [ "high" = $2 ];then
        echo "cpuperformance"
	cpufreq-set -c 0 -g performance #excute performance model
	cpufreq-set -c 1 -g performance #excute performance model
elif [ "middle" = $2 ];then
        echo "cpuselfdefined"
        cpufreq-set -c 0 -g ondemand #excute self adapt model
	cpufreq-set -c 1 -g ondemand #excute self adapt model
elif [ "low" = $2 ];then
        echo "cpupowersave"
	cpufreq-set -c 0 -g powersave #excute save model
	cpufreq-set -c 1 -g powersave #excute save model
fi
exit
