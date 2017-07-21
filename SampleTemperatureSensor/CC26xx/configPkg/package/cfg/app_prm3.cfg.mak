# invoke SourceDir generated makefile for app.prm3
app.prm3: .libraries,app.prm3
.libraries,app.prm3: package/cfg/app_prm3.xdl
	$(MAKE) -f C:\ti\simplelink\zstack_home_1_02_02a_44539\Projects\zstack\HomeAutomation\SampleTemperatureSensor\CC26xx/src/makefile.libs

clean::
	$(MAKE) -f C:\ti\simplelink\zstack_home_1_02_02a_44539\Projects\zstack\HomeAutomation\SampleTemperatureSensor\CC26xx/src/makefile.libs clean

