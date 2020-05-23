#! /bin/bash

# Terminal colors
red=$(tput setaf 1)
green=$(tput setaf 2)
normal=$(tput sgr0)

logFile=build_log_$(date +%G_%m_%d_%H%M%S).log
buildFolder=build

printf "${normal}Build script started\n"

# Checking if cmake is installed on the system

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


echo "Searching for Maven" >> ${logFile}
printf "${normal}Searching for Maven: "

if which mvn &> /dev/null ; then
        echo "Maven found"  >> ${logFile}
        printf "${green}Sucess\n"
else
        echo "Build failed: Coudn't find Maven" >> ${logFile}
        printf "${red}Failure\n"
        exit 1
fi


# Checking for old folder

if [[ -d ${buildFolder} ]] ; then
        echo "Removing old build folder" >> ${logFile}
        printf "${normal}Removing old build folder: "
        if rm -rf ${buildFolder} &> /dev/null ; then
                echo "Old build folder removed" >> ${logFile}
                printf "${green}Success\n"
        else 
                echo "Build failed: Coudn't delete old build folder"
                printf "${red}Falure\n"
		exit 2
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
        exit 3
fi

