# Install script for directory: /home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/user/labs/avt113-labs-team-5/libhv-http/cmake-build-debug/lib/libhv_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/hv" TYPE FILE FILES
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/hv.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/hconfig.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/hexport.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hplatform.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hdef.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hatomic.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/herr.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/htime.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hmath.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hbase.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hversion.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hsysinfo.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hproc.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hthread.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hmutex.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hsocket.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hlog.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hbuf.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hmain.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/base/hendian.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/ssl/hssl.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/event/hloop.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/event/nlog.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/util/base64.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/util/md5.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/util/sha1.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hmap.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hstring.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hfile.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hpath.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hdir.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hurl.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hscope.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hthreadpool.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hasync.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/hobjectpool.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/ifconfig.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/iniparser.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/json.hpp"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/singleton.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/cpputil/ThreadLocalStorage.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/Buffer.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/Channel.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/Event.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/EventLoop.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/EventLoopThread.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/EventLoopThreadPool.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/Status.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/TcpClient.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/TcpServer.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/UdpClient.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/evpp/UdpServer.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/httpdef.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/wsdef.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/http_content.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/HttpMessage.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/HttpParser.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/WebSocketParser.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/WebSocketChannel.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/server/HttpServer.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/server/HttpService.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/server/HttpContext.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/server/HttpResponseWriter.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/server/WebSocketServer.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/client/HttpClient.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/client/requests.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/client/axios.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/client/AsyncHttpClient.h"
    "/home/user/labs/avt113-labs-team-5/libhv-http/contrib/libhv/http/client/WebSocketClient.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake"
         "/home/user/labs/avt113-labs-team-5/libhv-http/cmake-build-debug/contrib/libhv/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/user/labs/avt113-labs-team-5/libhv-http/cmake-build-debug/contrib/libhv/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/user/labs/avt113-labs-team-5/libhv-http/cmake-build-debug/contrib/libhv/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig-debug.cmake")
  endif()
endif()

