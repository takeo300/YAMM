#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/SkypeStatus.o \
	${OBJECTDIR}/SkypeUser.o \
	${OBJECTDIR}/Skype.o \
	${OBJECTDIR}/Logger.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/C/MinGW/lib/libgdi32.a /C/MinGW/lib/libkernel32.a /C/MinGW/lib/libuser32.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe: /C/MinGW/lib/libgdi32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe: /C/MinGW/lib/libkernel32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe: /C/MinGW/lib/libuser32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/C/MinGW/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/SkypeStatus.o: SkypeStatus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/C/MinGW/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SkypeStatus.o SkypeStatus.cpp

${OBJECTDIR}/SkypeUser.o: SkypeUser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/C/MinGW/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/SkypeUser.o SkypeUser.cpp

${OBJECTDIR}/Skype.o: Skype.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/C/MinGW/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Skype.o Skype.cpp

${OBJECTDIR}/Logger.o: Logger.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I/C/MinGW/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Logger.o Logger.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/skype_communicator.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
