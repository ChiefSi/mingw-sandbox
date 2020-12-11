cmake_minimum_required(VERSION 3.16)

project(hello-world)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello-world hello-world.cpp)
install(TARGETS hello-world DESTINATION ${CMAKE_INSTALL_BINDIR})

# cmake issue 20753, 6months old
if(WIN32 OR NOT WIN32)
	install(CODE "set(CMAKE_FIND_ROOT_PATH \"${CMAKE_FIND_ROOT_PATH}\")")
	install(CODE [[
		file(GET_RUNTIME_DEPENDENCIES
			RESOLVED_DEPENDENCIES_VAR resolved
			UNRESOLVED_DEPENDENCIES_VAR unresolved
			EXECUTABLES $<TARGET_FILE:hello-world>
		)
		message(STATUS "Resolving runtime dependencies for $<TARGET_FILE:hello-world>")
		foreach(dep ${resolved})
			file(INSTALL ${dep} DESTINATION ${CMAKE_INSTALL_PREFIX})
		endforeach()
		foreach(dep ${unresolved})
			message(WARNING "Runtime dependency ${dep} could not be resolved.")
		endforeach()
	]])
endif()
