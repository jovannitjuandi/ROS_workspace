execute_process(COMMAND "/home/jovanni/owr_ws/build/rqt_virtual_joystick/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/jovanni/owr_ws/build/rqt_virtual_joystick/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
