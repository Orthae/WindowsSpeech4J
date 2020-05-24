#! /bin/bash

# Error codes
# 1. CMake not found on the system.
# 2. Maven not found on the system.
# 3. Failed to delete old temporary build folder.
# 4. Failed to create temporary build folder.
# 5. Failed to copy speech driver CMake file.
# 6. Failed to copy speech driver source code.
# 7. Failed to copy speech client Maven file.
# 8. Failed to copy speech client source code.
# 9. Failed to initialize CMake.
# 10. Failed to build speech driver.
# 11. Failed to copy speech driver library.
# 12. Failed to resovle Maven dependencies.
# 13. Failed to compile speech client.
# 14. Speech client tests failed to pass.

# Terminal colors
red=$(tput setaf 1)
green=$(tput setaf 2)
normal=$(tput sgr0)

logFile=build_log_$(date +%G_%m_%d_%H%M%S).log
buildFolder=build

printf "${normal}Build script started\n"

# Checking if CMake is installed on the system
echo "Searching for CMake" >> ${logFile}
printf "${normal}Searching for CMake: "

if which cmake &> /dev/null ; then
        echo "CMake found"  >> ${logFile}
        printf "${green}Sucess\n"
else
        echo "Build failed: Coudn't find CMake" >> ${logFile}
        printf "${red}Failure\n"
        exit 1
fi

# Checking if Maven is installed on the system
echo "Searching for Maven" >> ${logFile}
printf "${normal}Searching for Maven: "

if which mvn &> /dev/null ; then
        echo "Maven found"  >> ${logFile}
        printf "${green}Sucess\n"
else
        echo "Build failed: Coudn't find Maven" >> ${logFile}
        printf "${red}Failure\n"
        exit 2
fi


# Checking for old folder
if [[ -d ${buildFolder} ]] ; then
        echo "Removing old build folder" >> ${logFile}
        printf "${normal}Removing old build folder: "
        if rm -rf ${buildFolder} &>> ${logFile} ; then
                echo "Old build folder removed" >> ${logFile}
                printf "${green}Success\n"
        else 
                echo "Build failed: Coudn't delete old build folder" >> ${logFile}
                printf "${red}Falure\n"
		exit 3
	fi
fi

# Creating new build folder
echo "Creating temp build folder" >> ${logFile}
printf "${normal}Creating build folder: "

if mkdir ${buildFolder} &>> ${logFile} ; then
        echo "Temp folder created" >> ${logFile}
        printf "${green}Success\n"
else
        echo "Build failed: Coudn't create temp folder" >> ${logFile}
        printf "${red}Failure\n"
        exit 4
fi

# Copying speech driver
echo "Copying speech driver source code" >> ${logFile}
printf "${normal}Copying speech driver source code: "

# Speech driver CMake file
if mkdir ${buildFolder}/cpp && cp ../cpp/CMakeLists.txt ${buildFolder}/cpp/ ; then
        echo "Speech driver CMake file copied" >> ${logFile}
else
        echo "Build failed: Copying speech driver CMake file failed" >> ${logFile}
        printf "${red}Failure\n"
        exit 5
fi

# Speech driver source code
if cp -r  ../cpp/src ${buildFolder}/cpp/src ; then
        echo "Speech driver source code copied" >> ${logFile}
        printf "${green}Success\n"
else
        echo "Copying speech driver source code failed" >> ${logFile}
        printf "${red}Failure\n"
        exit 6
fi

# Copying speech client source
echo "Copying speech client source code" >> ${logFile}
printf "${normal}Copying speech client source code: "

# Speech client Maven POM
if mkdir ${buildFolder}/java && cp ../java/pom.xml ${buildFolder}/java/ ; then
        echo "Speech client POM file copied" >> ${logFile}
else
        echo "Build failed: Copying speech client POM file failed" >> ${logFile}
        printf "${red}Failure\n"
        exit 7
fi

# Speech client source code
if cp -r ../java/src ${buildFolder}/java/src ; then
        echo "Speech client source code copied" >> ${logFile}
        printf "${green}Success\n"
else
        echo "Build failed: Copying client driver source code failed" >> ${logFile}
        printf "${red}Failure\n"
        exit 8
fi

# Initialize CMake
echo "Initializing CMake" >> ${logFile}
printf "${normal}Initialing CMake: "

if cmake ${buildFolder}/cpp/CMakeLists.txt &>> ${logFile} ; then
	echo "CMake initialized" >> ${logFile}
	printf "${green}Success\n"
else 
	echo "Build failed: Failed to initialize CMake" >> ${logFile}
	printf "${red}Failure\n"
	exit 9
fi

# Build speech driver
echo "Building speech driver" >> ${logFile}
printf "${normal}Building speech driver: "

if cmake --build ${buildFolder}/cpp &>> ${logFile} ; then
	echo "Speech driver builded" >> ${logFile}
	printf "${green}Success\n"
else
	echo "Speech driver build failed" >> ${logFile}
	printf "${red}Failure\n"
	exit 10
fi

# Coping speech driver library file
echo "Coping speech driver library file" >> ${logFile}
printf "${normal}Coping speech driver library file: "

if cp ${buildFolder}/cpp/debug/WindowsSpeech4J.dll ${buildFolder}/java/src/main/resources/ &>> ${logFile} ; then
	echo "Speech driver library copied" >> ${logFile}
	printf "${green}Success\n"
else
	echo "Build failed: Failed to copy speech driver library" >> ${logFile}
	printf "${red}Failure\n"
	exit 11
fi

# Resolving Maven dependencies
echo "Resolving Maven dependencies" >> ${logFile}
printf "${normal}Resolving Maven dependencies: "

if mvn -f ${buildFolder}/java/pom.xml dependency:resolve &>> ${logFile} ; then
	echo "Dependencies resolved" >> ${logFile}
	printf "${green}Success\n"
else 
	echo "Build failed: Failed to resolve dependencies" >> ${logFile}
	printf "${red}Failure\n"
	exit 12
fi

# Compiling speech client
echo "Compiling speech client" >> ${logFile}
printf "${normal}Compiling speech client: " 

if mvn -f ${buildFolder}/java/pom.xml compile &>> ${logFile} ; then
	echo "Speech client compiled" >> ${logFile}
	printf "${green}Success\n"	
else 
	echo "Build failed: Failed to compile speech client" >> ${logFile}
	printf "${red}Failure\n"
	exit 13
fi

# Testing speech client
echo "Testing speech client" >> ${logFile}
printf "${normal}Testing speech client: "

if  mvn -f ${buildFolder}/java/pom.xml test &>> ${logFile} ; then
	echo "Tests passed" >> ${logFile}
	printf "${green}Success\n"
else 
	echo "Build failed: Tests failed" >> ${logFile}
	printf "${red}Failure\n"
	exit 14
fi

# Package project
echo "Packing project" >> ${logFile}
printf "Packing project: "

if  mvn -f ${buildFolder}/java/pom.xml package &>> ${logFile} ; then
	echo "Project has been packed" >> ${logFile}
	printf "${green}Success\n"
else 
	echo "Failed to package project" >> ${logFile}
	printf "${red}Failure\n"
	exit 15
fi
