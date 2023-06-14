#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=App_layer/Application.c MCAL/PIC18_config.c MCAL/GPIO/MCAL_GPIO.c MCAL/Interrupts/MCAL_Interrupts_external.c MCAL/Interrupts/MCAL_interrupt_manager.c ECUL/led/ECUL_led.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/App_layer/Application.p1 ${OBJECTDIR}/MCAL/PIC18_config.p1 ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 ${OBJECTDIR}/ECUL/led/ECUL_led.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/App_layer/Application.p1.d ${OBJECTDIR}/MCAL/PIC18_config.p1.d ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/App_layer/Application.p1 ${OBJECTDIR}/MCAL/PIC18_config.p1 ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 ${OBJECTDIR}/ECUL/led/ECUL_led.p1

# Source Files
SOURCEFILES=App_layer/Application.c MCAL/PIC18_config.c MCAL/GPIO/MCAL_GPIO.c MCAL/Interrupts/MCAL_Interrupts_external.c MCAL/Interrupts/MCAL_interrupt_manager.c ECUL/led/ECUL_led.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/App_layer/Application.p1: App_layer/Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App_layer" 
	@${RM} ${OBJECTDIR}/App_layer/Application.p1.d 
	@${RM} ${OBJECTDIR}/App_layer/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App_layer/Application.p1 App_layer/Application.c 
	@-${MV} ${OBJECTDIR}/App_layer/Application.d ${OBJECTDIR}/App_layer/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App_layer/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/PIC18_config.p1: MCAL/PIC18_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/PIC18_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/PIC18_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/PIC18_config.p1 MCAL/PIC18_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/PIC18_config.d ${OBJECTDIR}/MCAL/PIC18_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/PIC18_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1: MCAL/GPIO/MCAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 MCAL/GPIO/MCAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.d ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1: MCAL/Interrupts/MCAL_Interrupts_external.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 MCAL/Interrupts/MCAL_Interrupts_external.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1: MCAL/Interrupts/MCAL_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 MCAL/Interrupts/MCAL_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUL/led/ECUL_led.p1: ECUL/led/ECUL_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUL/led" 
	@${RM} ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUL/led/ECUL_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUL/led/ECUL_led.p1 ECUL/led/ECUL_led.c 
	@-${MV} ${OBJECTDIR}/ECUL/led/ECUL_led.d ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/App_layer/Application.p1: App_layer/Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/App_layer" 
	@${RM} ${OBJECTDIR}/App_layer/Application.p1.d 
	@${RM} ${OBJECTDIR}/App_layer/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/App_layer/Application.p1 App_layer/Application.c 
	@-${MV} ${OBJECTDIR}/App_layer/Application.d ${OBJECTDIR}/App_layer/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/App_layer/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/PIC18_config.p1: MCAL/PIC18_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/PIC18_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/PIC18_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/PIC18_config.p1 MCAL/PIC18_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/PIC18_config.d ${OBJECTDIR}/MCAL/PIC18_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/PIC18_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1: MCAL/GPIO/MCAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1 MCAL/GPIO/MCAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.d ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/MCAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1: MCAL/Interrupts/MCAL_Interrupts_external.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1 MCAL/Interrupts/MCAL_Interrupts_external.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/MCAL_Interrupts_external.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1: MCAL/Interrupts/MCAL_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1 MCAL/Interrupts/MCAL_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.d ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Interrupts/MCAL_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUL/led/ECUL_led.p1: ECUL/led/ECUL_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUL/led" 
	@${RM} ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d 
	@${RM} ${OBJECTDIR}/ECUL/led/ECUL_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUL/led/ECUL_led.p1 ECUL/led/ECUL_led.c 
	@-${MV} ${OBJECTDIR}/ECUL/led/ECUL_led.d ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUL/led/ECUL_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/SmartHome.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
