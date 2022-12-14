
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(RCFDemo)

SET(RCF_ROOT 					${CMAKE_SOURCE_DIR}/../.. )
SET(BIN_PATH 					${CMAKE_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH 		${BIN_PATH} )
SET(LIBRARY_OUTPUT_PATH 		${BIN_PATH})
LINK_DIRECTORIES( 				${BIN_PATH} )

SET(
    RCF_INCLUDES 
    ${RCF_ROOT}/include)
    
IF(MSVC)
	ADD_DEFINITIONS( -D_WIN32_WINNT=0x601 -DWIN32_LEAN_AND_MEAN )
    SET(RCF_LIBS ws2_32)
	IF(CMAKE_CL_64)
		SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
	ENDIF()
ELSE()
    SET(RCF_LIBS pthread dl stdc++fs uuid)	
ENDIF()

ADD_SUBDIRECTORY(RcfLib)
ADD_SUBDIRECTORY(RcfDll)
ADD_SUBDIRECTORY(DemoClient)
ADD_SUBDIRECTORY(DemoServer)
