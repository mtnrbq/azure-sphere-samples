#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)

project(WolfSSL_HighLevelApp C)

azsphere_configure_tools(TOOLS_REVISION "21.10")
azsphere_configure_api(TARGET_API_SET "11")

add_executable(${PROJECT_NAME} main.c eventloop_timer_utilities.c)
target_link_libraries(${PROJECT_NAME} applibs gcc_s c wolfssl)
target_compile_definitions(${PROJECT_NAME} PUBLIC -D_GNU_SOURCE)

azsphere_target_add_image_package(${PROJECT_NAME} RESOURCE_FILES "certs/DigiCertGlobalRootCA.pem")
