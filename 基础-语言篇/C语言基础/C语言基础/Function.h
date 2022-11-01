//
//  Function.h
//  C语言基础
//
//  Created by 华天杰 on 2018/10/28.
//  Copyright © 2018年 BQ. All rights reserved.
//

#ifndef Function_h
#define Function_h

#include <stdio.h>

/*
   函数：能够完成特定任务的独立程序代码单元
   函数类型：函数签名，一般包含函数的返回值、函数名、函数接收参数的类型
   函数原型：让编译器捕获在使用函数时可能出现的错误
 
   递归：函数自己调用自己，
   尾递归： 把递归调用置于函数的末尾，即正好在return语句之前
 
   & :取地址运算符
   指针： 存储内存地址的变量
   指针变量的值是地址
   * ： 间接运算符。
   int val = *ptr;
 
   声明指针：
   int * p ;
 
 
 <一> 数据是用二进制数表示的
  （1）问题
    + 32位是几个字节？1byte = 8 bit   4个字节
    + 二进制01011100转化为十进制是多少？  92
    + 二进制数00001111左移两位，会变成原来的几倍？ 左移一位是2倍，两位就是4倍
    + 补码形式表示的8位二进制数11111111，用十进制表示的话是多少？ -1
    + 补码形式表示的8位二进制数10101010，用16位的二进制表示的话是多少？ 1111111110101010
    + 反转部分图形模式，使用的是什么逻辑？ XOR运算
 
   （2）用二进制表示计算机信息的原因
     计算机内部是由IC这种电子部件构成的，IC只具有两种状态
     计算机处理信息最小的单元是位
     二进制的位数一般是8位、16位、32位、也就是8的倍数
     8位二进制数被称为一个字节
     内存和磁盘都是以字节单位来存储和读写数据的，因此字节是信息的基本单位
 
    1> 二进制如何转化为十进制：
     位权的概念
     39 --> 3的位权是 10，9的位权是1；3*10+9*1 = 39；
     101 --> 从右侧向左 1*2^0 + 0*2^1 + 1*2^1
 
 
    2> 移位运算和乘除运算的关系
 
        移位运算：
        左移运算符：<<  ==> 低位补0
        右移运算符：>>  ==> 区分正数和负数
        移位运算代替乘除法，
        十进制左移会变成原来10倍、100倍、1000倍。。。
        同样二进制左移后会变成原来的2倍、4倍、8倍，相反右侧移动会变成1/2、1/4、1/8....
 
    3> 便于计算机处理的“补数”
        二进制表示负数时会把最高位作为符号来使用，因此最高位也被成为符号位，符号位位0表示正数，符号位为1表示负数
 
       计算机中进行减法操作其实也是按照加法操作进行的；
 
       如何用二进制表示负数
       -1
       原生值1 ： 00000001
       按位取反：  11111110
       然后+1操作： 11111111
     4> 逻辑右移和算术右移的区别
 
      逻辑右移：左侧空位用00填充
      算术右移动：空出来的高位用符号位数字填充
 
      -4 ：11111100
      -1 ：11111111
      符号扩充：保持值不变的情况下，将其转化为8位、16位或是32位
      不管正数还是负数都使用符号位上的数字去扩充高位即可
 
      5> 掌握逻辑运算的窍门
         逻辑运算包含：
         + 逻辑非 NOT  0变成1，1变成0
         + 逻辑与  AND 两个都为1才是1，否则为0
         + 逻辑或  OR  至少有一方为1，结果为1，其他为0
         + 逻辑异或 XOR  排斥相同数值的运算
 
  <二> 计算机进行小数运算
 
     + 二进制数0.1，用十进制数表示的话是多少?
     + 用小数点后有3位的二进制数，能表示十进制数0.625吗？
     + 将小数分为符号、尾数、基数、指数4部分进行表现的形式称为什么？
     + 二进制数的基数是什么？
     + 通过把0作为数值范围的中间值，从而在不使用符号位的情况下来表示负数的表示方法称为什么？
     + 10101100.01010011这个二进制数，用十六进制数表示的话是多少？
 
    （1）将0.1累加100次得不到10
 
    （2）用二进制数表示小数
 
     将1011.0011这个有小数点的二进制数转化成十进制
     1x2^3+0x2^2+1x2^1+1x2^0+0x2^(-1)+0x2^(-2)+1x2^(-3)+1x2^(-4) = 11.1875
 
     (3) 计算机出错的原因
 
      有一些十进制的小数无法转换成二进制数的正确表示，只能够取近似值，例如十进制数0.1就无法用二进制数来表示；
      小数点后四位用二进制数表示时的数值范围：0.0000~0.1111，
      因此这里只能表示0.5、0.25、0.125、0.0625这四个二进制小数点后面的位权组合而成（相加总和）的小数
 
     （4）什么是浮点数
      浮点数的表示形式：符号+尾号+基数+指数
      双精度浮点数和单精度浮点数在表示同一个数值时使用的位数不同
 
     （5）正则表达式和EXCESS系统
         尾数部分使用正则表达式，可以将表现形式多样的浮点数统一为一种表现形式；
         例如L：十进制的0.75就有很多表现形式，0.75 x 10^0 、0.75 x 10^1,但遵循
       小数点前是0，小数点后不为0的原则 0.75 x 10^0 是标准的形式；同样二进制中将小数点前面的值
       固定为1的正则表达式；
         指数部分使用EXCESS系统，使用这种方式主要是为了表示负数时不使用符号位，
 
 
     （6）如何避免计算机在处理浮点数时出错
       + 一些实际运算的误差可以忽略不计
       + 将浮点数转化为整数再进行运算，尤其在设计财务方面的处理时，一定要将小数转化为浮点数或者采用BCD(Binary,Coded,Decimal)的方式
 
      (7)二进制和十六进制
      二进制表示数据时，可能位数太长不利于查看，此时可以采用十六进制表示，二进制的4位正好相当于十六进制的1位，
      例如：
        1011.0110 ==》 B.6 小数点后位数不够低位补0即可
 
 
 */

void up_and_down(int n);

void to_base_n(int n ,int b);

void sum_hundred_float();

#endif
