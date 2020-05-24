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
        if rm -rf ${buildFolder} &> /dev/null ; then
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

if mkdir ${buildFolder} 2> /dev/null ; then
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
        echo "Copying speech driver CMake file failed" >> ${logFile}
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
        echo "Copying speech client POM file failed" >> ${logFile}
        printf "${red}Failure\n"
        exit 7
fi

# Speech client source code
if cp -r ../java/src ${buildFolder}/java/src ; then
        echo "Speech client source code copied" >> ${logFile}
        printf "${green}Success\n"
else
        echo "Copying client driver source code failed" >> ${logFile}
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
	echo "Failed to initialize CMake" >> ${logFile}
	printf "${red}Failure\n"
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
fi

