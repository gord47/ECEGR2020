##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_6
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/gauma/ECEGR2020
ProjectPath            :=C:/Users/gauma/ECEGR2020/Lab_6
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab_6
OutDir                 :=../build-$(ConfigurationName)/Lab_6
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=gauma
Date                   :=16/03/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/Tools/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/Tools/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Tools/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Tools/mingw64/bin/ar.exe rcu
CXX      := C:/Tools/mingw64/bin/g++.exe
CC       := C:/Tools/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Tools/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab_6/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab_6" mkdir "..\build-$(ConfigurationName)\Lab_6"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab_6" mkdir "..\build-$(ConfigurationName)\Lab_6"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab_6/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab_6" mkdir "..\build-$(ConfigurationName)\Lab_6"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(ObjectSuffix): stuff2.cpp ../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/gauma/ECEGR2020/Lab_6/stuff2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stuff2.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(DependSuffix): stuff2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(DependSuffix) -MM stuff2.cpp

../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(PreprocessSuffix): stuff2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab_6/stuff2.cpp$(PreprocessSuffix) stuff2.cpp


-include ../build-$(ConfigurationName)/Lab_6//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


