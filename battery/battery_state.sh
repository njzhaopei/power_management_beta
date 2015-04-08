#!/bin/bash
fix=#
fix1=?
fix2=!
state=`upower -i $(upower -e | grep BAT) | grep --color=never -E "state|to\ full|to\ empty|percentage" | grep "state:" | cut -d":" -f2`
time_to_full=`upower -i $(upower -e | grep BAT) | grep --color=never -E "state|to\ full|to\ empty|percentage" | grep "time to full:" |cut -d":" -f2`
percentage=`upower -i $(upower -e | grep BAT) | grep --color=never -E "state|to\ full|to\ empty|percentage" | grep "percentage" | cut -d":" -f2`
echo ${state}${fix}${time_to_full}${fix1}${percentage}${fix2}


