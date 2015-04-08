#!/bin/bash
#电池基本信息
#电池厂商信息
var1=生产厂商:
var2=电池类型:
var3=设计容量:
var4=上次充满容量:
OEM_info=`cat /proc/acpi/battery/BAT1/info | grep "OEM info" | cut -d":" -f2`
#电池类型
battery_type=`cat /proc/acpi/battery/BAT1/info | grep "battery type" | cut -d":" -f2`
#设计容量
design_capacity=`cat /proc/acpi/battery/BAT1/info | grep "last full capacity" | cut -d":" -f2`
#电池充满容量
battery_full_capacity=`cat /proc/acpi/battery/BAT1/info | grep "full capacity" | cut -d":" -f2`
echo ${var1}${OEM_info}
echo ${var2}${battery_type} 
echo ${var3}${design_capacity}
echo ${var4}${battery_full_capacity}
