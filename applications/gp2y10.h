/*
 * Copyright (c) 2020, RudyLo <luhuadong@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-01-21     RudyLo       the first version
 */

#ifndef __GP2Y10_H__
#define __GP2Y10_H__

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#define GP2Y10LIB_VERSION   "0.0.1"

#define ADC_DEV_NAME        "adc1"      /* ADC device name */
#define ADC_DEV_CHANNEL     5           /* ADC channel */
#define REFER_VOLTAGE       330         /* 参考电压 3.3V,数据精度乘以100保留2位小数*/
#define CONVERT_BITS        (1 << 12)   /* 转换位数为12位 */

#define PULSE_TIME          280         /* us */
#define COV_RATIO           0.17        /* (ug/m3)/mV */
#define NO_DUST_VOLTAGE     600         /* mV */
#define SYS_VOLTAGE         5000

struct gp2y10_device
{
	rt_base_t  iled_pin;
	rt_base_t  aout_pin;
	rt_mutex_t lock;
};
typedef struct gp2y10_device *gp2y10_device_t;

gp2y10_device_t gp2y10_init(gp2y10_device_t dev, rt_base_t iled_pin, rt_base_t aout_pin);
float gp2y10_get_dust_density(gp2y10_device_t dev);


#endif /* __GP2Y10_H__ */