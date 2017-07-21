#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/tirtos_simplelink_2_11_01_09/packages;C:/ti/tirtos_simplelink_2_11_01_09/products/bios_6_41_02_41/packages;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829/inc;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829/driverlib;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829
override XDCROOT = c:/ti/xdctools_3_30_06_67_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/tirtos_simplelink_2_11_01_09/packages;C:/ti/tirtos_simplelink_2_11_01_09/products/bios_6_41_02_41/packages;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829/inc;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829/driverlib;C:/ti/tirtos_simplelink_2_11_01_09/products/cc26xxware_2_20_06_14829;c:/ti/xdctools_3_30_06_67_core/packages;..
HOSTOS = Windows
endif
