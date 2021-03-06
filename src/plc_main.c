/**
  * @file  plc_main.c
  * @brief  实现符合IEC61131标准的PLC运行时系统
  * @author hyafz   
  */
/* includes -----------------------------------------------------------------*/
#include "plc_cfg.h"
#include "plc_comm.h"
#include "plc_timer.h"
#include "plc_io.h"
#include "plc_stat.h"

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/

void plcProcessorInit(void)
{
    plcIOInit();

    plcCommInit();

    plcTimerInit();
}

/**
  * @brief PLC主函数
  */
void plcMain(void)
{
	/*初始化PLC*/
    plcProcessorInit();

    /*初始化统计功能*/
    statInit();

    /*启动统计功能*/
    statBegin();
                          
	/*执行PLC配置运行函数，不会返回。*/
	plcCfgRun();
}



