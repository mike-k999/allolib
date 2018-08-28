# macro to get subdirectories
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()


if(BUILD_EXAMPLES)
  subdirlist(EXAMPLE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/examples)
  #include root projects directory too
  list(APPEND EXAMPLE_DIRS ".")
  foreach(dir ${EXAMPLE_DIRS})
    file(GLOB EXAMPLE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} examples/${dir}/*.cpp)
#    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/examples/${dir}/flags.txt)
#      file(READ ${CMAKE_CURRENT_SOURCE_DIR}/examples/${dir}/flags.txt EXTRA_COMPILER_FLAGS)
#      #message("NOTE: Using additional flags from examples/${dir}/flags.txt: " ${EXTRA_COMPILER_FLAGS})
#      STRING(REGEX REPLACE "[\r\n]" " " EXTRA_COMPILER_FLAGS "${EXTRA_COMPILER_FLAGS}")
#    else()
#      set(EXTRA_COMPILER_FLAGS "")
#    endif()

    file(GLOB EXAMPLE_RES_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} examples/${dir}/*)

    foreach(example_src ${EXAMPLE_FILES})
      get_filename_component(EXAMPLE_NAME ${example_src} NAME_WE) # Get name w/o extension
	  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_ROOT_DIR}/build/bin/examples/${dir}")

      if ("${dir}" STREQUAL ".")
	set(EXAMPLE_TARGET examples_${EXAMPLE_NAME})
      else()
	set(EXAMPLE_TARGET examples_${dir}_${EXAMPLE_NAME})
      endif()
      add_executable(${EXAMPLE_TARGET} ${example_src})

#     message("Adding target for example: ${example_src}")
      include_directories(${ALLOCORE_INCLUDE_DIR} ${ALLOUTIL_INCLUDE_DIR} ${ALLOGLV_INCLUDE_DIR}
        ${GLV_INCLUDE_DIRS} ${GAMMA_INCLUDE_DIRS} ${ALLOAUDIO_INCLUDE_DIR} ${ALLOSPHERE_INCLUDE_DIR})
      #    message("Gamma : ${GAMMA_INCLUDE_DIRs}")
      add_dependencies(${EXAMPLE_TARGET} al)
      target_link_libraries(${EXAMPLE_TARGET} al)

      list(REMOVE_ITEM EXAMPLE_RES_FILES ${example_src})
#      add_custom_target("${EXAMPLE_TARGET}_run"
#	COMMAND "${EXAMPLE_TARGET}"
#	DEPENDS "${EXAMPLE_TARGET}"
#	WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
#	SOURCES ${example_src}
#	COMMENT "Running: ${EXAMPLE_TARGET}")

    endforeach(example_src)

  endforeach(dir)

endif(BUILD_EXAMPLES)