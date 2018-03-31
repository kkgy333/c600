/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name   : egon_def.h
*
* Author      : Gary.Wang
*
* Version     : 1.1.0
*
* Date        : 2009.05.21
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2009.05.21       1.1.0        build the file
*
************************************************************************************************************************
*/
#ifndef  __egon_def_h
#define  __egon_def_h

#define BOOT_PUB_HEAD_VERSION           "1100"    // X.X.XX
#define EGON_VERSION                    "1100"    // X.X.XX


#ifndef PLATFORM
#define PLATFORM                        SUNII_PLATFORM_VALUE
#endif

#define EGON2_DRAM_BASE                 0x20000000
#define EGON2_DRAM_SIZE                 0x02000000
#define EGON2_SRAM_BASE                 0x10000
#define EGON2_SRAM_SIZE                 ( 32 * 1024 )
#define EGON2_RESET_BASE                0xFFFF0000


#define EGON2_MMU_BASE                  0x20000
#define EGON2_REGS_BASE				    0x01c00000
#define EGON2_REGS_SIZE					0x02000000


#define NF_ALIGN_SIZE                   SZ_16K
#define SF_ALIGN_SIZE                   512       // change 256 to 512. by Gary, 2009-12-10 11:46:51
#define IE_ALIGN_SIZE                   512       // change  64 to 512. by Gary, 2009-12-10 11:46:51


#define SPI_NOR_SCT_SIZE                512       // add for spi nor. by Gary,2009-12-8 11:47:17
#define SPI_NOR_SCT_SIZE_WIDTH          9         // add for spi nor. by Gary,2009-12-8 11:47:17

#define BOOT_SECTOR_SIZE                512
#define BOOT_SECTOR_SIZE_WIDTH          9


#define MASK_TOTAL                      0x80000000
#define DEFAULT_VALUE                   0x0
#define STAMP_VALUE                     0x5F0A6C39


#define BOOT0_BASE                      ( EGON2_SRAM_BASE                       )
#define UBOOT_BASE						( 0x2A000000					        )
#define FEL_BASE                        ( 0x20               					)

#define DRAM_PARA_STORE_ADDR			(0x20800000)
#define SUNXI_DRAM_PARA_MAX   			(32)

//ͨ�õģ���GPIO��ص����ݽṹ
typedef struct _normal_gpio_cfg
{
    __u8      port;                       //�˿ں�
    __u8      port_num;                   //�˿��ڱ��
    __s8      mul_sel;                    //���ܱ��
    __s8      pull;                       //����״̬
    __s8      drv_level;                  //������������
    __s8      data;                       //�����ƽ
    __u8      reserved[2];                //����λ����֤����
}
normal_gpio_cfg;


/******************************************************************************/
/*                              file head of Boot                             */
/******************************************************************************/
typedef struct _Boot_file_head
{
	__u32  jump_instruction;   // one intruction jumping to real code
	__u8   magic[8];           // ="eGON.BT0" or "eGON.BT1",  not C-style string.
	__u32  check_sum;          // generated by PC
	__u32  length;             // generated by PC
	__u32  boot1_length;       // the size of boot_file_head_t
	__u32  align_size;         // the align size of boot1
	__u8   file_head_vsn[4];   // the version of boot0_file_head_t or boot1_file_head_t
	__u8   Boot_vsn[4];        // Boot version
	__u8   eGON_vsn[4];        // eGON version
	__u8   platform[8];        // platform information
}boot_file_head_t;




#endif     //  ifndef __egon_def_h

/* end of egon_def.h */