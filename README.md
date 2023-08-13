<!-- encoding: utf-8 -->

# STC89C52RC-PCF8591

STC-89C52RC 单片机搭配 PCF8591 模数转换器（ADC）通过 IIC 总线通信获取光敏、热敏电阻及电位器的电压。

## 重要参数

波特率：9600

晶振频率：11.0592MHz

## 开发环境

编译器：Keil UV5

开发工具：Visual Studio Code

开发工具插件：C/C++ Extension Pack、Embedded IDE

## 关于 PCF8591 模块

引脚 com 地址：

引脚|地址
-|-
AIN0|0x40
AIN1|0x41
AIN2|0x42
AIN3|0x43

板载了热敏电阻、光敏电阻和电位器：

位号|名称|引脚|地址
-|-|-|-
J4|热敏电阻|AIN1|0x41
J5|光敏电阻|AIN0|0x40
J6|电位器|AIN3|0x43
